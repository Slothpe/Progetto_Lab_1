#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include "Scena_menager.h"
#define SCENA_DEFAULT 9 // Valore fittizzio per settare la scena. se metto 0 va in confilitto per il controllo degli input

/*
 *ACCOUNT DI PROVA:

	ADMIN E UTENTE
 
 NOME: Antonio
 COGNOME: Perrulli
 PASSWORD: Ermitico2!
 POSTO PREFERITO: 100
 CIBO: Vegetariano
 CLASSE: Prima
 NUMERO PASSAPORTO: MA1234567

 secondo account:
 Nome: Pietro
 Cognome: Menandro
 Password: Rocco.12

 */
/*
	Dal account amministratore dobbiamo creare i voli e salvarlo nel file binario fly, Dobbiamo poter cancellare i voli,
	Modificare i voli e salvare tutte le modifiche nel file;


 */

int main(void)
{

    PROGRAMMA programma;
    programma.stato_programma = true;
    programma.scena = SCENA_DEFAULT ;

    printAirPlane();

    while (programma.stato_programma == true)
        {

		
        programma.scena = Menu_Principale();
        

        switch (programma.scena)
            {

				case Utente:

					Scena_Panello_Utente(&programma);
						
				break;
				

				case Amministratore:

					Scena_Pannello_Amministratore(&programma);
				
				break;

            	case Chiusura:
            	
            	printf("Chiusura del programma\n");
            	programma.stato_programma = false;
            	
            	break;        
				
            default:

                printf("Scelta non valida\n");

                break;

            }

        }

	printf("Utente: %s %s\n",programma.utente.nome, programma.utente.cognome);
    printf("Amministratore: %s %s ID: %s\n",programma.admin.nome, programma.admin.cognome, programma.admin.Id);


    return 0;
}
