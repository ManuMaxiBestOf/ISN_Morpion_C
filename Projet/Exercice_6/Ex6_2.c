#include "graphics.h"
/*1. Ecrire une fonction int difference(int a, int b) qui renvoie la différence de deux nombres entiers
*2. Ecrire une fonction void write_two_ints(int a, int b) qui ne renvoie rien mais qui affiche le texte:
“premier nombre: ... deuxieme nombre: ...”
*3. Ecrire une fonction absolue qui prend un entier en argument et renvoie la valeur absolue de ce nombre.
Finallement, tester ces fonctions dans le main.*/



int difference(int a, int b)
int d;
{
d=a-b; 
}
  
void write_two_ints(int a, int b)

    {
	 write_text("\n premier nombre: ");
	 write_int(a);
	 write_text("\n");
    
    
	 write_text("\n deuxième nombre: ");
	 write_int(b);
	 write_text("\n");

    }
int main( int argc, char *argv[] )
{

    int a,b,p;
    a=6;
    b=4;
    write_int (difference(a,b));

 return d;
  p=a;
 if (a<0)
 {
    return p=-a  ;
 }  
 else if (a>0);
 {

    return p=a;
 }

return 0;   

}


