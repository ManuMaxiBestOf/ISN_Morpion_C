/*On souhaite dans la suite remplir une fenetre graphique de rectangles identiques de diff�rentes couleurs, et les faire �clignoter�
de plusieurs couleurs.
Pour manipuler un de ces carr�es, on aura besoin, � priori, de:
� sa longueur
� la hauteur
� les coordonn�es d�un de ses sommets, disons celui en bas a gauche
� de sa couleur
Plutot que de manipuler pour chaque carr� 4 variables diff�rentes, correspondant aux 4 donn�es ci dessus, on se dit qu�il
serait plus agr�able demanipuler une seule variable. Nous allons donc cr�er un nouveau type: la structure struct rectangle:
struct rectangle{
int l;
int h;
POINT bas_gauche;
COULEUR c;
};
et on n�oubliera pas le point virgule � la fin!
1. Cr�er un fichier mosaique.c, et y inclure les commandes de pr�processeur habituelles.
2. Juste apr�s ces commandes, cr�er notre struct rectangle comme indiqu� ci-dessus.
3. Dans lemain, d�clarer une variable r de type struct rectangle.
4. Initialiser par exemple la largeur de r � 50 , sa hauteur � 50, son point bas gauche en (200,200), et sa couleur � r oug e.*/

#include "mosaique.c"

int main(int argc, char *argv[])
{
 RECTANGLE r;
 r.l=50;
 r.h=50;
 (r.p)x=200;
 (r.p)y=200;
 r.c=rouge;
}