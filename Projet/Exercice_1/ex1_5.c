#include "graphics.h"

/* Lire le programme ci-dessous et, SANS LE COMPLIER, donner 
 * la valeur finale que contient la variable poum.
 * Ensuite, compléter le programme afin de pouvoir vérifier votre réponse.
*/



int main( int argc, char *argv[] )
{
	/* Déclarer ses variables ici */
	int zip, zap, zou;
	
	/* Ecrire son programme ici */
	zip = 3;
	zap=zip+5;
	zou = zip-zap;
	zou = zou+4;
	write_int(zou);
	return 0;
	
}
