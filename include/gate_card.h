#ifndef GATE_CARD_H
#define GATE_CARD_H

#include "bakugan.h"

#define MAX_BAKUGANS_ON_GATE_CARD 4

typedef struct {
	char name[MAX_NAME_LEN];
 	Bakugan bakugans[MAX_BAKUGANS_ON_GATE_CARD];
} Gate_Card;

#endif
