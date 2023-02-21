#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netinet/ip_icmp.h>
#include <pthread.h>

#include "internet.h"
#include "block.h"
#include "color.h"

#define PING_SERVER_IP 0x08080808;

static const char* _web_icons[] = { "󰈂", "󰈁" };
static const char* _web_icon;

static size_t _check_connection() {
	int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
	if (sock < 0) {
		return 0;
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = PING_SERVER_IP;

	struct icmphdr request_header = {
		.type = ICMP_ECHO,
		.code = 0,
		.checksum = 0,
		.un.echo.id = 1234,
		.un.echo.sequence = 0
	};
	
	int status;

	status = sendto(sock, &request_header, sizeof(struct icmphdr), 0, (struct sockaddr*) &addr, sizeof addr);
	if (status <= 0) {
		return 0;
	}

	// wait for 1 second
	struct timeval timeout = {
		.tv_sec = 1,
		.tv_usec = 0
	};
	fd_set read_set;
	FD_SET(sock, &read_set);
	status = select(sock + 1, &read_set, NULL, NULL, &timeout);
	if (status <= 0) {
		return 0;
	}

	return 1;
}

static void *_update_internet(void *vargp) {
	_web_icon = _web_icons[_check_connection()];
	return NULL;
}

void initialize_internet() {
	_web_icon = _web_icons[0];
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, _update_internet, NULL);
}

void update_internet(size_t secs_passed) {
	if (secs_passed % 600 == 0) {
		_web_icon = _web_icons[_check_connection()];
	}
}

void show_internet() {
	create_text_block("internet", "󰖟", _web_icon, Blue);
}
