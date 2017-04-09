#include <string>
#include <sstream>

namespace patch {
template<typename T> std::string to_string(const T& n) {
	std::ostringstream stm;
	stm << n;
	return stm.str();
}
}

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>

#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <syslog.h>

#include "common/tools.h"

#include "accesscontrol/accesscontrolservice.h"
#include "audio/audioservice.h"
#include "authentification/authentificationservice.h"
#include "birthdays/birthdayservice.h"
#include "camera/cameraservice.h"
#include "changes/changeservice.h"
#include "flatmap/mapcontentservice.h"
#include "informations/informationservice.h"
#include "mail/mailservice.h"
#include "menu/menuservice.h"
#include "movies/movieservice.h"
#include "receiver/receiverservice.h"
#include "remote/schedule.h"
#include "remote/remoteservice.h"
#include "shoppinglist/entryservice.h"
#include "system/systemservice.h"
#include "temperature/temperatureservice.h"
#include "watchdog/watchdogservice.h"

#include "logger/logger.h"
#include "controller/filecontroller.h"

#define BUFLEN 512

using namespace std;

bool _updatedSchedules;
vector<Schedule> _schedules;
vector<ScheduleTask> _scheduleTasks;

Logger _logger;
FileController _fileController;

AccessControlService _accessControlService;
AudioService _audioService;
AuthentificationService _authentificationService;
BirthdayService _birthdayService;
CameraService _cameraService;
ChangeService _changeService;
EntryService _entryService;
InformationService _informationService;
MailService _mailService;
MenuService _menuService;
MapContentService _mapContentService;
MovieService _movieService;
ReceiverService _receiverService;
RemoteService _remoteService;
SystemService _systemService;
TemperatureService _temperatureService;
WatchdogService _watchdogService;

//TODO reactivate!
//RCSwitch _receiverSwitch;

pthread_mutex_t birthdaysMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t changesMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t gpiosMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t moviesMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t schedulesMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t socketsMutex = PTHREAD_MUTEX_INITIALIZER;

string executeCmd(string cmd, int source) {
	syslog(LOG_INFO, "Received command: %s", cmd.c_str());

	if (cmd.length() < 20) {
		return "Error 21:statement too short";
	}
	if (source != 1 && source != 2) {
		return "Error 14:Invalid source";
	}

	vector < string > data = Tools::explode(":", cmd);
	if (data.size() < 1) {
		return "Error 13:No username";
	}
	if (data.size() < 2) {
		return "Error 12:No password";
	}
	if (data.size() < 3) {
		return "Error 24:No category";
	}
	if (data.size() < 4) {
		return "Error 23:No action";
	}

	string username = data[0];
	string password = data[1];
	string category = data[2];
	string action = data[3];

	if (username == "") {
		return "Error 13:No username";
	}
	if (password == "") {
		return "Error 12:No password";
	}
	if (category == "") {
		return "Error 24:No category";
	}
	if (action == "") {
		return "Error 23:No action";
	}
	if (data[4] == "") {
		return "Error 25:No action parameter";
	}

	if (username == "Scheduler" && source != 2) {
		return "Error 26:scheduler not allowed from external source";
	}

	// TODO activate if logger is wished
	//_logger.addLog("DEBUG", data, username);

	//---------------Authentificate user--------------
	if (!_authentificationService.authentificateUser(username, password)) {
		syslog(LOG_INFO, "executeCmd: %s failed! authentificateUser failed!",
				cmd.c_str());
		return "Error 10:Authentification failed";
	}
	if (!_authentificationService.authentificateUserAction(username, password,
			action)) {
		syslog(LOG_INFO,
				"executeCmd: %s failed! authentificateUserAction failed!",
				cmd.c_str());
		return "Error 11:UserAction cannot be performed:No rights";
	}

	//-----------------Access Control-----------------
	if (category == "ACCESS") {
		if (action == "ACTIVATE" && data[4] == "ALARM") {
			return _accessControlService.activateAlarm();
		} else if (action == "CHECK" && data[4] == "CODE") {
			return _accessControlService.checkCode(data[5]);
		} else if (action == "PLAY" && data[4] == "ALARM") {
			return _accessControlService.playAlarm();
		} else if (action == "STOP" && data[4] == "ALARM") {
			return _accessControlService.stopAlarm();
		}
	}
	//--------------------Birthday--------------------
	else if (category == "BIRTHDAY") {
		return _birthdayService.performAction(action, data, _changeService,
				username);
	}
	//---------------------Camera---------------------
	else if (category == "CAMERA") {
		return _cameraService.PerformAction(action, data);
	}
	//---------------------Changes--------------------
	else if (category == "CHANGE") {
		return _changeService.performAction(action, data);
	}
	//------------------Informations------------------
	else if (category == "INFORMATION") {
		return _informationService.performAction(action, data);
	}
	//-------------------MapContent-------------------
	else if (category == "MAPCONTENT") {
		return _mapContentService.performAction(action, data, _changeService,
				username);
	}
	//----------------------Menu----------------------
	else if (category == "MENU") {
		return _menuService.performAction(action, data, _changeService,
				username);
	}
	//---------------------Movies---------------------
	else if (category == "MOVIE") {
		return _movieService.performAction(action, data, _changeService,
				username, _remoteService);
	}
	//---------------------Remote---------------------
	else if (category == "REMOTE") {
		if (data[4] == "SCHEDULE") {
			if (action == "ADD" || action == "DELETE" || action == "SET") {
				_updatedSchedules = true;
			}
		}
		return _remoteService.performAction(action, data, _changeService,
				username);
	}
	//------------------ShoppingList------------------
	if (category == "SHOPPINGLIST") {
		return _entryService.performAction(action, data, _changeService,
				username);
	}
	//----------------------Sound---------------------
	else if (category == "SOUND") {
		return _audioService.performAction(action, data);
	}
	//---------------------System---------------------
	else if (category == "SYSTEM") {
		return _systemService.PerformAction(action, data);
	}
	//--------------------Temperature-----------------
	else if (category == "TEMPERATURE") {
		return _temperatureService.PerformAction(action, data);
	}
	//----------------------User----------------------
	else if (category == "USER") {
		if (action == "VALIDATE") {
			return "validateuser:1";
		}
	}
	//---------------------Watchdog---------------------
	else if (category == "WATCHDOG") {
		return _watchdogService.PerformAction(action, data);
	}

	return "Error 20:action not found";
}

