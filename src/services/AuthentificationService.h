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

#include "../common/dto/UserDto.h"
#include "../common/Constants.h"
#include "../controller/FileController.h"
#include "xml/XmlService.h"

#ifndef AUTHENTIFICATIONSERVICE_H
#define AUTHENTIFICATIONSERVICE_H

class AuthentificationService {
private:
	std::vector<UserDto> _userList;

	std::string _userFile;

	int _invalidLoginCount;

	FileController _fileController;
	XmlService _xmlService;

	void saveUsers();
	void loadUsers();

	int getActionId(std::string);
	bool isAdminAction(std::string);
	int getInvalidLoginCount(std::string);

public:
	AuthentificationService();
	~AuthentificationService();

	void Initialize(FileController, std::string);

	std::string GetUsersString();
	std::vector<std::string> GetUserNames();

	bool AuthentificateUser(std::string, std::string);
	bool AuthentificateUserAction(std::string, std::string, std::string);

	bool AddUser(std::string, std::string, UserDto);
	bool DeleteUser(std::string, std::string, std::string);

	bool IsUserAdmin(std::string);

	std::string ResetFailedLogin(std::string, std::string, std::string);
};

#endif
