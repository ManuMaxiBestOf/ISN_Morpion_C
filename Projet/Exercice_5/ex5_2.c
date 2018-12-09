#include "graphics.h"
/* NIVEAU 1
   Afficher une fenetre graphique, et tracer une ligne blanche horizontale tous les 2 pixels, pour rayer completement la fenetre.
*/

int main( int argc, char *argv[] )
{ 
        int i;
        init_graphics (600,600);
        POINT p1,p2;
        
        p1.x=0;  p1.y=2;
        p2.x=600;  p2.y=2;
        
        draw_line(p1,p2,blanc);
        
        for ( i =0; i<300; i++)
        {
            p1.y=2+2*i; p2.y=2+2*i;
            draw_line(p1,p2,blanc);
        }
           wait_escape();
           return 0;
        
        
	
}
