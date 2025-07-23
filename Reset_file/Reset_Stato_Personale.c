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
#define FILE_NAME_PERSONALE "Data_Personale_Volo.bin"

/*
    Questo mini programma serve per impostare tutto il personale che è contenuto nel
    file da occupato a disponibile

*/

typedef struct {

	char nome[MAX_STRINGHE];
	char cognome[MAX_STRINGHE];
	char ruolo[MAX_STRINGHE]; //pilota hostess
	char Id[MAX_ID];  //3 lettere e gli altri restanti numeri
	bool occupato;

}PERSONALE_VOLO;

int main(void)
{

    PERSONALE_VOLO temp;
    int contatore = 0;
    FILE *ptr_file = fopen(FILE_NAME_PERSONALE, "rb");
    
    printf("Leggo il contenuto del file\n");

    while(fread(&temp,sizeof(PERSONALE_VOLO),1,ptr_file)!= 0)
    {
        contatore ++;
        printf("%s %d\n",temp.nome, temp.occupato);
    
    }

   printf("Lo salvo in un array\n");

    rewind(ptr_file);
    contatore ++ ;
    PERSONALE_VOLO array[contatore-1];

    int index = 0;
    while(fread(&temp,sizeof(PERSONALE_VOLO),1,ptr_file)!= 0)
    {
        printf("Temp: %s %d\n",temp.nome,temp.occupato);
        array[index] = temp;
        printf("Array: %s %d\n",array[index].nome,array[index].occupato);
        index++;
    }

    fclose(ptr_file);

    

    ptr_file = fopen(FILE_NAME_PERSONALE, "wb");
    
    printf("Modifico lo stato da occupato a libero\n");
    for(int i = 0; i < contatore-1; i++)
    {

        printf("PRIMA: %s %d\n",array[i].nome, array[i].occupato);
        array[i].occupato = false;
        fwrite(&array[i],sizeof(PERSONALE_VOLO),1,ptr_file);
        printf("DOPO: %s %d\n",array[i].nome, array[i].occupato);

    }
    fclose(ptr_file);
    return 0;
}