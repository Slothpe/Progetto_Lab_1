/**
* @file scena_manager.h
 * @brief Definizione delle scene e dei flussi logici del programma FlyTwo.
 *
 * Contiene gli enum per la gestione delle scene utente e amministratore,
 * e le funzioni che gestiscono il comportamento delle interfacce interattive.
 *
 * @author Antonio Perrulli e Pietro Menandro
 * @date 26/04/25
 */

#include <stdio.h>
#include <stdbool.h>
#include "info_Programma.h"

/**
 * @brief Enum principale per la selezione del tipo di scena.
 *
 * abbiamo scena utente, scena amministratore e chiusura del programma
 */

typedef enum{

	Utente,
	Amministratore,
	Chiusura,
} SCENA;

/**
 * @brief Enum per le scene del pannello amministratore.
 *
 */

typedef enum{

 	Scena_Chiusura_PA,
    Scena_Iscrizione_A,
    Scena_Accesso_A,
    Scena_Home_A,
	
}SCENA_AMMINISTRATORE;


/**
 * @brief Enum per le scene del pannello utente.
 */


typedef enum {
   

    Scena_Chiusura_PU,
    Scena_Iscrzione_U,
    Scena_Accesso_U,
    Scena_Home_U,
	Password_Dimenticata_U,

}SCENA_UTENTE;

/**
 * @brief Enum per le opzioni della home amministratore.
 */

typedef enum{

	Gestione_Catalogo,
	Controllo_Voli,
	Prenotazioni_Utenti,
	Attivazione_Account,
	Gestione_Notifiche_Voli,


}HOME_AMMINISTRATORE;


/**
 * @brief Enum per le opzioni di gestione del catalogo voli.
 */

typedef enum{

	Aggiungi_volo,
	Modifica_volo,
	Cancella_volo,
	Esci,


}GESTIONE_CATALOGO;

/**
 * @brief Enum per le opzioni della home utente.
 */

typedef enum {

	Esci_U, //chiusura home utente
	Gestisci_Biglietti,
	Gestisci_segnalazioni,

}HOME_UTENTE;

/**
 * @brief Enum per le opzioni di gestione prenotazioni.
 */

typedef enum{

	Indietro_Biglietto,
	Modifica_Biglietto,
	Canecella_Biglietto,
	Acquista_Biglietto,
	Visualizza_Prenotazioni,
	Check_In,

}GESTIONE_PRENOTAZIONI;

/**
 * @brief Gestisce la chiusura del programma.
 *
 * @return true se il programma deve essere chiuso.
 */

bool Scena_Chiusura_Programma();


//SCENE UETENTE
/**
 * @brief Avvia il pannello utente.
 *
 * @param p Puntatore alla struttura PROGRAMMA.
 */
void Scena_Panello_Utente(PROGRAMMA*);

/**
 * @brief Gestisce l'iscrizione di un nuovo utente.
 */
void Scena_Iscrizione_Utente(void);

/**
 * @brief Gestisce l'accesso utente.
 *
 * @param p Puntatore alla struttura PROGRAMMA.
 */
void Scena_Accesso_Utente(PROGRAMMA*);

/**
 * @brief Gestisce l'accesso alla schermata home del utente.
 *
 * @param p Puntatore alla struttura PROGRAMMA.
 */
void Scena_Home_Utente(PROGRAMMA*);

/**
 * @brief Gestisce la visualizzazione e modifica dei biglietti utente.
 *
 * @param u Struttura UTENTE da elaborare.
 * @return UTENTE aggiornato.
 */
UTENTE Scena_Gestione_Biglietti(UTENTE);


/**
 * @brief Gestisce l'acquisto di un nuovo biglietto.
 *
 * @param u Struttura UTENTE da aggiornare.
 * @return UTENTE aggiornato.
 */
UTENTE Scena_Acquista_Biglietto(UTENTE);

