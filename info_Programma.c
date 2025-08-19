/**
 * @file info_programma.c
 * @brief Implementazione dei menu e interfaccia del programma FlyTwo.
 *
 * Questo file gestisce i menu principali e le schermate interattive del sistema,
 * per utenti e amministratori. Contiene funzioni che restituiscono una scelta
 * numerica da parte dell'utente.
 *
 * @author Antonio Perrulli e Pietro Menandro
 * @date 19/04/25
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "info_Programma.h"

/**
 * @def SCENA_DEFAULT
 * 
 * @brief Macro per soluzione bug input.
 * 
 * 	La constante SCENA_DEFAULT viene usata per elimnare il bug del loop causato dal inserimento 
	di un carattere (come input da tastiera) nella variabile scelta. Questo perche lo scanf già
	di suo inserisce uno 0 quando riceve come input un carattere. Il problema e causato dal fatto 
	che il numero 0 negli enum rappresenta un opzione quindi anche se si inserisce un carattere, si
	effettua comunque una sceelta. Scelta che poi entra in loop per via del '\n' della stringa prima
	dello scanf e quindi viene valutata come '0' e ricomincia il loop.
 */

#define SCENA_DEFAULT 20 


 /**
  * @brief Visualizza il menu principale del programma FlyTwo.
  *
  * Consente di scegliere tra pannello utente, amministratore o uscita.
  * @return Valore intero della scelta effettuata.
  */
int Menu_Principale(void) {

    int scelta = SCENA_DEFAULT;

    printf("--------MENU PRINCIPALE----------\n");
    printf("Premi 0: Per Pannello Utente\n");
    printf("Premi 1: Per Pannello Amministratore\n");
    printf("Premi 2: per chiudere il programma\n");

	fflush(stdin);
    scanf("%d",&scelta);
	//printf("Scena dopo input: %d\n",scelta);

    return scelta;
}

/**
 * @brief Stampa il disegno ASCII di un aeroplano e messaggio di benvenuto.
 */
void printAirPlane(void) {
    printf("\n");
    printf("                             |\n");
    printf("                       --====|====--\n");
    printf("                             |\n");
    printf("                         .-''''''-.\n");
    printf("                       .'_________'.         FLYTWO\n");
    printf("                      /_/_|__|__|_\\_\\        Sistema Voli\n");
    printf("                     ;'-._       _.-';\n");
    printf(",--------------------|    `-. .-'    |--------------------,\n");
    printf(" ``\"\"--..__    ___   ;       '       ;   ___    __..--\"\"``\n");
    printf("           `\"-// \\\\.._\\             /_..// \\\\-\"`\n");
    printf("              \\\\_//    '._       _.'    \\\\_//\n");
    printf("               `\"`        ``---``        `\"`\n");

    printf("               Benvenuto nel progetto FlyTwo! \n");
    printf("------------------------------------------------------------\n\n");
}

/**
 * @brief Menu per utenti non autenticati.
 *
 * Opzioni: iscrizione, accesso, home, uscita.
 * @return Intero che rappresenta l'opzione selezionata.
 */
int Menu_Pannello_Utente(void){

	int scelta = SCENA_DEFAULT;
	printf("--------MENU UTENTE----------\n");
	printf("Premi 0: uscire\n");
	printf("Premi 1: per iscriverti\n");
	printf("Premi 2: per accedere\n");
	printf("Premi 3: per accedere alla home\n");
	
	
	fflush(stdin);
	scanf("%d",&scelta);
	return scelta;
	
}

/**
 * @brief Menu per amministratori non autenticati.
 *
 * Opzioni: iscrizione, accesso, home, uscita.
 * @return Valore intero della scelta effettuata.
 */
int Menu_Pannello_Amministratore(void){

	
	int scelta = SCENA_DEFAULT;
	printf("--------MENU AMMINISTRATORE----------\n");
	printf("Premi 0: uscire\n");
	printf("Premi 1: per isciriverti\n");
	printf("Premi 2: per accedere\n");
	printf("Premi 3: per la home amminstrazione\n");
	
	fflush(stdin);
	scanf("%d",&scelta);
	return scelta;
	
}

/**
 * @brief Menu home per amministratori autenticati.
 *
 * Opzioni: gestione voli, monitoraggio stato, prenotazioni utenti, attivazione account.
 * @return Intero che rappresenta l’opzione scelta.
 */
int Menu_Home_Amministratore(void) {

	int scelta = SCENA_DEFAULT;
	printf("--------MENU HOME AMMINISTRATORE----------\n");
	printf("Premi 0: per Gestione catalogo voli\n");
	printf("Premi 1: per Controllare stato voli\n");
	printf("Premi 2: per Lista Prenotazioni Utenti\n");
	printf("Premi 3: per Attivare un account amministratore\n");
	printf("Premi 4: uscire\n");

	fflush(stdin);
	scanf("%d",&scelta);
	return scelta;
}


/**
 * @brief Menu per la gestione del catalogo voli.
 *
 * Azioni disponibili: aggiunta, modifica, cancellazione voli.
 * @return Intero corrispondente alla scelta effettuata.
 */
int Menu_Gestione_Catalogo(void) {

	int scelta = SCENA_DEFAULT;

	printf("--------MENU GESTIONE CATALOGO----------\n");
	printf("Premi 0: per aggiungere un volo\n");
	printf("Premi 1: per modificare un volo\n");
	printf("Premi 2: cancellare un volo\n");
	printf("Premi 3: uscire\n");

	fflush(stdin);
	scanf("%d",&scelta);
	return scelta;
}

/**
 * @brief Menu home per utenti autenticati.
 *
 * Consente di accedere a funzionalità personali e di viaggio.
 * @return Intero corrispondente all’opzione selezionata.
 */
int Menu_Home_Utente(void) {
	
	int scelta = SCENA_DEFAULT;

	printf("\n--------- HOME UTENTE ---------\n");
	printf("Premi 0: Torna indietro\n");
	printf("Premi 1: Gestire i biglietti\n"); //Acquista biglietto
	printf("Premi 2: Gestire le segnalazioni\n");

	fflush(stdin);
	scanf("%d", &scelta);
	return scelta;
}

/**
 * @brief Menu che mostra le operazioni che si possono fare sui biglietti.
 * 
 * Le operazioni che consente di fare sono le classiche, cancellazione, acquisto,
 * acquisto e check-in di un biglietto.
 * 
 * @return Un intero che rappresenta la scelta selezionata
 */
int Menu_Gestione_Biglietti(void)
{
	int scelta = SCENA_DEFAULT;

	printf("\n--------- HOME UTENTE ---------\n");
	printf("Premi 0: Torna indietro\n");
	printf("Premi 1: Modificare i biglietti\n"); //Acquista biglietto
	printf("Premi 2: Cancellare i biglietti\n");
	printf("Premi 3: Acquistare i biglietti\n");
	printf("Premi 4: Per visualizzare tutte le prenotazioni\n");
	printf("Premi 5: Check_In\n");

	fflush(stdin);
	scanf("%d", &scelta);
	return scelta;

}