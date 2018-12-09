#include "graphics.h"
/* Dessiner, dans une fenetre graphique de 600*600, 5 lignes horizontales 
 * les unes au dessus des autres, espacées de 100.
*/

int main( int argc, char *argv[] )
{
	/* Déclarer ses variables ici */
	 init_graphics(600,600);
     POINT p1;
     POINT p2;
	
	/* Ecrire son programme ici */
     p1.x =0; p1.y=100;
     p2.x=600; p2.y=100;
     draw_line(p1,p2,blanc);
     
     p1.x =0; p1.y=200;
     p2.x=600; p2.y=200;
     draw_line(p1,p2,bleu);
     
     p1.x =0; p1.y=300;
     p2.x=600; p2.y=300;
     draw_line(p1,p2,jaune);
     
     p1.x =0; p1.y=400;
     p2.x=600; p2.y=400;
     draw_line(p1,p2,rouge);
     
     p1.x =0; p1.y=500;
     p2.x=600; p2.y=500;
     draw_line(p1,p2,citronvert);


	//Commande de fin de code
	wait_escape();
	return 0;	
}
