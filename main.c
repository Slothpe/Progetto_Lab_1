#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include "Scena_menager.h"

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

int main(void)
{   

    PROGRAMMA programma;
    programma.stato_programma = true;
    programma.scena = SCENA_DEFAULT;
    
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

    return 0;
    
}