void *server(void *arg) {
	syslog(LOG_INFO, "Server started!");

	int socketResult, connection, answer, clientLength;
	struct sockaddr_in clientAddress, serverAddress;
	char message[BUFLEN];

	int port = _remoteService.getPort();

	socketResult = socket(AF_INET, SOCK_DGRAM, 0);
	if (socketResult < 0) {
		syslog(LOG_CRIT, "Cant't open socket");
	}

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(port);

	connection = bind(socketResult, (struct sockaddr *) &serverAddress,
			sizeof(serverAddress));
	if (connection < 0) {
		syslog(LOG_CRIT, "Can't bind socket to port %d", port);
		exit(1);
	}

	syslog(LOG_INFO, "Server listen on port %u", port);

	while (1) {
		memset(message, 0x0, BUFLEN);
		clientLength = sizeof(clientAddress);

		answer = recvfrom(socketResult, message, BUFLEN, 0,
				(struct sockaddr *) &clientAddress, (socklen_t*) &clientLength);

		if (answer < 0) {
			syslog(LOG_ERR, "Can't receive data");
			continue;
		} else {
			syslog(LOG_INFO, "Received: %s", message);

			pthread_mutex_lock(&changesMutex);
			pthread_mutex_lock(&birthdaysMutex);
			pthread_mutex_lock(&moviesMutex);
			pthread_mutex_lock(&schedulesMutex);
			pthread_mutex_lock(&gpiosMutex);
			pthread_mutex_lock(&socketsMutex);

			// Parse and execute request
			string response = executeCmd(message, 1);

			if (_updatedSchedules) {
				_schedules = _remoteService.getSchedules();
				_updatedSchedules = false;
			}

			_remoteService.reloadData();
			_changeService.reloadData();

			pthread_mutex_unlock(&socketsMutex);
			pthread_mutex_unlock(&gpiosMutex);
			pthread_mutex_unlock(&schedulesMutex);
			pthread_mutex_unlock(&moviesMutex);
			pthread_mutex_unlock(&birthdaysMutex);
			pthread_mutex_unlock(&changesMutex);

			int sendResult = sendto(socketResult, response.c_str(),
					strlen(response.c_str()), 0,
					(struct sockaddr *) &clientAddress, clientLength);
			if (sendResult < 0) {
				syslog(LOG_ERR, "Can't send data");
			}
			syslog(LOG_INFO, "Sent: %s", response.c_str());
		}
	}
	close(socketResult);
	syslog(LOG_INFO, "Exiting *server");
	pthread_exit (NULL);
}

