#include <stdio.h>
#include <stdbool.h>
#define MAX_PASSEGERI 100
#define MAX_BIGLIETTI_UTENTE 10
#define MAX_PASSWORD 20 //Numero massimo di caratteri per la password
#define MAX_DOCUMENTO 10
#define MAX_PREFERENZE 12
#define MAX_STRINGHE 20
#define MAX_ID 10
#define NUMERO_PERSONALE 5



typedef struct {   //struttura per i dati dell'amministratore
    char nome[MAX_STRINGHE];
    char cognome[MAX_STRINGHE];
    char password[MAX_PASSWORD];
    char Id[MAX_ID];
    bool account_sbloccato;

}AMMINISTRATORE;


/*
	Questo mini programma serve per vedere tutti gli account
	amministratori che sonon stati salvati sul file
*/

int main(void){

	FILE* ptr = fopen("Data_Admin.bin","rb");
	AMMINISTRATORE temp;

	while(fread(&temp,sizeof(AMMINISTRATORE),1,ptr) != 0)
	{
		printf("%s %s %s\n",temp.nome, temp.cognome, temp.password);		
	}		

	fclose(ptr);

	return 0;
}


