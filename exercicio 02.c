//EXERCICIO 02.
//Gerar senhas a parƟr de opções com caracterísƟcas especificas que são selecionas pelo usuário. Demandas Essenciais
//1. O usuário pode definir a quanƟdade de caracteres que será gerado;
//2. O usuário pode escolher múlƟplas opções entre:
//a. Incluir uma letra maiúscula;
//b. Incluir uma letra minúscula;
//c. Incluir um número;
//d. Incluir um símbolo;
//3. O usuário pode clicar no botão “Copiar para a área de transferência”, que salvará a senha na área de transferência;
//1. O usuário pode ver a força da senha;
//2. O usuário pode selecionar a opção para incluir um emoji a senha;

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>


char gerarMaiuscula() {
   return 'A' + rand() % 26;
}


char gerarMinuscula() {
  return 'a' + rand() %26;

}

char gerarNumero() {
  return '0' + rand() %10;
}

char gerarSimbolo() {
  char simbolos[] = "!@#$%^&*()_+[]{}|;:,.<>?";
  return simbolos[rand()  %strlen(simbolos)];
}

void gerarSenha(char *senha, int tamanho, int incluirMaiuscula, int incluirMinuscula,int incluirNumero,int incluirSimbolo) {
  int i = 0;
  int tipos[4], numTipos = 0;
  

  if (incluirMaiuscula) tipos [numTipos++] = 0; 
  if (incluirMinuscula) tipos[numTipos++] = 1;
  if (incluirNumero) tipos[numTipos++] = 2;
  if (incluirSimbolo) tipos[numTipos++] = 3;

  while (i<tamanho) {
    int escolha = tipos[rand() % numTipos];
    switch(escolha) {
      case 0: 
        senha[i++] = gerarMaiuscula(); 
        break;
      case 1 :
        senha[i++] = gerarMinuscula();
          break;
      case 2:
        senha[i++] = gerarNumero();
        break;
      case 3 :
        senha[i++] = gerarSimbolo();
        break;
    }
  }
  senha[i] = '\0';
}
      
void avaliaForca(const char *senha) {
  int comprimento = strlen(senha);
  int temMaiuscula = 0, temMinuscula = 0, temNumero = 0, temSimbolo = 0;
  for (int i = 0; senha[i] != '\0'; i++) {
    if (isupper(senha[i])) {
      temMaiuscula =1;
    }else if (islower(senha[i])) {
      temMinuscula =1;
    }else if (isdigit(senha[i])) {
      temNumero =1;
    }else 
      temSimbolo =1;
  }

  int tipos = temMaiuscula + temMinuscula + temNumero + temSimbolo;

   
    printf("Força da senha:");

    
   if (comprimento < 6) {
     printf("Senha muito fraca (muito curta).\n");
   } else {
    
     if (tipos != 4) {
       printf(" Senha fraca (apenas um tipo de caractere).\n");
     } else if (tipos == 4) {
       printf(" Senha muito forte (quatro tipos de caracteres).\n");
     }
   }
}

  
int main() {
  int escolha,tamanho;
  char senha[100];
  srand(time(NULL)); 
  
  do {
    printf("\t---MENU---\n");
    printf("1.Gerar senha com letra maiuscula\n");
    printf("2.Gerar senha com letra minuscula\n");
    printf("3.Gerar senha com numeros \n");
    printf("4.Gerar senha com simbolos\n");
    printf("5.Gerar senha com todas opções\n");
    printf("6.Sair\n");
    scanf("%d", &escolha);

    if (escolha>=1 && escolha<=5) {
      printf("Digite a quantidade de caracteres :\n");
      scanf("%d", &tamanho);
      if (tamanho<1 ) {
        printf("Tamanho de senha inválida.\n");
        continue;
      }
    
    switch(escolha) {
      case 1:
        gerarSenha (senha,tamanho,1,0,0,0);
        break;
      
      case 2:
        gerarSenha(senha,tamanho,0,1,0,0);
        break;
      
      case 3 :
        gerarSenha(senha,tamanho,0,0,1,0);
        break;
      
      case 4 : 
        gerarSenha(senha,tamanho,0,0,0,1);
        break;

      case 5 :
        gerarSenha(senha,tamanho,1,1,1,1);
        break;
      }
      printf("Senha gerada : %s\n", senha);
      avaliaForca(senha);
    }else if (escolha!= 6) {
      printf("ESCOLHA INVÁLIDA, TENTE NOVAMENTE.\n");
    }
    
  }while(escolha!=6);
    printf("Saindo do programa...\n");
  
}

    

  

  
  

