#include "graphics.h"
/* NIVEAU 1
   1. Afficher une ligne verticale blanche qui sépare l'écran en deux
 * 2. Attendre un clic de l'utilisateur. S'il clic a gauche de la ligne, afficher un cercle en bleu (centre sur le clic), 
 * s'il clic à droite, afficher un cercle rouge (idem). 
 * Dans tous les cas, le cercle doit etre de rayon 25 et centré là ou on a cliqué.
*/



int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
     POINT p1, p2;
     init_graphics ( 500,500);
	
	/* Ecrire son programme ici */
    p1.x=250; p1.y= 500;
    p2.x=250; p2.y= 0;
     draw_line (p1,p2,blanc);
     
     p1=wait_clic();
     if (p1.x<250)
     {
     draw_fill_circle(p1,25,bleu);
     }
     if (p1.x>250)
     {
     draw_fill_circle(p1,25,rouge);
     }
     
   
  
   
	
	
	wait_escape();
	exit(0);
    
}
	
	

