#include "graphics.h"
/* Votre second programme.
 * Lire et comprendre le programme.
 * Résumer ce qu'il fait dans son cahier.
 */


int main( int argc, char *argv[] )
{
	/* Déclarer ses variables ici */
	int pim; /*Déclaration de la variable pim, qui sera un entier*/
	int pam; /*Idem pour pam*/
	int poum; //Idem pour poum
	
	
	/* Ecrire son programme ici */
	pim=3; //On "affecte" à la variable pim la valeur 3: la boite pim contient la valeur 3
	pam=5; 
	poum = pim + pam;
	
	write_int(poum);
	return 0;
	
	
	
}
