#ifndef FT_PENDU_H
#define FT_PENDU_H

#include "libft.h"

int checkWin(char*);
void drawPendu(int);

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

#endif
