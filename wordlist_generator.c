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

/* IN QUESTO FILE È RIPORTATO IL CODICE DELLE FUNZIONI, SE NON SI RIESCE A
   CAPIRNE IL COMPORTAMENTO SI CONSIGLIA DI LEGGERE IL FILE
   'wordlist_generator.h'.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#define INFO 10 //Numero massimo di info accettate dal programma.

//Creazione di un nuovo tipo definito di tipo struttura. Serve per greare un array di stringhe.
typedef struct{
  char *str;
} Nodo;

Nodo info[2*INFO];//L'array ha dimensioni 2*INFO perchè deve allocare anche lo spazio per la versione della parola con iniziale maiuscola.

int Inserisci(char *buffer){
  char c;
  FILE *src;
  printf("Il file indicato non esiste, ora verrà creato\n");
  if((src=fopen(buffer, "w"))){
    printf("Inserisci informazioni(max %d) sul target separate da spazi.\nQuando hai terminato inserisci il cancelletto '#' e premi invio\nEsempio: franco rossi 1990 milan roberta #\n", INFO);
    do{
      fputc(tolower((c=getchar())), src);
    }while(c!=35);//Il 35 corrisponde all' '#' nel codice ASCII
  }else{
    printf("Si è verificato un errore.");
    return(0);
  }
  fclose(src);
  return(1);
}

int Load(FILE *src){
  char buffer[200];
  int mixa=0;
  do{
    fscanf(src, "%s", buffer);//Si salva la stringa in una variabile d'appoggio.
    info[mixa].str=(char *)calloc(strlen(buffer)+1, sizeof(char));//si alloca lo spazio in memoria.
    strcpy(info[mixa].str, buffer);//Copia la stringa nello spazio allocato.

    //se il primo carattere della stringa è alfabetico genero una nuova stringa con iniziale maiuscola
    if(isalpha(info[mixa].str[0])){
      info[++mixa].str=(char *)calloc(strlen(buffer)+1, sizeof(char));
      buffer[0]=toupper(buffer[0]);
      strcpy(info[mixa].str, buffer);
    }
  }while (strcmp("#", info[mixa].str) && mixa++<INFO);

  fclose(src);
  return(mixa);
}

void Generazione(FILE *dest, int mixa){
  int i, j, h, r, g, f, e;
  //INIZIO CICLO
  for(i=0;i<mixa;i++){

    //SECONDO CICLO
    for(j=0;j<mixa;j++){
      if(!strcasecmp(info[i].str, info[j].str))//Se le due stringhe sono uguali si esegue uno skip. Lo stesso avviene per ogni nuovo ciclo.
        continue;
      fprintf(dest, "%s%s\n", info[i].str, info[j].str);

      //TERZO CICLO
      for(h=0;h<mixa;h++){
        if(!strcasecmp(info[i].str, info[h].str) || !strcasecmp(info[j].str, info[h].str))
          continue;
        fprintf(dest, "%s%s%s\n", info[i].str, info[j].str, info[h].str);

        //QUARTO CICLO
        for(r=0;r<mixa;r++){
          if(!strcasecmp(info[i].str, info[r].str) || !strcasecmp(info[j].str, info[r].str) || !strcasecmp(info[h].str, info[r].str))
            continue;
          fprintf(dest, "%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str);

          //QUINTO CICLO
          for(g=0;g<mixa;g++){
            if(!strcasecmp(info[i].str, info[g].str) || !strcasecmp(info[j].str, info[g].str) || !strcasecmp(info[h].str, info[g].str) || !strcasecmp(info[r].str, info[g].str))
              continue;
            fprintf(dest, "%s%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str, info[g].str);

            //SESTO CICLO
            for(f=0;f<mixa;f++){
              if(!strcasecmp(info[i].str, info[f].str) || !strcasecmp(info[j].str, info[f].str) || !strcasecmp(info[h].str, info[f].str) || !strcasecmp(info[r].str, info[f].str) || !strcasecmp(info[g].str, info[f].str))
                continue;
              fprintf(dest, "%s%s%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str, info[g].str, info[f].str);

              //SETTIMO CICLO
              for(e=0;e<mixa;e++){
                if(!strcasecmp(info[i].str, info[e].str) || !strcasecmp(info[j].str, info[e].str) || !strcasecmp(info[h].str, info[e].str) || !strcasecmp(info[r].str, info[e].str) || !strcasecmp(info[g].str, info[e].str) || !strcasecmp(info[f].str, info[e].str))
                  continue;
                fprintf(dest, "%s%s%s%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str, info[g].str, info[f].str, info[e].str);
              }
            }
          }
        }
      }
    }
  }
  fclose(dest);
}
