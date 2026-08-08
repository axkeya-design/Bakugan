#include "bakugan.h"

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
	printf("[9] Quit Game\n");

	printf("Action: ");

	scanf("%d", &option);

	switch (option)
	{
		case 1:
			Select_Bakugan(bakugans);
			break;
		case 9:
			exit(0);
		default:
			break;
	}
}
