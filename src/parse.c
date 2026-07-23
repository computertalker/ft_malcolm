#include "../include/malcolm.h"

enum P_Answer {
	SourceIPBad,
	TargetIPBad,
	SourceMACBad,
	TargetMACBad,
	NetworkBad,
	Good
};

#define SOURCE 0
#define TARGET 1
#define IP_SIZE 2

static enum P_Answer
resolve_ips(t_malcolm *m, char **av)
{
	(void)m;
	struct ifaddrs *ifaddr;
	struct in_addr ips[IP_SIZE];
	bool match[IP_SIZE];
	match[SOURCE] = false;
	match[TARGET] = false;

	if (inet_pton(AF_INET, av[SOURCE + 1], &ips[SOURCE]) == -1)
			return (SourceIPBad);
	if (inet_pton(AF_INET, av[TARGET + 1], &ips[TARGET]) == -1)
			return (TargetIPBad);

	if (getifaddrs(&ifaddr) == -1)
		return (NetworkBad);

	for (struct ifaddrs *ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr == NULL)
			continue;

		struct in_addr addr = ((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
		if (addr.s_addr == ips[SOURCE].s_addr)
			match[SOURCE] = true;
		else if (addr.s_addr == ips[TARGET].s_addr)
			match[TARGET] = true;
	}
	if (match[SOURCE])
		return (SourceIPBad);
	if (match[TARGET])
		return (TargetIPBad);
	freeifaddrs(ifaddr);
	return (Good);
}

/*
static enum P_Answer
resolve_macs(void) {
	return (Good);
}
*/

bool
parse_point(t_malcolm *m, char **av) {
	enum P_Answer a = resolve_ips(m, av);
	switch (a) {
		case SourceIPBad:
			fprintf(stderr, "ft_malcolm: error: source ip is bad\n");
			break;
		case TargetIPBad:
			fprintf(stderr, "ft_malcolm: error: target ip is bad\n");
			break;
		case SourceMACBad:
			fprintf(stderr, "ft_malcolm: error: source mac is bad\n");
			break;
		case TargetMACBad:
			fprintf(stderr, "ft_malcolm: error: target mac is bad\n");
			break;
		case NetworkBad:
			fprintf(stderr, "ft_malcolm: error: cannot recreate local network\n");
			break;
		case Good:
			return (true);	
	}
	return (false);
}
