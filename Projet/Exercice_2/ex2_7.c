#include "graphics.h"
/* Dessiner, dans une fenetre graphique de 600*600, un quadrillage formé de deux
 * lignes et deux colonnes, espacées régulièrement.
*/

int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
	 init_graphics(600,600);
     POINT p1;
     POINT p2;
	
	/* Ecrire son programme ici */
     p1.x=0; p1.y= 200;
     p2.x=600; p2.y=200;
     draw_line(p1,p2,blanc);
     
     p1.x=0; p1.y= 400;
     p2.x=600; p2.y=400;
     draw_line(p1,p2,blanc);
     
     p1.x=200; p1.y= 0;
     p2.x=200; p2.y=600;
     draw_line(p1,p2,blanc);
     
     p1.x=400; p1.y= 0;
     p2.x=400; p2.y=600;
     draw_line(p1,p2,blanc);


	//Commande de fin de code
	wait_escape();
	return 0;
	
}
