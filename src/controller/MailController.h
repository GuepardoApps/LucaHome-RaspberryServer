#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <errno.h>
#include <math.h>
#include <time.h>

#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <syslog.h>

#define MAX_MESSAGE_LENGTH 2048
#define SEND_SIMPLE_MAIL "python /etc/default/lucahome/mail.py"
#define SEND_IMAGE_MAIL "python /etc/default/lucahome/mailWithImage.py"

#ifndef MAILCONTROLLER_H
#define MAILCONTROLLER_H

class MailController
{
public:
	MailController();
	~MailController();

	void SendMail(std::string);
	void SendMailWithImage(std::string);
};

#endif
