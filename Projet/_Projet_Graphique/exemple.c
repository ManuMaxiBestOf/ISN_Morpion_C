#include <stdio.h>
#include "graphics.h"

#define LARGEUR	400
#define HAUTEUR	300 

int main( int argc, char *argv[] )
{
	int i,j;
	POINT centre;
	
	// Creer une fenetre graphique
	 init_graphics( LARGEUR, HAUTEUR, "Un premier exemple"); 
	
	// Dessiner des cercles tous les 10 pixels
	for (i = 0; i < LARGEUR/10; i++)
	{
		for (j = 0; j < HAUTEUR/10; j++)
		{
			centre.x = 10*i;
			centre.y = 10*j;
			
			draw_fill_circle(centre, 6, rouge);
		}
	}	
	
	
	// Attendre que l'utilisateur appuie sur la touche Echap
	wait_escape();
	exit(0);
}
