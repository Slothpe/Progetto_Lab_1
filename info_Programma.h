	//
// Created by Perrulli Antonio on 19/04/25.
//
#include <stdio.h>
#include "Data_set.h"
#include <stdbool.h>


typedef struct {

    bool stato_programma;
    int input_utente;
    int scena;
    bool utente_verifcato; //vero = utente esiste
    bool admin_verificato;
    UTENTE utente;
    AMMINISTRATORE admin;


}PROGRAMMA;

int Menu_Principale(void);
int Menu_Pannello_Utente(void);
void printAirPlane(void);
int Menu_Pannello_Amministratore(void);
int Menu_Home_Amministratore(void);
int Menu_Gestione_Catalogo(void);
