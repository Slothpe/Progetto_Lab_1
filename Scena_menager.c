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

			case Scena_Chiusura_PU:

			printf("Chiusura Pannello Utente\n");
			
			break;

			case Scena_Iscrzione_U:
			
			Scena_Iscrizione_Utente();	
			
			break;
			
			case Scena_Accesso_U:

			Scena_Accesso_Utente(&temp);
			
			break;
			
			case Scena_Home_U:

			Scena_Home_Utente(&temp);

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

void Scena_Home_Utente(PROGRAMMA* programma)
{
	PROGRAMMA temp = *programma;
	int scena = SCENA_DEFAULT;
	
	if (temp.utente_verifcato == false)
	{
		printf("Prima di poter accedere alla home, devi iscriverti oppure fare l'accesso\n");
	}else
	{	
		do
		{	
			scena = Menu_Home_Utente();

			switch (scena)
			{
			case Esci_U:
				printf("Chiusura del pannello\n");
				break;

			case Gestisci_Biglietti:
				
				temp.utente = Scena_Gestione_Biglietti(temp.utente);
				break;

			case Gestisci_segnalazioni:
				/* code */
				break;
			
			case Gestisci_Profilo:
				/* code */
				break;


			default:
				break;
			}

			/* code */
		} while (scena!= Esci_U);
		
		

	}
}
	
UTENTE Scena_Gestione_Biglietti(UTENTE user)
{
	FILE* file_Utente = fopen(FILE_NAME_USER,"rb");
	FILE* file_Voli = fopen(FILE_NAME_FLY,"rb");
	int numero_voli = Conta_Elementi(FILE_NAME_FLY);
	int numero_utenti = Conta_Elementi(FILE_NAME_USER);
	VOLO voli_salvati[numero_voli];
	UTENTE utenti_salvati [numero_utenti];
	int indice = 0;
	int scena = SCENA_DEFAULT;

	while (fread(&voli_salvati[indice],sizeof(VOLO),1,file_Voli) != 0)
	{
		indice ++;
	}
	
	indice = 0;

	while (fread(&utenti_salvati[indice],sizeof(UTENTE),1,file_Utente)!= 0)
	{
		indice ++;
	}
	

	do
	{
		scena = Menu_Gestione_Biglietti();

		switch (scena)
		{

		case Modifica_Biglietto:
		user = Scena_Modifica_Biglietto(utenti_salvati,numero_utenti,user,voli_salvati,numero_voli);

		break;


		case Indietro_Biglietto:
			printf("Chiusura del menù\n");
			break;
		

		case Canecella_Biglietto:

			user = Scena_Cancella_Biglietto(user,utenti_salvati,voli_salvati,numero_voli,numero_utenti);
		break;


		case Acquista_Biglietto:
			
			user = Scena_Acquista_Biglietto(user);
			break;
		


		case Check_In:
			user = Scena_Check_in(utenti_salvati,numero_utenti,user);
			break;
		
		default:
			break;
		}

		
	} while (scena != Indietro_Biglietto);
	
	return user;
}

