#ifndef LIBFT_H
#define LIBFT_H

void ft_putchar(char);
void ft_putstr(char*);
int ft_strlen(char*);

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

#endif
