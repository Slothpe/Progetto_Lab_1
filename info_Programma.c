//
// Created by Perrulli Antonio on 19/04/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "info_Programma.h"
#define SCENA_DEFAULT 20 
/*
	La constante SCENA_DEFAULT viene usata per elimnare il bug del loop causato dal inserimento 
	di un carattere (come input da tastiera) nella variabile scelta. Questo perche lo scanf già
	di suo inserisce uno 0 quando riceve come input un carattere. Il problema e causato dal fatto 
	che il numero 0 negli enum rappresenta un opzione quindi anche se si inserisce un carattere, si
	effettua comunque una sceelta. Scelta che poi entra in loop per via del '\n' della stringa prima
	dello scanf e quindi viene valutata come '0' e ricomincia il loop.

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

void printAirPlane(void) {
    printf("                             |\n");
    printf("                       --====|====--\n");
    printf("                             |\n");
    printf("                         .-''''''-.\n");
    printf("                       .'_________'.\n");
    printf("                      /_/_|__|__|_\\_\\\n");
    printf("                     ;'-._       _.-';\n");
    printf(",--------------------|    `-. .-'    |--------------------,\n");
    printf(" ``\"\"--..__    ___   ;       '       ;   ___    __..--\"\"``\n");
    printf("           `\"-// \\\\.._\\             /_..// \\\\-\"`\n");
    printf("              \\\\_//    '._       _.'    \\\\_//\n");
    printf("               `\"`        ``---``        `\"`\n");

	
}

int Menu_Pannello_Utente(void){

	int scelta = SCENA_DEFAULT;
	printf("--------MENU UTENTE----------\n");
	printf("Premi 0: uscire\n");
	printf("Premi 1: per isciriverti\n");
	printf("Premi 2: per accedere\n");
	printf("Premi 3: per la home\n");
	
	fflush(stdin);
	scanf("%d",&scelta);
	return scelta;
	
}
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

int Menu_Home_Amministratore(void) {

	int scelta = SCENA_DEFAULT;
	printf("--------MENU HOME AMMINISTRATORE----------\n");
	printf("Premi 0: per Gestione catalogo voli\n");
	printf("Premi 1: per Monitorare e modificare stato voli\n");
	printf("Premi 2: per Lista Prenotazioni Utenti\n");
	printf("Premi 3: per Attivare un account amministratore\n");
	printf("Premi 4: uscire\n");

	fflush(stdin);
	scanf("%d",&scelta);
	return scelta;
}

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

