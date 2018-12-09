#include "graphics.h"
#define NOMBRE 500


POINT deplace_point(POINT centre,int vecteur_x,int vecteur_y)
{
	centre.x=vecteur_x+centre.x;
	centre.y=vecteur_y+centre.y;
	return centre;
}

int rebond_dx(int dx,int largeur,int vecteur_x,int r)
{
	if(dx >= largeur-r || dx <= r)
		vecteur_x = -vecteur_x;
	return vecteur_x;
}

int rebond_dy(int dy,int hauteur,int vecteur_y,int r)
{
	if(dy >= hauteur-r || dy <=r)
		vecteur_y = -vecteur_y;
	return vecteur_y;
}

void affiche_cercle(POINT centre,int rayon,int couleur)
{	
	draw_fill_circle(centre,rayon,couleur);
}


int main( int argc, char* argv[])
{
	int W=800;
	int H=600;
	POINT centre[NOMBRE];
	int rayon[NOMBRE];
	int couleur[NOMBRE];
	int vecteur_x[NOMBRE];
	int vecteur_y[NOMBRE];
	int c=0;
	init_graphics(W,H);
	affiche_auto_off();

	for(c=0;c<NOMBRE;c++)
	{
		rayon[c]=alea_int(20)+20;
		centre[c].x=W/2;
		centre[c].y=H/2;
		vecteur_x[c]=alea_int(25)-12.5;
		vecteur_y[c]=alea_int(25)-12.5;
		couleur[c]=alea_int(255*255*255);
	}
	
	
		while(1)
		{	
		fill_screen(black);
        
			for(c=0;c<NOMBRE;c++)
			
			{	
				
				centre[c] = deplace_point(centre[c],vecteur_x[c],vecteur_y[c]);
				vecteur_x[c] = rebond_dx(centre[c].x,W,vecteur_x[c],rayon[c]);
				vecteur_y[c] = rebond_dy(centre[c].y,H,vecteur_y[c],rayon[c]);
				affiche_cercle(centre[c],rayon[c],couleur[c]);
				
				
			}
		attendre(15);
		affiche_all();
		}
	return 0;
}
