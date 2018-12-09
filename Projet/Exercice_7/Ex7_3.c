/*Écrire un programme qui ouvre une fenêtre, demande à l’utilisateur de cliquer 6 fois, et enregistre les points cliqués dans un
tableau.
Ensuite, afficher un cercle en chaque point où l’utilisateur a cliqué toutes les 0,2 secondes, jusqu’à ce que les 6 points soient
visibles.*/
#include "graphics.h"

int main ( int argc, char *argv[])
{
    init_graphics (800,800);
    POINT a,b,c,d,e,f;
    a=wait_clic();
    b=wait_clic();
    c=wait_clic();
    d=wait_clic();
    e=wait_clic();
    f=wait_clic();

    POINT tab[6];
    tab[0]=a;
    tab[1]=b;
    tab[2]=c;
    tab[3]=d;
    tab[4]=e;
    tab[5]=f;

    
    draw_fill_circle(tab[0], alea_int (200), alea_int(255*255*255));
    attendre (20);
    draw_fill_circle(tab[1], alea_int (200), alea_int(255*255*255));
    attendre (20);
    draw_fill_circle(tab[2], alea_int (200), alea_int(255*255*255));
    attendre (20);
    draw_fill_circle(tab[3], alea_int (200), alea_int(255*255*255));
    attendre (20);
    draw_fill_circle(tab[4], alea_int (200), alea_int(255*255*255));
    attendre (20);
    draw_fill_circle(tab[5], alea_int (200), alea_int(255*255*255));
    attendre (20);
    
wait_escape();
return 0;
}

    