
//
// Created by Perrulli Antonio on 26/04/25.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "Scena_menager.h"

void Scena_Panello_Utente(PROGRAMMA* programma){

	int scena;
	PROGRAMMA temp = *programma;

	do
	{
		scena = Menu_Pannello_Utente();
		
		switch(scena){

			case Scena_Iscrzione_U:
			
			Scena_Iscrizione_Utente();
			
			break;

			case Scena_Accesso_U:
			
			Scena_Accesso_Utente(&temp);
			
			break;

			case Scena_Chiusura_PU:
			
			printf("Chiusura Pannello Utente\n");
			
			break;
			
			default:

			printf("Scelta sbagliata\n");	
			
			break;
		}
	}while(scena != Scena_Chiusura_PU);
	*programma = temp;
}

void Scena_Pannello_Amministratore(PROGRAMMA* programma){


	int scena;
	PROGRAMMA temp = *programma;


	do
	{
		scena = Menu_Pannello_Amministratore();
		
		switch(scena){

			case Scena_Iscrizione_A:
			
			Scena_Iscrizione_Amministratore();
			
			break;

			case Scena_Accesso_A:
			
			Scena_Accesso_Amministratore(&temp);
			
			break;

			case Scena_Home_A:

				Scena_Home_Amministratore(&temp);

				break;


			case Scena_Chiusura_PA:
			
			printf("Chiusura Pannello Amministratore\n");
			
			break;
			
			default:

			printf("Scelta sbagliata\n");	
			
			break;
		}
	}while(scena != Scena_Chiusura_PU);
	*programma = temp;
}

void Scena_Iscrizione_Utente(void) {

    bool utente_esistenete = false;
    UTENTE temp;

    temp = Iscrizione_Utente();

    printf("Verifico se l'utente esiste gia\n");
    utente_esistenete = Trova_Utente(temp);

    if (utente_esistenete == true) {

        printf("Utente già esistente, fai l'accesso\n");
    }else {
        Inserisci_Utente(temp);
    }
}

bool Scena_Chiusura_Programma() {

    printf("Arrivederci!\n");
    
    return false;

}

void Scena_Accesso_Utente(PROGRAMMA* programma) {

    bool utente_trovato = false;
    UTENTE temp;

    temp = Accesso_Utente(&utente_trovato);
    if (utente_trovato == true) {
        printf("Benvenuto: %s, %s\n",temp.nome,temp.cognome);
    }else {

        printf("Utente non trovato\n");
        printf("Ritenta l'accesso oopure iscriviti se ancora non lo hai fatto \n");

    }

    programma->utente = temp;
    programma->utente_verifcato = utente_trovato;
}

void Scena_Iscrizione_Amministratore(void)
{
	bool stato = false;
	AMMINISTRATORE temp;

	temp = Iscrizione_Amministratore();

	printf("Verifico se l'amministratore esiste già\n");

	stato = Trova_Admin(temp);

	if(stato == true){
	
		printf("Questo account amminsitratore esiste già\n");
	}else{

		Inserici_Admin(temp);
		printf("Salvo l'account amministratore\n");

	}

}

bool Scena_Accesso_Amministratore(PROGRAMMA* programma){

	AMMINISTRATORE temp;
	bool stato = false;

	temp  =  accesso_Amministratore(&stato);

	if(stato == true)
	{
		printf("Bevenuto admin: %s %s\n",temp.nome, temp.cognome);
		programma->admin = temp;

	}else
	{
		printf("Account non trovato riprova o fai l'accesso!\n");
	}


	return stato;
	
}

void Scena_Home_Amministratore(PROGRAMMA* programma) {

	int scelta = 0 ;
	PROGRAMMA temp = *programma;

	do{
		if (temp.admin.account_sbloccato == false) {
			printf("Il tuo account ancora non è stato accetato, (attendi che un tuo superiore lo faccia)\n");
			scelta = 0;
		}else {
			scelta = Menu_Home_Amministratore();
			switch (scelta) {

				case Gestione_Catalogo:

					Scena_Gestione_Catalogo();
					
				
				break;

				case Controllo_Voli:
					/*
					 *1) Monitoraggio voli (Ricerca per data luogo di partenza e arrivo)
					 *		Deve dire quanti posti sono disponibili,la disponibiltià residua
					 *		ed eventuali cancellazioni
					 *		ATTENZIONE: forse per fare questa parte bisogna fare la home utente
					 */
					break;

				case Prenotazioni_Utenti:
					/*
					 *1) Vedere le prenotazioni del utente (ricerca per data, ora e stato)
					 *	Stati Biglietto: Confermato, in attesa, cancellato
					 *
					 */
					break;
				default:
					printf("Scelta Sbagliata\n");
					break;
			}
		}
		
	}while (scelta != 0);
}


void Scena_Gestione_Catalogo(void){

	char Id_input [MAX_ID];
	int Numero_voli = Conta_Elementi(FILE_NAME_FLY);
	VOLO Voli_Salvati[Numero_voli];
	VOLO Lista_Aggiornata [Numero_voli-1]; // Array per cancellare un volo
	FILE *ptr_file = fopen(FILE_NAME_FLY,"rb");
	int indice = 0;
	VOLO temp;


	//devo salvare i voli nel array voli_salvati
	while (fread(&Voli_Salvati[indice],sizeof(VOLO),1,ptr_file))
	{
		indice ++;
	}
	fclose(ptr_file);

	indice = 0;

	int scelta = SCENA_DEFAULT;
	

	while(scelta != 3){

		scelta = Menu_Gestione_Catalogo();

	switch(scelta)
	{
		
		case Aggiungi_volo:
			
			
			temp = Crea_Volo();
			Salva_volo(temp);

		break;

		case Modifica_volo:

			Stampa_Voli(Voli_Salvati);
			
			printf("Inserisci l'id del volo da modificare; ");
			scanf("%s",Id_input);

			Cambia_Volo(Id_input,Voli_Salvati,Numero_voli);
		

		break;

		case Cancella_volo:

			printf("Inserisci l'id del volo da cancellare; ");
			scanf("%s",Id_input);

			

			indice = 0;

			for (int i = 0; i < Numero_voli; i++)
			{
				if (strcmp(Id_input,Voli_Salvati[i].Id_Volo) != 0)
				{
					Lista_Aggiornata[indice] = Voli_Salvati[i];
					indice++;
				}
				
			}

			Aggiorna_File(&Lista_Aggiornata[0],&Lista_Aggiornata[indice],FILE_NAME_FLY);
			printf("Volo Cancellato\n");
			
		
		
		break;



		default:
			
		
		break;
	}
}
	

	
}
