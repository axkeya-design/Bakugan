#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SHORT_STR_LEN  20
#define NORMAL_STR_LEN 50
#define LONG_STR_LEN   100
#define MAX_GATE_CARDS 12
#define MAX_BAKUGANS_ON_CARD 4

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
	char name[NORMAL_STR_LEN];
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
		printf("Error: File not found!\n");
		return 0;
	}

	char line[LONG_STR_LEN];
	int count = 0;

	while (fgets(line, sizeof(line), file) != NULL && count < bakugan_count)
	{
		char element_str[SHORT_STR_LEN];
		char temp_name[NORMAL_STR_LEN];
		int temp_g;
		
		int parsed = sscanf(line, "%[^,],%d,%s", temp_name, &temp_g, element_str);

		if (parsed == 3)
		{
			Element checked_element = string_to_element(element_str);

			if (checked_element == UNKNOWN_ELEMENT)
			{
				printf("Error: UNKNOWN_ELEMENT %s for bakugan %s!\n", element_str, temp_name);
				fclose(file);
				return 0;
			}

			strcpy(bakugans[count].name, temp_name);
    		bakugans[count].base_g_power = temp_g;
			bakugans[count].g_power = temp_g;
			bakugans[count].element = checked_element;
			count++;
		}
		else 
		{
			printf("Error: No correct bakugan paramentrs!\n");
			fclose(file);
			return 0;
		}
	}

	fclose(file);
	return count;
}

typedef struct {
	char name[NORMAL_STR_LEN];
	int element_bonuses[6];
	bool is_card_open;
	Bakugan bakugans_on_card[MAX_BAKUGANS_ON_CARD]; 
    int bakugan_count;
} GateCard;

typedef struct {
	GateCard gate_cards[MAX_GATE_CARDS];
	int card_count;
} Battlefield;

Battlefield init_battlefield() 
{
    Battlefield field;
    field.card_count = 0;
	memset(field.gate_cards, 0, sizeof(field.gate_cards));
    return field;
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

	Battlefield field = init_battlefield();

	for (int i = 0; i < 4; i++)
	{
		for (int i = 0; i < 3; i++)
		{
			printf("[]");
		}
		printf("\n");
	}

	return 0;
}
