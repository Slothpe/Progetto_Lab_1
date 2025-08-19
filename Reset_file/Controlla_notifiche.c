#include <stdbool.h>
#include<stdio.h>
#define SCENA_DEFAULT 20 // Valore fittizzio per settare la scena. se metto 0 va in confilitto per il controllo degli input
#define FILE_NAME_PERSONALE "Data_Personale_Volo.bin"
#define FILE_NAME_USER "Data_User.bin"
#define FILE_NAME_ADMIN "Data_Admin.bin"
#define FILE_NAME_FLY "Data_Fly.bin"
#define FILE_NAME_NOTIFICHE "Notifiche_Voli.bin"
#define MAX_PASSEGERI 100
#define MAX_BIGLIETTI_UTENTE 10
#define MAX_PASSWORD 20 //Numero massimo di caratteri per la password
#define MAX_DOCUMENTO 10
#define MAX_PREFERENZE 12
#define MAX_STRINGHE 20
#define MAX_ID 10
#define NUMERO_PERSONALE 4
#define MAX_NUMERO_BIGLIETTO 12
#define PRIMA_CLASSE "Prima Classe"
#define BUSSINES "Bussines"
#define ECONOMY "Economy"
#define NUMERO_CARTA 16
#define MAX_NOTIFICA 350

/**
* @brief Rappresenta un ruolo per l'equipaggio del volo
*
* Contiene dati anagrafici e informazioni sul ruolo della persona (es.pilota, hostess)
*/

typedef struct {

	char nome[MAX_STRINGHE];
	char cognome[MAX_STRINGHE];
	char ruolo[MAX_STRINGHE]; //pilota hostess
	char Id[MAX_ID];  //3 lettere e gli altri restanti numeri
	bool occupato;

}PERSONALE_VOLO;

/**
* @brief Rappresenta le date per la creazione dei voli
*
* Contiene dati come giorno,mese,anno,ora e minuti
*/
typedef struct
{
	int giorno;
    int mese;
    int anno;
    int ora;
    int minuti;
 }DATA;

 /**
* @brief Rappresenta i dati per la creazione del volo
*
* Contiene ID dell'aereomobile, ID del volo, dati per la partenza e destinazione,
* numero di posti disponibili per la prima classe, business ed economy, se il volo è attivo in ritardo o in volo
* e una notifica per avvisare i passeggeri sullo stato del volo se appunto è in ritardo, cancellato o in volo
*/
typedef struct    //struttura per i dati del volo
{
	char Id_Aereomobile[MAX_ID];
    char Id_Volo[MAX_ID];
    char partenza_origine[MAX_STRINGHE];
    char destinazione[MAX_STRINGHE];
    DATA data;
    bool posti_disponibili[MAX_PASSEGERI];    //è diventato booleano, devor ricreari voli e nella funzione crea volo, devo settare sto array tutto su true!
	int posti_prima_classe;
	int posti_business;
	int posti_economy;
    bool Stato_volo; //se il volo è attivo in ritardo o cancellato
    char messaggio[MAX_STRINGHE]; //Messaggio tipo di notifica se il volo e cancellato o in ritardo
	PERSONALE_VOLO personale[NUMERO_PERSONALE];
}VOLO;

/**
* @brief Rappresenta il sistema di notifica del volo
* Contiene il massimo di caratteri del messaggio (500), il tipo di messaggio, se riguarda il ritardo
* o la cancellazione del volo
*/
typedef struct 
{
    char messaggio [MAX_NOTIFICA];
    VOLO volo_associato;
    
} NOTIFICA;

/**
* @brief Rappresenta i dati del biglietto
*
* Contiene dati anagrafici del passeggero e i vari dati sulla prenotazione per quanto riguarda il numero del posto
* la classe e il volo
*/
typedef struct{

    char numero_biglietto[MAX_NUMERO_BIGLIETTO]; //Biglietto composto da prima due lettere e poi tutti nuneri
	char nome[MAX_STRINGHE];
	char cognome[MAX_STRINGHE];
	int numero_posto;
	char classe[MAX_STRINGHE];
    int prezzo;
	VOLO volo;	
    bool Check_in;
	
}BIGLIETTO;

/**
* @brief Rappresenta i dati anagrafici per i passeggeri e le varie informazioni
*
* Contiene dati anagrafici dei passeggeri, password per accedere al profilo dell'utente, scelta dei pasti,
* scelta del posto, della classe, il quantitativo di biglietti acquistati da quell'utente,
* numero di segnalazioni (max 5).
*/
typedef struct   //struttura per inserire dati passeggeri
{
    char nome[MAX_STRINGHE];
    char cognome[MAX_STRINGHE];
    char numero_documeto[MAX_DOCUMENTO];
    char password[MAX_PASSWORD];
    char pasti[MAX_PREFERENZE]; //pasto preferito
    int posto_preferito;
    char classe_preferita[MAX_PREFERENZE];  //economy, business, firstclass
    BIGLIETTO biglietti_utente[MAX_BIGLIETTI_UTENTE];
    int numero_biglietti_acquistati;
	char segnalazioni[5][500]; // Ogni utente può inviare massimo 5 segnalazioni
	int num_segnalazioni; // Conta il numero di segnalazioni inviate
}UTENTE;

/**
* @brief Rappresenta i dati anagrafici e informazioni per accedere al profilo dell'amministratore
*
* Contiene dati anagrafici, password e numero dell'ID per l'account
*/
typedef struct {   //struttura per i dati dell'amministratore
    char nome[MAX_STRINGHE];
    char cognome[MAX_STRINGHE];
    char password[MAX_PASSWORD];
    char Id[MAX_ID];
    bool account_sbloccato;

}AMMINISTRATORE;

int main(void)
{


    NOTIFICA temp;
    FILE* ptr_file = fopen(FILE_NAME_NOTIFICHE,"rb");

    
    while (fread(&temp,sizeof(NOTIFICA),1,ptr_file)!= 0)
    {
        printf("Messaggio: %s\n",temp.messaggio);
        printf("Volo: %s\n",temp.volo_associato.Id_Volo);
    }
    
}