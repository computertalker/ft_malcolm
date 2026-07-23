#include "../include/malcolm.h"

static volatile int Running = 1;

void
handle_sigint(int sig) {
	(void)sig;
	printf("\n");
	Running = 0;
}

static
void malcolm_header(void) {
    printf("\033[34m ▄▄▄· ▄▄▄   ▄▄▄·           \n");
    printf("▐█ ▀█ ▀▄ █·▐█ ▄█           \n");
    printf("▄█▀▀█ ▐▀▀▄  ██▀·           \n");
    printf("▐█ ▪▐▌▐█•█▌▐█▪·•           \n");
    printf(" ▀  ▀ .▀  ▀.▀              \n");
    printf(".▄▄ ·  ▄▄▄·            ·▄▄▄\n");
    printf("▐█ ▀. ▐█ ▄█▪     ▪     ▐▄▄·\n");
    printf("▄▀▀▀█▄ ██▀· ▄█▀▄  ▄█▀▄ ██▪ \n");
    printf("▐█▄▪▐█▐█▪·•▐█▌.▐▌▐█▌.▐▌██▌.\n");
    printf(" ▀▀▀▀ .▀    ▀█▄▀▪ ▀█▄▀▪▀▀▀ \n\033[0m\n");
}


int
main(int ac, char** av)
{
	(void)av;
	if (geteuid() != 0) {
		fprintf(stderr, "ft_malcolm: You must run this program as root\n");
		exit(1);
	}
	if (ac != 5) {
		fprintf(stderr, "ft_malcolm: format:\nsudo %s\n"
			       	"	[source-ip]\n"
			       	"	[source-mac-addr]\n"
			       	"	[target-ip]\n"
			       	"	[target-mac-addr]\n\n[!]: it must be in this exact order.\n", av[0]);
		exit(1);
	}
	signal(SIGINT, handle_sigint);
	malcolm_header();

	t_malcolm m;
	if (!parse_point(&m, av))
		exit(1);
	while (Running) {
		;
	}
	return (0);
}
