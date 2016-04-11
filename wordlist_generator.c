/*
 ============================================================================
 Name        : GeneratoreDizionari.c
 Author      : Sh13n, Orange_dugongo
 Version     : 
 Copyright   :
 Description : Generatore di dizionari in C
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define INFO 10

typedef struct{
  char str[128];
} String;

int main(){
  char c, s[]="Dizionario";
  String info[2*INFO];
  FILE *string, *diz;
  int mixa=0, i, j, h, r, g, f, e;


  //INSERIMENTO VALORI SUL FILE
  if((string=fopen("string", "w"))){
    printf("Inserisci informazioni(max %d) sul target separate da spazi.\nQuando hai terminato inserisci il cancelletto '#' e premi invio\nEsempio: franco rossi 1990 milan roberta #\n", INFO);
    do{
      fputc(tolower((c=getchar())), string);
    }while(c!=35);
    fclose(string);
  }else{
    printf("Si è verificato un errore.");
    return(0);
  }

  //CONTROLLO SE L'UTENTE HA INSERITO VALORI NEGLI ARRAY
  string=fopen("string", "r");
  do{
    fscanf(string, "%s", info[mixa].str);
    //se il primo carattere della stringa è alfabetico genero la stringa maiuscola
    if(isalpha(info[mixa].str[0])){
      info[mixa+1]=info[mixa++];
      info[mixa].str[0]=toupper(info[mixa].str[0]);
    }
  }while (strcmp("#", info[mixa].str) && mixa++<INFO);
  fclose(string);

  //APERTURA FILE
  diz = fopen(s, "w");
  //INIZIO CICLO
  for(i=0;i<mixa;i++){

    //SECONDO CICLO
    for(j=0;j<mixa;j++){
      if(!strcasecmp(info[i].str, info[j].str))
        continue;
      fprintf(diz, "%s%s\n", info[i].str, info[j].str);

      //TERZO CICLO
      for(h=0;h<mixa;h++){
        if(!strcasecmp(info[i].str, info[h].str) || !strcasecmp(info[j].str, info[h].str))
          continue;
        fprintf(diz, "%s%s%s\n", info[i].str, info[j].str, info[h].str);

        //QUARTO CICLO
        for(r=0;r<mixa;r++){
          if(!strcasecmp(info[i].str, info[r].str) || !strcasecmp(info[j].str, info[r].str) || !strcasecmp(info[h].str, info[r].str))
            continue;
          fprintf(diz, "%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str);

          //QUINTO CICLO
          for(g=0;g<mixa;g++){
            if(!strcasecmp(info[i].str, info[g].str) || !strcasecmp(info[j].str, info[g].str) || !strcasecmp(info[h].str, info[g].str) || !strcasecmp(info[r].str, info[g].str))
              continue;
            fprintf(diz, "%s%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str, info[g].str);

            //SESTO CICLO
            for(f=0;f<mixa;f++){
              if(!strcasecmp(info[i].str, info[f].str) || !strcasecmp(info[j].str, info[f].str) || !strcasecmp(info[h].str, info[f].str) || !strcasecmp(info[r].str, info[f].str) || !strcasecmp(info[g].str, info[f].str))
                continue;
              fprintf(diz, "%s%s%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str, info[g].str, info[f].str);

              //SETTIMO CICLO
              for(e=0;e<mixa;e++){
                if(!strcasecmp(info[i].str, info[e].str) || !strcasecmp(info[j].str, info[e].str) || !strcasecmp(info[h].str, info[e].str) || !strcasecmp(info[r].str, info[e].str) || !strcasecmp(info[g].str, info[e].str) || !strcasecmp(info[f].str, info[e].str))
                  continue;
                fprintf(diz, "%s%s%s%s%s%s%s\n", info[i].str, info[j].str, info[h].str, info[r].str, info[g].str, info[f].str, info[e].str);
              }
            }
          }
        }
      }
    }
  }
  fclose(diz);
  printf("dizionario creato con successo, il nome del dizionario è %s.", s);
  return(0);
}