UTENTE Scena_Acquista_Biglietto(UTENTE user)
{
	
	int numero_voli = Conta_Elementi(FILE_NAME_FLY); //Numero di voli salvati nel file
	int numero_utenti = Conta_Elementi(FILE_NAME_USER); //Numero di utenti isciritti al programma	int indice = 0; //indice per riempire l'array
	UTENTE utenti[numero_utenti]; //Array che contiene tutti gli utenti salvati nel file
	VOLO voli[numero_voli];//Array che contiene tutti i voli salvati nel file 
	FILE *ptr_file = fopen(FILE_NAME_FLY,"rb");
	FILE *ptr_file2 = fopen(FILE_NAME_USER,"rb");
	int indice = 0;


	//Associazione al array gli utenti salvati nel file
	while (fread(&utenti[indice],sizeof(UTENTE),1,ptr_file2) != 0)
	{
		indice ++;
	}
	
	fclose(ptr_file2);
	indice = 0;

	//Associazione al array dei voli salvati nel file
		while (fread(&voli[indice],sizeof(VOLO),1,ptr_file) != 0)
	{
		indice ++;
	}

	fclose(ptr_file);
	indice = 0;

	BIGLIETTO ticket; 
	char Id_Volo [MAX_ID];
	int numero_posto = 0;
	int scelta = SCENA_DEFAULT;
	int classe = SCENA_DEFAULT;
	ticket.Check_in = false;
	bool associato = false;

	
	Trova_Volo();

	printf("-------------------------------------\n");
	while (scelta!= 0)
	{
		printf("Inserisci 0 per uscire\n");
		printf("Inserisci 1 per Acquistare il biglietto\n");
		fflush(stdin);
		scanf("%d",&scelta);
		
		switch (scelta)
		{
		case 0:

			printf("Chiusura della sezione Acquisto biglietto\n");

			break;
		
		case 1:

			printf("Inserisci l'Id del volo di cui si vuole acquistare un biglietto\n");
			fflush(stdin);
			scanf("%s",Id_Volo);

				for (int  i = 0; i < numero_voli; i++)
				{
				
				if (strcmp(voli[i].Id_Volo,Id_Volo) == 0 && (voli[i].posti_economy + voli[i].posti_prima_classe + voli[i].posti_business) > 0)
				{
					printf("Procedo al acquisto del biglietto\n");
					strcpy(ticket.nome,user.nome);
					strcpy(ticket.cognome,user.cognome);
					ticket.volo = voli[i];
					printf("Inserisci la classe del biglietto\n");
					while(classe != 1 && classe != 2 && classe != 3)
					{
						printf("Premi 1 per la prima classe\n");
						printf("Premi 2 per la bussines\n");
						printf("Premi 3 per l' economy\n");

						scanf("%d",&classe);

						switch (classe)
						{
						case 1:
							
							printf("Hai scelto la prima classe\n");
							if (voli[i].posti_prima_classe > 0)
							{
								strcpy(ticket.classe,"Prima classe");
								ticket.prezzo = 1000;
								voli[i].posti_prima_classe -= 1;
							}else
							{
								printf("Non ci sono posti disponibili\n");
							}
							
							

							break;
						
						
						case 2:
							
							printf("Hai scelto la bussines\n");

							if(voli[i].posti_business > 0)
							{
								strcpy(ticket.classe,"Bussines");
								ticket.prezzo = 500;
								voli[i].posti_business -= 1;
							}else
							{
								printf("Non ci sono posti disoponibili\n");
							}

							break;
						
						
						case 3:

							printf("Hai scelto l'economy\n");

							if(voli[i].posti_economy > 0)
							{
								strcpy(ticket.classe,"economy");
								ticket.prezzo = 100;
								voli[i].posti_economy -= 1;
							}
							else
							{
								printf("Non ci sono posti disponibili\n");
							}
						

							break;
						
						
						default:
							break;
						}
						
					}
					
					do
					{

							printf("Inserisci il numero del posto da 0 a 99\n");
							fflush(stdin);

							scanf("%d",&numero_posto);

							if (numero_posto >= 0 && numero_posto < 100 && voli[i].posti_disponibili[numero_posto] == true)
							{
								associato = true;
								printf("Posto associato\n");
								ticket.numero_posto = numero_posto;
								Genera_Numero_Biglietto(ticket.numero_biglietto);
								voli[i].posti_disponibili[numero_posto] = false;
								user.biglietti_utente[user.numero_biglietti_acquistati] = ticket;
								user.numero_biglietti_acquistati ++;
								
								for (int i = 0; i < numero_utenti; i++)
								{
									if (strcmp(utenti[i].numero_documeto, user.numero_documeto) == 0)
									{
										utenti[i] = user;
									}
									
								}
								
							}
							
					} while (associato == false);
			}
		}
			break;

		default:
			break;
		}
	}

	Aggiorna_File(&utenti[0],&utenti[numero_utenti],FILE_NAME_USER);
	Aggiorna_File(&voli[0],&voli[numero_voli],FILE_NAME_FLY);

	return user;


}

