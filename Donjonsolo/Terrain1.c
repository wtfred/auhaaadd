
void map (int *PosX, int *PosY, char TableauMap [40] [40]) // Fonction pour terrain du premier niveau
{
    int x;
    int y;
    for (x = 0 ; x < 40 ; x++)
    {
        for (y = 0 ; y < 40 ; y++) // double boucle for pour remplir l'integralité des tables en cases vides
        {
            TableauMap [x] [y] = ' ';

        }
    }

    for (x = 0 ; x < 40 ; x++)
    {
        TableauMap [39] [x] = '\n'; // ?? sert à fermer le tableau?
    }

    for (x = 0 ; x < 40 ; x++) // assigne le mur Ouest
    {
        TableauMap [0][x] = '°';
    }

    for (x = 0 ; x < 40 ; x++) // assigne le mur Est
    {
        TableauMap [38] [x] = '°';
    }

    for (y = 0 ; y < 39 ; y++) // assigne le mur Nord
    {
        TableauMap [y] [0] = '°';
    }

    for (y = 0 ; y < 39 ; y++) // assigne le mur Sud
    {
        TableauMap [y] [39] = '°';
    }

    TableauMap [0] [1] = 'E'; // signal la porte d'entree du donjon

    TableauMap [*PosX] [*PosY] = '@'; // pion personnage

    TableauMap [2] [2] = 'M'; // monstre

    TableauMap [5] [5] = 'C'; // coffre

    for (x = 0 ; x < 40 ; x++) // double boucle print pour afficher le donjon
    {
        for (y = 0 ; y < 40 ; y++)
        {
            printf ("%c", TableauMap[y][x]);

        }
    }

}
