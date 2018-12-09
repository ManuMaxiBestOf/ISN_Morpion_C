#include "graphics.h"
/* NIVEAU 1
   Un exemple de programme utilisant l'instruction if.
 * Sans lancer le programme, dire quel texte va s'afficher. Vérifier ensuite en lancant le programme
*/

int main( int argc, char *argv[] )
{ 
	/* Déclarer ses variables ici */
	int pim, pam, poum;
	
	
	/* Ecrire son programme ici */
	
	/*Premier test*/
	pim = 5;
	
	if(pim < 10)
	{
		write_text("La variable pim est inférieure à 10");
	}
	
	/*Second test*/
	pim = 4;
	pam = 8;
	
	if(pim<=pam)
	{
		write_text("La variable pim est inférieur ou égale à la variable pam");
	}
	else
	{
		write_text("La variable pim est strictement supérieure à la variable pam");
	}
	
	/*Troisième test*/
	pim = 4;
	poum = 12;
		
	if(3*pim == poum)
	{
		write_text("poum est le triple de pim");
	}
	
	pim = 3;
	if(3*pim == poum)
	{
		write_text("poum est le triple de pim");
	}
	
	/*Quatrième test*/
	pim = 1;
	pam = 3;
	poum = 2;
	if( (2*pim == poum) && (pam > poum) )
	{
		pim = pim+1;
		pam = pam-1;
	}
	else if ( (2*pim == poum) || (pam > poum) )
	{
		pim = pim+2;
		pam = pam-2;
	}
	else
	{
		pim = pim+3;
		pam = pam-3;
	}
	write_int(pim);
	write_int(pam);
	
	
	exit(0);
}
