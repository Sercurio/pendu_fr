#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ft_pendu.h"
#include "fichier.h"

int main(int argc, char const *argv[]) {

  FILE* fptr = NULL;
  char* motMystere;
  char* motEtoile;
  char lettreProposee = 0;
  char listeLettre[52] = {0};
  int tailleMot = 0;
  int win = 0;
  int essai = 9;
  int index = 0;
  int lettreTrouvee = 0;
  int indexListeLettre = 0;
  int nombreDeLigne = 0;


  //Ouverture du fichier
  fptr = fopen("dictionnaire.txt", "r");

  //L'ouverture a-t-elle fonctionnée?
  if(fptr != NULL){

    // Recuperation d'un mot pseudo-aleatoire dans le fichier dictionnaire.txt
    nombreDeLigne = nbLignes(fptr);
    motMystere = motAleatoire(fptr, chiffreAleatoire(0, nombreDeLigne));
    tailleMot = strlen(motMystere);

    motEtoile = malloc(strlen(motMystere)+1 * sizeof(char));

    initMot(motEtoile, motMystere);

    while(win != 1 && essai != 0){
      index = 0;
      printf("Veuillez rentrer une lettre\n");
      printf("Nombre d'essai restant : %d\n", essai);
      printf("Lettres deja proposee : %s\n", listeLettre);
      printf("%s\n", motEtoile);
      scanf(" %c", &lettreProposee);
      lettreProposee=toupper(lettreProposee);
      listeLettre[indexListeLettre] = lettreProposee;
      indexListeLettre++;
      listeLettre[indexListeLettre] = '\0';

      lettreTrouvee = 0;
      while(index != tailleMot){
        if(motMystere[index] == lettreProposee){
          motEtoile[index] = lettreProposee;
          lettreTrouvee = 1;
        }
        index++;
      }
      if(lettreTrouvee == 1)
        essai++;

      win = checkWin(motEtoile);
      essai--;
      drawPendu(essai);
    }

    if(win == 1){
      printf("t'as gagne\n%s", motMystere);
    }
    else if(win == 0 && essai == 0){
      printf("t'as perdu, Le mot etait %s", motMystere);
    }
  }
  return 0;
}
