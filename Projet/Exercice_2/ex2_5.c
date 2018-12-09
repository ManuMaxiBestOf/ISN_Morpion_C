#include "graphics.h"
/* Dessiner, dans une fenetre graphique de 600*600, un anneau rouge (deux cercles
 * concentriques, avec de la couleur entre ces deux cercles)
 * INDICATIONS:
 * - la commande draw_fill_circle permet de tracer un cercle plein
 * - pour effacer une zone, il suffit de la colorier en noir!
*/

int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
	 init_graphics (600,600);
     POINT p1;
    
	
	/* Ecrire son programme ici */
     p1.x=300; p1.y=300;
     draw_fill_circle(p1,200,rouge);
     
      p1.x=300; p1.y=300;
     draw_fill_circle(p1,180,noir);


	//Commande de fin de code
	wait_escape();
	return 0;
	
	
	
}
