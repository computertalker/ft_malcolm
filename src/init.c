#include "../include/malcolm.h"

void
init_malcolm (t_malcolm *m) {
	memset(&m->source_ip, 0, sizeof(m->source_ip));
	memset(&m->target_ip, 0, sizeof(m->target_ip));
	memset(&m->source_mac, 0, sizeof(m->source_mac));
	memset(&m->target_mac, 0, sizeof(m->target_mac));
	return ;
}
