#include <stdio.h>
#include <stdlib.h>


void murVertical (int x, int y1, int y2, char tableauMap [20] [20]);
void murHorizontal (int y, int x1, int x2, char tableauMap [20] [20]);

void donjonMap (int *PosX,int *PosY, char tableauMap [20] [20]);
int deplacement (int *PosX, int *PosY, char tableauMap [20] [20]);
void affichage (int *PosX, int *PosY, char tableauMap [20] [20]);
void Menu ();
void creationperso ();

int main()
{
    char tableauMap [20] [20];
    int fin = 0;
    int PosX = 1;
    int PosY = 1;

    Menu();
    donjonMap (&PosX,&PosY, tableauMap);

    while (fin == 0)
    {
        fin = deplacement (&PosX,&PosY, tableauMap);
        printf("votre position est %d,%d\n", PosX,PosY);
        affichage (&PosX, &PosY, tableauMap);
        printf("\ntest");
    }

    return 0;
}


void Menu ()
{
    int inputmenu;
    printf("\nDONJON\n\n");
    printf("1. NEW GAME\n");
    printf("2. LOAD GAME\n");
    printf("3. About\n");
    printf("4. EXIT\n");
    scanf ("%i", &inputmenu);

    switch (inputmenu)
    {
        case (1):
            creationperso();
            break;

        case (2):
            Menu();
            break;
        case (3):
            printf("\n\n N/S/E/W pour se deplacer dans le donjon");
            Menu();
            break;

        case (4):
            Menu();
            break;

    }
}

void creationperso ()
{
    char nomperso [50]; // nombre de cases pour le pseudo du personnage
    printf("Quel est votre nom?\n");
    scanf ("%s", &nomperso);
    printf ("Votre nom est : %s", nomperso);
    printf ("\nVous entrez dans le donjon\n");
}

void donjonMap (int *PosX,int *PosY, char tableauMap [20] [20])
{
    int x; // int pour horizontal
    int y; // int pour vertical
    for (x = 0; x < 20; x++)
    {
        for (y = 0 ; y < 20 ; y++)
        {
            tableauMap [y] [x] = ' ';  // rempli le tableau de case vide
        }
    }
    for (y = 0; y < 20 ; y++)
    {
        tableauMap [y] [19] = '\n'; // necessaire, no idea why
    }
        for (y = 0; y < 20 ; y++)
    {
        tableauMap [y] [18] = 'X'; // affiche le mur Est
    }

    for (y = 0 ; y < 20 ; y++)
    {
        tableauMap [y] [0] = 'X'; // affiche le mur Ouest
    }

    for (x = 0 ; x < 19 ; x++)
    {
        tableauMap [0] [x] = 'X'; // affiche le mur Nord
    }

    for ( x = 0 ; x < 19 ; x++)
    {
        tableauMap [19] [x] = 'X'; // affiche le mur Sud
    }

    murHorizontal(2, 2, 4, tableauMap);



    tableauMap [1] [0] = 'E'; // entree du donjon
    tableauMap [*PosY] [*PosX] = '@'; // pion personnage
    tableauMap [4] [4] = 'M'; // pion monstre
    tableauMap [7] [7] = 'C'; // pion coffre


}

void murVertical (int x, int y1, int y2, char tableauMap [20] [20]) // facilite la creation de mur vertical
{
    int y;

    for (y = y1; y < y2 ; y++)
    {
        tableauMap [x] [y] = 'X';
    }

}

void murHorizontal (int y, int x1, int x2, char tableauMap [20] [20]) // facilite la creation de mur horizontal
{
    int x;

    for (x = x1; x < x2 ; x++)
    {
        tableauMap [x] [y] = 'X';
    }
}

void affichage (int *PosX, int *PosY, char tableauMap [20] [20])
{
    int x = 0;
    int y = 0;
    tableauMap [*PosY] [*PosX] = '@'; // pion personnage

    for (x = 0; x < 20; x++)
    {
        for (y = 0 ; y < 20 ; y++)
        {
            printf ("%c",tableauMap [x] [y]); // affiche le tableau sur la console
        }
    }
        printf("\nOu souhaitez vous vous deplacer?\nN/S/W/E\n\n");
}

int deplacement (int *PosX, int *PosY, char tableauMap [20] [20])
{

    char choixDirection;
    scanf("%c", &choixDirection);
    if (choixDirection == 'S')

    {
        if (tableauMap [*PosY + 1] [*PosX] == 'X')
        {
            return 0;
        }
        else if (tableauMap [*PosY + 1] [*PosX] == 'M')
        {
            combat();
               /* if (return 0)
                {
                    *PosY = *PosY + 1;
                    tableauMap [*PosY - 1] [*PosX] = ' ';
                }
                else
                {
                    *PosY = *PosY - 1;
                }*/
        }
        else
        {

            *PosY = *PosY + 1;
            tableauMap [*PosY - 1] [*PosX] = ' ';
        }



    }

    if (choixDirection == 'N')
    {
        if (tableauMap [*PosY - 1] [*PosX] == 'X')
        {
            return 0;
        }
        *PosY = *PosY - 1;
        tableauMap [*PosY + 1] [*PosX] = ' ';


    }

    if (choixDirection == 'E')
    {
        if (tableauMap [*PosY] [*PosX + 1] == 'X')
        {
            return 0;
        }
        *PosX = *PosX + 1;
        tableauMap [*PosY] [*PosX - 1] = ' ';


    }

    if (choixDirection == 'W')
    {
        if ( tableauMap [*PosY] [*PosX - 1] == 'X')
        {
            return 0;
        }
        *PosX = *PosX - 1;
        tableauMap [*PosY] [*PosX + 1] = ' ';


    }
    if (choixDirection == 'F')
    {
        return 1;
    }

    return 0;

}

void feuillePersonnage ()
{

}

void feuilleMonstre ()
{

}

int combat ()
{
    int attaque = 20;
    int attaqueMonstre = 5;
    int defenseMonstre = 5;
    int pvMonstre = 12;
    int inputCombat;
    char tableauMap [20] [20];

    printf ("\nVous entrez en combat.\n");
    printf ("Que souhaitez vous faire?\n");
    printf ("1. Attaque\n");
    printf ("2. Inventaire\n");
    printf ("3. Fuite \n");
    scanf ("%i", &inputCombat);

    if (inputCombat == 1)
    {
        pvMonstre = pvMonstre - attaque;
    }
    if (pvMonstre <= 0)
    {
        printf("\nLe monstre est mort.\n");
        tableauMap [4] [4] = ' ';
        return 0;

    }

}
