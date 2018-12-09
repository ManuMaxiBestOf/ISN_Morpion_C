#include "graphics.h"
/*Ecrire un programme qui 
 * - créé une fenetre graphique de 400 pixels par 400 pixels
 * - affiche un cercle centré au milieu de la fenetre, de rayon 100
 * - affiche un carré vide qui contienne le cercle, à l'aide de la commande draw_rectangle
*/

int main( int argc, char *argv[] )
{
	/* Déclarer ses variables ici */
	init_graphics(400,400);
    POINT p1;
    POINT p2;
	
	/* Ecrire son programme ici */
    p1.x =200; p1.y =200;
    draw_circle(p1,100,citronvert);
    
    p1.x=100; p1.y=100;
    p2.x=300; p2.y=300;
    draw_rectangle(p1,p2,bleu);


	
	//Commande de fin de code
	wait_escape();
	return 0;
	
}
