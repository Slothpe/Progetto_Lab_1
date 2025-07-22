
//
// Created by Perrulli Antonio on 26/04/25.
//

#include <stdio.h>
#include <stdbool.h>
#include "info_Programma.h"


typedef enum{

	Utente,
	Amministratore,
	Chiusura,
} SCENA;

typedef enum{

 	Scena_Chiusura_PA,
    Scena_Iscrizione_A,
    Scena_Accesso_A,
    Scena_Home_A,
	
}SCENA_AMMINISTRATORE;

typedef enum {
    // U = Utente , A = Amministratore P = Programma

    Scena_Chiusura_PU,//0
    Scena_Iscrzione_U,//1
    Scena_Accesso_U,//2
    Scena_Home_U,//3

}SCENA_UTENTE;

typedef enum{

	Gestione_Catalogo,
	Controllo_Voli,
	Prenotazioni_Utenti,
	Attivazione_Account,


}HOME_AMMINISTRATORE;

typedef enum{

	Aggiungi_volo,
	Modifica_volo,
	Cancella_volo,
	Esci,


}GESTIONE_CATALOGO;


bool Scena_Chiusura_Programma();



void Scena_Panello_Utente(PROGRAMMA*);
void Scena_Iscrizione_Utente(void);
void Scena_Accesso_Utente(PROGRAMMA*);

void Scena_Pannello_Amministratore(PROGRAMMA*);
void Scena_Iscrizione_Amministratore(void);
bool Scena_Accesso_Amministratore(PROGRAMMA*);
void Scena_Home_Amministratore(PROGRAMMA*);
void Scena_Gestione_Catalogo(void);
