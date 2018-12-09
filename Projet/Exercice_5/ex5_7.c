è#include "graphics.h"
/* NIVEAU 3 (OPTIONNEL)
   Reprendre l'animation précédente, mais la balle doit désormais rebondir sur le bord de l'écran.
 * Amélioration si vous etes en avance: la couleur de la balle doit évoluer doucement au cours du temps dans les ton bleu
*/

int main( int argc, char *argv[] )
{ 
	int dx;
    int dy;
    POINT p;
    init_graphics (600,600);
    
    
    dx=3;
    dy=4;
    
    init_graphics(600,600);
	p.x= 300; p.y = 300;
	draw_circle(p, 20, bleu);
	while(1)
	{
		draw_fill_circle(p,20,noir);
		p.x=p.x+dx; p.y=p.y+dy;
		draw_fill_circle(p,20,bleu);
		attendre(10);
        if (p.x>580)
        {
            dx=-dx; 
            draw_fill_circle(p,20,noir);
            p.x=p.x; p.y=p.y;
            draw_fill_circle(p,20,bleu);
            attendre(10); 
        }  
        if (p.y>580)
        {
            dy=-dy;
            draw_fill_circle(p,20,noir);
            p.x=p.x; p.y=p.y;
            draw_fill_circle(p,20,bleu);
            attendre(10);
        } 

        if (p.x<20)
        {
            dx=-dx;
            draw_fill_circle(p,20,noir);
            p.x=p.x; p.y=p.y;
            draw_fill_circle(p,20,bleu);
            attendre(10);
        }
         if (p.y<20)
        {
            dy=-dy;
            draw_fill_circle(p,20,noir);
            p.x=p.x; p.y=p.y;
            draw_fill_circle(p,20,bleu);
            attendre(10);
        }
     }
    
	wait_escape();
    return 0;
}
