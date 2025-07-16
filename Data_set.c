//
// Created by Perrulli Antonio on 14/04/25.
//
#include "Data_set.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#define DEFAULT_SCELTA 9;

UTENTE Iscrizione_Utente(void){  

    /*
        Questa funzione gestisce l'iscrizione di un utente
        Affinchè un utente sia registrato è necessario inseire
        le seguneti informazioni:

        1) Nome
        2) Cognome
        3) Password con simboli speciali
        4) Numero di documento (Passaporto)
        5) Scelta sul pasto preferito (tipologia)
        6) Scelta sul numero di posto preferito
        7) Tipologia di classe preferita (prima ecc...)
    
        Durante l'acquisizione di queste informazioni, vengono effettuati dei controlli
        affinchè le info siano corrette e sensate.
    */
        UTENTE temp;
    
        printf("Inserisci il nome:\n");
        scanf(" %s", temp.nome);

        printf("Inserisci il cognome:\n");
        scanf(" %s", temp.cognome);

        printf("Inserisci la password (Lunghezza max 19, almeno una lettera maiuscola e un carattere speciale = (! "" # $ /'"%" & , ( ) * + ' - ))\n");
        fflush(stdin);

        do {
            
            scanf("%s",temp.password);

        }while(Controlla_Password(temp.password) == false);

        Scelta_Pasto(temp.pasti);

        temp.posto_preferito = Scelta_Posto_Preferito();

        Scelta_Classe_Preferita(temp.classe_preferita);

        printf("Inserisci il numero del passaporto (Max 9 caratteri): ");
        do {

            scanf("%s",temp.numero_documeto);
        }while(Controlla_Documento(temp.numero_documeto) == false);

        temp.numero_biglietti_acquistati = 0;

    return temp;
    }

void Scelta_Pasto(char pasto[]){   
   
    /*
        Per la realizzazione del account associato ad un utente, è obbligatorio
        scegliere una tipologia di pasto tra quelle proposte.

        Anche qui è presenta la constate globale DEFAULT_SCELTA per far fornte al inserimento di unn carattere
        al posto di un numero come scelta. Il numero che ho inserito è abritatrio, ed ho inserito un valore in modo
        tale che non vada in conflitto con le opzioni dei menu (quanto meno per il momento .... :)  )
    
    */
    int scelta = DEFAULT_SCELTA;
    bool scelta_corretta = false; //e falso finchè l'utente non fa una scelta corretta
    char* opzioni_pasto [5] = {"Vegetariano","Vegano","Lattosio","Glutine","niente"}; //scelte effetuabili dal utente

    printf("Inserisci una preferenza sul cibo:\n");
    while (scelta_corretta == false)
    {
        
        printf("Inserisci 0: Vegetariano\n");
        printf("Inserisci 1: Vegano\n");
        printf("Inserisci 2: Lattosio\n");
        printf("Inserisci 3: Glutine\n");
        printf("Inserisci 4: niente\n");

        fflush(stdin);
        scanf("%d",&scelta);

        if (scelta > 4|| scelta < 0) {
            printf("Errore nella scelta della preferenza, Riprova\n");
        }else {
            printf("Scelta corretta\n");
           strcpy(pasto,opzioni_pasto[scelta]);
            scelta_corretta = true;
        }

    }
    }

int Scelta_Posto_Preferito(void)  //funzione per scegliere il posto preferito

/*
    Anche qui come accennato al inzio per la realizzazione del profilo associato ad un untente e obbligatorio
    scegliere un numero di posto preferito. Non sono stati inseriti grandi controlli, l'importante che il numero
    scelta dal utente sia compreso tra 0 e MAX_PASSEGGERI -> Numero massimo di passeggeri che un aereo può ospitare

*/
{
    int posto_inserito = 0;

    while(posto_inserito <= 0 || posto_inserito > MAX_PASSEGERI) {
        printf("Inserisci il posto preferito numero compreso tra 0 e 100: ");
        scanf("%d",&posto_inserito);
        puts("");
    }

    return posto_inserito;

}

