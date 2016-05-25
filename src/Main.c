/*
============================================================================
Name        : Generatoredestionari.c
Version     : beta 0.1
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

int main(int argc, char *argv[]){
  char fname[200], name[200], cname[200], fdest[200];
  int n, r;
  Soggetto *head=NULL, *x;
  if(argc>1)
    Quickly(argv, argc);//Not Work
  else{
    printf("Quale file vuoi caricare: ");
    scanf("%s", fname);
    if((r=Read(&head, fname)) && r>0)
      printf("File caricato correttamente\n");
    else if(r<0)
      printf("Nuovo file creato\n");
    else{
      printf("ERRORE\nImpossibile caricare correttamente il file\n");
      head=NULL;
    }
    do{
      printf("\n-------------Menu-------------\n");
      printf("\n 1. Aggiungi un nuovo soggetto.");
      printf("\n 2. Crea dizionario.");
      printf("\n 3. Stampa soggetti.");
      printf("\n 4. Cerca.");
      printf("\n 5. Elimina.");
      printf("\n 0. Salva ed esci.\n");
      printf("\n Cosa vuoi fare: ");

      switch(n){
        case 0: Save(head, fname);
          break;
        case 1: Link(NewS(), &head);
          break;
        case 2: Anagrafica(name, cname);
                printf("Su quale file vuoi salvare il dizionario: ");
                scanf("%s", fdest);
                if((x=Search(head, name, cname))){
                  Generazione(fopen(fdest, "w"), x);
                  printf("\nDizionario creato con successo.\n");
                }else
                  printf("\nIl soggetto inserito non esiste.\n");
          break;
        case 3: Print(head, "all");
          break;
        case 4: Anagrafica(name, cname);
                if((x=Search(head, name, cname)))
                  Print(x, "once");
                else
                  printf("\nIl soggetto inserito non esiste.\n");
          break;
        case 5: Anagrafica(name, cname);
                Delete(&head, cname, name);
          break;
        default: printf("Scelta non valida");
      }
    }while(n);
  }
}
