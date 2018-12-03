#ifndef FT_FICHIER_H
#define FT_FICHIER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR 26

int nbLignes(FILE*);
char* motAleatoire(FILE*, int);
int chiffreAleatoire(int, int);

int nbLignes(FILE* fichier){
  int i = 0;
  char *ligne = malloc(MAX_CHAR * sizeof(char));

  while(fgets(ligne, MAX_CHAR, fichier)) i++;
  free(ligne);
  return i;
}

int chiffreAleatoire(int min, int max){
  int chiffreAleatoire = -1;

  srand(time(NULL));
  chiffreAleatoire = min + rand() % ((max - min) + 1);

  return chiffreAleatoire;
}

char* motAleatoire(FILE* fichier, int noLigne){
    int i=0;
    char* mot = malloc(MAX_CHAR * sizeof(char));

    fseek(fichier, 0, SEEK_SET);

    while(i < noLigne)
    {
        mot = fgets(mot, MAX_CHAR, fichier);
        i++;
    }
    //i = 0;
    /*while(mot[i] != '\0')
      if (mot[i] == '\0') {
        mot[i] = '\0';
      }
      else{
        i++;
      }*/
    return mot;
}

#endif
