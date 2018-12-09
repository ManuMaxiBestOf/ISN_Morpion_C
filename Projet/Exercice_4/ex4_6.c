#include "graphics.h"
/* NIVEAU 2
   1. Afficher une ligne verticale blanche qui sépare l'écran en deux parties égales
 * 2. Attendre deux clics. S'ils sont tous les deux du même coté de la ligne,
 * afficher une ligne verte reliant ces deux points. S'ils ne sont pas du même
 * coté, afficher une ligne rouge reliant ces deux points.
*/

int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
	POINT p1,p2;
    init_graphics (600,600);
	/* Ecrire son programme ici */
    p1.x= 300; p1.y = 600;
    p2.x= 300; p2.y = 0;
    draw_line(p1,p2,blanc);
            
    p1=wait_clic();
    p2=wait_clic();
        
     if ((p1.x<300 && p2.x<300) || (p1.x>300 &&p2.x>300))
     { 
        draw_line(p1,p2,vert);
     } 
     else if ((p1.x<300 && p2.x>300) || (p1.x>300 && p2.x<300))
     {
        draw_line(p1,p2,rouge);
     }
    
    
	
	
	
	wait_escape();
	exit(0);
}
