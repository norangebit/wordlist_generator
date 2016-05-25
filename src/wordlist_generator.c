/*
============================================================================
Name        : Generatoredestionari.c
Version     : beta 0.0.4
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

typedef struct Soggetto{
  char *nome;
  char *cnome;
  char *info[INFO];
  int mixa;
  struct Soggetto *next;
} Soggetto;

void Generazione(FILE *dest, Soggetto *x){

  int i, j, h, r, g, f, e;
  //INIZIO CICLO
  for(i=0;i<(x->mixa);i++){

    //SECONDO CICLO
    for(j=0;j<(x->mixa);j++){
      if(!strcasecmp(x->info[i], x->info[j]))//Se le due stringhe sono uguali si esegue uno skip. Lo stesso avviene per ogni nuovo ciclo.
        continue;
      fprintf(dest, "%s%s\n", x->info[i], x->info[j]);

      //TERZO CICLO
      for(h=0;h<(x->mixa);h++){
        if(!strcasecmp(x->info[i], x->info[h]) || !strcasecmp(x->info[j], x->info[h]))
          continue;
        fprintf(dest, "%s%s%s\n", x->info[i], x->info[j], x->info[h]);

        //QUARTO CICLO
        for(r=0;r<(x->mixa);r++){
          if(!strcasecmp(x->info[i], x->info[r]) || !strcasecmp(x->info[j], x->info[r]) || !strcasecmp(x->info[h], x->info[r]))
            continue;
          fprintf(dest, "%s%s%s%s\n", x->info[i], x->info[j], x->info[h], x->info[r]);

          //QUINTO CICLO
          for(g=0;g<(x->mixa);g++){
            if(!strcasecmp(x->info[i], x->info[g]) || !strcasecmp(x->info[j], x->info[g]) || !strcasecmp(x->info[h], x->info[g]) || !strcasecmp(x->info[r], x->info[g]))
              continue;
            fprintf(dest, "%s%s%s%s%s\n", x->info[i], x->info[j], x->info[h], x->info[r], x->info[g]);

            //SESTO CICLO
            for(f=0;f<(x->mixa);f++){
              if(!strcasecmp(x->info[i], x->info[f]) || !strcasecmp(x->info[j], x->info[f]) || !strcasecmp(x->info[h], x->info[f]) || !strcasecmp(x->info[r], x->info[f]) || !strcasecmp(x->info[g], x->info[f]))
                continue;
              fprintf(dest, "%s%s%s%s%s%s\n", x->info[i], x->info[j], x->info[h], x->info[r], x->info[g], x->info[f]);

              //SETTIMO CICLO
              for(e=0;e<(x->mixa);e++){
                if(!strcasecmp(x->info[i], x->info[e]) || !strcasecmp(x->info[j], x->info[e]) || !strcasecmp(x->info[h], x->info[e]) || !strcasecmp(x->info[r], x->info[e]) || !strcasecmp(x->info[g], x->info[e]) || !strcasecmp(x->info[f], x->info[e]))
                  continue;
                fprintf(dest, "%s%s%s%s%s%s%s\n", x->info[i], x->info[j], x->info[h], x->info[r], x->info[g], x->info[f], x->info[e]);
              }
            }
          }
        }
      }
    }
  }
  fclose(dest);
}

Soggetto *NewS(){
  char buffer[200];
  int mixa=0;
  Soggetto *New=(Soggetto *)malloc(sizeof(Soggetto));
  printf("Inserisci il nome del sogetto: ");
  scanf("%s", buffer);
  New->nome=(char *)calloc(strlen(buffer)+1, sizeof(char));//Alloco lo spazio in memoria
  strcpy(New->nome, buffer);//Copia la stringa

  printf("Inserisci il cognome del sogetto: ");
  scanf("%s", buffer);
  New->cnome=(char *)calloc(strlen(buffer)+1, sizeof(char));//Alloco lo spazio
  strcpy(New->cnome, buffer);//copia della stringa
  printf("Inserisci le info sul sogetto. \"#\" per terminare: ");
  scanf("%s", buffer);
  while(strcmp(buffer, "#") && mixa<INFO){

    New->info[mixa]=(char *)calloc(strlen(buffer)+1, sizeof(char));//Alloco lo spazio in memoria
    strcpy(New->info[mixa++], buffer);//Copia della stringa

    if(isalpha(buffer[0])){//Genera la stringa con l'iniziale nel caso inverso
      if(islower(buffer[0]))
        buffer[0]=toupper(buffer[0]);
      else
        buffer[0]=tolower(buffer[0]);

      New->info[mixa]=(char *)calloc(strlen(buffer)+1, sizeof(char));//Alloco lo spazio in memoria
      strcpy(New->info[mixa++], buffer);//Copia della stringa
    }
    scanf("%s", buffer);
  }
  New->mixa=mixa;
  return New;
}

void Link(Soggetto *New, Soggetto **head){
  int i;
  Soggetto *cur=*head, *pre=NULL;
  while(cur && strcmp(cur->cnome, New->cnome)<0){//Scorre la lista controllando il cognome
    pre=cur;
    cur=cur->next;
  }
  if(cur && !strcmp(cur->cnome, New->cnome))//Scorre la lista controllando il nome
    while(cur && strcmp(New->nome, cur->nome)>0){
      pre=cur;
      cur=cur->next;
    }
  if(cur && !strcmp(New->nome, cur->nome)){//Se i due soggetti sono omonimi il vecchio viene sostituito dal nuovo
    if(!pre){
      New->next=cur->next;
      *head=New;
    }else{
      New->next=cur->next;
      pre->next=New;
    }
    for(i=0;i<cur->mixa;i++)//Viene deallocato lo spazio in memoria
      free(cur->info[i]);
    free(cur->nome);
    free(cur->cnome);
    free(cur);
  }else if(!pre){//inserimento in testa
    New->next=*head;
    *head=New;
  }else{//inserimento nel mezzo o in coda
    New->next=cur;
    pre->next=New;
  }
}

void Save(Soggetto *cur, char *fname){
  int i;
  FILE *dest=fopen(fname, "w");
  while(cur){
    fprintf(dest, "%s %s # ", cur->cnome, cur->nome);
    for(i=0;i<(cur->mixa);i++)
      fprintf(dest, "%s ", cur->info[i]);
    fprintf(dest, "##\n");

    cur=cur->next;
  }
}

int Read(Soggetto **head, char *fname){
  FILE *src;
  int mixa;
  char buffer[200];

  if(!(src=fopen(fname, "r")))
    return -1;

  while(fscanf(src, "%s", buffer)!=EOF){
    mixa=0;
    Soggetto *New=(Soggetto *)malloc(sizeof(Soggetto));
    New->cnome=(char *)calloc(strlen(buffer)+1, sizeof(char));
    strcpy(New->cnome, buffer);

    fscanf(src, "%s", buffer);
    New->nome=(char *)calloc(strlen(buffer)+1, sizeof(char));//Alloca spazio in memoria
    strcpy(New->nome, buffer);//Copia la stringa

    fscanf(src, "%s", buffer);
    if(strcmp(buffer, "#"))//Lettura carattere di controllo
      return 0;

    fscanf(src, "%s", buffer);
    while(strcmp(buffer, "##") && mixa<INFO){
      New->info[mixa]=(char *)calloc(strlen(buffer)+1, sizeof(char));
      strcpy(New->info[mixa++], buffer);
      fscanf(src, "%s", buffer);
    }
    New->mixa=mixa;
    Link(New, head);
  }
  return 1;
}

Soggetto *Search(Soggetto *head, char *nome, char *cnome){
  Soggetto *cur=head, *pre=NULL;
  while(cur && strcmp(cnome, cur->cnome)>0){//Scorre la lista in base al cognome
    pre=cur;
    cur=cur->next;
  }
  if(cur && !strcmp(cur->cnome, cnome))//Scorre la lista in base al nome
    while(cur && strcmp(nome, cur->nome)>0){
      pre=cur;
      cur=cur->next;
    }
  if(cur && !strcmp(nome, cur->nome) && !strcmp(cnome, cur->cnome))//Se il soggetto cercato esiste
    return cur;
  else
    return NULL;
}

void Quickly(char *str[], int mixa){
  FILE *dest=fopen("diz.txt", "w");
  int i, j, h, r, g, f, e;
  //INIZIO CICLO
  for(i=1;i<mixa;i++){

    //SECONDO CICLO
    for(j=1;j<mixa;j++){
      if(!strcasecmp(str[i], str[j]))//Se le due stringhe sono uguali si esegue uno skip. Lo stesso avviene per ogni nuovo ciclo.
        continue;
      fprintf(dest, "%s%s\n", str[i], str[j]);

      //TERZO CICLO
      for(h=1;h<mixa;h++){
        if(!strcasecmp(str[i], str[h]) || !strcasecmp(str[j], str[h]))
          continue;
        fprintf(dest, "%s%s%s\n", str[i], str[j], str[h]);

        //QUARTO CICLO
        for(r=1;r<mixa;r++){
          if(!strcasecmp(str[i], str[r]) || !strcasecmp(str[j], str[r]) || !strcasecmp(str[h], str[r]))
            continue;
          fprintf(dest, "%s%s%s%s\n", str[i], str[j], str[h], str[r]);

          //QUINTO CICLO
          for(g=1;g<mixa;g++){
            if(!strcasecmp(str[i], str[g]) || !strcasecmp(str[j], str[g]) || !strcasecmp(str[h], str[g]) || !strcasecmp(str[r], str[g]))
              continue;
            fprintf(dest, "%s%s%s%s%s\n", str[i], str[j], str[h], str[r], str[g]);

            //SESTO CICLO
            for(f=1;f<mixa;f++){
              if(!strcasecmp(str[i], str[f]) || !strcasecmp(str[j], str[f]) || !strcasecmp(str[h], str[f]) || !strcasecmp(str[r], str[f]) || !strcasecmp(str[g], str[f]))
                continue;
              fprintf(dest, "%s%s%s%s%s%s\n", str[i], str[j], str[h], str[r], str[g], str[f]);

              //SETTIMO CICLO
              for(e=1;e<mixa;e++){
                if(!strcasecmp(str[i], str[e]) || !strcasecmp(str[j], str[e]) || !strcasecmp(str[h], str[e]) || !strcasecmp(str[r], str[e]) || !strcasecmp(str[g], str[e]) || !strcasecmp(str[f], str[e]))
                  continue;
                fprintf(dest, "%s%s%s%s%s%s%s\n", str[i], str[j], str[h], str[r], str[g], str[f], str[e]);
              }
            }
          }
        }
      }
    }
  }
  fclose(dest);
}

void Print(Soggetto *head, char *mode){
  int i;
  if(!strcmp(mode, "all"))//Stampa dell'intero elenco dei soggetti
    while(head){
      printf("%s %s\n", head->cnome, head->nome);
      head=head->next;
    }
  else{//Stampa di un unico soggetto
    printf("\n%s %s: ", head->cnome, head->nome);
    for(i=0;i<head->mixa;i++)
      i==0?printf("%s", head->info[i]):printf(", %s", head->info[i]);
  }
}

void Delete(Soggetto **head, char *cname, char *name){
  int i;
  Soggetto *cur=*head, *pre=NULL;
  while(cur && strcmp(cname, cur->cnome)>0){//Scorre la lista in base al cognome
    pre=cur;
    cur=cur->next;
  }
  if(cur && !strcmp(cur->cnome, cname))//Scorre la lista in base al nome
    while(cur && strcmp(name, cur->nome)>0){
      pre=cur;
      cur=cur->next;
    }

  if(cur && !strcmp(cur->nome, name)){
    if(!pre)//eliminazione in testa
      *head=cur->next;
    else//eliminazione in coda o nel mezzo
      pre->next=cur->next;

    //dealloca lo spazio in memoria
    for(i=0;i<cur->mixa;i++)
      free(cur->info[i]);

    free(cur->nome);
    free(cur->cnome);
    free(cur);
  }else
    printf("Il soggetto inserito non esiste.\n");
}

void Anagrafica(char *name, char *cname){
  printf("Inserisci il nome del soggetto: ");
  scanf("%s", name);
  printf("Inserisci il cognome del soggetto: ");
  scanf("%s", cname);
}
