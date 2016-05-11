/*
============================================================================
Name        : Generatoredestionari.c
Author      : Sh13n, Orange_dugongo
Version     : alpha 0.4
Copyright   : CC BY-SA 3.0 IT
Description : Generatore di destionari in C
============================================================================
 */

 #include "wordlist_generator.h"

int main(){
  char buffer[200], *save;
  FILE *src;

  printf("Da quale file vuoi caricare i dati: ");
  scanf("%s", buffer);

  //LETTURA VALORI SUL FILE
  if(!(src=fopen(buffer, "r")))
    //INSERIMENTO VALORI SUL FILE
    if(!Inserisci(buffer))
      return(0);
    else
      src=fopen(buffer, "r");

  //APERTURA FILE
  printf("Su quali file vuoi salvare i dati: ");
  scanf("%s", buffer);
  save=(char *)calloc(strlen(buffer)+1, sizeof(char));
  strcpy(save, buffer);

  Generazione(fopen(save, "w"), Load(src, buffer));

  printf("Il Dizionario è stato creato con successo, il nome del dizionario è %s.", save);
  return(0);
}
