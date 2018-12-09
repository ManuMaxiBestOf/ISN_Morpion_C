#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

int main(int argc, char** argv)
{
    
    
    init_reseau();
    char * message_recu;
    char message_a_envoyer[_TAILLE_RESEAU_TRANSFERT_];

    printf("CLIENT\n---------\n");
      
    while(!connexion_client_serveur("127.0.0.1",1234)) //en attente d'une connexion...
    {
        ;   //on ne fait rien.
    }
    
    
    printf("Connexion avec le serveur etablie. \nAdresse du serveur: %s, port du serveur: %d \n"
        , ip_du_client(), port_du_client());
    
    //Le protocole choisi marche ainsi: le serveur envoie le premier message, puis c'est chacun a son tour.
    while(1)
    {
        message_recu = lire_message(); 
        printf("Serveur dit: %s\n Vous:",message_recu);
        gets(message_a_envoyer);
        envoyer_message(message_a_envoyer);
    }
    
    
    fin_reseau();
    
    return 0;
}