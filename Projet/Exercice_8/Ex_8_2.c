/*Ouvrez le dossier �graphics.h�. Vous avez d�sormais toutes les connaissances (ou presque) pour pouvoir lire les informations
dedans.
graphics.h est ce qu�on appelle un fichier d�ent�te: il ne contient pas les programmes eux m�me, mais simplement leur
noms, et, en commentaire, comment s�en servir. Il contient aussi les structures utilis�es.
Les programmes en eux m�me se trouvent dans graphics.c. Vous avez tout � fait le droit d�aller voir, mais nombre de
concepts n�ont pas �t� vus en classe...
1. Rep�rer et recopier la d�finition de la struct POINT (Attention, une astuce a �t� utilis�e ici pour raccourcir le code)
2. Existe-t-il une fonction permettant de cr�er une couleur � partir des composantes en rouge, vert et bleu?
3. Retrouver la fonction wait_clic(). Comprenez-vous ce qu�il y a d��crit?
4. A-t-on utilis� toutes les fonctions de dessin d�objet?
5. Trouver une commande qui vous permettrai d�afficher par exemple le score d�un jeu en bas a droite.
6. Existe-t-il une fonction permettant de calculer combien de temps une balle a mis entre deux rebonds? (expliquer un
peu).
Exercice 7.3 [Ma premi�re structure]
On souhaite dans la suite remplir une fenet*/
1
struct point
{
int x;
int y;
};
typedef struct point POINT;

2
struct couleur_RVB
{
int rouge;
int vert;
int bleu;
};
typedef struct couleur COULEUR;

5
void aff_int(int n, int taille, POINT p, COULEUR C);

6
void chrono_start();
float chrono_val();
/*on commence le chrono quand la balle touche un mur puis on prend la valeur du chrono 
quand la balle touche un autre mur*/