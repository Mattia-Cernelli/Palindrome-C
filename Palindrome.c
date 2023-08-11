/* 
1) Il programma chiede all'utente di inserire una stringa (max 99 char) e la memorizza in un vettore stringa[100], poi viene passata
alla funzione char*store_vect che copia la stringa in un nuovo vettore puntato da temp allocato
dinamicamente, la cui dimensione coincide esattamente con la dimensione della stringa (la stringa è
memorizzata in un vettore di 100 caratteri ma potrà essere composta da un numero minore di caratteri).
La funzione restituisce l’indirizzo del vettore allocato dinamicamente.  

2) int pal (char *): ricevuto l’indirizzo della stringa, verifica se è palindroma: restituisce 1 (la stringa esiste)
o 0 (la stringa non esiste). Utilizzare la notazione puntatore e vettore (Punti 7)

3) char* cerca_pal(char *data[], char *): Determina se la stringa passata è contenuta nell'array di puntatori e ne 
restituisce l'indirizzo solo se è palindroma. 

4) char* reverse(char *): usando la notazione puntatore inverte la stringa, a cui punta s1, copiandola in un
nuovo vettore allocato dinamicamente di cui restituisce l’indirizzo. 

5) int conta(char *, int *, int *): la funzione restituisce il numero di caratteri della stringa passata, riceve due interi passati per riferimento 
rispettivamente voc e cons e li modifica contando vocali e consonanti.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

//def. prototipi 
char* store_vect();
int pal(char *);
char* cerca_pal(char **, char *);
char* reverse (char *);
int conta(char *, int *, int *);

int main(){

char stringa[100];
char *str;
char *strPtr;
char *rev;
int dim , voc, cons;

char *data[MAX] ={"tenet", "abxnao", "xxppxx", "cfsav", "sgdsgvb"};

printf("Inserisci una stringa(max 99 char): ");
scanf("%s", stringa);

str = store_vect(stringa);

strPtr = cerca_pal(data, str);

if(strPtr){
	printf("La stringa %s è presente nell'archivio ed è palindroma, indirizzo: %p \n", str, strPtr);
}

rev = reverse(str);

printf("La stringa %s in reverse é %s \n", str, rev);

dim = conta(str, &voc,&cons);

printf("La stringa contiene %d caratteri, %d vocali, %d consonanti \n", dim, voc, cons);
return 0;
}


char * store_vect(char s[]){
char *temp = (char *) calloc(strlen(s) , sizeof(char));
if(!temp){
	printf("Lo spazio richiesto non è disponibile \n");
	exit(0);
}
strcpy(temp, s);
return temp;
}

//Traccia: utilizzare notazione puntatore e vettore 

//notazione puntatore
int pal(char *string){
int dim = strlen(string);
	for(int i=0; i<dim/2; i++){ 
		if(*(string + i) != *(string+dim-1-i))
      		return 0;
  		return 1;
  	}
}
 
/*notazione vettore
int pal(char string[]){
int dim = strlen(string);
	for(int i=0;i<dim/2;i++){
		if(string[i] != string[dim-1-i])
      		return 0;
  		return 1;
	}

}*/

char *cerca_pal(char **archivio, char *str){

int i;

	for(i=0;i<MAX;i++)
		if((!strcmp(archivio[i], str)) && pal(str))
			return archivio[i];
return NULL;
}

char* reverse (char* s1){
int dim = strlen(s1);
char* temp = malloc(dim+1);
	for(int i=0; i<dim; i++)
		*(temp+i)=*(s1+dim-1-i);
		*(s1+dim)='\0';
return temp;
}

int conta(char vect[], int *voc, int *cons){
*voc = 0;
*cons = 0;
int i;
	for(i = 1; i<=strlen(vect); i++){
		if( (vect[i] == 'a') || (vect[i] == 'e') || (vect[i] == 'i') || (vect[i] == 'o') || (vect[i] == 'u'))
			(*voc)++;
		else 
			(*cons)++;
	}

return i-1;
}
