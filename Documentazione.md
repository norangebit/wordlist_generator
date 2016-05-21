# Documentazione

## Guida

Questo software è in grado di funzionare in due modalità differenti:

1. Modalità quickly
2. Modalità standard

### Modalità quickly(Ancora non funzionante)

In questa modalità la generazione di un nuovo dizionario è resa il più facile e immediata possibile. L'utente dovrà eseguire da termilane il programma seguito dalla info sul soggetto.

**_Esempio_:** Se il nostro eseguibile si chiama _"main"_ e le info sul soggetto sono {mario, rossi, 1985, roma} da terminale dovremmo digitare il seguente codice.

`./main mario rossi 1985 roma`

Il software automaticamente provvederà a mixare tra di loro le varie stringhe e a salvare il dizionario così creato nel file _"diz.txt"_.

### Modalità standard

In questa modalità il software permette di gestire più _database_ di soggetti. Unfile rappresenta un _database_ e in ogni _database_ può essere salvato un numero illimitato di Soggetti. In questo modo si possono gestire più soggetti contemporaneamente a patto che siano salvati nello stesso file. Per avviare il programma in questa modalità basterà eseguire il programma senza l'aggiunta di altri argomenti.

Una volta lanciato il programma in questa modalità il software chiederà all'utente quale file desidera caricare. L'utente per scegliere dovrà immettere il nome del file che desidera aprire. Se il file non esiste o è corrotto il programma restituirà un messaggio di errore. Il programma in automatico provvederà alla creazione del file e permetterà all'utente l'esecuzione del programma.

**N.B.** Alla prima esecuzione del programma l'utente dovrà inserire il nome del file che intende creare, senza preoccuparsi del messaggio di errore.

#### Menu

Dopo aver creato/aperto il file l'utente si troverà difronte al seguente menu:

1. Aggiungi un nuovo soggetto.
2. Crea dizionario.
3. Stampa soggetti.
4. Cerca.
5. Salva ed esci.

L'utente dovrà digitare il numero corrispondente alla propria scelta.

##### Aggiungi un nuovo soggetto

Scegliendo questa voce all'utente verrà chiesto di inserire il nome e il cognome del soggetto e le info(max 10) su di esso.

##### Crea dizionario

Scegliendo questa voce il programma chiederà all'utente di identificare l'utente desiderato(identificato da nome e cognome) e il nome del file sul quale si vuole salvare il dizionario.

**N.B.** Il file può anche non esistere, in quel caso il programma lo creerà in automatico.

##### Stampa soggetti

Selezionando questa voce il programma stamperà a video l'intero elenco di soggetti presenti nel _database_ attualmente in uso.

**N.B.** il programma stampa solo l'elenco dei nomi e cognomi, le info su ogni soggetto vengono escluse.

##### Cerca

Selezionando questa voce il programma stamperà a video le info del soggetto cercato dall'utente.

##### Salva ed esci

Scegliendo questa voce l'utente terminerà il programma e salverà le modifiche sul _database_ precedentemente aperto/creato.

##### Struttura _database_

Il _database_ è un semplice file di testo, per questo l'utente potrebbe editarlo con un qualsiasi editor di testo. Se si sceglie di fare ciò si prega di fare attenzione alla struttura interna del file.

**_Esempio_:** Il soggetto si chiama Mario Rossi e le sue info sono {mario, rossi, 1985, roma}, quindi nel _database_ si avrà:

`Rossi Mario # mario Mario rossi Rossi 1985 roma Roma ##`

L'utente potrebbe omettere la distinzione tra maiuscole e minuscole ma si sconsiglia di non farlo in quanto si potrebbero perdere combinazioni preziose. Comunque l'importante e digitare prima il cognome e poi il nome separati da uno spazio, poi inserire il cancelletto, poi le info sempre separate da spazzi e infine un doppio cancelletto. Se non si formatta nel seguente modo il file potrebbe non essere caricato correttamente o risultare corrotto.

## License

Questo file è rilasciato secondo i termini della licenza _Creative Commons_ [**BY-SA 3.0**](link)
