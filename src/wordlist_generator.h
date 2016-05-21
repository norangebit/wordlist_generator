/*
============================================================================
Name        : Generatoredestionari.c
Version     : beta 0.0.2
Description : Generatore di dizionari in C
============================================================================
Copyright (c) 2016 Sh13n, Orange_dugongo

This file is part of wordlist_generator.

    wordlist_generator is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    wordlist_generator is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with wordlist_generator.  If not, see <http://www.gnu.org/licenses/>.
*/



/* IN QUESTO FILE SONO RIPORTATI SOLO I PROTOTIPI DELLE FUNZIONI E UNA BREVE
   SPIEGAZIONE DEL LORO COMPORTAMENTO. PER LEGGERE IL CODICE DELLE FUNZIONI SI
   DEVE LEGGERE IL FILE 'wordlist_generator.c'.
*/

#include "wordlist_generator.c"

//LEGGE LE INFO DA MEMORIA E GENERA IL DIZIONARIO
  /*  La funzione acetta come input il puntatore al file su cui deve salvare il
      dizionario e il puntatore al soggetto da cui ricava le info. La funzione essendo
      di tipo void non restituisce nessun elemento.
  */
void Generazione(FILE *dest, Soggetto *x);


//CREA UN NUOVO SOGGETTO
  /*  La funzione permette di caricare in memoria un nuovo soggetto, comprensivo
      di nome cognome e le relative info. La funzione restituisce in output
      il puntatore al nuovo sogetto.
  */
Soggetto *NewS();


//INSERISCE IN ORDINE ALFABETICO UN NUOVO SOGGETTO NELLA LISTA
  /*  La funzione accetta in imput il puntatore al nuovo soggetto e il puntatore
      al puntatore(doppio puntatore) alla testa della sista. La funzione
      permette di inserire in ordine alfabetico(cognome nome) il nuovo soggetto
      nella lista. La funzione non acetta omonimi.
  */
void Link(Soggetto *New, Soggetto **head);


//PERMETTE DI SALVARE SU FILE LA LISTA DEI SOGGETTI7
  /*  La funzione accetta in input il puntatore alla testa della lista e il
      nome del file su cui si desidera salvare.
  */
void Save(Soggetto *head, char *fname);


//LEGGE DA FILE UNA LISTA DI SOGGETTI E LA CARICA IN MEMORIA
  /*  La funzione accetta in input il puntatore al puntatore(doppio puntatore)
      alla testa della lista e il nome del file da cui si vuole leggere.
      La funzione restituisce 0 in caso di errori di lettura e 1 se il
      procedimento è andato a buon fine.
  */
int Read(Soggetto **head, char *fname);


//CERCA UN SOGGETTO NELLA LISTA
  /*  La funzione accetta in input il puntatore alla testa della lista, il nome
      e il cognome del soggetto. La funzione restituisce il puntatore al
      soggetto ricercato. Nel caso in cui non si verifichi nessun match la
      funzione restituisce NULL.
  */
Soggetto *Search(Soggetto *head, char *nome, char *cnome);


//GENERA UN DIZIONARIO VELOCEMENTE
  /*  La funzione acetta in input argv e argc e si occupa di generare un
      dizionario senza interazione con l'utente.
  */
void Quickly(char *str[], int mixa);


//STAMAPA A VIDEO UNO O PIÙ UTENTI
  /*  La funzione può operare in due modalità differenti.
      MODALITÀ ONCE: stampa un unico soggetto con info incluse. Per accedere a
      questa modalità inserire il puntatore al sogetto desiderato nel primo
      campo e "once" nel secondo.
      MODALITÀ ALL: stampa l'elenco di tutti i soggetti caricati nel database
      per attivare questa modalità inserire il puntatore alla testa della lista
      e nel secondo campo "all".
  */
void Print(Soggetto *head, char *mode);
