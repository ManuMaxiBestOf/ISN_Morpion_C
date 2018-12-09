#include "graphics.h"
/* NIVEAU 3
   Deuxième animation:
 * Reprendre l'animation précédente, mais en donnant au tout début le "vecteur vitesse" du déplacement du cercle.
 * Pour cela, déclarer au début 2 entiers, dx et dy, qui donnent le décalage en abscisse et en ordonnée du centre à chaque tour de boucle. 
   Plus dx sera grand, plus le point ira vite en abscisse, plus dy sera grand, plus il ira vite en ordonnée.
*/

int main( int argc, char *argv[] )
{  
	int dx;
    int dy;
    POINT p;
    init_graphics (600,600);
    
    
    dx=3;
    dy=2;
    
    init_graphics(600,600);
	p.x= 300; p.y = 300;
	draw_circle(p, 20, bleu);
	while(1)
	{
		draw_fill_circle(p,20,noir);
		p.x=p.x+dx; p.y=p.y+dy;
		draw_fill_circle(p,20,bleu);
		attendre(10);
     }
    
	wait_escape();
    return 0;

}
