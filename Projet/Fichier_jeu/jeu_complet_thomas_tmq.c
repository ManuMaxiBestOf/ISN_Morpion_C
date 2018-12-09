#include "graphics.h"
#define H 1100
#define L 1300
#define SDL_TTF_OK
#define RC (H+L)/60

struct jeu
{
    int tab[3][3]; //0: pas de pion, 1: pion J1; 2: pion J2
    int aqui; // 1: J1 joue; 2: J2 joue
};
typedef struct jeu JEU;

struct ia   
{
    POINT i,a;
    int g;
};
typedef struct ia IA;

POINT ij2point(int i, int j) //prend en entre i et j, et renvoie le centre du cercle correspondant
{
     POINT m;
     m.x=(0.2*L)+(0.3*L*i);
     m.y=(0.2*H)+(0.3*H*j);
     return m;
}

void plateau(POINT a,POINT b,POINT c,POINT d,POINT e,POINT f,POINT g,POINT h,POINT v)// Dessine le plateau de jeu.
{
        draw_line(a,c, citronvert);
        draw_line(a,g, citronvert);
        draw_line(g,v, citronvert);
        draw_line(v,c, citronvert);
        draw_line(a,v, citronvert);
        draw_line(g,c, citronvert);
        draw_line(f,d, citronvert);
        draw_line(h,b, citronvert);
        draw_circle(a, RC ,citronvert );
        draw_circle(b, RC ,citronvert );
        draw_circle(c, RC ,citronvert );
        draw_circle(d, RC ,citronvert );
        draw_circle(e, RC ,citronvert );
        draw_circle(f, RC ,citronvert );
        draw_circle(g, RC ,citronvert );
        draw_circle(h, RC ,citronvert );
        draw_circle(v, RC ,citronvert );
        draw_fill_circle(a, RC-1 ,noir);
        draw_fill_circle(b, RC-1 ,noir);
        draw_fill_circle(c, RC-1 ,noir);
        draw_fill_circle(d, RC-1 ,noir);
        draw_fill_circle(e, RC-1 ,noir);
        draw_fill_circle(f, RC-1 ,noir);
        draw_fill_circle(g, RC-1 ,noir);
        draw_fill_circle(h, RC-1 ,noir);
        draw_fill_circle(v, RC-1 ,noir);
}

void affichage(int i, int j,int n) //prend i et j en facteur et trace un cercle correspondant au coordonees.
{
   POINT m=ij2point(i,j);
   if (n == 1)
   {
    draw_fill_circle(m,RC-1,blue);
   }
   else     
   if (n == 2)
   {
    draw_fill_circle(m,RC-1,rouge);
   }
   else 
   {
    draw_fill_circle(m,RC-1,noir);
   }
}

POINT coord()  //attend un clic et renvoie i et j codes dans un point et renvoie (-1,-1) si il clic nul part
{
      POINT p=wait_clic();
      POINT m;
      int i,j,z;
      i=-1; j=-1;
      for ( z = 0; z < 3; z++)
      {
         if ( (p.x > (0.2*L+0.3*L*z)-(RC/2)) && (p.x < (0.2*L+0.3*L*z)+(RC/2)) ) 
        {
            i=z;
        } 
        
      }
      for (z = 0; z < 3; z++)
      {
        if (p.y > (0.2*H+0.3*H*z)-(RC/2) && p.y < (0.2*H+0.3*H*z)+(RC/2))
         {
            j=z ;
         } 
       }
      
      m.x = i;
      m.y = j;
      return m;
}

