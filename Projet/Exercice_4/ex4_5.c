#include "graphics.h"
/* NIVEAU 2
   1. Afficher une ligne verticale blanche qui sépare l'écran en deux
 * 2. Attendre un clic de l'utilisateur. S'il clic a gauche de la ligne, afficher un cercle bleu, mais symétrique par 
 * rapport à la ligne blanche, et vice et versa
*/

int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
    POINT p1,p2;
    init_graphics (300,300);
	
	/* Ecrire son programme ici */
        p1.x= 150; p1.y= 300;
        p2.x=150; p2.y=0;
        
         draw_line(p1,p2,blanc);
     
        p1=wait_clic();
        if (p1.x<150)
        {
            p1.x= 150+(150-p1.x); 
            draw_fill_circle(p1,30,bleu);
        }  else if(p1.x>150)
        {
            p1.x=150-(p1.x-150); 
            draw_fill_circle(p2,30,bleu);
        }
   
   
	
	
	wait_escape();
	exit(0);
	
	
	
}