/**
 * @brief Cancella un biglietto associato all'utente.
 *
 * @param u Utente attivo.
 * @param utenti Array di utenti.
 * @param voli Array di voli.
 * @param num_utenti Numero totale di utenti.
 * @param num_voli Numero totale di voli.
 * @return UTENTE aggiornato.
 */
UTENTE Scena_Cancella_Biglietto(UTENTE, UTENTE [], VOLO [], int,int);

/** @brief Funzione che gestisce la scena per effettuare il check-in da
 * parte del utente.
 * 
 * @param uetenti Lista di tutti gli utenti iscritti
 * @param numero_utenti Numero di tutti gli utenti iscritti
 * @param utente_log L'utente loggato che sta eseguendo il programma
 * 
 */
UTENTE Scena_Check_in(UTENTE [],int, UTENTE);

/** @brief Funzione che serve per gestire la scena in cui un utente
 * puo modificare i dati del proprio biglietto di volo
 * 
 * @param utenti_salvati Lista degli utenti salvati
 * @param numero_utenti Rappresenta il numero di utenti che sono iscritti al programma
 * @param utente_log Utente che è loggato e quindi sta utilizzando il programma
 * @param voli_salvati Lista di tutti i voli esistenti
 * @param numero_voli Numero di tutti i voli che sono salvati
 */
UTENTE Scena_Modifica_Biglietto(UTENTE[], int, UTENTE, VOLO [], int);

/** @brief Funzione che serve per gestire la scena in cui un utente
 * puo visualizzare e gestire tutte le notfiche associate ai suoi biglietti
 * 
 * @param utente_log Utente loggato e che quindi sta usando il programma
 */
void Scena__Gestisci_Segnalazioni(UTENTE);

/** @brief Funzione che gestisce la scena in cui l'utente ha smarrito la password
 * 
 * Per poter recuperare la password, bisogna sapere il numero del proprio documento
 * 
 */
void Scena_Password_Dimenticata(void);

//SCENE AMMINISTRATORE

/**
 * @brief Avvia il pannello amministratore.
 *
 * @param p Puntatore alla struttura PROGRAMMA.
 */
void Scena_Pannello_Amministratore(PROGRAMMA*);

/**
 * @brief Gestisce l'iscrizione di un nuovo amministratore.
 */
void Scena_Iscrizione_Amministratore(void);

/**
 * @brief Gestisce l'accesso amministratore.
 *
 * @param p Puntatore alla struttura PROGRAMMA.
 * @return true se l'accesso è riuscito.
 */
bool Scena_Accesso_Amministratore(PROGRAMMA*);

/**
 * @brief Visualizza la home amministratore.
 *
 * @param p Puntatore alla struttura PROGRAMMA.
 */
void Scena_Home_Amministratore(PROGRAMMA*);

/**
 * @brief Gestisce il catalogo voli.
 */
void Scena_Gestione_Catalogo(void);

/**
 * @brief Funzione che serve per gestrire la scena che mostra
 * lo stato dei voli esistenti
 */
void Scena_Controllo_Voli(void);

/**
 * @brief Funzione che serve per gestire la scena per visualizzare
 * e gestire lo stato di prenotazione dei voli da parte degli utenti
 * 
 * @param Voli_salvati Lista di tutti i voli esistenti
 * @param numero_voli Numero di tutti voli salvati	
 */
void Scena_Stato_Prenotazioni_Utenti(VOLO [], int);

/** @brief Funzione che serve per gestire la scena in cui un utente
 * amministartore puo visualizzare, cancellare e aggiungere delle notifiche
 * ed associarle ad un volo
 * 
 */
void Scena_Gestione_Notifiche_Voli(void);

/** @brief Funzione che serve per gestire l'attivazione di un nuovo
 * account amministratore. Per l'attivazione bisgona inserire l'id associato
 * all utente. 
 */
void Scena_Attivazione_Account_Amministratore(void);