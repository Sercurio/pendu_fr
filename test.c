#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c);
void ft_putstr(char* str);
int ft_strlen(char* str);
int checkWin(char* str);
char* pickWord();

int main(int argc, char const *argv[]) {

  char* motMystere = "communisme";
  char* motEtoile;
  char lettreProposee = 0;
  int tailleMot = ft_strlen(motMystere);
  int win = 0;
  int essai = 9;
  int index = 0;
  int lettreTrouvee = 0;

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
    ft_putstr(motEtoile);
    ft_putchar('\n');
    scanf(" %c", &lettreProposee);

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
    switch (essai) {
      case 8: ft_putstr("____\n");break;
      case 7: ft_putstr("  |\n  |\n  |\n  |\n__|__\n\n");break;
      case 6: ft_putstr("   ____\n  |\n  |\n  |\n  |\n__|__\n\n");break;
      case 5: ft_putstr("   ____\n  |/\n  |\n  |\n  |\n__|__\n\n");break;
      case 4: ft_putstr("   ____\n  |/   |\n  |\n  |\n  |\n__|__\n\n");break;
      case 3: ft_putstr("   ____\n  |/   |\n  |    O\n  |\n  |\n__|__\n\n");break;
      case 2: ft_putstr("   ____\n  |/   |\n  |    O\n  |   /|\\\n  |   \n__|__\n\n");break;
      case 1: ft_putstr("   ____\n  |/   |\n  |    O\n  |   /|\\\n  |   /-\\\n__|__\n\n");break;
    }
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

//La fameuse methode putchar
void ft_putchar(char c){
  write(1, &c, 1);
}

//Le putchar amélioré
void ft_putstr(char* str){
  while(*str != '\0'){
    ft_putchar(*str);
    str++;
  }
}

//Une methode pour compter le nombre de caractere d'une chaine
int ft_strlen(char* str){
  int len = 0;
  while(*str != '\0'){
    str++;
    len++;
  }
  return len;
}

//Une methode pour verifier si le joueur a gagner
int checkWin(char* str){
  int win = 1;

  while(*str != '\0'){
    if(*str == '*')
      win = 0;
    str++;
  }
  return win;
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
