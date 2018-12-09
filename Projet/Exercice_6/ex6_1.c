#include "graphics.h"
/* Quelques exemples de fonction.
 * Lire et comprendre ce que font les fonctions suivantes.
 * Remarque: ce sont simplement des exemples qui n'ont pas d'interet en tant que programme ici...
*/

/* Ecrire ses fonctions ici*/
int somme( int x, int y, int z)
{
	int s;
	s = x+y+z;
	return s;	
}


void write_score (int score)
{
	write_text("\n Le score est: ");
	write_int(score);
	write_text("\n");

}
 

POINT translation(POINT p, POINT vecteur)
{
	POINT p_image;
	p_image.x = p.x + vecteur.x;
	p_image.y = p.y + vecteur.y;
	return p_image;
}


/* Ecrire son programme ici */
int main( int argc, char *argv[] )
{ 
	int i=2, j=3, k=4, l;
	POINT p1, p2, v;
	
	l = somme(i,j,k);
	write_score(l);
	
	p1.x = 100; 
	p1.y = 100;
	v.x = 200;
	v.y = -50;
	p2 = translation(p1,v);
	
	exit(0);
}
