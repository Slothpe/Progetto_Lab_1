//
// Created by Perrulli Antonio on 19/04/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "info_Programma.h"


int Menu_Principale(void) {

    int scelta;

    printf("--------MENU PRINCIPALE----------\n");
    printf("Premi 0: Per Pannello Utente\n");
    printf("Premi 1: Per Pannello Amministratore\n");
    printf("Premi 2: per chiudere il programma\n");

    scanf("%d",&scelta);

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

	int scelta;
	printf("--------MENU UTENTE----------\n");
	printf("Premi 0: uscire\n");
	printf("Premi 1: per isciriverti\n");
	printf("Premi 2: per accedere\n");
	printf("Premi 3: per la home\n");
	
	scanf("%d",&scelta);
	return scelta;
	
}
int Menu_Pannello_Amministratore(void){

	
	int scelta;
	printf("--------MENU AMMINISTRATORE----------\n");
	printf("Premi 0: uscire\n");
	printf("Premi 1: per isciriverti\n");
	printf("Premi 2: per accedere\n");
	printf("Premi 3: per la home amminstrazione\n");
	
	scanf("%d",&scelta);
	return scelta;
	
}

int Menu_Home_Amministratore(void) {

	int scelta = 0;
	printf("--------MENU HOME AMMINISTRATORE----------\n");
	printf("Premi 0: per Gestione catalogo voli\n");
	printf("Premi 1: per Monitorare e modificare stato voli\n");
	printf("Premi 2: per Lista Prenotazioni Utenti\n");
	printf("Premi 3: per Attivare un account amministratore\n");
	printf("Premi 4: uscire\n");
	scanf("%d",&scelta);
	return scelta;
}

int Menu_Gestione_Catalogo(void) {

	int scelta = 0;
	printf("--------MENU GESTIONE CATALOGO----------\n");
	printf("Premi 0: per aggiungere un volo\n");
	printf("Premi 1: per modificare un volo\n");
	printf("Premi 2: cancellare un volo\n");
	printf("Premi 3: uscire\n");
	scanf("%d",&scelta);
	return scelta;
}

