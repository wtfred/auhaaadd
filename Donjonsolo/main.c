#include <stdio.h>
#include <stdlib.h>

void map (int *PosX, int *PosY, char TableauMap [40] [40]);

int main()
{
    char TableauMap [40] [40];
    int PosX = 1;
    int PosY = 1;
    map (&PosX, &PosY, TableauMap);

    return 0;

}
