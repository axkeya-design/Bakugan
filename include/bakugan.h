#ifndef BAKUGAN_H
#define BAKUGAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20

typedef struct {
	char name[MAX_NAME_LEN];
	int g_power;
	int init_g_power;
} Bakugan;

Bakugan init_bakugan(const char *name, int g_power);
void Select_Bakugan(Bakugan bakugans[]);
void showOptions(Bakugan bakugans[]);

#endif 
