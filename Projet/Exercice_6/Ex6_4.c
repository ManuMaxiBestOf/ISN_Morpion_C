#include "graphics.h"
/*1. Ecrire une fonction POINT translation( POINT p, POINT vecteur) qui renvoie le translaté du point p par le
vecteur vecteur.
2. Tester la fonction précédente en affichant un triangle, puis le translaté de ce triangle par un vecteur que vous avez
choisi*/

POINT translation(POINT p, POINT vecteur)
{
	POINT p_image;
	p_image.x = p.x + vecteur.x;
	p_image.y = p.y + vecteur.y;
	return p_image;
}
    
    void triangle(POINT p1, POINT p2, POINT p3, COULEUR c)

{
    draw_line(p1,p2,c);
    draw_line(p1,p3,c);
    draw_line(p2,p3,c);
}

int main( int argc, char *argv[] )
{

    init_graphics (600,600);
    POINT p1,p2,p3,v;
    
    p1=wait_clic();   
    p2=wait_clic();   
    p3=wait_clic();   
    
    triangle(p1,p2,p3,jaune);
    
    v.x=200;  v.y=200;
    
    p1.x=p1.x+v.x;   p1.y=p1.y+v.y;
    p2.x=p2.x+v.x;   p2.y=p2.y+v.y;
    p3.x=p3.x+v.x;   p3.y=p3.y+v.y;
    
    triangle(p1,p2,p3,vert);
    
wait_escape();
return 0;
}
    
    
    



