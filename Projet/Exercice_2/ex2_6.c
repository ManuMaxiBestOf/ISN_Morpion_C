#include "graphics.h"
/* Dessiner, dans une fenetre graphique de 600*600, une croix (style x) formée 
 * de deux segments, insérée dans un carré de coté 50 et dont un centre 
 * est en (120, 170)
*/

int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
    init_graphics(600,600);
    POINT p1;
    POINT p2;
	
	
	/* Ecrire son programme ici */
    p1.x=95; p1.y=145;
    p2.x=145; p2.y= 195;
    draw_rectangle(p1,p2,bleu);
    
    p1.x=95; p1.y=145;
    p2.x=145; p2.y= 195;
    draw_line(p1,p2,blanc);
    
    p1.x=95; p1.y=195;
    p2.x=145; p2.y= 145;
    draw_line(p1,p2,blanc);



	//Commande de fin de code
	wait_escape();
	return 0;
	
	
}
