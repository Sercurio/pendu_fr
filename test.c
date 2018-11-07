#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_pendu.h"

int main(int argc, char const *argv[]) {

  char* motMystere = "communisme";
  char* motEtoile;
  char lettreProposee = 0;
  char listeLettre[52] = {0};
  int tailleMot = ft_strlen(motMystere);
  int win = 0;
  int essai = 9;
  int index = 0;
  int lettreTrouvee = 0;
  int indexListeLettre = 0;

  //motMystere = pickWord();

  motEtoile = malloc((tailleMot + 1) * sizeof(char));

  while(motMystere[index] != '\0'){
    motEtoile[index] = '*';
    index++;
  }
  motEtoile[index] = '\0';

  while(win != 1 && essai != 0){
    index = 0;
    ft_putstr("Veuillez rentrer une lettre\n");
    ft_putstr("Nombre d'essai restant : ");
    ft_putchar(essai + 48);
    ft_putchar('\n');
    ft_putstr("Lettres deja proposee : ");
    ft_putstr(listeLettre);
    ft_putchar('\n');
    ft_putstr(motEtoile);
    ft_putchar('\n');
    scanf(" %c", &lettreProposee);
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
    ft_putstr("t\'as gagn");
    ft_putchar(130);
    ft_putstr(" man");
  }
  else if(win == 0 && essai == 0){
    ft_putstr("t\'as perdu");
  }
  return 0;
}

char* pickWord(){
  FILE* fptr;
  int caractereLu = 0;
  char listeMot[10][10];
  int i = 0;
  int j = 0;
  char* ptr;

  fptr = fopen("dictionnaire.txt", "r");
  if (fptr == NULL)
    ft_putstr("Erreur ouverture fichier dictionnaire.txt");
  else{
    while(caractereLu != EOF){
      j = 0;
      while(caractereLu != '\0'){
        caractereLu = fgetc(fptr);
        listeMot[i][j] = caractereLu;
        j++;
      }
      i++;
    }
    fclose(fptr);
  }
  ft_putstr(listeMot[0]);
  ptr = listeMot[1];
  return ptr;
}
