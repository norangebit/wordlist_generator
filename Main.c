/*
============================================================================
Name        : Generatoredestionari.c
Version     : alpha 0.4.1
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

 #include "wordlist_generator.h"

int main(){
  char buffer[200];
  FILE *src;

  printf("Da quale file vuoi caricare i dati: ");
  scanf("%s", buffer);

  //LETTURA VALORI SUL FILE
  if(!(src=fopen(buffer, "r")))//Se non è stato posibile aprire il file ne viene screato uno nuovo.
    //INSERIMENTO VALORI SUL FILE
    if(!Inserisci(buffer))//Per leggere il codice della funziona aprire il file 'wordlist_generator.c'
      return(0);
    else
      src=fopen(buffer, "r");//Nel caso si sia creato un nuovo file bisogna aprirlo in modalità lettura.
  //APERTURA FILE
  printf("Su quale file vuoi salvare i dati: ");
  scanf("%s", buffer);

  Generazione(fopen(buffer, "w"), Load(src));//Per leggere il codice della funziona aprire il file 'wordlist_generator.c'

  printf("Il Dizionario è stato creato con successo, il nome del dizionario è %s.", buffer);
  return(0);
}
