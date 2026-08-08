#include "bakugan.h"

Bakugan init_bakugan(const char *name, int g_power)
{
	Bakugan bakugan;
	strcpy(bakugan.name, name);
	bakugan.g_power = g_power;
	bakugan.init_g_power = g_power;
	return bakugan;
}

