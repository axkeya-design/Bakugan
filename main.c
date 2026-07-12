#include <stdio.h>
#include <stdlib.h>

typedef enum {
    PYRUS,
    AQUOS,
    SUBTERRA,
    HAOS,
    VENTUS,
    DARKUS
} Element;

const char *ELEMENT_NAMES[] = {
    "Pyrus",
    "Aquos",
    "Subterra",
    "Haos",
    "Ventus",
    "Darkus"
};

typedef struct {
	const char *name;
	const int base_g_power;
	int g_power;
	Element element;
} Bakugan;

Bakugan Create_Bakugan(const char *name, int base_g_power, Element element) 
{
	Bakugan bakugan = { 
		name,
		base_g_power, 
		base_g_power,
		element
	};

	return bakugan;
}

void display_status(Bakugan bakugan) {
	printf("Bakugan: %s, Base G-Power: %d, Current G-Power: %d, Element: %s\n", 
			bakugan.name, 
			bakugan.base_g_power, 
			bakugan.g_power,
			ELEMENT_NAMES[bakugan.element]
	);
}

int main()
{
	Bakugan drago = Create_Bakugan("Dragonoid", 370, PYRUS);

	display_status(drago);
	return 0;
}
