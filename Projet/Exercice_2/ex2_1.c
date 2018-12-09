#include "graphics.h"

/* Premier programme d'affichage graphique. Compiler et executer ce programme, et comprendre ce qu'il fait.
 * */

int main( int argc, char *argv[] )
{
	// Déclarer ses variables ci-dessous
	POINT p1;
	POINT p2;
		
	init_graphics(400,400); //Cette commande créé une fenetre graphique de 400 pixels par 400 pixels
	
	
	// Ecrire son code ci-dessous
	p1.x = 50;	p1.y = 50;
	p2.x = 100; p2.y = 150;
	draw_fill_rectangle(p1,p2,bleu);

	p1.x = 220;	p1.y = 230;
	p2.x = 350; p2.y = 390;
	draw_fill_rectangle(p1,p2,blanc);
	
	p1.x = 50;	p1.y = 200;
	p2.x = 350; p2.y = 200;
	draw_line(p1,p2,vert);

	p1.x = 75;	p1.y = 100;
	draw_circle(p1,100,magenta);
	
	
	//Commande de fin de code
	wait_escape();
	return 0;
}
