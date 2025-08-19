/**
* @file Data_set.h
* @brief Definizione delle funzioni per la gestione del dataset per il programma FlyTwo
*
* include le firme per inizializzare, modificare i dati degli utenti, voli e prenotazioni.
* E' il punto d'ingresso per le operazioni che presentano il dataset
* @author Antonio Perrulli e Pietro Menandro
* @date 14/04/25
*/
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



/**
 * @brief Permette la registrazione di un nuovo utente passeggero.
 *
 * Crea una struttura UTENTE con dati inseriti manualmente: nome, cognome, documento
 *
 * @return Struttura UTENTE compilata con le informazioni inserite.
 */
UTENTE Iscrizione_Utente(void);

/**
 * @brief Consente all'utente di scegliere il pasto preferito per il volo.
*/
void Scelta_Pasto(char[]);

/**
 * @brief Permette all'utente di selezionare il posto preferito.
 *
 * Mostra le opzioni disponibili e ritorna la scelta effettuata.
 *
 * @return Codice numerico corrispondente al posto selezionato.
 */
int Scelta_Posto_Preferito(void);

/**
 * @brief Verifica la validità della password secondo i criteri del sistema.
 *
 * Controlla lunghezza, caratteri speciali e complessità della password inserita.
 *
 * @param password Stringa da verificare.
 * @return true se la password è valida, false altrimenti.
*/
bool Controlla_Password(char[]);

/**
 * @brief Controlla se il documento utente ha un formato valido.
 *
 * Verifica lunghezza e struttura alfanumerica del documento.
 *
 * @param documento Puntatore alla stringa che rappresenta il documento.
 * @return true se il documento è corretto, false altrimenti.
 */
bool Controlla_Documento(char*);

/**
 * @brief Conta gli elementi presenti in un file binario.
 *
 * Utile per conoscere il numero di utenti, voli, o segnalazioni salvati.
 *
 * @param nome_file Nome del file da analizzare.
 * @return Numero di elementi trovati nel file.
 */
int Conta_Elementi(char*);

/**
 * @brief Inserisce un utente nel file binario del database.
 *
 * Aggiunge la struttura UTENTE come elemento nel file di memoria.
 *
 * @param u Struttura UTENTE da inserire.
 */
void Inserisci_Utente(UTENTE);

/**
 * @brief Gestisce l'accesso di un utente registrato.
 *
 * Richiede le credenziali (documento e password) da tastiera e verifica la loro validità
 * confrontandole con quelle presenti nel database. Se l'accesso è riuscito, restituisce
 * la struttura UTENTE corrispondente e aggiorna il flag di successo.
 *
 * @param successo Puntatore a variabile booleana che indica l'esito del login (true se riuscito).
 * @return Struttura UTENTE in caso di accesso riuscito, struttura vuota altrimenti.
 */
UTENTE Accesso_Utente(bool*);

/**
 * @brief Permette all'utente di selezionare la classe preferita.
 *
 * La scelta viene salvata nel parametro ricevuto.
 *
 * @param classe Array di caratteri dove viene memorizzata la classe.
 */
void Scelta_Classe_Preferita(char[]);

/**
 * @brief Verifica se un utente è già registrato nel sistema.
 *
 * Controlla la presenza dell'utente confrontando i suoi dati.
 *
 * @param u Struttura UTENTE da cercare nel database.
 * @return true se l'utente esiste, false altrimenti.
 */
bool Trova_Utente(UTENTE);

/**
 * @brief Crea un volo inserendo manualmente tutti i suoi dettagli.
 *
 * Restituisce una struttura VOLO con origine, destinazione, data e orario.
 *
 * @return VOLO compilato con i dati inseriti.
 */
VOLO Crea_Volo(void);

/**
 * @brief Inserisce il luogo di partenza per un volo.
 *
 * Acquisisce la stringa da tastiera e la memorizza nel parametro.
 *
 * @param partenza Array di caratteri dove viene salvato il nome della città.
 */
void Inserisci_Luogo_Partenza(char[]);

/**
 * @brief Inserisce il luogo di destinazione del volo.
 *
 * Salva nel parametro la stringa inserita dall’utente.
 *
 * @param destinazione Array di caratteri dove viene memorizzata la destinazione.
 */
void Inserisci_Luogo_Destinazione(char[]);

/**
 * @brief Permette l’inserimento della data del volo.
 *
 * Richiede giorno, mese e anno da tastiera e restituisce una struttura DATA.
 *
 * @return Struttura DATA con la data selezionata.
 */
DATA Inserisci_Data_Volo(void);

/**
 * @brief Registra un nuovo amministratore nel sistema.
 *
 * Crea una struttura AMMINISTRATORE con i dati inseriti manualmente.
 *
 * @return Struttura AMMINISTRATORE completa.
 */
AMMINISTRATORE Iscrizione_Amministratore(void);

/**
 * @brief Genera un ID univoco per un amministratore.
 *
 * Assegna un codice identificativo al profilo amministratore.
 *
 * @param ID_admin Array di caratteri dove verrà salvato l'ID generato.
 */
void Generazione_ID_Amministratore(char[]);

