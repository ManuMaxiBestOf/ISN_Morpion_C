#include "graphics.h"
/* NIVEAU 1
   A chaque clic d'utilisateur, afficher un cercle de rayon aléatoire, et ce sans fin. 
 * Rq: La "couleur" est en fait simplement la donnée de 3 valeurs: 
 * - la quantité de rouge entre 0 (aucune) et 255 (max) (R: red)
 * - la quantité de vert entre 0 et 255	(G: green)
 * - la quantité de bleu entre 0 et 255 (B: blue)
 * Cela donne un nombre entre 0 et 255*255*255. Si vous souhaitez afficher une couleur "au hasard", 
 * vous pouvez donc écrire à la place de la "couleur":
 * alea_int(255*255*255)
*/

int main( int argc, char *argv[] )
{ 
	init_graphics (600,600);
    POINT c;
    
    c=wait_clic();
    while(1)
    {
        c=wait_clic();
        draw_fill_circle(c,alea_int(400),alea_int(255*255*255));
        
    }
    wait_escape();
    return 0;
}

