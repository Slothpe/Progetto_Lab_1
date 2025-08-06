//
// Created by Perrulli Antonio on 14/04/25.
#include <stdbool.h>
#include<stdio.h>
#define SCENA_DEFAULT 20 // Valore fittizzio per settare la scena. se metto 0 va in confilitto per il controllo degli input
#define FILE_NAME_PERSONALE "Data_Personale_Volo.bin"
#define FILE_NAME_USER "Data_User.bin"
#define FILE_NAME_ADMIN "Data_Admin.bin"
#define FILE_NAME_FLY "Data_Fly.bin"
#define MAX_PASSEGERI 100
#define MAX_BIGLIETTI_UTENTE 10
#define MAX_PASSWORD 20 //Numero massimo di caratteri per la password
#define MAX_DOCUMENTO 10
#define MAX_PREFERENZE 12
#define MAX_STRINGHE 20
#define MAX_ID 10
#define NUMERO_PERSONALE 4


typedef struct {

	char nome[MAX_STRINGHE];
	char cognome[MAX_STRINGHE];
	char ruolo[MAX_STRINGHE]; //pilota hostess
	char Id[MAX_ID];  //3 lettere e gli altri restanti numeri
	bool occupato;

}PERSONALE_VOLO;

typedef struct
{
	int giorno;
    int mese;
    int anno;
    int ora;
    int minuti;
 }DATA;

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

typedef struct{

	char nome[MAX_STRINGHE];
	char cognome[MAX_STRINGHE];
	int numero_posto;
	char classe[MAX_STRINGHE];
    int prezzo;
	VOLO volo;	
    bool Check_in;
	
}BIGLIETTO;



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


struct NOTIFICA   //struttura per le notifiche del volo
{
    char messaggio[500];   //massimo di caratteri che può contenere un messaggio
    char tipo[MAX_STRINGHE];   //ritardi, cambio di orario
    VOLO volo_interessato;
};

typedef struct {   //struttura per i dati dell'amministratore
    char nome[MAX_STRINGHE];
    char cognome[MAX_STRINGHE];
    char password[MAX_PASSWORD];
    char Id[MAX_ID];
    bool account_sbloccato;

}AMMINISTRATORE;

int main(void)
{
    FILE* ptr_file = fopen(FILE_NAME_USER,"rb");
    UTENTE temp;

    while (fread(&temp,sizeof(UTENTE),1,ptr_file) != 0)
    {
        printf("%s %s %s\n",temp.nome,temp.cognome,temp.password);
    }
    


    return 0;
}