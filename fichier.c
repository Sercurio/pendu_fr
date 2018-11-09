#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 26

int nbLignes(FILE*);

int main(int argc, char const *argv[]) {
  //Declaration & Initialisation
  FILE* fptr = NULL;
  char* mot = NULL;
  int nombreDeLigne = 0;

  //Allocation dynamique pour la taille de nos mots récupérés
  mot = malloc(MAX_CHAR * sizeof(char));

  //Ouverture du fichier
  fptr = fopen("dictionnaire.txt", "r");

  //L'ouverture a-t-elle fonctionnée?
  if(fptr != NULL){
    //On recupere le nombre total de lignes du fichier
    nombreDeLigne = nbLignes(fptr);

    printf("%d",nombreDeLigne);


  }

  return 0;
}

int nbLignes(FILE* fichier){
  int i = 0;
  char *ligne = malloc(MAX_CHAR * sizeof(char));

  while(fgets(ligne, MAX_CHAR, fichier)) i++;
  free(ligne);
  return i;
}