/**
 * @brief Verifica se un amministratore è presente nel sistema.
 *
 * Confronta i dati della struttura AMMINISTRATORE con quelli archiviati.
 *
 * @param admin Struttura AMMINISTRATORE da cercare.
 * @return true se l'amministratore è stato trovato, false altrimenti.
 */
bool Trova_Admin(AMMINISTRATORE);

/**
 * @brief Inserisce un amministratore nel database.
 *
 * Salva la struttura AMMINISTRATORE nel file binario del sistema.
 *
 * @param admin Struttura da registrare.
 */
void Inserici_Admin(AMMINISTRATORE);

/**
 * @brief Gestisce l'accesso di un amministratore tramite credenziali.
 *
 * Verifica ID e password, e aggiorna il flag di successo in caso di login corretto.
 *
 * @param successo Puntatore a booleano che indica se l'accesso è riuscito.
 * @return Struttura AMMINISTRATORE corrispondente, se l'accesso è valido.
 */
AMMINISTRATORE accesso_Amministratore(bool*);

/**
 * @brief Gestisce un array di voli: visualizzazione, modifica o aggiornamento.
 *
 * Consente di operare su una lista di voli preesistente.
 *
 * @param voli Array di strutture VOLO.
 * @param num_voli Numero totale di voli nell'array.
 */
void Gestisci_voli(VOLO [], int);

/**
 * @brief Genera un codice identificativo univoco per un volo.
 *
 * Il codice viene salvato nell'array passato come parametro.
 *
 * @param ID_volo Array di caratteri dove salvare l'ID generato.
 */
void Generazione_ID_Volo(char[]);

/**
 * @brief Verifica se l’anno inserito è bisestile.
 *
 * Applica le regole del calendario gregoriano per controllare l’anno.
 *
 * @param anno Valore intero dell’anno da verificare.
 * @return true se è bisestile, false altrimenti.
 */
bool Bisestile(int anno);


/**
 * @brief Verifica se una data è valida considerando gli anni bisestili.
 *
 * Controlla giorno, mese e anno per stabilire la validità della data.
 *
 * @param giorno Giorno della data.
 * @param mese Mese della data.
 * @param anno Anno da verificare.
 * @return true se la data è valida, false altrimenti.
 */
bool Verifica_Data_Bisestile(int giorno, int mese, int anno);

/**
 * @brief Associa personale di bordo a un volo.
 *
 * Aggiunge membri staff alla struttura VOLO specificata.
 *
 * @param v Struttura VOLO da aggiornare.
 * @return VOLO con il personale assegnato.
 */
VOLO Associa_Personale_volo(VOLO);

/**
 * @brief Salva i dati di un volo nel sistema.
 *
 * Aggiunge la struttura VOLO al file binario.
 *
 * @param v Struttura VOLO da salvare.
 */
void Salva_volo(VOLO);

/**
 * @brief Aggiorna un file binario sostituendo un elemento esistente con uno nuovo.
 *
 * La funzione gestisce l’aggiornamento dell’elemento nel file indicato,
 * confrontando il contenuto e sovrascrivendo quello vecchio con quello nuovo.
 * È pensata per strutture binarie e può essere adattata a vari tipi di dati.
 *
 * @param nuovo Puntatore all’elemento aggiornato.
 * @param vecchio Puntatore all’elemento da sostituire.
 * @param nome_file Nome del file binario da aggiornare.
 */
void Aggiorna_File(void*, void*, char*);

/**
 * @brief Visualizza l’elenco completo dei voli disponibili.
 *
 * Stampa i dettagli di ogni volo contenuto nell’array passato.
 *
 * @param voli Array di voli da mostrare.
 */
void Stampa_Voli(VOLO []);

/**
 * @brief Permette di modificare il volo associato a un biglietto.
 *
 * Cambia l’ID volo del biglietto, aggiornando i dati in memoria.
 *
 * @param id_biglietto ID del biglietto da modificare.
 * @param voli Array di voli disponibili.
 * @param num_voli Numero totale di voli.
 */
void Cambia_Volo(char[MAX_ID], VOLO [], int, UTENTE [],int);

/**
 * @brief Consente di trovare un volo.
 * 
 * Per la ricecrca del volo viene chiesto un range di date, se esiste 
 * un volo che cade in quel range di date allora viene stampato.
 * 
 * 
*/
void Trova_Volo(void);

/**
 * @brief Genera il numero identificativo di un biglietto.
 * 
 * Il nunmero di un boglietto è composto da 2 lettere del alfabeto e numeri.
 * La generazione avviene casualmente, non ci sono dei parametri particolari.
 * 
 * @param numero_biglietto Rappresenta il numero del biglietto da generare. la lunghezza
 * massima viene definita dalla macro MAX_NUMERO_BIGLIETTO = 12
 */
void Genera_Numero_Biglietto(char [MAX_NUMERO_BIGLIETTO]);

/**
 * @brief Stampa tutti i biglietti acquistati ad un utente
 * 
 * Ogni utente ha una voce che si chima biglietti_utente, che non è altro che un
 * array di biglietti. Quindi questa funzione non fa altro che stampare tutti le voci
 * che sono associate alla struct BIGLIETTO.
 * 
 * @param user Rappresenta l'utente di cui si vuole stmpare i biglietti acquistati
 */
void Stampa_Biglietti_Utente(UTENTE);

void Salva_Notifica(NOTIFICA);