#include <stdio.h>

int main( int argc, char *argv[] )
{
	int i;
	
	printf("Ceci est un progamme en mode texte\n");
	printf("----------------------------------\n");
	printf("On va compter de 1 a 100 :\n");
	
	for (i = 1; i <= 100; i++)
	{
		printf(" i vaut %3u \n", i);
	}
	
	printf("\n\nFini!\n");
	
	return 0;
}
