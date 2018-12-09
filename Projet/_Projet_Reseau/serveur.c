#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

int main(int argc, char** argv)
{
    char * message_recu;
    char message_a_envoyer[_TAILLE_RESEAU_TRANSFERT_];
    
    
    init_reseau();
    printf("SERVEUR\n---------\n");
    
    ouvrir_serveur(1234);
    while(!serveur_accepte_client())    //en attente d'une connexion sur ce serveur...
    {
        ;      //on ne fait rien.
    }
    
    
    printf("Connexion avec un client etablie!\nAdresse ip du client: %s, port choisi par le client: %d\n",
        ip_du_client(), port_du_client());
    
    //Le protocole choisi marche ainsi: le serveur envoie le premier message de bienvenue, puis c'est chacun a son tour.
    envoyer_message("Bienvenue. Entrez votre premier message.\n");
    
    while(1)
    {
        message_recu = lire_message();
        printf("Client dit: %s\nVous:",message_recu);
        gets(message_a_envoyer);
        envoyer_message(message_a_envoyer);
    }
    
    serveur_ferme_client();
    fin_reseau();
    
    return 0;
}