#include "bakugan.h"
#include "gate_card.h"

int main(void)
{
	Bakugan bakugans[3];
	Gate_Card gate_cards[12];

	bakugans[0] = init_bakugan("Dragonoid", 400);
    bakugans[1] = init_bakugan("Naga", 350);
    bakugans[2] = init_bakugan("Hydranoid", 450);
	
	while(1)
	{
        for (int i = 0; i < 3; i++)
        {
            printf("[][][][]\n");
        }

		showOptions(bakugans);

		while(getchar() != '\n');
    } 

    return 0;
}
