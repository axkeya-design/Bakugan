#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	int g_power;
	int init_g_power;
} Bakugan;

void Select_Bakugan(Bakugan bakugans[])
{
	int option;

	printf("[1] (%s, G-Power: %d)\n[2] (%s, G-Power: %d)\n[3] (%s, G-Power: %d)\n", 
			bakugans[0].name, bakugans[0].g_power,
			bakugans[1].name, bakugans[0].g_power,
			bakugans[2].name, bakugans[0].g_power
	);

	printf("Select: ");

	scanf("%d", &option);

	switch (option)
	{
		case 1:
			break;
		default:
			break;
	}
}

void showOptions(Bakugan bakugans[])
{
	int option;

	printf("[1] Select Bakugan\n");

	printf("Select: ");

	scanf("%d", &option);

	switch (option)
	{
		case 1:
			Select_Bakugan(bakugans);
			break;
		default:
			break;
	}
}

void actions(char action, Bakugan bakugans[])
{
	switch (action)
	{
		case 'w':
			showOptions(bakugans);
			break;
		default:
			break;
	}
}

Bakugan init_bakugan(const char *name, int g_power)
{
	Bakugan bakugan;
	strcpy(bakugan.name, name);
	bakugan.g_power = g_power;
	bakugan.init_g_power = g_power;
	return bakugan;
}

int main(void)
{
    char action;
	Bakugan bakugans[3];

	bakugans[0] = init_bakugan("Dragonoid", 400);
    bakugans[1] = init_bakugan("Naga", 350);
    bakugans[2] = init_bakugan("Hydranoid", 450);
	
    do 
	{
        for (int i = 0; i < 3; i++)
        {
            printf("[][][]\n");
        }

        printf("Action: ");

        scanf(" %c", &action);

		while (getchar() != '\n');

		actions(action, bakugans);
    } 
	while (action != 'q');

    return 0;
}
