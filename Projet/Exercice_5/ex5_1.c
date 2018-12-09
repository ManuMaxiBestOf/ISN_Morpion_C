#include "graphics.h"
/* NIVEAU 1
   Un exemple de programme utilisant les instructions for et while.
 * Sans lancer le programme, dire ce qui va s'afficher
*/

int main( int argc, char *argv[] )
{ 
	int i;	//IMPORTANT: il faut déclarer le i qu'on va mettre dans la boucle!
	int test;
	
	
	for(i=0; i<5; i++)	//Bien faire attention à la syntaxe
	{
		write_text("\nessai numero:");
		write_int(i);
	}
	
	i=21;
	while(i!=0)
	{
		write_text("i n'est toujours pas nul!\n");
		i = i/2;	//bien réfléchir ici... i est déclarer comme un entier... donc...?
	}
	
	test = 1;
	i=21;
	while(test)		//relire ce qu'on a vu en cours sur les conditions si besoin est...
	{
		write_text("i est différent de zéro\n");
		i = i/2;
		if(i==0)
		{
			test = 0;
		}
	}
	
	exit(0);
}
