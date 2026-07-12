#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    PYRUS,
    AQUOS,
    SUBTERRA,
    HAOS,
    VENTUS,
    DARKUS,
	UNKNOWN_ELEMENT
} Element;

const char *ELEMENT_NAMES[] = {
    "Pyrus",
    "Aquos",
    "Subterra",
    "Haos",
    "Ventus",
    "Darkus",
	"Unknown"
};

Element string_to_element(const char *str) {
    if (strcmp(str, "PYRUS") == 0) return PYRUS;
    if (strcmp(str, "AQUOS") == 0) return AQUOS;
    if (strcmp(str, "SUBTERRA") == 0) return SUBTERRA;
    if (strcmp(str, "HAOS") == 0) return HAOS;
    if (strcmp(str, "VENTUS") == 0) return VENTUS;
	if (strcmp(str, "DARKUS") == 0) return DARKUS;
    return UNKNOWN_ELEMENT;
}

typedef struct {
	char name[50];
	int base_g_power;
	int g_power;
	Element element;
} Bakugan;

Bakugan Create_Bakugan(char *name, int base_g_power, Element element) 
{
	Bakugan bakugan;
    strncpy(bakugan.name, name, sizeof(bakugan.name) - 1); 
    bakugan.name[sizeof(bakugan.name) - 1] = '\0';
    bakugan.base_g_power = base_g_power;
    bakugan.g_power = base_g_power;
    bakugan.element = element;

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

int load_bakugans(const char *filename, Bakugan *bakugans, int bakugan_count)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL) 
	{
		printf("Error: File not found!");
		return 0;
	}

	char line[100];
	int count = 0;

	while (fgets(line, sizeof(line), file) != NULL && count < bakugan_count)
	{
		char element_str[20];
		int parsed = sscanf(line, "%[^,],%d,%s", bakugans[count].name, &bakugans[count].base_g_power, element_str);

		if (parsed == 3)
		{
			bakugans[count].g_power = bakugans[count].base_g_power;
			bakugans[count].element = string_to_element(element_str);
			count++;
		}
		else 
		{
			printf("Error: No correct bakugan paramentrs!")
			return 0;
		}
	}

	fclose(file);
	return count;
}

int main()
{
	Bakugan collection[10];
	int total = load_bakugans("bakugans.csv", collection, 10);

	if (total == 0) return 1;

	printf("Total bakugans: %d\n", total);

	for (int i = 0; i < total; i++)
	{
		printf("%d.", i + 1);
		display_status(collection[i]);
	}

	return 0;
}
