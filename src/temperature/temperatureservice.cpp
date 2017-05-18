#include "temperatureservice.h"

/*===============PUBLIC==============*/

TemperatureService::TemperatureService() {
	_isInitialized = false;

	MIN_TEMP = 15;
	MAX_TEMP = 35;

	//TODO: add gpios for LEDs
	LED_NORMAL_TEMP = -1;
	LED_ERROR_LOW_TEMP = -1;
	LED_ERROR_HIGH_TEMP = -1;

	_temperatureControlActive = true;
}

TemperatureService::~TemperatureService() {
}

void TemperatureService::Initialize(FileController fileController,
		MailService mailService, std::string sensorId,
		std::string temperatureArea, std::string graphPath) {
	_fileController = fileController;
	_mailService = mailService;

	_settingsFile = "/etc/default/lucahome/temperaturesettings";
	loadSettings();

	std::ostringstream path;
	path << "/sys/bus/w1/devices/" << sensorId << "/w1_slave";
	_sensorPath = path.str();

	_temperatureArea = temperatureArea;

	_graphPath = graphPath;

	_warningCount = 0;
	_isInitialized = true;
}

void TemperatureService::ControlTemperature() {
	if (!_isInitialized) {
		syslog(LOG_INFO, "TemperatureService is not initialized!");
		return;
	}

	double currentTemperature = loadTemperature();

	if (currentTemperature < MIN_TEMP) {
		syslog(LOG_INFO, "Temperature low! %d", currentTemperature);

		std::ostringstream data;
		data << "Current temperature at " << _temperatureArea << " is too low! "
				<< currentTemperature << "�C!";

		sendWarningMail(data.str());
		enableLED(LED_ERROR_LOW_TEMP);
	} else if (currentTemperature > MAX_TEMP) {
		syslog(LOG_INFO, "Temperature high! %d", currentTemperature);

		std::ostringstream data;
		data << "Current temperature at " << _temperatureArea
				<< " is too high! " << currentTemperature << "�C!";

		sendWarningMail(data.str());
		enableLED(LED_ERROR_HIGH_TEMP);
	} else {
		if (_warningCount > 0) {
			syslog(LOG_INFO,
					"Temperature was for %d minutes not in normal values!",
					_warningCount);
		}

		_warningCount = 0;
		enableLED(LED_NORMAL_TEMP);
	}
}

std::string TemperatureService::PerformAction(std::string action,
		std::vector<std::string> data) {
	if (action == "GET") {
		if (data.size() == 5) {
			if (data[4] == "REST") {
				return getRestString();
			} else if (data[4] == "WEBSITE") {
				return getString();
			} else {
				return "Error 132:Wrong action parameter for temperature";
			}
		} else {
			return "Error 131:Wrong data size for temperature";
		}
	} else if (action == "SETCONTROLTASK") {
		if (data[4] == "ON") {
			_temperatureControlActive = true;
			return "setTemperatureControl:1:1";
		} else if (data[4] == "OFF") {
			_temperatureControlActive = false;
			return "setTemperatureControl:0:1";
		} else {
			return "Error 133:Invalid data for temperature";
		}
	} else {
		return "Error 130:Action not found for temperature";
	}
}

bool TemperatureService::GetTemperatureControlActive() {
	return _temperatureControlActive;
}

/*==============PRIVATE==============*/

void TemperatureService::saveSettings() {
	std::string xmldata = _xmlService.generateTemperatureSettingsXml(MIN_TEMP,
			MAX_TEMP, LED_NORMAL_TEMP, LED_ERROR_LOW_TEMP, LED_ERROR_HIGH_TEMP,
			_temperatureControlActive);
	_fileController.saveFile(_settingsFile, xmldata);
}

void TemperatureService::loadSettings() {
	std::string settingsString = _fileController.readFile(_settingsFile);
	_xmlService.setContent(settingsString);

	MIN_TEMP = _xmlService.getTempMin();
	MAX_TEMP = _xmlService.getTempMax();

	LED_NORMAL_TEMP = _xmlService.getLEDTempNormal();
	LED_ERROR_LOW_TEMP = _xmlService.getLEDTempLow();
	LED_ERROR_HIGH_TEMP = _xmlService.getLEDTempHigh();

	_temperatureControlActive = _xmlService.isTempControlActive();
}

double TemperatureService::loadTemperature() {
	const char *charPath = _sensorPath.c_str();
	FILE *device = fopen(charPath, "r");

	double temperature = -1;
	char crcVar[5];

	if (device != NULL) {
		if (!ferror(device)) {
			fscanf(device, "%*x %*x %*x %*x %*x %*x %*x %*x %*x : crc=%*x %s",
					crcVar);
			if (strncmp(crcVar, "YES", 3) == 0) {
				fscanf(device, "%*x %*x %*x %*x %*x %*x %*x %*x %*x t=%lf",
						&temperature);
				temperature /= 1000.0;
			} else {
				syslog(LOG_INFO, "Error strncmp!");
			}
		} else {
			syslog(LOG_INFO, "Error with device!");
		}
	} else {
		syslog(LOG_INFO, "Check connections %s", _sensorPath.c_str());
	}

	fclose(device);

	return temperature;
}

void TemperatureService::sendWarningMail(std::string warning) {
	_warningCount++;

	if (_warningCount % 10 != 0) {
		syslog(LOG_INFO,
				"Already send a mail within the last five or more minutes!");
		return;
	}

	_mailService.sendMail(warning);
}

void TemperatureService::enableLED(int led) {
	if (led == -1) {
		//syslog(LOG_INFO, "LED has wrong value! Cannot enable -1!");
		return;
	}

	PiControl::writeGpio(LED_ERROR_HIGH_TEMP, 0);
	PiControl::writeGpio(LED_ERROR_LOW_TEMP, 0);
	PiControl::writeGpio(LED_NORMAL_TEMP, 0);

	if (led == LED_ERROR_HIGH_TEMP) {
		PiControl::writeGpio(LED_ERROR_HIGH_TEMP, 1);
	} else if (led == LED_ERROR_LOW_TEMP) {
		PiControl::writeGpio(LED_ERROR_LOW_TEMP, 1);
	} else if (led == LED_NORMAL_TEMP) {
		PiControl::writeGpio(LED_NORMAL_TEMP, 1);
	} else {
		syslog(LOG_INFO, "LED has wrong value! Cannot enable %d!", led);
	}
}

double TemperatureService::getValue() {
	if (!_isInitialized) {
		syslog(LOG_INFO, "TemperatureService is not initialized!");
		return -1;
	}

	return loadTemperature();
}

std::string TemperatureService::getString() {
	if (!_isInitialized) {
		syslog(LOG_INFO, "TemperatureService is not initialized!");
		return "";
	}

	std::stringstream out;
	out << loadTemperature();
	out << std::endl;

	return out.str();
}

std::string TemperatureService::getRestString() {
	if (!_isInitialized) {
		syslog(LOG_INFO, "TemperatureService is not initialized!");
		return "";
	}

	std::stringstream out;

	out << "{temperature:" << "{value:" << loadTemperature() << "};" << "{area:"
			<< _temperatureArea << "};" << "{sensorPath:" << _sensorPath << "};"
			<< "{graphPath:" << _graphPath << "};" << "};";

	out << "\x00" << std::endl;

	return out.str();
}
