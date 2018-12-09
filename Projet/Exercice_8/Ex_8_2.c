/*Ouvrez le dossier “graphics.h”. Vous avez désormais toutes les connaissances (ou presque) pour pouvoir lire les informations
dedans.
graphics.h est ce qu’on appelle un fichier d’entête: il ne contient pas les programmes eux même, mais simplement leur
noms, et, en commentaire, comment s’en servir. Il contient aussi les structures utilisées.
Les programmes en eux même se trouvent dans graphics.c. Vous avez tout à fait le droit d’aller voir, mais nombre de
concepts n’ont pas été vus en classe...
1. Repérer et recopier la définition de la struct POINT (Attention, une astuce a été utilisée ici pour raccourcir le code)
2. Existe-t-il une fonction permettant de créer une couleur à partir des composantes en rouge, vert et bleu?
3. Retrouver la fonction wait_clic(). Comprenez-vous ce qu’il y a d’écrit?
4. A-t-on utilisé toutes les fonctions de dessin d’objet?
5. Trouver une commande qui vous permettrai d’afficher par exemple le score d’un jeu en bas a droite.
6. Existe-t-il une fonction permettant de calculer combien de temps une balle a mis entre deux rebonds? (expliquer un
peu).
Exercice 7.3 [Ma première structure]
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