void *scheduler(void *arg) {
	syslog(LOG_INFO, "Scheduler started!");

	time_t now;
	struct tm now_info;
	int weekday;

	while (1) {
		now = time(0);
		localtime_r(&now, &now_info);

		time_t rawtime;
		tm * timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		weekday = timeinfo->tm_wday;

		pthread_mutex_lock(&schedulesMutex);

		// Search for done, deleted and inactive Schedules
		vector<ScheduleTask>::iterator it = _scheduleTasks.begin();
		while (it != _scheduleTasks.end()) {
			int found = 0;
			int done = 0;
			int active = 1;

			for (int s = 0; s < _schedules.size(); s++) {
				if (_schedules[s].getName() == (*it).getSchedule()) {
					found = 1;
					if (!_schedules[s].getStatus()) {
						active = 0;
					}
				}
			}

			if ((*it).isDone()) {
				double deltaTime = difftime((*it).getTime(), now);
				if (deltaTime < -61) {
					done = 1;
				}
			}

			if (!found || !active || done) {
				syslog(LOG_INFO, "Removing Task '%s'",
						(*it).getSchedule().c_str());
				it = _scheduleTasks.erase(it);
			} else {
				++it;
			}
		}

		// Add Schedules to Tasklist
		for (int s = 0; s < _schedules.size(); s++) {
			int found = 0;

			for (int st = 0; st < _scheduleTasks.size(); st++) {
				if (_schedules[s].getName()
						== _scheduleTasks[st].getSchedule()) {
					found = 1;
				}
			}

			if (!found && _schedules[s].getStatus()) {
				time_t newtime = time(0);
				struct tm tasktime;
				localtime_r(&newtime, &tasktime);
				tasktime.tm_hour = _schedules[s].getHour();
				tasktime.tm_min = _schedules[s].getMinute();
				tasktime.tm_sec = 0;

				newtime = mktime(&tasktime);
				ScheduleTask task(_schedules[s].getName(), newtime,
						_schedules[s].getWeekday());
				_scheduleTasks.push_back(task);
				syslog(LOG_INFO, "Adding Task '%s'",
						_schedules[s].getName().c_str());
			}
		}

		// Execute Tasks
		for (int st = 0; st < _scheduleTasks.size(); st++) {
			time_t tasktime = _scheduleTasks[st].getTime();
			struct tm tasktime_info;
			localtime_r(&tasktime, &tasktime_info);

			int scheduleWeekday = _scheduleTasks[st].getWeekday();
			string schedule = _scheduleTasks[st].getSchedule();

			if (_scheduleTasks[st].isDone() == 0 && scheduleWeekday == weekday
					&& tasktime_info.tm_hour == now_info.tm_hour
					&& tasktime_info.tm_min == now_info.tm_min) {

				syslog(LOG_INFO, "Executing Task '%s'", schedule.c_str());

				for (int s = 0; s < _schedules.size(); s++) {
					if (schedule == _schedules[s].getName()) {
						if (_schedules[s].getStatus()) {
							if (_schedules[s].getSocket() != "") {
								stringstream socket_out;
								socket_out
										<< "Scheduler:435435:REMOTE:SET:SOCKET:"
										<< _schedules[s].getSocket() << ":"
										<< _schedules[s].getOnoff();

								pthread_mutex_lock(&socketsMutex);

								string response = executeCmd(socket_out.str(),
										2);
								if (response != "setsocket:1") {
									syslog(LOG_INFO,
											"Setting socket %s by scheduler failed!",
											_schedules[s].getSocket().c_str());
								}

								pthread_mutex_unlock(&socketsMutex);
							}

							if (_schedules[s].getGpio() != "") {
								stringstream gpio_out;
								gpio_out << "Scheduler:435435:REMOTE:SET:GPIO:"
										<< _schedules[s].getGpio() << ":"
										<< _schedules[s].getOnoff();

								pthread_mutex_lock(&gpiosMutex);

								string response = executeCmd(gpio_out.str(), 2);
								if (response != "setgpio:1") {
									syslog(LOG_INFO,
											"Setting gpio %s by scheduler failed!",
											_schedules[s].getGpio().c_str());
								}

								pthread_mutex_unlock(&gpiosMutex);
							}

							if (_schedules[s].getPlaySound() == 1
									&& _schedules[s].getIsTimer() != 1) {
								if (_schedules[s].getPlayRaspberry()
										== _remoteService.getRaspberry()) {
									stringstream sound_out;
									sound_out
											<< "Scheduler:435435:SOUND:PLAY:WAKEUP";

									stringstream socket_out;
									socket_out
											<< "Scheduler:435435:REMOTE:SET:SOCKET:SOUND:1";

									pthread_mutex_lock(&socketsMutex);

									string responseSocket = executeCmd(
											socket_out.str(), 2);
									if (responseSocket
											!= "activateSoundSocket:1") {
										syslog(LOG_INFO,
												"Activating sound socket failed! %s",
												responseSocket.c_str());
									} else {
										string responseSound = executeCmd(
												sound_out.str(), 2);
										if (responseSound
												!= _remoteService.getWakeUpSound().c_str()) {
											syslog(LOG_INFO,
													"Playing wakeup failed! %s | %s",
													_remoteService.getWakeUpSound().c_str(),
													responseSound.c_str());
										}
									}

									pthread_mutex_unlock(&socketsMutex);
								}
							}

							if (_schedules[s].getIsTimer() == 1) {
								if (_schedules[s].getPlaySound() == 1) {
									if (_schedules[s].getPlayRaspberry()
											== _remoteService.getRaspberry()) {
										stringstream sound_out;
										sound_out
												<< "Scheduler:435435:SOUND:STOP:WAKEUP";

										stringstream socket_out;
										socket_out
												<< "Scheduler:435435:REMOTE:SET:SOCKET:SOUND:0";

										pthread_mutex_lock(&socketsMutex);

										string responseSocket = executeCmd(
												socket_out.str(), 2);
										if (responseSocket
												!= "deactivateSoundSocket:0") {
											syslog(LOG_INFO,
													"Deactivating sound socket failed! %s",
													responseSocket.c_str());
										} else {
											string responseSound = executeCmd(
													sound_out.str(), 2);
											if (responseSound
													!= "stopplaying:1") {
												syslog(LOG_INFO,
														"Stopping wakeup failed! %s | %s",
														_remoteService.getWakeUpSound().c_str(),
														responseSound.c_str());
											}
										}

										pthread_mutex_unlock(&socketsMutex);
									}
								}

								stringstream schedule_delete_out;
								schedule_delete_out
										<< "Scheduler:435435:REMOTE:DELETE:SCHEDULE:"
										<< _schedules[s].getName();

								string response = executeCmd(
										schedule_delete_out.str(), 2);
								if (response != "deleteschedule:1") {
									syslog(LOG_INFO,
											"Deleting schedule %s by scheduler failed!",
											_schedules[s].getName().c_str());
								}
							}
						}
					}
				}
				_scheduleTasks[st].setDone(1);
			}
		}
		pthread_mutex_unlock(&schedulesMutex);
		sleep(10);
	}
	syslog(LOG_INFO, "Exiting *scheduler");
	pthread_exit (NULL);
}