bool Controlla_Password(char password[]) {  

    /*
        Per la realizzazione del account e necessario inserire una password, la password deve mantenere e
        rispettare dei vincoli particolari, non abbiamo un vincolo sulla lunghezza minima ma solo sulla
        massima (Mi rendo conto che non è il massimo della sicurezza :[  ). Esistono però dei vincoli
        sui simboli che compongono la password, ovvero una lettera maisucola, una minuscola e carattere
        speciale (! " # $ % & , ( ) * + ' - )

    */

    bool stato_carattere = false;
    bool stato_speciale = false;
    int lunghezza_stringa = strlen(password);


    for(int i = 0; i < lunghezza_stringa; i++)
    {
        //Controllo se ci sono lettere maiuscole
        for (int j = 'A'; j <= 'Z'; j++) {
            if (password[i] == j) {
                stato_carattere = true;
            }
        }
        //Controllo se ci sono lettere minuscole
        for (int j = 'a'; j < 'z'; j++) {
            if (password[i] == j) {
                stato_carattere = true;
            }
        }
        //Controllo se ci sono caratteri speciali
        for (int j = '!'; j < '.'; j++) {
            if (password[i] == j) {
                stato_speciale = true;
            }
        }
    }

    (stato_speciale == false? printf("Inserisci un carattere speciale\n") : printf("Carattere speciale: ok\n"));
    (stato_carattere == false? printf("Inserisci almeno una lettera maiuscola\n") : printf("Lettera: ok\n"));
    return stato_carattere && stato_speciale;
}

bool Controlla_Documento(char numero_passaporto[]) 
{
    bool stato_1 = false;
    bool stato_2 = false;
    bool stato_3 = true;
    bool stato_4 =  false;

    stato_4 = (strlen(numero_passaporto) == 9? true: false);

    for (int i = 'A'; i <= 'Z'; i++) { //controllo il primo carattere della stringa
        if (numero_passaporto[0] == i) {
            stato_1 = true;
        }
    }

    for (int i = 'A'; i <= 'Z'; i++) { //controllo il secondo carattere della stringa
        if(numero_passaporto[1] == i) {
            stato_2 = true;
        }
    }

    for (int i = 2; i < MAX_DOCUMENTO; i++) { //controllo se i restanti caratteri sono numeri
        if (isdigit(numero_passaporto[i] == 0)){
            stato_3 = false;
        }
    }
      if(stato_4 && stato_3 && stato_2 && stato_1 == true)
      {
          printf("Documento corretto\n");
      }else {
          printf("Documento errato, Riprova: \n");
      }
    return  stato_3 && stato_2 && stato_1 && stato_4;
}

int Conta_Elementi(char* stringa) {


    FILE* ptr = fopen(stringa,"rb");
    int utenti_iscritti = 0;
    long size = 0;

    fseek(ptr,0,SEEK_END);//Sposto la "testina del file" alla fine

    size = ftell(ptr); //restituisce la posizione corrente del file in byte

    if(strcmp(stringa,FILE_NAME_PERSONALE) == 0) {
        utenti_iscritti = size / sizeof(PERSONALE_VOLO);

    }else if(strcmp(stringa,FILE_NAME_FLY) == 0){
        utenti_iscritti = size / sizeof(VOLO);
    }else if(strcmp(stringa,FILE_NAME_ADMIN)) {
        utenti_iscritti = size / sizeof(AMMINISTRATORE);
    }else if(strcmp(stringa,FILE_NAME_USER) == 0) {
        utenti_iscritti = size / sizeof(UTENTE);
    }


    rewind(ptr);

    fclose(ptr);

    return utenti_iscritti;

}

void Inserisci_Utente(UTENTE utente) {

   FILE* ptr =  fopen(FILE_NAME_USER,"ab"); //Apro il file in modalità append per aggiungere il nuovo utente

    fwrite(&utente,sizeof(UTENTE),1, ptr);
    printf("salvo l'utente nel file\n");

    fclose(ptr);
}

UTENTE Accesso_Utente(bool* trovato) {

    UTENTE temp;

    *trovato = false;
    char utente_nome [20];
    char password [20];

    printf("Inserisci il nome_utente: ");


    scanf("%s",utente_nome);
    fflush(stdin);

    puts("");

    printf("Inserisci la password: ");
    scanf("%s",password);
    fflush(stdin);



    FILE* ptr = fopen(FILE_NAME_USER,"rb");


    while (fread(&temp,sizeof(UTENTE),1,ptr) != 0) {
        if ((strcmp(password, temp.password) == 0) && (strcmp(utente_nome, temp.nome) == 0)) {
            *trovato = true;
            return temp;
        }
    }

    fclose(ptr);

    return temp;
}

