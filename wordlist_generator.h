/*
============================================================================
Name        : Generatoredestionari.c
Author      : Sh13n, Orange_dugongo
Version     : alpha 0.4
Copyright   : CC BY-SA 3.0 IT
Description : Generatore di dizionari in C
============================================================================
 */

#include "wordlist_generator.c"

//LEGGE LE INFO DA TASTIERA E LE SALVA SU UN FILE
int Inserisci(char *buffer);

//LEGGE LE INFO DA UN FILE E LE CARICA IN MEMORIA
int Load(FILE *src, char *buffer);

//LEGGE LE INFO DA MEMORIA E GENERA IL DIZIONARIO
void Generazione(FILE *dest, int mixa);
