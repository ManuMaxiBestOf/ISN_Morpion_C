/*1. Cr�er une fonction RECTANGLE init_rectangle(int l, int h, int x, int y, COULEUR c) qui renvoie le RECTANGLE
de largeur l, hauteur h, point bas gauche de coordonn�es x et y et de couleur c. Remarquez que le fait qu�on ai cr�er
une struct nous permet de cr�er une fonction qui renvoie toutes les informations n�cessaires d�un seul coup, chose
impossible avant!
2. Cr�er une fonction void affiche_rectangle(RECTANGLE r) qui affiche le rectangle r.
3. Tester ces fonctions pour cr�er 4 rectangles de votre choix et les afficher.*/
#include "mosaique.c"
#define XMAX 600
#define YMAX 600

RECTANGLE init_rectangle(int l,int h,int x,int y,COULEUR c)
{
 RECTANGLE r;
 r.p.x=x; 
 r.p.y=y;
 r.l=l;
 r.h=h;
 r.c=c;
 return r;
}

void affiche_rectangle(RECTANGLE r)
{ 
 POINT p2;
 p2.x=r.p.x+r.l;
 p2.y=r.p.y+r.h;
 draw_fill_rectangle(r.p,p2,r.c);
}


int main(int argc, char *argv[])
{
 RECTANGLE r;
 init_graphics(XMAX,YMAX);
 r=init_rectangle(200,200,200,200,bleu);
 affiche_rectangle(r);
 r=init_rectangle(200,200,0,0,blanc);
 affiche_rectangle(r);
 r=init_rectangle(200,200,400,0,blanc);
 affiche_rectangle(r);
  r=init_rectangle(200,200,200,400,blanc);
 affiche_rectangle(r);
 
 wait_escape();
 return 0;
} 