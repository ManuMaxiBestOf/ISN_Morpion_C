#include "graphics.h"
/* La commande de souris wait_clic() renvoie les coordonnées du point qui a été cliqué par la souris:
 POINT p
 p= wait_clic();

Une fois que la souris sera cliqué, le point p contiendra les coordonnées.

Lire, compiler, tester et comprendre le programme suivant.
*/

int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
	POINT p;
	
	init_graphics(600,900);
	
	/* Ecrire son programme ici */
	p.x = 300; p.y = 400;
	draw_fill_circle(p, 120, vert);
	
	p = wait_clic();
	draw_fill_circle(p, 200, orange);

	wait_escape();
	exit(0);
	
	
	
}