void *receiver(void *arg) {
	syslog(LOG_INFO, "Receiver started!");

	int receivergpio = _remoteService.getReceiverGpio();

	bool foundValidGpio = false;
	//TODO: enable receiver later to test feature! only if receiver is mounted on RPi and store data to assets!
	if (receivergpio > 0 && receivergpio < 30) {
		foundValidGpio = true;

		//TODO reactivate!
		//_receiverSwitch = RCSwitch();
		//_receiverSwitch.enableReceive(receivergpio);
	} else {
		syslog(LOG_INFO, "receivergpio has invalid value: %d", receivergpio);
	}

	if (wiringPiSetup() == -1) {
		syslog(LOG_INFO, "wiringPiSetup failed, exiting...");
		foundValidGpio = false;
	}

	while (foundValidGpio) {
		//TODO reactivate!
		/*if (_receiverSwitch.available()) {
		 int value = _receiverSwitch.getReceivedValue();

		 if (value == 0) {
		 syslog(LOG_INFO, "Received value with unknown encoding!");
		 } else {
		 _receiverService.performAction(value);
		 }

		 _receiverSwitch.resetAvailable();
		 }*/
	}

	syslog(LOG_INFO, "Exiting *receiver");
	pthread_exit (NULL);
}

void *birthdayControl(void *arg) {
	syslog(LOG_INFO, "BirthdayControl started!");

	while (1) {
		if (_birthdayService.GetBirthdayControlActive()) {
			_birthdayService.checkBirthday();
		}

		//Check birthdays once a day (86400sec == 1440min == 24h)
		sleep(24 * 60 * 60);
	}

	syslog(LOG_INFO, "Exiting *birthdayControl");
	pthread_exit (NULL);
}

