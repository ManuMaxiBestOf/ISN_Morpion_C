#include "graphics.h"
/* Première animation:
 * Ce programme montre comment animer le déplacement d'un cercle de rayon 20. Pour cela, on répète indéfiniment une séquence pendant laquelle on:
 * - éfface le cercle précédent
 * - calcule les coordonnées du centre du nouveau
 * - affiche le nouveau cercle
 * Faire tourner le programme et comprenez-le, puis modifiez le afin que le cercle parte vers le haut.
*/

int main( int argc, char *argv[] )
{ 
	POINT p;
	init_graphics(600,600);
	p.x= 300; p.y = 300;
	draw_circle(p, 20, bleu);
	while(1)
	{
		draw_fill_circle(p,20,noir);
		p.y++;
		draw_fill_circle(p,20,bleu);
		attendre(10);
		
	}
	return 0;
}
