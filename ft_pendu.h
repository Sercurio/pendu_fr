#ifndef FT_PENDU_H
#define FT_PENDU_H

int checkWin(char*);
void drawPendu(int);
void initMot(char*, char*);

//Une methode pour verifier si le joueur a gagné
int checkWin(char* str){
  int win = 1;

  while(*str != '\0'){
    if(*str == '*')
      win = 0;
    str++;
  }
  return win;
}

//Une fonction qui dessine le pendu en fonction du nombre d'essais restants
void drawPendu(int essai){
  switch (essai) {
    case 8: printf("____\n");break;
    case 7: printf("  |\n  |\n  |\n  |\n__|__\n\n");break;
    case 6: printf("   ____\n  |\n  |\n  |\n  |\n__|__\n\n");break;
    case 5: printf("   ____\n  |/\n  |\n  |\n  |\n__|__\n\n");break;
    case 4: printf("   ____\n  |/   |\n  |\n  |\n  |\n__|__\n\n");break;
    case 3: printf("   ____\n  |/   |\n  |    O\n  |\n  |\n__|__\n\n");break;
    case 2: printf("   ____\n  |/   |\n  |    O\n  |   /|\\\n  |   \n__|__\n\n");break;
    case 1: printf("   ____\n  |/   |\n  |    O\n  |   /|\\\n  |   /-\\\n__|__\n\n");break;
  }
}

void initMot(char* motEtoile, char* motMystere){
  int i = 0;

  while(motMystere[i] != '\0'){
    motEtoile[i] = '*';
    i++;
  }
  motEtoile[i - 1] = '\0';
}

#endif