void *cameraStartControl(void *arg) {
	syslog(LOG_INFO, "CameraStartControl started!");

	while (1) {
		if (_cameraService.GetStartCamera()
				&& !_cameraService.GetStopCamera()) {
			_cameraService.StartMotion();
		}

		sleep(1);
	}

	syslog(LOG_INFO, "Exiting *cameraStartControl");
	pthread_exit (NULL);
}

void *cameraStopControl(void *arg) {
	syslog(LOG_INFO, "CameraStopControl started!");

	while (1) {
		if (!_cameraService.GetStartCamera()
				&& _cameraService.GetStopCamera()) {
			_cameraService.StopMotion();
		}

		sleep(1);
	}

	syslog(LOG_INFO, "Exiting *cameraStopControl");
	pthread_exit (NULL);
}

void *motionControl(void *arg) {
	syslog(LOG_INFO, "MotionControl started!");

	while (1) {
		if (_cameraService.GetMotionControlActive()) {
			_cameraService.Check();
		}

		//Check motion every 30 seconds (1800 msec == 30 sec)
		sleep(15 * 60);
	}

	syslog(LOG_INFO, "Exiting *motionControl");
	pthread_exit (NULL);
}

void *temperatureControl(void *arg) {
	syslog(LOG_INFO, "TemperatureControl started!");

	while (1) {
		if (_temperatureService.GetTemperatureControlActive()) {
			_temperatureService.ControlTemperature();
		}

		//Check temperature every 30 seconds
		sleep(30);
	}

	syslog(LOG_INFO, "Exiting *temperatureControl");
	pthread_exit (NULL);
}

int main(void) {
	openlog("lucahome", LOG_PID | LOG_CONS, LOG_USER);
	syslog(LOG_INFO, "Starting LucaHome!");

	time_t now = time(0);
	syslog(LOG_INFO, "Current Scheduler-Time: %s", ctime(&now));

	_authentificationService.initialize(_fileController);
	_birthdayService.initialize(_fileController, _mailService);
	_changeService.initialize(_fileController);
	_entryService.initialize(_fileController);
	_informationService.initialize(_fileController);
	_mapContentService.initialize(_fileController);
	_menuService.initialize(_fileController);
	_movieService.initialize(_fileController);
	_remoteService.initialize(_fileController);
	_audioService.initialize("/media/lucahome/",
			_remoteService.getWakeUpSound(), _remoteService.getAlarmSound(),
			_remoteService.getRaspberry());
	_accessControlService.initialize(_fileController, _mailService,
			User("AccessControl", "518716", 1), _remoteService.getAccessUrl(),
			_remoteService.getMediaMirror());
	_cameraService.Initialize("/NAS/Camera/", _remoteService.getCameraUrl(),
			_mailService, _systemService);
	_temperatureService.Initialize(_mailService, _remoteService.getSensor(),
			_remoteService.getArea(), _remoteService.getTemperatureGraphUrl());

	_logger.initialize(_fileController);

	std::ostringstream startMessage;
	startMessage << "Starting LucaHome at " << _remoteService.getArea();
	_mailService.sendMail(startMessage.str());

	_updatedSchedules = false;
	_schedules = _remoteService.getSchedules();

	pthread_t scheduleThread, serverThread, receiverThread, temperatureThread,
			birthdayThread, cameraStartThread, cameraStopThread, motionThread;

	pthread_create(&serverThread, NULL, server, NULL);
	pthread_create(&scheduleThread, NULL, scheduler, NULL);
	pthread_create(&receiverThread, NULL, receiver, NULL);
	pthread_create(&temperatureThread, NULL, temperatureControl, NULL);
	pthread_create(&birthdayThread, NULL, birthdayControl, NULL);
	pthread_create(&cameraStartThread, NULL, cameraStartControl, NULL);
	pthread_create(&cameraStopThread, NULL, cameraStopControl, NULL);
	pthread_create(&motionThread, NULL, motionControl, NULL);

	pthread_join(serverThread, NULL);
	pthread_join(scheduleThread, NULL);
	pthread_join(receiverThread, NULL);
	pthread_join(temperatureThread, NULL);
	pthread_join(birthdayThread, NULL);
	pthread_join(cameraStartThread, NULL);
	pthread_join(cameraStopThread, NULL);
	pthread_join(motionThread, NULL);

	pthread_mutex_destroy(&socketsMutex);
	pthread_mutex_destroy(&gpiosMutex);
	pthread_mutex_destroy(&schedulesMutex);
	pthread_mutex_destroy(&moviesMutex);
	pthread_mutex_destroy(&birthdaysMutex);
	pthread_mutex_destroy(&changesMutex);

	closelog();
}