UTENTE Scena_Cancella_Biglietto(UTENTE user, UTENTE utenti_salvati[],VOLO voli_salvati[],int numero_voli, int numero_utenti)
{


	char numero_biglietto[MAX_NUMERO_BIGLIETTO];
	BIGLIETTO nuovi_biglietti [MAX_BIGLIETTI_UTENTE];
	int indice = 0;
	bool cancellato = false;

	if(user.numero_biglietti_acquistati > 0)
	{

	printf("Biglietti acquistati dal utente (per la cancellazzione, verrà richiesto il numero del biglietto)\n");
	Stampa_Biglietti_Utente(user);
	
	
	printf("Inserisci il numero del biglietto: ");
	scanf("%s",numero_biglietto);
	puts(" ");


	for (int i = 0; i < user.numero_biglietti_acquistati; i++)
	{
		if (strcmp(numero_biglietto,user.biglietti_utente[i].numero_biglietto) == 0)
		{	
			cancellato = true;
			for (int j = 0; j < numero_voli; j++)
			{
					if (strcmp(voli_salvati[j].Id_Volo,user.biglietti_utente[i].volo.Id_Volo) == 0)
					{
						if (strcmp(user.biglietti_utente[i].classe,"Prima classe") == 0)
						{
							user.biglietti_utente[i].volo.posti_prima_classe ++;
							user.biglietti_utente[i].volo.posti_disponibili[user.biglietti_utente[i].numero_posto] = true;
						}else if (strcmp(user.biglietti_utente[i].classe,"Bussines") == 0)
						{
							user.biglietti_utente[i].volo.posti_business ++;
							user.biglietti_utente[i].volo.posti_disponibili[user.biglietti_utente[i].numero_posto] = true;
						}else if (strcmp(user.biglietti_utente[i].classe,"economy") == 0)
						{
							user.biglietti_utente[i].volo.posti_economy ++;
							user.biglietti_utente[i].volo.posti_disponibili[user.biglietti_utente[i].numero_posto] = true;
						}						
					
						voli_salvati[j] = user.biglietti_utente[i].volo;
					}		
			}
		}
		else
		{	printf("SONO QUI\n");
			nuovi_biglietti[indice] = user.biglietti_utente[i];
			indice ++;
		}
		
	}
	if (cancellato == true)
	{
		user.numero_biglietti_acquistati --;

	}
	
	printf("numero biglietti acquistati :%d\n",user.numero_biglietti_acquistati);
	for (int i = 0; i < user.numero_biglietti_acquistati; i++)
	{
		user.biglietti_utente[i] = nuovi_biglietti[i];
	}
	
	for (int i = 0; i < numero_utenti; i++)
	{
		if (strcmp(utenti_salvati[i].numero_documeto,user.numero_documeto) == 0 )
		{
			utenti_salvati[i] = user;
		}
	}
	
	Aggiorna_File(&voli_salvati[0],&voli_salvati[numero_voli],FILE_NAME_FLY);
	Aggiorna_File(&utenti_salvati[0],&utenti_salvati[numero_utenti],FILE_NAME_USER);
	
	printf("Stampo lista aggiornata dei biglietti associati al utente\n");
	Stampa_Biglietti_Utente(user);
	
	}else
	{
		printf("Nessun biglietto è stato acquistato\n");
	}
	return user;		
}

UTENTE Scena_Check_in(UTENTE utenti[],int numero_utenti, UTENTE utente_log)
{
	char Numero_biglietto [MAX_NUMERO_BIGLIETTO];
	bool Trovato = false;
	
	printf("Stampo tutti i biglietti associati all utente.\n");
	
	printf("Attenzione per effettuare il Chek_in, verrà richiesto il numero del biglietto\n");

		Stampa_Biglietti_Utente(utente_log);

		fflush(stdin);

		printf("Inserisci il numero del biglietto sul quale si vuole effetturare il check-in\n");
		fflush(stdin);

		scanf("%s",Numero_biglietto);

		for (int i = 0; i < utente_log.numero_biglietti_acquistati; i++)
		{
			if (strcmp(utente_log.biglietti_utente[i].numero_biglietto,Numero_biglietto) == 0)
			{
				printf("Il biglietto è stato trovato, effettuo il check-in");
				utente_log.biglietti_utente[i].Check_in = true;
				Trovato = true;
			}
			
		}
		
		(Trovato == false? printf("Il numero del biglietto è errato\n"): printf("\n"));

			
			if (Trovato == true)
			{
			for (int i = 0; i < numero_utenti; i++)
			{
				if(strcmp(utenti[i].numero_documeto,utente_log.numero_documeto) == 0)
				{
					utenti[i] = utente_log;
				}
			}

			printf("Il check-in è stato effettuato correttamente\n");

			Aggiorna_File(&utenti[0],&utenti[numero_utenti],FILE_NAME_USER);

			}
			else
			{
				printf("Il numero del biglietto è errato\n");
			}
			
			return utente_log;
			
}
		
