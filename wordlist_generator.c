/*
============================================================================
Name        : Generatoredestionari.c
Author      : Sh13n, Orange_dugongo
Version     : alpha 0.4
Copyright   : CC BY-SA 3.0 IT
Description : Generatore di destionari in C
============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#define INFO 10

int Inserisci(char *);

typedef struct{
  char *str;
} src;

int main(){
  char buffer[200], *save;
  src info[2*INFO];
  FILE *src, *dest;
  int i, j, h, r, g, f, e, mixa=0;

  printf("Da quale file vuoi caricare i dati: ");
  scanf("%s", buffer);

  //LETTURA VALORI SUL FILE
  if(!(src=fopen(buffer, "r")))
    //INSERIMENTO VALORI SUL FILE
    if(!Inserisci(buffer))
      return(0);
    else
      src=fopen(buffer, "r");

  //CONTROLLO SE L'UTENTE HA INSERITO VALORI NEGLI ARRAY
  do{
    fscanf(src, "%s", buffer);
    info[mixa].str=(char *)calloc(strlen(buffer)+1, sizeof(char));
    strcpy(info[mixa].str, buffer);

    //se il primo carattere della srca è alfabetico genero la srca maiuscola
    if(isalpha(info[mixa].str[0])){
      info[++mixa].str=(char *)calloc(strlen(buffer)+1, sizeof(char));
      buffer[0]=toupper(buffer[0]);
      strcpy(info[mixa].str, buffer);
    }
  }while (strcmp("#", info[mixa].str) && mixa++<INFO);
  fclose(src);

  //APERTURA FILE
  printf("Su quali file vuoi salvare i dati: ");
  scanf("%s", buffer);
  save=(char *)calloc(strlen(buffer)+1, sizeof(char));
  strcpy(save, buffer);
  dest = fopen(save, "w");

  //INIZIO CICLO
  for(i=0;i<mixa;i++){

    //SECONDO CICLO
    for(j=0;j<mixa;j++){
      if(!strcasecmp(info[i].str, info[j].str))
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
  printf("Il Dizionario è stato creato con successo, il nome del destionario è %s.", save);
  return(0);
}

int Inserisci(char *buffer){
  char c;
  FILE *src;
  printf("Il file indicato non esiste, ora verrà creato\n");
  if((src=fopen(buffer, "w"))){
    printf("Inserisci informazioni(max %d) sul target separate da spazi.\nQuando hai terminato inserisci il cancelletto '#' e premi invio\nEsempio: franco rossi 1990 milan roberta #\n", INFO);
    do{
      fputc(tolower((c=getchar())), src);
    }while(c!=35);
  }else{
    printf("Si è verificato un errore.");
    return(0);
  }
  fclose(src);
  return(1);
}
