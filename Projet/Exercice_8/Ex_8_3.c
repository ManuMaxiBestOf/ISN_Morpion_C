/*On souhaite dans la suite remplir une fenetre graphique de rectangles identiques de différentes couleurs, et les faire “clignoter”
de plusieurs couleurs.
Pour manipuler un de ces carrées, on aura besoin, à priori, de:
• sa longueur
• la hauteur
• les coordonnées d’un de ses sommets, disons celui en bas a gauche
• de sa couleur
Plutot que de manipuler pour chaque carré 4 variables différentes, correspondant aux 4 données ci dessus, on se dit qu’il
serait plus agréable demanipuler une seule variable. Nous allons donc créer un nouveau type: la structure struct rectangle:
struct rectangle{
int l;
int h;
POINT bas_gauche;
COULEUR c;
};
et on n’oubliera pas le point virgule à la fin!
1. Créer un fichier mosaique.c, et y inclure les commandes de préprocesseur habituelles.
2. Juste après ces commandes, créer notre struct rectangle comme indiqué ci-dessus.
3. Dans lemain, déclarer une variable r de type struct rectangle.
4. Initialiser par exemple la largeur de r à 50 , sa hauteur à 50, son point bas gauche en (200,200), et sa couleur à r oug e.*/

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