bool Trova_Utente(UTENTE utente) {

    bool stato = false;

    UTENTE temp;

    FILE* ptr = fopen(FILE_NAME_USER,"rb");

    while (fread(&temp,sizeof(UTENTE),1,ptr) != 0) {
        if ((strcmp(utente.numero_documeto, temp.numero_documeto)) == 0) {
            stato = true;
        }
    }

    fclose(ptr);
    return stato;
}

void Scelta_Classe_Preferita(char classe[])
{

    int scelta = 0;
    char* preferenza_utente = NULL; //Contiene la preferenza scelta dal utente
    bool scelta_corretta = false; //e falso finche l'utente non fa una scelta corretta
    char* opzioni_classe [3] = {"Prima Classe","Business","Economy"}; //scelte effetuabili dal utente

    printf("Inserisci una preferenza sulla classe:\n");
    while (scelta_corretta == false)
    {

        printf("Inserisci 0: Prima Classe\n");
        printf("Inserisci 1: Business\n");
        printf("Inserisci 2: Economy\n");

        fflush(stdin);
        scanf("%d",&scelta);

        if (scelta > 4|| scelta < 0) {
            printf("Errore nella scelta della preferenza, Riprova\n");
        }else {
            printf("Scelta corretta\n");
            strcpy(classe,opzioni_classe[scelta]);
            scelta_corretta = true;
        }

    }

}

void Inserisci_Luogo_Partenza(char partenza[]){

	printf("Inserisci il luogo di partenza: ");
	scanf("%s",partenza);
	puts("");

	partenza[0] = toupper(partenza[0]);
}

void Inserisci_Luogo_Destinazione(char destinazione[])
{
	printf("Inserisci il luogo di destinazione: ");
	scanf("%s",destinazione);
	puts("");

	destinazione[0] = toupper(destinazione[0]);
}

DATA Inserisci_Data_Volo(void)
{
	DATA temp;
	bool verifica = false;


    while (verifica == false) {
        printf("Inserisci il giorno della partenza: ");
        scanf("%d",&temp.giorno);
        puts("");
        if (temp.giorno >= 1 && temp.giorno <= 31) {
            verifica = true;
        }else {
            printf("il numero del giorno deve essere compreso tra 1 e 31\n");
        }
    }

    verifica = false;

     while (verifica == false) {
         printf("Inserisci il mese della partenza: ");
         scanf("%d",&temp.mese);
         puts("");
         if (temp.mese >= 1 && temp.mese <= 12) {
             verifica = true;
         }else {
             printf("Il numero del mese dev'essere compreso tra 1 e 12\n");
         }
     }

    verifica = false;

    while (verifica == false) {
        printf("Inserisci l'anno della partenza(soglia massima 2025 - 2030): ");
        scanf("%d",&temp.anno);
        puts("");
        if (temp.anno >= 2025 && temp.anno <= 2030) {
            verifica = true;
        }
    }

    verifica = false;

    while (verifica == false) {
        printf("Inserisci l'ora della partenza (0:00 - 23 : 59: ");
        scanf("%d",&temp.ora);
        puts("");
        if (temp.ora >= 0 && temp.ora <= 23) {
            verifica = true;
        }
    }

    verifica = false;

    while (verifica == false) {
        printf("Inserisci i minuti(00-59): ");
        scanf("%d",&temp.minuti);
        puts("");

        if (temp.minuti >= 0 && temp.minuti <= 59) {
            verifica = true;
        }
    }
	return temp;
}

AMMINISTRATORE Iscrizione_Amministratore(void) {  //funzione per l'iscrizione dell'amministratore
    AMMINISTRATORE temp;

    printf("Inserisci il nome: ");
    scanf(" %s", temp.nome);

    puts("");
	
    printf("Inserisci il cognome: ");
    scanf(" %s", temp.cognome);

    puts("");
    	
    printf("Inserisci la password (Lunghezza max 19, almeno una lettera Maiuscola e un carattere speciale)\n");
    fflush(stdin);

    do {
        scanf("%s",temp.password);
    }while(Controlla_Password(temp.password) == false);

    Generazione_ID_Amministratore(temp.Id);

    temp.account_sbloccato = false;

    return temp;
}

void Generazione_ID_Amministratore(char Id[]) { //funzione per la generazione dell'ID dell'amministratore
    srand(time(NULL));  //per generare l'id in modo casuale

    for (int i = 0; i < 3; i++) {
        Id[i] = 'A' + rand() % 26;  //genera lettere random maiuscole nelle prime 3 posizioni
    }
    for (int i = 3; i < MAX_ID-1; i++) {
        Id[i] = '0' + rand() % 10;  //genera numeri random nelle poszioni successive dopo le lettere maiuscole
    }

    Id[MAX_ID-1] ='\0';
}

