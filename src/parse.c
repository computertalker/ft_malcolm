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

static P_Answer
resolve_ips(t_malcolm *m, char **av)
{
	(void)m;
	struct ifaddrs *ifaddr;
	struct in_addr ips[IP_SIZE];
	bool match[IP_SIZE];
	match[SOURCE] = false;
	match[TARGET] = false;

	if ((inet_pton(AF_INET, av[SOURCE + 1], &ips[SOURCE]) == -1)
			return (SourceIPBad);
	if ((inet_pton(AF_INET, av[TARGET + 1], &ips[TARGET]) == -1)
			return (TargetIPBad);

	f (getifaddrs(ifaddr) == -1)
		return (NetworkBad);

	for (struct ifaddrs *ifa = ifaddr; ifa != NULL; ifa = ifa->next) {
		if (ifa->if_addr == NULL)
			continue;
		
		if (ifa->ifa_addr == ips[SOURCE])
			match[SOURCE] = true;
		else if (ifa_addr == ips[TARGET])
			match[TARGET] = true;
	}
	if (!match[SOURCE])
		return (SourceIPBad);
	if (!match[TARGET])
		return (TargetIPBad);
	freeifaddrs(ifaddr);
}

static P_Answer
resolve_macs(void) {
	return (Good);
}

bool
parse_point(t_malcolm *m, char **av) {
	(void)m;
	(void)av;
	P_Answer a = resolve_ips(len, av);
	switch (a) {
		case SourceIPBad:
			fprintf(stderr, "ft_malcolm: error: source ip is bad\n");
		case TargetIPBad:
			fprintf(stderr, "ft_malcolm: error: target ip is bad\n");
		case SourceMACBad:
			fprintf(stderr, "ft_malcolm: error: source mac is bad\n");
		case TargetMACBad:
			fprintf(stderr, "ft_malcolm: error: target mac is bad\n");
		case NetwrokBad:
			fprintf(stderr, "ft_malcolm: error: cannot recreate local network\n"); 
	}
	if (a != Good)
		return (false);
	return (true);
}
