#include "graphics.h"
/* Dessiner, dans une fenetre graphique de 600*600, un carré dont
 * le coin en bas à gauche est aux coordonnées (20,20) et dont
 * chaque coté est de couleur différente.
*/

int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
	 init_graphics(600,600);
     POINT p1;
     POINT p2;
	
	/* Ecrire son programme ici */
     p1.x=200; p1.y=200;
     p2.x=500; p2.y=200;
     draw_line(p1,p2,vert);
     
     p1.x=200; p1.y=200;
     p2.x=200; p2.y=500;
     draw_line(p1,p2,bleu);
     
     p1.x=500; p1.y=200;
     p2.x=500; p2.y=500;
     draw_line(p1,p2,rouge);
     
     p1.x=200; p1.y=500;
     p2.x=500; p2.y=500;
     draw_line(p1,p2,blanc);





	//Commande de fin de code
	wait_escape();
	return 0;
	
	
	
}