bool Trova_Admin(AMMINISTRATORE admin)
{
	bool stato = false;
	AMMINISTRATORE temp;

	FILE* pt_file =fopen (FILE_NAME_ADMIN,"rb");

	while(fread(&temp,sizeof(AMMINISTRATORE),1,pt_file)!= 0)
	{
		if(strcmp(temp.nome,admin.nome) == 0 && strcmp(temp.cognome, admin.cognome) == 0)
		{
			stato = true;
		}
	}
	fclose(pt_file);

	return stato;
}

void Inserici_Admin(AMMINISTRATORE admin){

	FILE* ptr_file = fopen(FILE_NAME_ADMIN, "ab");

	fwrite(&admin,sizeof(AMMINISTRATORE),1,ptr_file);
	printf("Account salvato\n");
	system("clear");

	fclose(ptr_file);
	
}

AMMINISTRATORE accesso_Amministratore(bool* stato)
{
	char nome_admin[MAX_STRINGHE];
	char password[MAX_STRINGHE];
	AMMINISTRATORE temp;
	AMMINISTRATORE Out;

	printf("Inserisci il nome del utente: ");
	scanf("%s",nome_admin);
	puts("");

	
	printf("Inserisci la password: ");
	scanf("%s",password);
	puts("");



	FILE* ptr_file = fopen(FILE_NAME_ADMIN,"rb");

	while(fread(&temp,sizeof(AMMINISTRATORE),1,ptr_file) != 0)
	{
		if(strcmp(temp.nome, nome_admin) == 0 && strcmp(temp.password,password) == 0 ){

			*stato = true;
			Out = temp;
			
		}
	}

	return Out;
}

void Generazione_ID_Volo(char Id_Volo[]) {    //generazione ID VOLO
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        Id_Volo[i] = 'A' + rand() % 26;
    }
    for (int i = 3; i < MAX_ID-1; i++) {
        Id_Volo[i] = '0' + rand() % 10;
    }
    Id_Volo[MAX_ID-1] ='\0';
}

VOLO Crea_Volo(void) {  //funzione per creare il volo
    VOLO temp;

    Generazione_ID_Volo(temp.Id_Volo);
    Inserisci_Luogo_Partenza(temp.partenza_origine);
    Inserisci_Luogo_Destinazione(temp.destinazione);

    bool verifica = false;
    while (!verifica) {
        temp.data = Inserisci_Data_Volo();

        // Controlla che la data sia valida tenendo conto degli anni bisestili
        if (Verifica_Data_Bisestile(temp.data.giorno, temp.data.mese, temp.data.anno)) {
            verifica = true;
        } else {
            printf("Data inserita non valida! Reinserisci una data corretta.\n");
        }
    }

    temp.posti_prima_classe = 20;
    temp.posti_business = 30;
    temp.posti_economy = 50;
    temp.Stato_volo = false;
    strcpy(temp.messaggio, "nessuno");

    return temp;
}

bool Bisestile(int anno) {  // Funzione bisestile
    return (anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0));
}

