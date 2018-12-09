#include "graphics.h"
/* NIVEAU 1
   Reprendre l'exercice précédent, et le compléter pour qu'on obtienne 3 cercles de couleurs différentes 
 * en fonction de l'endroit ou l'on clic, en utilisant des "else if"
*/
int main( int argc, char*argv[])

{
     POINT p1,p2;
     init_graphics (600,600);
     
     p1.x =200; p1.y =600;
     p2.x= 200; p2.y=0;
     draw_line(p1,p2,blanc);
     
     p1.x =400; p1.y =600;
     p2.x= 400; p2.y=0;
     draw_line(p1,p2,blanc);
     
     p1=wait_clic();
     if (p1.x>200 && p1.x<400)
     {
        draw_fill_circle(p1,30,blanc);
        
     } 
     else if(p1.x>0 && p1.x<200)
     { 
        draw_fill_circle(p1,30,bleu);
     }
     else if (p1.x>400 && p1.x<600)
     {
        draw_fill_circle(p1,30,rouge);
     }
     
     wait_escape ();
     
     return 0;
     
     }