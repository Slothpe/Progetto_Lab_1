
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
   

    Scena_Chiusura_PU,
    Scena_Iscrzione_U,
    Scena_Accesso_U,
    Scena_Home_U,
	Password_Dimenticata_U,

}SCENA_UTENTE;

typedef enum{

	Gestione_Catalogo,
	Controllo_Voli,
	Prenotazioni_Utenti,
	Attivazione_Account,
	Gestione_Notifiche_Voli,


}HOME_AMMINISTRATORE;

typedef enum{

	Aggiungi_volo,
	Modifica_volo,
	Cancella_volo,
	Esci,


}GESTIONE_CATALOGO;

typedef enum {

	Esci_U, //chiusura home utente
	Gestisci_Biglietti,
	Gestisci_segnalazioni,

}HOME_UTENTE;

typedef enum{

	Indietro_Biglietto,
	Modifica_Biglietto,
	Canecella_Biglietto,
	Acquista_Biglietto,
	Visualizza_Prenotazioni,
	Check_In,

}GESTIONE_PRENOTAZIONI;

bool Scena_Chiusura_Programma();


//SCENE UETENTE
void Scena_Panello_Utente(PROGRAMMA*);
void Scena_Iscrizione_Utente(void);
void Scena_Accesso_Utente(PROGRAMMA*);
void Scena_Home_Utente(PROGRAMMA*);
UTENTE Scena_Gestione_Biglietti(UTENTE);
UTENTE Scena_Acquista_Biglietto(UTENTE);
UTENTE Scena_Cancella_Biglietto(UTENTE, UTENTE [], VOLO [], int,int);
UTENTE Scena_Check_in(UTENTE [],int, UTENTE);
UTENTE Scena_Modifica_Biglietto(UTENTE[], int, UTENTE, VOLO [], int);
void Scena__Gestisci_Segnalazioni(UTENTE);
void Scena_Password_Dimenticata(void);

//SCENE AMMINISTRATORE
void Scena_Pannello_Amministratore(PROGRAMMA*);
void Scena_Iscrizione_Amministratore(void);
bool Scena_Accesso_Amministratore(PROGRAMMA*);
void Scena_Home_Amministratore(PROGRAMMA*);
void Scena_Gestione_Catalogo(void);
void Scena_Controllo_Voli(void);
void Scena_Stato_Prenotazioni_Utenti(VOLO [], int);
void Scena_Gestione_Notifiche_Voli(void);
void Scena_Attivazione_Account_Amministratore(void);