/*(a) Cr�er une fonction POINT deplace point(POINT centre, int dx, int dy) qui d�place le le point en entr�e
de dx et dy, et renvoie le point d�plac� en sortie.
(b) Cr�er deux fonctions int rebond_dx(POINT centre, int dx) et int rebond_dy(POINT centre, int dy)
qui v�rifient si le point est sorti de l��cran � gauche ou � droite (ou eh haut ou en bas), et renvoient la valeur de
dx ou d y.
(c) Cr�er une fonction void affiche_point(POINT centre, int rayon, COULEUR couleur) qui dessine simplement
la balle de centre centre, de rayon rayon et de couleur couleur.
(d) Cr�er ensuite un main pour tester ces fonctions en animant une balle comme dans l�exercice 5.7.*/
#include "graphics.h"
#define XMAX 800
#define YMAX 800
POINT deplacement ( POINT centre, int dx,int dy)
{
    centre.x=centre.x+dx;
    centre.y=centre.y+dy;
    return centre;
}


int rebond_dx (POINT p, int dx, int r)
{
  if (p.x>XMAX-r || p.x<0+r)
   {
   dx=-dx;
   }
    return dx;
}
int rebond_dy (POINT p, int dy, int r)
{
  if (p.y>YMAX-r || p.y<0+r)
  {
  dy=-dy;
  }
  return dy;
}

int main ( int argc, char *argv[])
{
    int  dy,dx,r;
    POINT  centre;
    init_graphics (800,800);
    
    dx=2;
    dy=3;
    centre.x=400;
    centre.y=400;
    r=50;
    draw_fill_circle(centre,r,bleu);
    while (1)
    {
        centre=deplacement(centre, dx,dy );
        draw_fill_circle(centre,r,bleu);
     
        dy=rebond_dy(centre,dy,r);
     
        dx=rebond_dx (centre,dx,r);
        draw_fill_circle(centre,r,noir);
    } 
wait_escape ();
return 0;
}

    

    
  
  