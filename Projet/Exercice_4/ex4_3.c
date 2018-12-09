#include "graphics.h"
/* NIVEAU 1
   1. Afficher deux lignes verticales blanches qui séparent l'écran en trois
 * 2. Attendre un clic de l'utilisateur. 
 * S'il clic au milieu, afficher un cercle rouge, centré sur le clic. 
*/

int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
     POINT p1,p2;
     init_graphics(600,600);
	
	/* Ecrire son programme ici */
     p1.x=200; p1.y=600;
     p2.x=200; p2.y= 0;
     draw_line(p1,p2,blanc);
          
     p1.x=400; p1.y=600;
     p2.x=400; p2.y= 0;
     draw_line(p1,p2,blanc);
     
     
     p1=wait_clic();
     if (p1.x<400 && p1.x >200)
     {
     draw_fill_circle(p1,30,rouge);
     }
	

	
	
	
	wait_escape();
	exit(0);
	
	
	
}
