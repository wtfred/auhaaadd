#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

void donjonMapy (int *PosX,int *PosY, char tableauMap [20] [20]);
void murVerticaly (int x, int y1, int y2, char tableauMap [20] [20]);
void murHorizontaly (int y, int x1, int x2, char tableauMap [20] [20]);
void affichage (int *PosX, int *PosY, char tableauMap [20] [20]);

#endif // MAP_H_INCLUDED
