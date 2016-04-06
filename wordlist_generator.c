/*
 ============================================================================
 Name        : GeneratoreDizionari.c
 Author      : Sh13n
 Version     :
 Copyright   : OpenSource
 Description : Generatore di dizionari in C, alpha 0.1
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	FILE * string;
    FILE *dic;
	int c;
	int mixa = 0;

	char info1[128] = "vuoto";
	char info2[128] = "vuoto";
	char info3[128] = "vuoto";
	char info4[128] = "vuoto";
	char info5[128] = "vuoto";
	char info6[128] = "vuoto";
	char info7[128] = "vuoto";
	char info8[128] = "vuoto";
	char info9[128] = "vuoto";
	char info10[128] = "vuoto";

	char cont[128];
	char cont2[128];
	char cont3[128];
	char cont4[128];
	char cont5[128];
	char cont6[128];
	char cont7[128];

	int i;
	int j;
	int h;
	int r;
	int g;
	int f;
	int d;
	int z;

	//INSERIMENTO VALORI SUL FILE
	string = fopen("string", "w");
	if(string == NULL){printf("Errore");}
	else{
		printf("Inserisci informazioni sul target separate da spazi.\nQuando hai terminato inserisci il cancelletto '#' e premi invio\nEsempio: franco rossi 1990 milan roberta #\n");

		do{
			c=getchar();
			fputc(c, string);
		} while(c != 35);
		fclose(string);
	}

	rewind(string);
	string = fopen("string" , "r");
	fscanf(string,"%s %s %s %s %s %s %s %s %s %s",info1,info2,info3,info4,info5,info6,info7,info8,info9,info10 );
	fclose(string);

	//CONTROLLO SE L'UTENTE HA INSERITO VALORI NEGLI ARRAY
	if (strcmp(info1, "vuoto") == 0){} else if(strcmp(info1, "#") == 0){} else{mixa++;}
	if (strcmp(info2, "vuoto") == 0){} else if(strcmp(info2, "#") == 0){} else{mixa++;}
	if (strcmp(info3, "vuoto") == 0){} else if(strcmp(info3, "#") == 0){} else{mixa++;}
	if (strcmp(info4, "vuoto") == 0){} else if(strcmp(info4, "#") == 0){} else{mixa++;}
	if (strcmp(info5, "vuoto") == 0){} else if(strcmp(info5, "#") == 0){} else{mixa++;}
	if (strcmp(info6, "vuoto") == 0){} else if(strcmp(info6, "#") == 0){} else{mixa++;}
	if (strcmp(info7, "vuoto") == 0){} else if(strcmp(info7, "#") == 0){} else{mixa++;}
	if (strcmp(info8, "vuoto") == 0){} else if(strcmp(info8, "#") == 0){} else{mixa++;}
	if (strcmp(info9, "vuoto") == 0){} else if(strcmp(info9, "#") == 0){} else{mixa++;}
	if (strcmp(info10, "vuoto") == 0){} else if(strcmp(info10, "#") == 0){} else{mixa++;}

	//APERTURA FILE
	dic= fopen("dict", "w");

	//INIZIO CICLO
	for(i=1; i<mixa+1; i++){

		if(i==1){
		for(z=0;z<128;z++){
		cont[z]=info1[z]; }
		}
		else if(i==2){
		for(z=0;z<128;z++){
		cont[z]=info2[z]; }
		}
		else if(i==3){
		for(z=0;z<128;z++){
		cont[z]=info3[z]; }
		}
		else if(i==4){
		for(z=0;z<128;z++){
		cont[z]=info4[z]; }
		}
		else if(i==5){
		for(z=0;z<128;z++){
		cont[z]=info5[z]; }
		}
		else if(i==6){
		for(z=0;z<128;z++){
		cont[z]=info6[z]; }
		}
		else if(i==7){
		for(z=0;z<128;z++){
		cont[z]=info7[z]; }
		}
		else if(i==8){
		for(z=0;z<128;z++){
		cont[z]=info8[z]; }
		}
		else if(i==9){
		for(z=0;z<128;z++){
		cont[z]=info9[z]; }
		}
		else if(i==10){
		for(z=0;z<128;z++){
		cont[z]=info10[z]; }
		}

		//SECONDO CICLIO
		for(j=1; j<mixa+1; j++){

			if(j==1){
			for(z=0;z<128;z++){
			cont2[z]=info1[z]; }
			}
			else if(j==2){
			for(z=0;z<128;z++){
			cont2[z]=info2[z]; }
			}
			else if(j==3){
			for(z=0;z<128;z++){
			cont2[z]=info3[z]; }
			}
			else if(j==4){
			for(z=0;z<128;z++){
			cont2[z]=info4[z]; }
			}
			else if(j==5){
			for(z=0;z<128;z++){
			cont2[z]=info5[z]; }
			}
			else if(j==6){
			for(z=0;z<128;z++){
			cont2[z]=info6[z]; }
			}
			else if(j==7){
			for(z=0;z<128;z++){
			cont2[z]=info7[z]; }
			}
			else if(j==8){
			for(z=0;z<128;z++){
			cont2[z]=info8[z]; }
			}
			else if(j==9){
			for(z=0;z<128;z++){
			cont2[z]=info9[z]; }
			}
			else if(j==10){
			for(z=0;z<128;z++){
			cont2[z]=info10[z]; }
			}

			fprintf(dic,"\n%s%s",cont,cont2);

			//TERZO CICLO
			if((mixa > 3) || (mixa == 3)){
				for(h=1; h<mixa+1; h++){

					if(h==1){
					for(z=0;z<128;z++){
					cont3[z]=info1[z]; }
					}
					else if(h==2){
					for(z=0;z<128;z++){
					cont3[z]=info2[z]; }
					}
					else if(h==3){
					for(z=0;z<128;z++){
					cont3[z]=info3[z]; }
					}
					else if(h==4){
					for(z=0;z<128;z++){
					cont3[z]=info4[z]; }
					}
					else if(h==5){
					for(z=0;z<128;z++){
					cont3[z]=info5[z]; }
					}
					else if(h==6){
					for(z=0;z<128;z++){
					cont3[z]=info6[z]; }
					}
					else if(h==7){
					for(z=0;z<128;z++){
					cont3[z]=info7[z]; }
					}
					else if(h==8){
					for(z=0;z<128;z++){
					cont3[z]=info8[z]; }
					}
					else if(h==9){
					for(z=0;z<128;z++){
					cont3[z]=info9[z]; }
					}
					else if(h==10){
					for(z=0;z<128;z++){
					cont3[z]=info10[z]; }
					}
					fprintf(dic,"\n%s%s%s",cont,cont2,cont3);
					//QUARTO CICLO
					if((mixa > 4) || (mixa == 4)){
						for(r=1; r<mixa+1; r++){

							if(r==1){
							for(z=0;z<128;z++){
							cont4[z]=info1[z]; }
							}
							else if(r==2){
							for(z=0;z<128;z++){
							cont4[z]=info2[z]; }
							}
							else if(r==3){
							for(z=0;z<128;z++){
							cont4[z]=info3[z]; }
							}
							else if(r==4){
							for(z=0;z<128;z++){
							cont4[z]=info4[z]; }
							}
							else if(r==5){
							for(z=0;z<128;z++){
							cont4[z]=info5[z]; }
							}
							else if(r==6){
							for(z=0;z<128;z++){
							cont4[z]=info6[z]; }
							}
							else if(r==7){
							for(z=0;z<128;z++){
							cont4[z]=info7[z]; }
							}
							else if(r==8){
							for(z=0;z<128;z++){
							cont4[z]=info8[z]; }
							}
							else if(r==9){
							for(z=0;z<128;z++){
							cont4[z]=info9[z]; }
							}
							else if(r==10){
							for(z=0;z<128;z++){
							cont4[z]=info10[z]; }
							}
							fprintf(dic,"\n%s%s%s%s",cont,cont2,cont3,cont4);
							//INIZIO QUINTO CICLO
							if((mixa > 5) || (mixa == 5)){
								for(g=1; g<mixa+1; g++){

									if(g==1){
									for(z=0;z<128;z++){
									cont5[z]=info1[z]; }
									}
									else if(g==2){
									for(z=0;z<128;z++){
									cont5[z]=info2[z]; }
									}
									else if(g==3){
									for(z=0;z<128;z++){
									cont5[z]=info3[z]; }
									}
									else if(g==4){
									for(z=0;z<128;z++){
									cont5[z]=info4[z]; }
									}
									else if(g==5){
									for(z=0;z<128;z++){
									cont5[z]=info5[z]; }
									}
									else if(g==6){
									for(z=0;z<128;z++){
									cont5[z]=info6[z]; }
									}
									else if(g==7){
									for(z=0;z<128;z++){
									cont5[z]=info7[z]; }
									}
									else if(g==8){
									for(z=0;z<128;z++){
									cont5[z]=info8[z]; }
									}
									else if(g==9){
									for(z=0;z<128;z++){
									cont5[z]=info9[z]; }
									}
									else if(g==10){
									for(z=0;z<128;z++){
									cont5[z]=info10[z]; }
									}
									fprintf(dic,"\n%s%s%s%s%s",cont,cont2,cont3,cont4,cont5);

									//INIZIO SESTO CICLO
									if((mixa > 6) || (mixa == 6)){
										for(f=1; f<mixa+1; f++){

											if(f==1){
											for(z=0;z<128;z++){
											cont6[z]=info1[z]; }
											}
											else if(f==2){
											for(z=0;z<128;z++){
											cont6[z]=info2[z]; }
											}
											else if(f==3){
											for(z=0;z<128;z++){
											cont6[z]=info3[z]; }
											}
											else if(f==4){
											for(z=0;z<128;z++){
											cont6[z]=info4[z]; }
											}
											else if(f==5){
											for(z=0;z<128;z++){
											cont6[z]=info5[z]; }
											}
											else if(f==6){
											for(z=0;z<128;z++){
											cont6[z]=info6[z]; }
											}
											else if(f==7){
											for(z=0;z<128;z++){
											cont6[z]=info7[z]; }
											}
											else if(f==8){
											for(z=0;z<128;z++){
											cont6[z]=info8[z]; }
											}
											else if(f==9){
											for(z=0;z<128;z++){
											cont6[z]=info9[z]; }
											}
											else if(f==10){
											for(z=0;z<128;z++){
											cont6[z]=info10[z]; }
											}
											fprintf(dic,"\n%s%s%s%s%s%s",cont,cont2,cont3,cont4,cont5,cont6);

											//INIZIO SETTIMO CICLO
											if((mixa > 7) || (mixa == 7)){
												for(d=1; d<mixa+1; d++){

													if(d==1){
													for(z=0;z<128;z++){
													cont7[z]=info1[z]; }
													}
													else if(d==2){
													for(z=0;z<128;z++){
													cont7[z]=info2[z]; }
													}
													else if(d==3){
													for(z=0;z<128;z++){
													cont7[z]=info3[z]; }
													}
													else if(d==4){
													for(z=0;z<128;z++){
													cont7[z]=info4[z]; }
													}
													else if(d==5){
													for(z=0;z<128;z++){
													cont7[z]=info5[z]; }
													}
													else if(d==6){
													for(z=0;z<128;z++){
													cont7[z]=info6[z]; }
													}
													else if(d==7){
													for(z=0;z<128;z++){
													cont7[z]=info7[z]; }
													}
													else if(d==8){
													for(z=0;z<128;z++){
													cont7[z]=info8[z]; }
													}
													else if(d==9){
													for(z=0;z<128;z++){
													cont7[z]=info9[z]; }
													}
													else if(d==10){
													for(z=0;z<128;z++){
													cont7[z]=info10[z]; }
													}

													fprintf(dic,"\n%s%s%s%s%s%s%s",cont,cont2,cont3,cont4,cont5,cont6,cont7);

												}//fino for settimo cilco
											}//fine if settimo ciclo
										}//fine for sesto ciclo
									}//fine if sesto ciclo

								}//fine for quinto ciclo
							}//fine if quinto ciclo

						}//fine if quarto ciclo
					}//fine if quarto ciclo
				}//fine for terzo ciclo
			}//fine if terzo ciclo

		}//fine secondo ciclo

	}
	fclose(dic);

	printf("\ndizionario creato con successo, il nome del dizionario è dict.");

    return EXIT_SUCCESS;

}
