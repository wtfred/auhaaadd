


void donjonMapy (int *PosX,int *PosY, char tableauMap [20] [20])
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

    murHorizontaly(2, 2, 4, tableauMap);



    tableauMap [1] [0] = 'E'; // entree du donjon
    tableauMap [*PosY] [*PosX] = '@'; // pion personnage
    tableauMap [4] [4] = 'M'; // pion monstre
    tableauMap [7] [7] = 'C'; // pion coffre


}

void murVerticaly (int x, int y1, int y2, char tableauMap [20] [20]) // facilite la creation de mur vertical
{
    int y;

    for (y = y1; y < y2 ; y++)
    {
        tableauMap [x] [y] = 'X';
    }

}

void murHorizontaly (int y, int x1, int x2, char tableauMap [20] [20]) // facilite la creation de mur horizontal
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


