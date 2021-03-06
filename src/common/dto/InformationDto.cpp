#include "InformationDto.h"

InformationDto::InformationDto()
{
}

InformationDto::InformationDto(
	std::string author,
	std::string company,
	std::string contact,
	std::string buildDate,
	std::string serverVersion,
	std::string websiteVersion,
	std::string temperatureLoggerVersion,
	std::string androidApplicationVersion,
	std::string androidAccessApplicationVersion,
	std::string mediaServerVersion,
	std::string wpfApplicationVersion)
{
	_author = author;
	_company = company;
	_contact = contact;
	_buildDate = buildDate;
	_serverVersion = serverVersion;
	_websiteVersion = websiteVersion;
	_temperatureLoggerVersion = temperatureLoggerVersion;
	_androidApplicationVersion = androidApplicationVersion;
	_androidAccessApplicationVersion = androidAccessApplicationVersion;
	_mediaServerVersion = mediaServerVersion;
	_wpfApplicationVersion = wpfApplicationVersion;
}

InformationDto::~InformationDto()
{
}

std::string InformationDto::GetAuthor()
{
	return _author;
}

std::string InformationDto::GetCompany()
{
	return _company;
}

std::string InformationDto::GetContact()
{
	return _contact;
}

std::string InformationDto::GetBuildDate()
{
	return _buildDate;
}

std::string InformationDto::GetServerVersion()
{
	return _serverVersion;
}

std::string InformationDto::GetWebsiteVersion()
{
	return _websiteVersion;
}

std::string InformationDto::GetTemperatureLoggerVersion()
{
	return _temperatureLoggerVersion;
}

std::string InformationDto::GetAndroidApplicationVersion()
{
	return _androidApplicationVersion;
}

std::string InformationDto::GetAndroidAccessApplicationVersion()
{
	return _androidAccessApplicationVersion;
}

std::string InformationDto::GetMediaServerVersion()
{
	return _mediaServerVersion;
}

std::string InformationDto::GetWpfApplicationVersion()
{
	return _wpfApplicationVersion;
}

std::string InformationDto::JsonString()
{
	std::string str =
		std::string("{")
		+ std::string("\"Information\":")
		+ std::string("{")
		+ std::string("\"Author\":\"") + _author + std::string("\",")
		+ std::string("\"Company\":\"") + _company + std::string("\",")
		+ std::string("\"Contact\":\"") + _contact + std::string("\",")
		+ std::string("\"BuildDate\":\"") + _buildDate + std::string("\",")
		+ std::string("\"ServerVersion\":\"") + _serverVersion + std::string("\",")
		+ std::string("\"WebsiteVersion\":\"") + _websiteVersion + std::string("\",")
		+ std::string("\"TemperatureLoggerVersion\":\"") + _temperatureLoggerVersion + std::string("\",")
		+ std::string("\"AndroidApplicationVersion\":\"") + _androidApplicationVersion + std::string("\",")
		+ std::string("\"AndroidAccessApplicationVersion\":\"") + _androidAccessApplicationVersion + std::string("\",")
		+ std::string("\"MediaServerVersion\":\"") + _mediaServerVersion + std::string("\",")
		+ std::string("\"WpfApplicationVersion\":\"") + _wpfApplicationVersion
		+ std::string("\"}")
		+ std::string("}");
	return str;
}

std::string InformationDto::PhpString()
{
	std::stringstream out;

	out << "information::" << "Author::" << _author << ";"
		<< "information::" << "Company::" << _company << ";"
		<< "information::" << "Contact::" << _contact << ";"
		<< "information::" << "Build Date::" << _buildDate << ";"
		<< "information::" << "Server Version::" << _serverVersion << ";"
		<< "information::" << "Website Version::" << _websiteVersion << ";"
		<< "information::" << "Temperature Logger Version::" << _temperatureLoggerVersion << ";"
		<< "information::" << "Android Application Version::" << _androidApplicationVersion << ";"
		<< "information::" << "Android Access Application Version::" << _androidAccessApplicationVersion << ";"
		<< "information::" << "Media Server Version::" << _mediaServerVersion << ";"
		<< "information::" << "WPF Application Version::" << _wpfApplicationVersion << ";";

	out << "\x00" << std::endl;

	return out.str();
}

std::string InformationDto::ToString()
{
	std::string str =
		std::string("InformationDto { Author: ") + _author
		+ std::string("; Company: ") + _company
		+ std::string("; Contact: ") + _contact
		+ std::string("; BuildDate: ") + _buildDate
		+ std::string("; ServerVersion: ") + _serverVersion
		+ std::string("; WebsiteVersion: ") + _websiteVersion
		+ std::string("; TemperatureLoggerVersion: ") + _temperatureLoggerVersion
		+ std::string("; AndroidApplicationVersion: ") + _androidApplicationVersion
		+ std::string("; AndroidAccessApplicationVersion: ") + _androidAccessApplicationVersion
		+ std::string("; MediaServerVersion: ") + _mediaServerVersion
		+ std::string("; WpfApplicationVersion: ") + _wpfApplicationVersion
		+ std::string(" }");
	return str;
}