UTENTE Scena_Modifica_Biglietto(UTENTE utenti[], int numero_utenti, UTENTE utente_log, VOLO voli[], int numero_voli)
{
	int scelta = SCENA_DEFAULT;
	int numero_posto = 0;
	char numero_biglietto [MAX_NUMERO_BIGLIETTO];
	VOLO temp_volo;
	int classe = 0;
	bool posto_cambiato = false;
	bool classe_cambiata = false;

	while(scelta != 0)
	{
		printf("Inserisci 0 per uscire\n");
		printf("Inserisci 1 per cambiare il numero del sedile\n");
		printf("Inserisci 2 per cambiare la classe\n");

		fflush(stdin);

		scanf("%d",&scelta);

		if (scelta == 0)
		{
			printf("Chiusura del menù\n");
		}else
		{

			printf("Per poter effettuare delle modifiche, bisogna inserire il numero del biglietto\n");
			printf("Stampo i biglietti associati all utente\n");

			Stampa_Biglietti_Utente(utente_log);
			fflush(stdin);

			scanf("%s",numero_biglietto);

			for (int  i = 0; i < utente_log.numero_biglietti_acquistati; i++)
			{
				if (strcmp(numero_biglietto,utente_log.biglietti_utente[i].numero_biglietto) == 0)
				{
					//temp_volo = utente_log.biglietti_utente[i].volo;
					switch (scelta)
					{
					case 1:
						
							do
							{
							printf("Inserisci il numero del sedile (compreso tra 0 e 99)\n");
							fflush(stdin);

							scanf("%d",&numero_posto);

							if (numero_posto >= 0 && numero_posto < 100)
							{
							
								if (temp_volo.posti_disponibili[numero_posto] == false)
								{
									utente_log.biglietti_utente[i].volo.posti_disponibili[utente_log.biglietti_utente[i].numero_posto] = false;
									utente_log.biglietti_utente[i].volo.posti_disponibili[numero_posto] = true;
									utente_log.biglietti_utente[i].numero_posto = numero_posto;

									printf("%d\n",utente_log.biglietti_utente[i].numero_posto);

									posto_cambiato = true;
								}

							}else
							{
								printf("Il numero del sedile è inesistente\n");
							}
							} while (posto_cambiato != true);
						
						break;

						case 2:

						do
						{
							printf("Inserisci 1 per la Prima Classe\n");
							printf("Inserisci 2 per la Business\n");
							printf("Inserisci 3 per l' Economy\n");

							fflush(stdin);

							scanf("%d",&classe);

							switch (classe)
							{
							case 1:
								
								strcpy(utente_log.biglietti_utente[i].classe,"Prima Classe");
								classe_cambiata = true;
								break;
							
							case 2:
								
								strcpy(utente_log.biglietti_utente[i].classe,"business");
								classe_cambiata = true;
								break;

							case 3:
								
								strcpy(utente_log.biglietti_utente[i].classe,"Economy");
								classe_cambiata = true;
								break;

							default:
								break;
							}

						} while (classe_cambiata != true);
						


						break;
					
					default:
						break;
					}

					temp_volo = utente_log.biglietti_utente[i].volo;
				}
				
			}
			
			
		}
		
	}

	for (int i = 0; i < numero_utenti; i++)
	{
		if(strcmp(utente_log.numero_documeto, utenti[i].numero_documeto) == 0)
		{
			utenti[i] = utente_log;
		}
	}
	
	for (int i = 0; i < numero_voli; i++)
	{
		if (strcmp(temp_volo.Id_Volo,voli[i].Id_Volo) == 0)
		{
			voli[i] = temp_volo;
		}
		
	}
	Aggiorna_File(&utenti[0],&utenti[numero_utenti],FILE_NAME_USER);
	Aggiorna_File(&voli[0],&voli[numero_voli],FILE_NAME_FLY);

	return utente_log;
	
}