bool Verifica_Data_Bisestile(int giorno, int mese, int anno) {
        if (mese < 1 || mese > 12) {  //controllo se il mese inserito è valido
            return false;
        }

        if (mese == 2) {  //controllo per il mese di febbraio
            if (Bisestile(anno)) {
                return (giorno >= 1 && giorno <= 29);
            } else {
                return (giorno >= 1 && giorno <= 28);
            }
        }

        int giorni_mese[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  //array per i giorni massimi di ogni mese

        return (giorno >= 1 && giorno <= giorni_mese[mese - 1]);  // Controllo se il giorno è valido per quel mese
    }

void Associa_Personale_volo(VOLO temp) {
    /*I controlli che fa questa funzione e vedere se il personale che si vuole inserire e disponibile oppure e gia
     *stato associato. Se il personale scelto è libero allora viene associato al volo, altrimenti richiede di inserire un
     *nuovo personale
     *
     */

    int associato = 0;
    int Indice = 0;
    char ID_ingresso[MAX_ID];
    bool stato = false;
    int elementi = Conta_Elementi(FILE_NAME_PERSONALE);
    PERSONALE_VOLO personale_volo[elementi];

    FILE* ptr = fopen(FILE_NAME_PERSONALE,"rb");

    // legge gli elementi di un file e li salva in un array

    while(fread(&personale_volo[Indice],sizeof(PERSONALE_VOLO),1,ptr) != 0) {
        Indice++;
    }
    fclose(ptr);

        printf("Stampo i piloti\n");
        for (int i = 0; i < elementi; i++) {
            if (strcmp(personale_volo[i].ruolo, "Pilota") == 0) {
                printf("%s %s %s %s ",personale_volo[i].cognome,personale_volo[i].nome,personale_volo[i].ruolo,personale_volo[i].Id);
                if(personale_volo[i].occupato == false) {
                    printf("Stato: Libero\n");
                }else {
                    printf("Stato: Occupato");
                }            }
        }


    while (stato == false) {
        printf("Inserisci l'Id di un pilota da associare al volo: ");
        scanf("%s",ID_ingresso);
        puts("\n");

        for (int i = 0; i < elementi; i++) {
            if (strcmp(personale_volo[i].ruolo,"Pilota") == 0 && strcmp(personale_volo[i].Id,ID_ingresso) == 0) {
                if (personale_volo[i].occupato == false) {
                    printf("Il pilota è occupato in un altro volo\n");
                }else {
                    printf("Pilota %s %s Inserito",personale_volo[i].nome, personale_volo[i].cognome);
                    personale_volo[i].occupato = true;
                    temp.personale[associato] = personale_volo[i];
                    associato++;
                    stato = true;
                }
            }
        }
    }

    stato = false;

    printf("Stampo i Co-Piloti\n");
    for (int i = 0; i < elementi; i++) {
        if (strcmp(personale_volo[i].ruolo, "Co-Pilota") == 0) {
            printf("%s %s %s %s ",personale_volo[i].cognome,personale_volo[i].nome,personale_volo[i].ruolo,personale_volo[i].Id);
            if(personale_volo[i].occupato == false) {
                printf("Stato: Libero\n");
            }else {
                printf("Stato: Occupato\n");
            }            }
    }

    while (stato == false) {
        printf("Inserisci l'Id di un CO-Pilota da associare al volo: ");
        scanf("%s",ID_ingresso);
        puts("\n");

        for (int i = 0; i < elementi; i++) {
            if (strcmp(personale_volo[i].ruolo,"Co-Pilota") == 0 && strcmp(personale_volo[i].Id,ID_ingresso) == 0) {
                if (personale_volo[i].occupato == false) {
                    printf("Il Co-Pilota è occupato in un altro volo\n");
                }else {
                    printf("Pilota %s %s Inserito",personale_volo[i].nome, personale_volo[i].cognome);
                    personale_volo[i].occupato = true;
                    temp.personale[associato] = personale_volo[i];
                    associato++;
                    stato = true;
                }
            }
        }
    }

    stato = false;

    printf("Stampo i Hostess\n");
    for (int i = 0; i < elementi; i++) {
        if (strcmp(personale_volo[i].ruolo, "Hostess") == 0) {
            printf("%s %s %s %s ",personale_volo[i].cognome,personale_volo[i].nome,personale_volo[i].ruolo,personale_volo[i].Id);
            if(personale_volo[i].occupato == false) {
                printf("Stato: Libero\n");
            }else {
                printf("Stato: Occupato\n");
            }            }
    }

    for (int i = 0; i < 3; i++) {
        while (stato == false) {
            printf("Inserisci l'Id di un Hostess da associare al volo: ");
            scanf("%s",ID_ingresso);
            puts("\n");

            for (int j = 0; j < elementi; j++) {
                if (strcmp(personale_volo[j].ruolo,"Hostess") == 0 && strcmp(personale_volo[j].Id,ID_ingresso) == 0) {
                    if (personale_volo[j].occupato == false) {
                        printf("L'Hosstess è occupato in un altro volo\n");
                    }else {
                        printf("Pilota %s %s Inserito",personale_volo[j].nome, personale_volo[j].cognome);
                        personale_volo[j].occupato = true;
                        temp.personale[associato] = personale_volo[j];
                        associato++;
                        stato = true;
                    }
                }
            }
        }
    }


}

void Salva_volo(VOLO volo){
	
	FILE* ptr_file = fopen(FILE_NAME_FLY,"ab");
	
	fwrite(&volo,sizeof(VOLO),1,ptr_file);
	printf("Salvo il volo\n");
	
	fclose(ptr_file);
		
}



/*
VOLO Trova_Volo(VOLO voli[], int num_voli, char* origine, char* destinazione, int giorno, int mese, int anno, int ora, int minuti, int Id_Volo) {
    for (int i = 0; i < num_voli; i++) {
        // Cerca per ID volo
        if (Id_Volo != NULL && strcmp(voli[i].Id_Volo, Id_Volo) == 0) {
            return voli[i];
        }

        // Cerca per tratta (origine e destinazione)
        if (origine != NULL && destinazione != NULL &&
            strcmp(voli[i].partenza_origine, origine) == 0 &&
            strcmp(voli[i].destinazione, destinazione) == 0) {
            return voli[i];
            }

        // Cerca per data
        if (giorno != -1 && mese != -1 && anno != -1 &&
            voli[i].data.giorno == giorno &&
            voli[i].data.mese == mese &&
            voli[i].data.anno == anno) {
            return voli[i];
            }

        // Cerca per orario
        if (ora != -1 && minuti != -1 &&
            voli[i].data.ora == ora &&
            voli[i].data.minuti == minuti) {
            return voli[i];
            }
    }

    // Se nessun volo è trovato, restituisce un volo "vuoto"
    return (VOLO) {0};
}
*/
/*
bool Check_In(UTENTE* utente, VOLO* volo) {
    // Controlla se il volo è attivo
    if (!volo->Stato_volo) {
        printf("Il volo %s è stato cancellato o non è attivo.\n", volo->Id_Volo);
        return false; // Se il volo è cancellato, il check-in fallisce
    }

    // Mostra i posti disponibili
    printf("Posti disponibili:\n");
    for (int i = 0; i < MAX_PASSEGERI; i++) {
        if (volo->posti_disponibili[i] == 0) { // Se il posto è libero (0), lo stampa
            printf("Posto %d\n", i + 1);
        }
    }

    // Richiede all'utente di scegliere un posto
    int scelta_posto;
    printf("Inserisci il numero di posto che vuoi selezionare: ");
    scanf("%d", &scelta_posto);

    // Verifica che il numero scelto sia valido e che il posto sia libero
    if (scelta_posto < 1 || scelta_posto > MAX_PASSEGERI || volo->posti_disponibili[scelta_posto - 1] != 0) {
        printf("Posto non disponibile o numero errato.\n");
        return false; // Se il posto non è valido, il check-in fallisce
    }

    // Assegna il posto selezionato all'utente e aggiorna il volo
    volo->posti_disponibili[scelta_posto - 1] = 1; // Segna il posto come occupato
    utente->biglietti_utente[utente->numero_biglietti_acquistati - 1].numero_posto = scelta_posto;  //salva il numero del posto scelto

    // Conferma la registrazione del check-in
    printf("Check-in completato! Posto %d assegnato.\n", scelta_posto);
    return true; // Indica che il check-in è stato completato con successo
}

bool Invia_Segnalazione(UTENTE* utente, char* messaggio) {
    // Controlla che l'utente non abbia superato il numero massimo di segnalazioni (5)
    if (utente->num_segnalazioni < 5) {
        // Copia il messaggio all'interno dell'array delle segnalazioni dell'utente
        strcpy(utente->segnalazioni[utente->num_segnalazioni], messaggio);

        // Incrementa il numero di segnalazioni registrate per l'utente
        utente->num_segnalazioni++;

        // Stampa un messaggio di conferma per l'utente
        printf(" Segnalazione registrata per %s %s.\n", utente->nome, utente->cognome);
        return true;  // Conferma che la segnalazione è stata inviata con successo
    } else {
        // Se l'utente ha già inviato il massimo numero di segnalazioni, stampa un messaggio di errore
        printf(" Numero massimo di segnalazioni raggiunto.\n");
        return false;  // Indica che la segnalazione non può essere registrata
    }
}

void Visualizza_Segnalazioni(UTENTE* utente) {
    printf("\n📢 Segnalazioni per %s %s\n", utente->nome, utente->cognome);
    printf("-----------------------------------\n");

    // Controlla se l'utente ha inviato almeno una segnalazione
    if (utente->num_segnalazioni == 0) {
        printf("Nessuna segnalazione presente.\n");  // Avvisa che non ci sono segnalazioni registrate
        return;
    }

    // Itera attraverso tutte le segnalazioni registrate per l'utente
    for (int i = 0; i < utente->num_segnalazioni; i++) {
        printf(" Segnalazione #%d: %s\n", i + 1, utente->segnalazioni[i]);  // Stampa ogni segnalazione registrata
    }

    printf("-----------------------------------\n");
}
*/
