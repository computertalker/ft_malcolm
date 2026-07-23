#include "../include/malcolm.h"

void
init_malcolm (t_malcolm *m) {
	m->source_ip = {0};
	m->target_ip = {0};
	m->source_mac = {0};
	m->target_mac = {0};
	return ;
}
