#include "graphics.h"
/* NIVEAU 2
   Afficher une fenetre graphique, et afficher un rond blanc au centre de rayon 100.
 * Attendre un clic de l'utilisateur. Tant qu'il ne clic pas dans le cercle, attendre un nouveau clic. 
 * S'il clic dans le cercle, changer la couleur à rouge.
 * REMARQUE: pour connaitre la distance entre deux POINTs p1 et p2, il suffit de faire : 
 * distance(p1,p2);
*/

int main( int argc, char *argv[] )
{ 
	init_graphics (600,600);
    POINT p1,p2;
    
    p1.x=300;   p1.y=300;
    draw_fill_circle (p1,100,blanc);
    p2=wait_clic();
    while(1)
    {
       if (distance(p2,p1)>100)
        {
          p2=wait_clic() ;
        } 
        else    
        {
        draw_fill_circle(p1,100,rouge);
        }
    }
    wait_escape ();
    return (0);
}
