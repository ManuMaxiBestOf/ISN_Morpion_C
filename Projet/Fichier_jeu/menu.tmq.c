#include "graphics.h"
#define H 200
#define L 200


int main( int argc, char *argv[] )
{


    init_graphics(L,H,"menu");

    POINT r1, r2 ,r3, r4;
 
 
    r1.x = 1/3*L ,r1.y = 1/6*H;
    r2.x = 2/3*L ,r2.y = 1/3*H;
    fill_screen(citronvert );
    draw_fill_rectangle(r1,r2 ,bleu);
    
    wait_escape();
    exit(0);
}