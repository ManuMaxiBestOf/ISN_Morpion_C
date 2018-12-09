#include "graphics.h"
/*Ecrire une fonction void triangle(POINT p1, POINT p2, POINT p3, COULEUR c) qui affiche un triangle crée par les
trois points passés en argument.
La tester dans le main sur différents exemples.*/

void triangle(POINT p1, POINT p2, POINT p3, COULEUR c)

{
    draw_line(p1,p2,c);
    draw_line(p1,p3,c);
    draw_line(p2,p3,c);
}
    
int main( int argc, char *argv[] )

{ 
 init_graphics (600,600);
 POINT p1,p2,p3;
  p1.x=40;  p1.y=300;    
  p2.x=50;  p2.y=200;        
  p3.x=350; p3.y=100;
 
 triangle(p1,p2,p3,blanc);

wait_escape();
return 0;
}