int victoire(int tab[3][3])// verifie si un des joueurs à gagner.
{
      if (tab[0][0] == tab[0][1] && tab[0][2] == tab[0][1] && tab[0][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][0], (tab[0][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[0][0] == tab[1][0] && tab[2][0] == tab[1][0] && tab[0][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][0], (tab[0][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[2][0] == tab[2][1] && tab[2][2] == tab[2][0] && tab[2][0] !=0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[2][0], (tab[2][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[0][2] == tab[1][2] && tab[2][2] == tab[1][2] && tab[0][2] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][2], (tab[0][2] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[0][0] == tab[1][1] && tab[2][2] == tab[1][1] && tab[0][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][0], (tab[0][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[2][0] == tab[1][1] && tab[1][1] == tab[0][2] && tab[2][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[2][0], (tab[2][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      else if (tab[1][0] == tab [1][1] && tab[1][1] == tab[1][2] && tab[1][0] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[1][0], (tab[1][0] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
     
      else if (tab[0][1] == tab[1][1] && tab[2][1] == tab[0][1] && tab[0][1] != 0)
      {
        printf("JOUEUR %d(%s) GAGNE", tab[0][1], (tab[0][1] == 1) ? "Bleu" : "Rouge");
        fflush(stdout);
        return 1;
      }
      
        return 0;
}

int possible(POINT p, int tab[3][3])// verifie si le jeton est possible d'être deplacer. renvoie 1 si oui sinon renvoie 0
{
    
    if (p.x == p.y && p.x == 0)
    {
        if ((tab[p.x + 1][p.y] == 0) || (tab[p.x + 1][p.y + 1] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 1 && p.y == 0)
    {
        if ((tab[p.x + 1][p.y] == 0) || (tab[p.x - 1][p.y] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 2 && p.y == 0)
    {
        if ((tab[p.x - 1][p.y] == 0) || (tab[p.x - 1][p.y + 1] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 0 && p.y == 1)
    {
        if ((tab[p.x + 1][p.y] == 0) || (tab[p.x][p.y - 1] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 1 && p.y ==1)
    {
        return 1;
    }
    if (p.x == 2 && p.y == 1)
    {
        if ((tab[p.x - 1][p.y] == 0) || (tab[p.x][p.y - 1] == 0) || (tab[p.x][p.y + 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 0 && p.y == 2)
    {
        if ((tab[p.x + 1][p.y] == 0) || (tab[p.x][p.y - 1] == 0) || (tab[p.x + 1][p.y - 1] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 1 && p.y == 2)
    {
        if ((tab[p.x - 1][p.y] == 0) || (tab[p.x][p.y - 1] == 0) || (tab[p.x + 1][p.y] == 0))
                return 1;
        else
                return 0;
    }
    if (p.x == 2 && p.y == 2)
    {
        if ((tab[p.x - 1][p.y] == 0) || (tab[p.x - 1][p.y - 1] == 0) || (tab[p.x][p.y - 1] == 0))
                return 1;
        else
                return 0;
    }
       
    return -1;
}

int deplacement(POINT p1,POINT p2,int ta, int tab[3][3])// prend en entrer les deux points desirés et fait apparaitre un jeton au deuxieme point en supprimant le jeton present au premier point.
{                                                       //renvoie 0 pour comfirmer le deplacement sinon 1.
    if (tab[p2.x][p2.y] == 0)
    {
        affichage(p2.x, p2.y, ta);
        tab[p2.x][p2.y] = ta;
        tab[p1.x][p1.y] = 0;
        affichage(p1.x, p1.y, 0);
        return 0;
    }
    return 1;
}
int verife_deplacement(POINT p1, POINT p2, int tab[3][3])// empêche les deplacments impossibles qui ne suivent pas les lignes du plateau
{
    if (p1.x == 0 && p1.y == 0)
    {
        if ((p2.x == 1 && p2.y == 0) || (p2.x == 0 && p2.y == 1) || (p2.x == 1 && p2.y == 1))
        {
            return 1;
        }
        else    
            return 0;
    }
    else   
            if (p1.x == 1 && p1.y == 0)
            {
                if ((p2.x == 0 && p2.y == 0) || (p2.x == 2 && p2.y == 0) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else    
                    return 0;
            }
            else    
            if (p1.x == 2 && p1.y == 0)
            {
                if ((p2.x == 1 && p2.y == 0) || (p2.x == 2 && p2.y == 1) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else    
                    return 0;
            }
            else    
            if (p1.x == 0 && p1.y == 1)
            {
                if ((p2.x == 0 && p2.y == 0) || (p2.x == 0 && p2.y == 2) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else    
            if (p1.x == 1 && p1.y == 1)
            {   
                    return 1;
            }
            else 
            if (p1.x == 2 && p1.y == 1)
            {
                if ((p2.x == 2 && p2.y == 2) || (p2.x == 2 && p2.y == 0) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else 
            if (p1.x == 0 && p1.y == 2)
            {
                if ((p2.x == 0 && p2.y == 1) || (p2.x == 1 && p2.y == 2) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else 
            if (p1.x == 1 && p1.y == 2)
            {
                if ((p2.x == 0 && p2.y == 2) || (p2.x == 2 && p2.y == 2) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else 
            if (p1.x == 2 && p1.y == 2)
            {
                if ((p2.x == 1 && p2.y == 2) || (p2.x == 2 && p2.y == 1) || (p2.x == 1 && p2.y == 1))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else    
                    return 0;
}
IA intelligence_artificielle_emp(JEU tmq)
{
    IA ia;
    int z = 0;
    int k;
    if ((tmq.tab[0][0] == tmq.tab[0][1] && tmq.tab[0][0] == 1 && tmq.tab[0][2] == 0) && (tmq.tab[1][1] == 1 || tmq.tab[1][2] == 1) && (tmq.tab[1][1] == 2 || tmq.tab[1][2] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 2;
            ia.g = 1;
            
        }
        else    if (tmq.tab[1][2] == 2)
        {
            ia.i.x = 1; ia.i.y = 2;
            ia.a.x = 0; ia.a.y = 2;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[0][2] == tmq.tab[0][1] && tmq.tab[0][2] == 1 && tmq.tab[0][0] == 0) && (tmq.tab[1][1] == 1 || tmq.tab[1][0] == 1) && (tmq.tab[1][1] == 2 || tmq.tab[1][0] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 1;
            
        }
        else    if (tmq.tab[1][0] == 2)
        {
            ia.i.x = 1; ia.i.y = 0;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[0][0] == tmq.tab[1][0] && tmq.tab[0][0] == 1 && tmq.tab[2][0] == 0) && (tmq.tab[1][1] == 1 || tmq.tab[2][1] == 1) && (tmq.tab[1][1] == 2 || tmq.tab[2][1] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 1;
            
        }
        else if (tmq.tab[2][1] == 2)
        {
            ia.i.x = 2; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[1][0] == tmq.tab[2][0] && tmq.tab[1][0] == 1 && tmq.tab[0][0] == 0) && (tmq.tab[1][1] == 1 || tmq.tab[0][1] == 1) && (tmq.tab[1][1] == 2 || tmq.tab[0][1] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 1;
            
        }
        else if (tmq.tab[0][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[2][0] == tmq.tab[2][1] && tmq.tab[2][0] == 1 && tmq.tab[2][2] == 0) && (tmq.tab[1][1] == 1 || tmq.tab[1][2] == 1) && (tmq.tab[1][1] == 2 || tmq.tab[1][2] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 1;
            
        }
        else if (tmq.tab[1][2] == 2)
        {
            ia.i.x = 1; ia.i.y = 2;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 1;
            
        }
      }
    if ((tmq.tab[2][2] == tmq.tab[2][1] && tmq.tab[2][2] == 1 && tmq.tab[2][0] == 0) && (tmq.tab[1][1] == 1 || tmq.tab[1][0] == 1) && (tmq.tab[1][1] == 2 || tmq.tab[1][0] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 1;
            
        }
        else if (tmq.tab[1][0] == 2)
        {
            ia.i.x = 1; ia.i.y = 0;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[0][2] == tmq.tab[1][2] && tmq.tab[0][2] == 1 && tmq.tab[2][2] == 0) && (tmq.tab[1][1] == 1 || tmq.tab[2][1] == 1) && (tmq.tab[1][1] == 2 || tmq.tab[2][1] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 1;
            
        }
        else if (tmq.tab[2][1] == 2)
        {
            ia.i.x = 2; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[2][2] == tmq.tab[1][2] && tmq.tab[2][2] == 1 && tmq.tab[0][2] == 0) && (tmq.tab[1][1] == 1 || tmq.tab[0][1] == 1) && (tmq.tab[1][1] == 2 || tmq.tab[0][1] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 1;
            
        }
        else if (tmq.tab[0][1] == 2)
        {
            ia.i.x = 0; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[2][2] == tmq.tab[1][1] && tmq.tab[2][2] == 1 && tmq.tab[0][0] == 0) && (tmq.tab[1][0] == 1 || tmq.tab[0][1] == 1) && (tmq.tab[1][0] == 2 || tmq.tab[0][1] == 2))
      {
        if (tmq.tab[1][0] == 2)
        {
            ia.i.x = 1; ia.i.y = 0;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 1;
            
        }
        else if (tmq.tab[0][1] == 2)
        {
            ia.i.x = 0; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 1;
           
        }
      }
    else    if ((tmq.tab[1][0] == tmq.tab[1][1] && tmq.tab[1][0] == 1 && tmq.tab[1][2] == 0) && (tmq.tab[0][2] == 1 || tmq.tab[2][2] == 1) && (tmq.tab[0][2] == 2 || tmq.tab[2][2] == 2))
      {
        if (tmq.tab[0][2] == 2)
        {
            ia.i.x = 0; ia.i.y = 2;
            ia.a.x = 1; ia.a.y = 2;
            ia.g = 1;
            
        }
        else if (tmq.tab[2][2] == 2)
        {
            ia.i.x = 2; ia.i.y = 2;
            ia.a.x = 1; ia.a.y = 2;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[1][2] == tmq.tab[1][1] && tmq.tab[1][1] == 1 && tmq.tab[1][0] == 0) && (tmq.tab[0][0] == 1 || tmq.tab[2][0] == 1) && (tmq.tab[0][0] == 2 || tmq.tab[2][0] == 2))
      {
        if (tmq.tab[0][0] == 2)
        {
            ia.i.x = 0; ia.i.y = 0;
            ia.a.x = 1; ia.a.y = 0;
            ia.g = 1;
            
        }
        else if (tmq.tab[2][0] == 2)
        {
            ia.i.x = 2; ia.i.y = 0;
            ia.a.x = 1; ia.a.y = 0;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[0][1] == tmq.tab[1][1] && tmq.tab[1][1] == 1 && tmq.tab[2][1] == 0) && (tmq.tab[2][0] == 1 || tmq.tab[2][2] == 1) && (tmq.tab[2][0] == 2|| tmq.tab[2][2] == 2))
      {
        if (tmq.tab[2][0] == 2)
        {
            ia.i.x = 2; ia.i.y = 0;
            ia.a.x = 2; ia.a.y = 1;
            ia.g = 1;
            
        }
        else if (tmq.tab[2][2] == 2)
        {
            ia.i.x = 2; ia.i.y = 2;
            ia.a.x = 2; ia.a.y = 1;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[2][1] == tmq.tab[1][1] && tmq.tab[1][1] == 1 && tmq.tab[0][1] == 0) && (tmq.tab[0][0] == 1 || tmq.tab[0][2] == 1) && (tmq.tab[0][0] == 2 || tmq.tab[0][2] == 2))
      {
        if (tmq.tab[0][0] == 2)
        {
            ia.i.x = 0; ia.i.y = 0;
            ia.a.x = 0; ia.a.y = 1;
            ia.g = 1;

        }
        else if (tmq.tab[0][2] == 2)
        {
            ia.i.x = 0; ia.i.y = 2;
            ia.a.x = 0; ia.a.y = 1;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[0][0] == tmq.tab[1][1] && tmq.tab[1][1] == 1 && tmq.tab[2][2] == 0) && (tmq.tab[1][2] == 1 || tmq.tab[2][1] == 1) && (tmq.tab[1][2] == 2 || tmq.tab[2][1] == 2))
      {
        if (tmq.tab[1][2] == 2)
        {
            ia.i.x = 1; ia.i.y = 2;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 1;
            
        }
        else if (tmq.tab[2][1] == 2)
        {
            ia.i.x = 2; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[2][2] == tmq.tab[1][1] && tmq.tab[1][1] == 1 && tmq.tab[0][0] == 0) && (tmq.tab[0][1] == 1 || tmq.tab[1][0] == 1) && (tmq.tab[0][1] == 2 || tmq.tab[1][0] == 2))
      {
        if (tmq.tab[0][1] == 2)
        {
            ia.i.x = 0; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 1;
            
        }
        else if (tmq.tab[1][0] == 2)
        {
            ia.i.x = 1; ia.i.y = 0;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[0][2] == tmq.tab[1][1] && tmq.tab[1][1] == 1 && tmq.tab[2][0] == 0) && (tmq.tab[1][0] == 1 || tmq.tab[2][1] == 1) && (tmq.tab[1][0] == 2 || tmq.tab[2][1] == 2))
      {
        if (tmq.tab[1][0] == 2)
        {
            ia.i.x = 1; ia.i.y = 0;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 1;
            
        }
        else if (tmq.tab[2][1] == 2)
        {
            ia.i.x = 2; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 1;
            
        }
      }
    else    if ((tmq.tab[2][0] == tmq.tab[1][1] && tmq.tab[1][1] == 1 && tmq.tab[0][2] == 0) && (tmq.tab[0][1] == 1 || tmq.tab[1][2] == 1) && (tmq.tab[0][1] == 2 || tmq.tab[1][2] == 2))
      {
        if (tmq.tab[0][1] == 2)
        {
            ia.i.x = 0; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 2;
            ia.g = 1;
            
        }
        else if (tmq.tab[1][2] == 2)
        {
            ia.i.x = 1; ia.i.y = 2;
            ia.a.x = 0; ia.a.y = 2;
            ia.g = 1;
            
        }
      }
    else    if (tmq.tab[0][0] == tmq.tab[2][2] && tmq.tab[1][1] == 0)
      {
        while(z == 0)
                {
                    ia.i.x = alea_int(2); ia.i.y = alea_int(2);
                    if (tmq.tab[ia.i.x][ia.i.y] == 2)
                    {
                        k = possible(ia.i, tmq.tab);
                        if (k == 1)
                        z = 1 ;
                    } 
                }
        ia.a.x = 1; ia.a.y = 1;
        ia.g = 1;
        
      }
    else    if (tmq.tab[0][2] == tmq.tab[2][0] && tmq.tab[1][1] == 0)
      {
        while(z == 0)
                {
                    ia.i.x = alea_int(2); ia.i.y = alea_int(2);
                    if (tmq.tab[ia.i.x][ia.i.y] == 2)
                    {
                        k = possible(ia.i, tmq.tab);
                        if (k == 1)
                        z = 1 ;
                    }
                }
        ia.a.x = 1; ia.a.y = 1;
        ia.g = 1;
        
      }
    else    if (tmq.tab[1][0] == tmq.tab[1][2] && tmq.tab[1][1] == 0)
      {
        while(z == 0)
        {
            ia.i.x = alea_int(2); ia.i.y = alea_int(2);
            if (tmq.tab[ia.i.x][ia.i.y] == 2)
            {
                k = possible(ia.i, tmq.tab);
                if (k == 1)
                z = 1 ;
            }
        }
        ia.a.x = 1; ia.a.y = 1;
        ia.g = 1;
        
      }
    else    if (tmq.tab[0][1] == tmq.tab[2][1] && tmq.tab[1][1] == 0)
      {
        while(z == 0)
                {
                    ia.i.x = alea_int(2); ia.i.y = alea_int(2);
                    if (tmq.tab[ia.i.x][ia.i.y] == 2)
                    {
                        k = possible(ia.i, tmq.tab);
                        if (k == 1)
                        z = 1 ;
                    } 
                }
        ia.a.x = 1; ia.a.y = 1;
        ia.g = 1;
        
      }
    else 
    {

        ia.g = 0;
    }
        
        return ia;
}
IA intelligence_artificielle_gag(JEU tmq)
{
    IA ia;
    int k = 0;
    int z = 0;
    if (tmq.tab[0][0] == tmq.tab[0][2] && tmq.tab[0][0] == 2 && tmq.tab[0][1] == 0 && tmq.tab[1][1] == 2)
    {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 1;
            ia.g = 2;
    }
    else    if (tmq.tab[0][0] == tmq.tab[2][0] && tmq.tab[0][0] == 2 && tmq.tab[1][0] == 0 && tmq.tab[1][1] == 2)
    {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 1; ia.a.y = 0;
            ia.g = 2;
    }
    else    if (tmq.tab[0][2] == tmq.tab[2][2] && tmq.tab[0][2] == 2 && tmq.tab[1][2] == 0 && tmq.tab[1][1] == 2)
    {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 1; ia.a.y = 2;
            ia.g = 2;
    }
    else    if (tmq.tab[2][0] == tmq.tab[2][2] && tmq.tab[2][0] == 2 && tmq.tab[2][1] == 0 && tmq.tab[1][1] == 2)
    {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 1;
            ia.g = 2;
    }
    else    if (tmq.tab[0][0] == tmq.tab[2][2] && tmq.tab[0][0] == 2 && tmq.tab[1][1] == 0)
    {
                while(z == 0)
                {
                    while(k == 0)
                    {
                        ia.i.x = alea_int(2); ia.i.y = alea_int(2);
                        if (ia.i.x == 0 && ia.i.y == 0)
                        k = 0;
                        else    if (ia.i.x == 2 && ia.i.y == 2)
                        k = 0;
                        else    k = 99;
                    }
                    if (tmq.tab[ia.i.x][ia.i.y] == 2)
                    {
                        k = possible(ia.i, tmq.tab);
                        if (k == 1)
                        z = 1 ;
                    } 
                    k = 0;
                }
            ia.a.x = 1; ia.a.y = 1;
            ia.g = 2; 
    }
    else    if (tmq.tab[0][2] == tmq.tab[2][0] && tmq.tab[0][2] == 2 && tmq.tab[1][1] == 0)
    {
            while(z == 0)
                {
                    while(k == 0)
                    {
                        ia.i.x = alea_int(2); ia.i.y = alea_int(2);
                        if (ia.i.x == 0 && ia.i.y == 2)
                        k = 0;
                        else    if (ia.i.x == 2 && ia.i.y == 0)
                        k = 0;
                        else    k = 99;
                    }
                    if (tmq.tab[ia.i.x][ia.i.y] == 2)
                    {
                        k = possible(ia.i, tmq.tab);
                        if (k == 1)
                        z = 1 ;
                    } 
                }
            ia.a.x = 1; ia.a.y = 1;
            ia.g = 2;
            
    }
    else    if (tmq.tab[1][0] == tmq.tab[1][2] && tmq.tab[1][0] == 2 && tmq.tab[1][1] == 0)
    {
            while(z == 0)
                {
                    while(k == 0)
                    {
                        ia.i.x = alea_int(2); ia.i.y = alea_int(2);
                        if (ia.i.x == 1 && ia.i.y == 0)
                        k = 0;
                        else    if (ia.i.x == 1 && ia.i.y == 2)
                        k = 0;
                        else    k = 99;
                    }
                    if (tmq.tab[ia.i.x][ia.i.y] == 2)
                    {
                        k = possible(ia.i, tmq.tab);
                        if (k == 1)
                        z = 1 ;
                    } 
                }
            ia.a.x = 1; ia.a.y = 1;
            ia.g = 2;
    }
    else    if (tmq.tab[0][1] == tmq.tab[2][1] && tmq.tab[0][1] == 2 && tmq.tab[1][1] == 0)
    {
            while(z == 0)
                {
                    while(k == 0)
                    {
                        ia.i.x = alea_int(2); ia.i.y = alea_int(2);
                        if (ia.i.x == 0 && ia.i.y == 1)
                        k = 0;
                        else    if (ia.i.x == 2 && ia.i.y == 1)
                        k = 0;
                        else    k = 99;
                    }
                    if (tmq.tab[ia.i.x][ia.i.y] == 2)
                    {
                        k = possible(ia.i, tmq.tab);
                        if (k == 1)
                        z = 1 ;
                    } 
                }
            ia.a.x = 1; ia.a.y = 1;
            ia.g = 2;
    }
    else    if ((tmq.tab[0][0] == tmq.tab[0][1] && tmq.tab[0][0] == 2 && tmq.tab[0][2] == 0) && (tmq.tab[1][1] == 2 || tmq.tab[1][2] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 2;
            ia.g = 2;
            
        }
        else    if (tmq.tab[1][2] == 2)
        {
            ia.i.x = 1; ia.i.y = 2;
            ia.a.x = 0; ia.a.y = 2;
            ia.g = 2;
            
        }
      }
    else    if ((tmq.tab[0][2] == tmq.tab[0][1] && tmq.tab[0][2] == 2 && tmq.tab[0][0] == 0) && (tmq.tab[1][1] == 2 || tmq.tab[1][0] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 2;
            
        }
        else    if (tmq.tab[1][0] == 2)
        {
            ia.i.x = 1; ia.i.y = 0;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 2;
            
        }
      }
    else    if ((tmq.tab[0][0] == tmq.tab[1][0] && tmq.tab[0][0] == 2 && tmq.tab[2][0] == 0) && (tmq.tab[1][1] == 2 || tmq.tab[2][1] == 2)) 
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 2;
            
        }
        else if (tmq.tab[2][1] == 2)
        {
            ia.i.x = 2; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 2;
            
        }
      }
    else    if ((tmq.tab[1][0] == tmq.tab[2][0] && tmq.tab[1][0] == 2 && tmq.tab[0][0] == 0) && (tmq.tab[1][1] == 2 || tmq.tab[0][1] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 2;
            
        }
        else if (tmq.tab[0][1] == 2)
        {
            ia.i.x = 0; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 2;
            
        }
      }
    else    if ((tmq.tab[2][0] == tmq.tab[2][1] && tmq.tab[2][0] == 2 && tmq.tab[2][2] == 0) && (tmq.tab[1][1] == 2 || tmq.tab[1][2] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 2;
            
        }
        else if (tmq.tab[1][2] == 2)
        {
            ia.i.x = 1; ia.i.y = 2;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 2;
            
        }
      }
    if ((tmq.tab[2][2] == tmq.tab[2][1] && tmq.tab[2][2] == 2 && tmq.tab[2][0] == 0) && (tmq.tab[1][1] == 2 || tmq.tab[1][0] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 2;
            
        }
        else if (tmq.tab[1][0] == 2)
        {
            ia.i.x = 1; ia.i.y = 0;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 2;
            
        }
      }
    else    if ((tmq.tab[0][2] == tmq.tab[1][2] && tmq.tab[0][2] == 2 && tmq.tab[2][2] == 0) && (tmq.tab[1][1] == 2 || tmq.tab[2][1] == 2))
      {
        if (tmq.tab[1][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 2;
            
        }
        else if (tmq.tab[2][1] == 2)
        {
            ia.i.x = 2; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 2;
            
        }
      }
    else    if ((tmq.tab[2][2] == tmq.tab[1][1] && tmq.tab[2][2] == 2 && tmq.tab[0][0] == 0) && (tmq.tab[1][0] == 2 || tmq.tab[0][1] == 2))
      {
        if (tmq.tab[1][0] == 2)
        {
            ia.i.x = 1; ia.i.y = 0;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 2;
            
        }
        else if (tmq.tab[0][1] == 2)
        {
            ia.i.x = 1; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 0;
            ia.g = 2;
           
        }
      }
    else    if ((tmq.tab[0][0] == tmq.tab[1][1] && tmq.tab[0][0] == 2 && tmq.tab[2][2] == 0) && (tmq.tab[2][1] == 2 || tmq.tab[1][2] == 2))
      {
        if (tmq.tab[2][1] == 2)
        {
            ia.i.x = 2; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 2;
            
        }
        else if (tmq.tab[1][2] == 2)
        {
            ia.i.x = 1; ia.i.y = 2;
            ia.a.x = 2; ia.a.y = 2;
            ia.g = 2;
           
        }
      }
    else    if ((tmq.tab[1][0] == tmq.tab[1][1] && tmq.tab[1][0] == 2 && tmq.tab[1][2] == 0) && (tmq.tab[0][2] == 2 || tmq.tab[2][2] == 2))
      {
        if (tmq.tab[0][2] == 2)
        {
            ia.i.x = 0; ia.i.y = 2;
            ia.a.x = 1; ia.a.y = 2;
            ia.g = 2;
            
        }
        else if (tmq.tab[2][2] == 2)
        {
            ia.i.x = 2; ia.i.y = 2;
            ia.a.x = 1; ia.a.y = 2;
            ia.g = 2;
            
        }
      }
    else    if ((tmq.tab[1][2] == tmq.tab[1][1] && tmq.tab[1][1] == 2 && tmq.tab[1][0] == 0) && (tmq.tab[0][0] == 2 || tmq.tab[2][0] == 2))
      {
        if (tmq.tab[0][0] == 2)
        {
            ia.i.x = 0; ia.i.y = 0;
            ia.a.x = 1; ia.a.y = 0;
            ia.g = 2;
            
        }
        else if (tmq.tab[2][0] == 2)
        {
            ia.i.x = 2; ia.i.y = 0;
            ia.a.x = 1; ia.a.y = 0;
            ia.g = 2;
            
        }
      }
    else    if ((tmq.tab[0][1] == tmq.tab[1][1] && tmq.tab[1][1] == 2 && tmq.tab[2][1] == 0) && (tmq.tab[2][0] == 2 || tmq.tab[2][2] == 2))
      {
        if (tmq.tab[2][0] == 2)
        {
            ia.i.x = 2; ia.i.y = 0;
            ia.a.x = 2; ia.a.y = 1;
            ia.g = 2;
            
        }
        else if (tmq.tab[2][2] == 2)
        {
            ia.i.x = 2; ia.i.y = 2;
            ia.a.x = 2; ia.a.y = 1;
            ia.g = 2;   
        }
      }
    else    if ((tmq.tab[2][1] == tmq.tab[1][1] && tmq.tab[1][1] == 2 && tmq.tab[0][1] == 0) && (tmq.tab[0][0] == 2 || tmq.tab[0][2] == 2))
      {
        if (tmq.tab[0][0] == 2)
        {
            ia.i.x = 0; ia.i.y = 0;
            ia.a.x = 0; ia.a.y = 1;
            ia.g = 2;
            
        }
        else if (tmq.tab[0][2] == 2)
        {
            ia.i.x = 0; ia.i.y = 2;
            ia.a.x = 0; ia.a.y = 1;
            ia.g = 2;
            
        }
      }
    else    if ((tmq.tab[0][2] == tmq.tab[1][1] && tmq.tab[1][1] == 2 && tmq.tab[2][0] == 0) && (tmq.tab[1][0] == 2 || tmq.tab[2][1] == 2))
    {
        if (tmq.tab[1][0] == 2)
        {
            ia.i.x = 1; ia.i.y = 0;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 2;
            
        }
        else if (tmq.tab[2][1] == 2)
        {
            ia.i.x = 2; ia.i.y = 1;
            ia.a.x = 2; ia.a.y = 0;
            ia.g = 2;
            
        }
    }
    else    if ((tmq.tab[2][0] == tmq.tab[1][1] && tmq.tab[1][1] == 2 && tmq.tab[0][2] == 0) && (tmq.tab[0][1] == 2 || tmq.tab[1][2] == 2))
    {
        if (tmq.tab[0][1] == 2)
        {
            ia.i.x = 0; ia.i.y = 1;
            ia.a.x = 0; ia.a.y = 2;
            ia.g = 2;
            
        }
        else if (tmq.tab[1][2] == 2)
        {
            ia.i.x = 1; ia.i.y = 2;
            ia.a.x = 0; ia.a.y = 2;
            ia.g = 2;
            
        }
    }
    else 
    {
        ia.g = 0;
    }
    return ia;
}

POINT intelligence_artificielle_init(JEU tmq)
{   
    POINT p;
    int k = 0;
    if (tmq.tab[0][0] == tmq.tab[0][1] && tmq.tab[0][0] != 0 && tmq.tab[0][2] == 0)
    {
        p.x = 0; p.y = 2;
    }
    else    if (tmq.tab [0][0] == tmq.tab[0][2] && tmq.tab[0][0] != 0 && tmq.tab[0][1] == 0)
    {
        p.x = 0; p.y = 1;
    }
    else    if (tmq.tab [0][1] == tmq.tab[0][2] && tmq.tab[0][1] != 0 && tmq.tab[0][0] == 0)
    {
        p.x = 0; p.y = 0;
    }
    else    if (tmq.tab [0][0] == tmq.tab[1][0] && tmq.tab[1][0] != 0 && tmq.tab[2][0] == 0)
    {
        p.x = 2; p.y = 0;
    }
    else    if (tmq.tab [0][0] == tmq.tab[2][0] && tmq.tab[0][0] != 0 && tmq.tab[1][0] == 0)
    {
        p.x = 1; p.y = 0;
    }
    else    if (tmq.tab [1][0] == tmq.tab[2][0] && tmq.tab[1][0] != 0 && tmq.tab[0][0] == 0)
    {
        p.x = 0; p.y = 0;
    }
    else    if (tmq.tab [2][0] == tmq.tab[2][1] && tmq.tab[2][0] != 0 && tmq.tab[2][2] == 0)
    {
        p.x = 2; p.y = 2;
    }
    else    if (tmq.tab [2][0] == tmq.tab[2][2] && tmq.tab[2][0] != 0 && tmq.tab[2][1] == 0)
    {
        p.x = 2; p.y = 1;
    }
    else    if (tmq.tab [2][1] == tmq.tab[2][2] && tmq.tab[2][2] != 0 && tmq.tab[2][0] == 0)
    {
        p.x = 2; p.y = 0;
    }
    else    if (tmq.tab [0][2] == tmq.tab[1][2] && tmq.tab[0][2] != 0 && tmq.tab[2][2] == 0)
    {
        p.x = 2; p.y = 2;
    }
    else    if (tmq.tab [0][2] == tmq.tab[2][2] && tmq.tab[0][2] != 0 && tmq.tab[1][2] == 0)
    {
        p.x = 1; p.y = 2;
    }
    else    if (tmq.tab [2][2] == tmq.tab[1][2] && tmq.tab[2][2] != 0 && tmq.tab[0][2] == 0)
    {
        p.x = 0; p.y = 2;
    }
    else    if (tmq.tab [1][0] == tmq.tab[1][1] && tmq.tab[1][0] != 0 && tmq.tab[1][2] == 0)
    {
        p.x = 1; p.y = 2;
    }
    else    if (tmq.tab [1][0] == tmq.tab[1][2] && tmq.tab[1][0] != 0 && tmq.tab[1][1] == 0)
    {
        p.x = 1; p.y = 1;
    }
    else    if (tmq.tab [1][1] == tmq.tab[1][2] && tmq.tab[1][1] != 0 && tmq.tab[1][0] == 0)
    {
        p.x = 1; p.y = 0;
    }
    else    if (tmq.tab [0][1] == tmq.tab[1][1] && tmq.tab[0][1] != 0 && tmq.tab[2][1] == 0)
    {
        p.x = 2; p.y = 1;
    }
    else    if (tmq.tab [0][1] == tmq.tab[2][1] && tmq.tab[0][1] != 0 && tmq.tab[1][1] == 0)
    {
        p.x = 1; p.y = 1;
    }
    else    if (tmq.tab [1][1] == tmq.tab[2][1] && tmq.tab[1][1] != 0 && tmq.tab[0][1] == 0)
    {
        p.x = 0; p.y = 1;
    }
    else    if (tmq.tab [0][0] == tmq.tab[1][1] && tmq.tab[0][0] != 0 && tmq.tab[2][2] == 0)
    {
        p.x = 2; p.y = 2;
    }
    else    if (tmq.tab [0][0] == tmq.tab[2][2] && tmq.tab[0][0] != 0 && tmq.tab[1][1] == 0)
    {
        p.x = 1; p.y = 1;
    }
    else    if (tmq.tab [1][1] == tmq.tab[0][2] && tmq.tab[0][2] != 0 && tmq.tab[0][0] == 0)
    {
        p.x = 0; p.y = 0;
    }
    else    if (tmq.tab [0][2] == tmq.tab[1][1] && tmq.tab[0][2] != 0 && tmq.tab[2][0] == 0)
    {
        p.x = 2; p.y = 0;
    }
    else    if (tmq.tab [0][2] == tmq.tab[2][0] && tmq.tab[2][0] != 0 && tmq.tab[1][1] == 0 )
    {
        p.x = 1; p.y = 1;
    }
    else    if (tmq.tab [1][1] == tmq.tab[2][0] && tmq.tab[2][0] != 0 && tmq.tab[0][2] == 0)
    {
        p.x = 0; p.y = 2;
    }
    else
    {
        while(k == 0)
            {
                p.x = alea_int(2); p.y = alea_int(2);
                if (tmq.tab[p.x][p.y] == 0)
                {
                    affichage(p.x,p.y,tmq.aqui);
                    tmq.tab[p.x][p.y] = tmq.aqui;
                    k = 1;
                }
            }
    }
    return p;
}   
void jeu_ia()
{
init_graphics(L,H,"Plateau");

        JEU tmq;
        POINT a,b,c,d,e,f,g,h,v;
        POINT p,p1,p2;
        int i,j,u,z,k,t;
        IA ia;

        a=ij2point(0,0);
        b=ij2point(0,1);
        c=ij2point(0,2);
        d=ij2point(1,0);
        e=ij2point(1,1);
        f=ij2point(1,2);
        g=ij2point(2,0);
        h=ij2point(2,1);
        v=ij2point(2,2);

        plateau(a,b,c,d,e,f,g,h,v);
        
         for (i = 0; i < 3; i++) // initialise le tableau
    
        {
            for (j = 0; j < 3; j++)
            {
                tmq.tab[i][j] = 0;
            }
        
        }
        
        for (u = 0; u < 3; u++)
        {   
            tmq.aqui = 1;
            k = 0;
            while (k == 0)  
            
            {
                p = coord();
                if (tmq.tab[p.x][p.y] == 0)
                {
                    affichage(p.x,p.y,tmq.aqui);
                    tmq.tab[p.x][p.y] = tmq.aqui;
                    k = 1;
                }
                
            }
            attendre(1000);
            k = 0;
            tmq.aqui = 2;
            p = intelligence_artificielle_init(tmq);
            affichage(p.x, p.y, tmq.aqui);
            tmq.tab[p.x][p.y] = tmq.aqui;
            if (victoire(tmq.tab) == 1)
            exit(0);
        }
           
        tmq.aqui = 1;
        while(1)
        {
            attendre(1000);
            z = 0;
            if (tmq.aqui == 1)
            {
                while(z == 0)
                {
                    p1 = coord();
                    if (tmq.tab[p1.x][p1.y] == 1)
                    {
                        k = possible(p1, tmq.tab);
                        if (k == 1)
                        z = 1 ;
                    }  
                }
                while(z == 1)
                {
                    t = 0;
                    while(t == 0)
                    {
                        p2 = coord();
                        t = verife_deplacement(p1,p2,tmq.tab);
                    }
                    z = deplacement(p1,p2,tmq.aqui,tmq.tab);
                }
            }
            else    
            {
                ia = intelligence_artificielle_gag(tmq);
                printf("ia egale %d", ia.g);
                if (ia.g == 2)
                    {
                        deplacement(ia.i, ia.a, tmq.aqui, tmq.tab);
                    }
                else 
                    {
                        ia = intelligence_artificielle_emp(tmq);
                        printf("ia egale %d", ia.g);
                        if (ia.g == 1)
                            {
                                deplacement(ia.i, ia.a, tmq.aqui, tmq.tab);
                            }
                        else
                        {                    
                            while(z == 0)
                            {
                                p1.x = alea_int(2); p1.y = alea_int(2);
                                if (tmq.tab[p1.x][p1.y] == 2)
                                {
                                    k = possible(p1, tmq.tab);
                                    if (k == 1)
                                    z = 1 ;
                                } 
                            }
                                while(z == 1)
                            {
                                t = 0;
                                while(t == 0)
                                {
                                    p2.x = alea_int(2); p2.y = alea_int(2);
                                    t = verife_deplacement(p1,p2,tmq.tab);
                                }
                                z = deplacement(p1,p2,tmq.aqui,tmq.tab);    
                            }
                        } 
                    }
            }
            if (tmq.aqui == 1)
                tmq.aqui = 2;
            else
                tmq.aqui = 1;
                
            if (victoire(tmq.tab) == 1)
                exit(0); 
                     
        }
        
        wait_escape();
        exit(0);
}
void jeu()
{
    init_graphics(L,H,"Plateau");

        JEU tmq;
        POINT a,b,c,d,e,f,g,h,v;
        POINT p,p1,p2;
        int i,j,u,z,k,t;

        a=ij2point(0,0);
        b=ij2point(0,1);
        c=ij2point(0,2);
        d=ij2point(1,0);
        e=ij2point(1,1);
        f=ij2point(1,2);
        g=ij2point(2,0);
        h=ij2point(2,1);
        v=ij2point(2,2);

        plateau(a,b,c,d,e,f,g,h,v);
    
    for (i = 0; i < 3; i++) // initialise le tableau
    
    {
       for (j = 0; j < 3; j++)
        {
           tmq.tab[i][j] = 0;
        }
        
    }
    tmq.aqui = 1;
    for(u = 0;u < 6;u++)
    {
        k = 0;
        while (k == 0)  
        {
            p = coord();
            if (tmq.tab[p.x][p.y] == 0)
            {
                affichage(p.x,p.y,tmq.aqui);
                tmq.tab[p.x][p.y] = tmq.aqui;
                k = 1;
            }
        }       
        if (tmq.aqui == 1)
           tmq.aqui = 2 ;
        else  
           tmq.aqui = 1;
           
        if (victoire(tmq.tab) == 1)
        exit(0);
        k = 0;
    }
    
   
    for (i = 0; i < 3; i++)
    {
       for (j = 0; j < 3; j++)
        {
           printf("la case [%d][%d] a la valeure %d    ",i,j,tmq.tab[i][j]    );// affiche les valeures du tableau.
           fflush(stdout);
        }
        
    }
    
    
    while(1)
    {
        z = 0;
        if (tmq.aqui == 1)
        {
            while(z == 0)
            {
                p1 = coord();
                if (tmq.tab[p1.x][p1.y] == 1)
                {
                    k = possible(p1, tmq.tab);
                    if (k == 1)
                    z = 1 ;
                }  
            }
            while(z == 1)
            {
                t = 0;
                while(t == 0)
                {
                    p2 = coord();
                    t = verife_deplacement(p1,p2,tmq.tab);
                }
                z = deplacement(p1,p2,tmq.aqui,tmq.tab);
            }
        }
        else    
        {
           while(z == 0)
            {
                p1 = coord();
                if (tmq.tab[p1.x][p1.y] == 2)
                {
                    k = possible(p1, tmq.tab);
                    if (k == 1)
                    z = 1 ;
                } 
            }
            while(z == 1)
            {
                t = 0;
                while(t == 0)
                {
                    p2 = coord();
                    t = verife_deplacement(p1,p2,tmq.tab);
                }
                z = deplacement(p1,p2,tmq.aqui,tmq.tab);    
            }
        }
        
        if (tmq.aqui == 1)
            tmq.aqui = 2;
        else
            tmq.aqui = 1;
            
        if (victoire(tmq.tab) == 1)
            exit(0);
    }
    
    wait_escape();
	exit(0);
}
int main( int argc, char *argv[] )
    {
        init_graphics(L,H,"menu");

        POINT r1, r2 ,r3, r4,r5 ,r6, j1, j2, j3, j4,j5, j6,j7;
        
        j7.x = 81*L/192; j7.y= 127*H/192;
        j6.x = 81*L/192; j6.y= 63*H/192;
        j5.x = 49*L/192; j5.y = 175*H/192;
        j4.x = 3*L/12; j4.y = 23*H/24;
        j3.x = 3*L/12; j3.y= 11*H/12;
        j2.x = 5*L/12; j2.y= 2*H/3;
        j1.x = 5*L/12; j1.y= 4*H/12;
        r1.x = L/3; r1.y = H/6;
        r2.x = 2*L/3; r2.y = H/3;
        fill_screen(burlywood);
    
    
            draw_fill_rectangle(r1, r2,black);
   
    
            r3.x=L/3; r3.y=H/2;
            r4.x=2*L/3; r4.y=2*H/3;
    
            draw_fill_rectangle(r3,r4,black);
    
            r5.x=L/6; r5.y=5*H/6;
            r6.x=5*L/6; r6.y=9*H/10;
    
            draw_fill_rectangle(r5,r6,black);
                                

                        aff_pol("JVJ", (L+H)/22, j1, white);
                        aff_pol("JVJ", (L+H)/22, j6, bleu);
                        aff_pol("JVC", (L+H)/22, j2, white);
                        aff_pol("JVC", (L+H)/22, j7, red);
                        aff_pol("TMQ GAME", (L+H)/28, j5, gris);
                        aff_pol("TMQ GAME",  (L+H)/28, j3, white);
                        aff_pol("Manu, Quentin et Thomas presentent :", (L+H)/80, j4, black);
        POINT p;
         
            int i,j;
            int n=0;
            i=0;     j=0;
        while(n == 0)
        {
            p=wait_clic();
        
            if ( (p.x > r1.x) && (p.x < r2.x) && (p.y > r1.y) && (p.y < r2.y) )
            { 
                i++; j++;
                n=1;
            }  
  
        
        
     
           else if( (p.x > r3.x) && (p.x < r4.x) && (p.y > r3.y) && (p.y < r4.y) )
            { 
                i=i+2; j=j+2;
                n=1;
            }  
        }
           if (i==1 && j==1)
          
            {
             jeu();
            }
            if (i==2 && j==2)
      
            {
              jeu_ia();
            }
        
        
        wait_escape();
        exit(0);
    }