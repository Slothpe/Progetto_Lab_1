/**
 * @file info_programma.h
 * @brief Dichiarazioni delle funzioni che gestiscono i menu e lo stato del programma FlyTwo.
 *
 * Fornisce le interfacce per il flusso delle scene, i pannelli utente e amministratore,
 * e per la stampa grafica iniziale. Include la costante SCENA_DEFAULT per prevenire
 * bug da input errati.
 *
 * @author Antonio Perrulli e Pietro Menandro
 * @date 19/04/25
 */
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

/**
 * @brief Visualizza il menu principale e ritorna la scelta dell'utente.
 *
 * Consente di accedere al pannello utente, pannello amministratore o uscire dal programma.
 *
 * @return Valore numerico corrispondente alla scena selezionata.
 */
int Menu_Principale(void);

/**
 * @brief Visualizza il pannello per l'utente non autenticato.
 *
 * Permette operazioni come iscrizione, accesso e accesso alla home utente.
 *
 * @return Valore numerico che rappresenta la scelta dell’utente.
 */
int Menu_Pannello_Utente(void);

/**
 * @brief Visualizza un aereo grafico ASCII come messaggio di benvenuto.
 *
 * Estetica introduttiva per il progetto FlyTwo.
 */
void printAirPlane(void);

/**
 * @brief Visualizza il pannello per l’amministratore non autenticato.
 *
 * Offre accesso alle funzioni di login e gestione area amministratore.
 *
 * @return Valore numerico che rappresenta la scelta dell’amministratore.
 */
int Menu_Pannello_Amministratore(void);

/**
 * @brief Mostra la home riservata all’amministratore autenticato.
 *
 * Offre accesso al catalogo voli, stato voli, prenotazioni e attivazione account.
 *
 * @return Scelta effettuata come valore intero.
 */
int Menu_Home_Amministratore(void);


/**
 * @brief Menu per la gestione del catalogo voli da parte dell’amministratore.
 *
 * Permette di aggiungere, modificare o eliminare voli.
 *
 * @return Intero che rappresenta l'operazione scelta.
 */
int Menu_Gestione_Catalogo(void);

/**
 * @brief Mostra la home utente con tutte le funzionalità disponibili.
 *
 * Include accesso a check-in, profilo, segnalazioni e visualizzazione biglietti.
 *
 * @return Intero che rappresenta la scena selezionata.
 */
int Menu_Home_Utente(void);

/**
 * @brief Mostra tutte le operazioni che si possono fare sui biglietti.
 * 
 * Include Modifica_Biglietti, Cancella_Biglietti, Acquista_Biglietti, Check_In
 */
int Menu_Gestione_Biglietti(void);