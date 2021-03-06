#include <stdio.h>
#include <stdlib.h>
#include "map.h"





int inputUtilisateur (int *PosX, int *PosY, int *bourse, char tableauMap [20] [20]);

int combat (int *bourse);
void Menu ();
void creationperso ();

int main()
{
    char tableauMap [20] [20];
    int fin = 0;
    int PosX = 1;
    int PosY = 1;
    int bourse = 50;
    Menu(); // menu principal1

    donjonMapy (&PosX,&PosY, tableauMap); // initialisation du donjon

    while (fin == 0) // boucle de jeu
    {
        fin = inputUtilisateur (&PosX,&PosY, &bourse, tableauMap); // demande d'input � l'utilisateur
        printf("votre position est %d,%d\n", PosX,PosY); // indique la position sur le tableau
        affichage (&PosX, &PosY, tableauMap); // affiche le tableau
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

void creationperso () // creation du personnage et de ses variables
{
    char nomperso [50]; // nombre de cases pour le pseudo du personnage
    printf("Quel est votre nom?\n");
    scanf ("%s", &nomperso);
    printf ("Votre nom est : %s", nomperso);
    printf ("\nVous entrez dans le donjon\n");
}



int menuJeu(int *PosX, int *PosY, int *bourse, char tableauMap [20] [20])
{
    int inputMenu;
    printf("          \nINVENTAIRE\n\n");
    printf("1. Caracteristiques\n");
    printf("2. Objets\n");
    printf("3. Equipement\n");
    printf("4. Sauvegarder\n");
    printf("5. Retour en jeu\n");
    printf("6. Quitter le jeu\n");
    scanf ("%i", &inputMenu);

    if (inputMenu == 1) // affiche menu caracs
    {
        return 0;
    }
    if (inputMenu == 2) // affichage menu objets
    {
        system("cls");
        printf("Vous avez %i or\n", bourse);
        return 0;
    }
    if (inputMenu == 3) // affiche menu equipement
    {
        return 0;
    }

    if (inputMenu == 4) // menu de sauvegarde
    {
        return 0;
    }
    if (inputMenu == 5) // retour en jeu
    {
        return 0;
    }

    if (inputMenu == 6) // quitter le jeu
    {
        return 1;
    }

}
int inputUtilisateur (int *PosX, int *PosY, int *bourse, char tableauMap [20] [20])
{

    char choixUtilisateur;
    scanf("%c", &choixUtilisateur);
    if (choixUtilisateur == 'S')

    {
        if (tableauMap [*PosY + 1] [*PosX] == 'X')
        {
            return 0;
        }
        else if (tableauMap [*PosY + 1] [*PosX] == 'M')
        {
            combat(bourse);
            *PosY = *PosY + 1;
            tableauMap [*PosY - 1] [*PosX] = ' ';
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

    if (choixUtilisateur == 'N')
    {
        if (tableauMap [*PosY - 1] [*PosX] == 'X')
        {
            return 0;
        }

        else if (tableauMap [*PosY - 1] [*PosX] == 'M')
        {
            combat(bourse);
            *PosY = *PosY - 1;
            tableauMap [*PosY + 1] [*PosX] = ' ';
        }
        else
        {

            *PosY = *PosY - 1;
            tableauMap [*PosY + 1] [*PosX] = ' ';
        }



    }

    if (choixUtilisateur == 'E')
    {
        if (tableauMap [*PosY] [*PosX + 1] == 'X')
        {
            return 0;
        }
        else if (tableauMap [*PosY] [*PosX + 1] == 'M')
        {
        combat(bourse);
        *PosX = *PosX + 1;
        tableauMap [*PosY] [*PosX - 1] = ' ';
        }
        else
        {

            *PosX = *PosX + 1;
            tableauMap [*PosY] [*PosX - 1] = ' ';
        }



    }

    if (choixUtilisateur == 'W')
    {
        if ( tableauMap [*PosY] [*PosX - 1] == 'X')
        {
            return 0;
        }

        else if (tableauMap [*PosY] [*PosX - 1] == 'M')
        {
        combat(bourse);
        *PosX = *PosX - 1;
        tableauMap [*PosY] [*PosX + 1] = ' ';
        }
        else
        {

        *PosX = *PosX - 1;
        tableauMap [*PosY] [*PosX + 1] = ' ';
        }



    }

    if (choixUtilisateur  == 'I')
    {
        system("cls");
        menuJeu(*PosX, *PosY, *bourse, tableauMap [20] [20]);
    }
    if (choixUtilisateur == 'F')
    {
        return 1;
    }

    return 0;

}

/*void feuillePersonnage (int *bourse)
{
    *bourse = 50;
}

void feuilleMonstre ()
{

}
*/
int combat (int *bourse) // temporaire

{
    int pvChar = 200;
    int pvCharRestant = pvChar;

    int defense = 10;
    int attaque = 50;
    int attaqueMonstre = 25;
    int defenseMonstre = 10;
    int pvMonstre = 100;
    int pvMonstreRestant = pvMonstre;
    int inputCombat;

    while (pvChar | pvMonstre >= 0) // boucle de combat
    {

        printf ("\nVous entrez en combat contre un monstre.\n");
        printf ("Que souhaitez vous faire?\n");
        printf ("1. Attaque\n");
        printf ("2. Inventaire\n");
        printf ("3. Fuite \n");
        scanf ("%i", &inputCombat);

        if (inputCombat == 1)
        {
            pvMonstreRestant = pvMonstre - (attaque - defenseMonstre);
            pvMonstre = pvMonstreRestant;
            printf("\nVous attaquez le monstre, il lui reste %i points de vie.", pvMonstreRestant);

            pvCharRestant = pvChar - (attaqueMonstre - defense);
            pvChar = pvCharRestant;
            printf ("\nLe monstre vous attaque, il vous reste %i points de vie.\n", pvCharRestant);

        }

        if (inputCombat == 2)
        {
            return 0;
        }

        if (inputCombat == 3)
        {
            return 0;
        }
        if (pvMonstre <= 0)
        {
            printf("\nLe monstre est mort.\n");
            *bourse = *bourse + 50;
            return 0;
        }
        if (pvChar <= 0)
        {
            printf("\nVous etes mort.");
            system("cls");
            Menu();
        }
    }
}
