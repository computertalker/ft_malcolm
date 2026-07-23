#ifndef MALCOLM_H
#define MALCOLM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <stdbool.h>

typedef struct s_malcolm {
	struct sockaddr_in *source_ip;
	struct sockaddr_in *target_ip;
	struct sockaddr_ll *source_mac;
	struct sockaddr_ll *target_mac;
} t_malcolm;

void init_malcolm(t_malcolm *m);
bool parse_point(t_malcolm *m, char **av);

#endif
