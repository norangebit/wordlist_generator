/*
============================================================================
Name        : Generatoredestionari.c
Version     : alpha 0.4
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

//LEGGE LE INFO DA TASTIERA E LE SALVA SU UN FILE
  /*  Prende in input una stringa, e crea un file di testo col nome della stringa.
      Nel file di testo vengono copiate le informazione inserite dall'utente.
      La funzione restituisce come output 1 se non ci sono stati errori e
      0 in caso d'errore.
  */
int Inserisci(char *buffer);


//LEGGE LE INFO DA UN FILE E LE CARICA IN MEMORIA
  /*  La funzione prende in input il puntatore al file da cui deve leggere le
      info. Carica in memoria le info sul soggetto e restituisce come output il
      numero di info sul soggetto.
  */
int Load(FILE *src);


//LEGGE LE INFO DA MEMORIA E GENERA IL DIZIONARIO
  /*  La funzione acetta come input il puntatore al file su cui deve salvare il
      dizionario e il numero di parole inserite dall'utente. La funzione essendo
      di tipo void non restituisce nessun elemento.
  */
void Generazione(FILE *dest, int mixa);
