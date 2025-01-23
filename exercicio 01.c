//EXERCICIO 01.
//FEITO EM LINGUAGEM C.

#include<stdio.h>
#include<string.h>
#include<ctype.h>



int ValidaNumeroRomano(char *romano) {
    int tamanho = strlen(romano);
    int repeticoes = 0;
    char ultimo = '\0';

    for (int i = 0; i < tamanho; i++) {
        char atual = toupper(romano[i]);

        
        if (atual != 'I' && atual != 'V' && atual != 'X' &&
            atual != 'L' && atual != 'C' && atual != 'D' && atual != 'M') {
            return 0; 
        }

        // aqui Contando repetições consecutivas do mesmo símbolo
        if (atual == ultimo) {
            repeticoes++;
            // agora, Verificando se passa o limite de 3 repetições para símbolos repetíveis
            if ((atual == 'I' || atual == 'X' || atual == 'C' || atual == 'M') && repeticoes > 3) {
                return 0; 
            }
            
            if (atual == 'V' || atual == 'L' || atual == 'D') {
                return 0; 
            }
        } else {
            repeticoes = 1;
        }

                    // nessa condição faço a verificação de subtraçoes inválidas
        if (i > 0) {
            char anterior = toupper(romano[i - 1]);

            if (anterior == 'I' && atual != 'V' && atual != 'X' && atual != 'I') {
                return 0;
            }
            if (anterior == 'X' && atual != 'L' && atual != 'C' && atual != 'X' && atual != 'I' && atual != 'V') {
                return 0;
            }
            if (anterior == 'C' && atual != 'D' && atual != 'M' && atual != 'C' && atual != 'X' && atual != 'L') {
                return 0;
            }
            if ((anterior == 'V' || anterior == 'L' || anterior == 'D') && atual == anterior) {
                return 0; 
            }
        }

        ultimo = atual;
    }

    return 1; 
}
        
        
        

int romanoParaDecimal(char *romano) { 
    int resultado = 0;
    int i = 0;
    int tamanho = strlen(romano);

    int valores[] = {1000, 500, 100, 50, 10, 5, 1};
    char simbolos[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

    while (i < tamanho) {
        int valorAtual = 0;
        int valorProximo = 0;

    
        for (int j = 0; j < 7; j++) {
            if (toupper(romano[i]) == simbolos[j]) {
                valorAtual = valores[j];
                break;
            }
        }

        
        if (i + 1 < tamanho) {
            for (int j = 0; j < 7; j++) {
                if (toupper(romano[i + 1]) == simbolos[j]) {
                    valorProximo = valores[j];
                    break;
                }
            }
        }

        // caso o valor atual for menor que o próximo, subtraio
        if (valorAtual < valorProximo) {
            resultado -= valorAtual;
        } else {
            resultado += valorAtual;
        }

        i++;
    }

    return resultado; 
}

                                // funcao de conversão de decimal para romano..
void decimalParaRomano(int numero) {
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < 13; i++) {
        while (numero >= valores[i]) {
            printf("%s", simbolos[i]);
            numero -= valores[i];
        }
    }
}

int main() {
    char escolha;
    char romano[20];
    int decimal;

    do {
        printf("\tMenu\n");
        printf("ESCOLHA UMA OPÇÃO :\n");
        printf("1. Romano para Decimal\n");
        printf("2. Decimal para Romano\n");
        printf("3. Sair\n");
        scanf(" %c", &escolha);  
    
        switch (escolha) {
            case '1':
                printf("Digite o número romano: ");
                scanf("%s", romano);
                if (ValidaNumeroRomano(romano)) {
                    int resultado = romanoParaDecimal(romano);
                    printf("O número romano %s é equivalente a: %d em decimal.\n", romano, resultado);
                }else 
                    printf("NUMERO INVÁLIDO,Tente novamente.\n");
                break;

            case '2':
                printf("Digite o número decimal: ");
                scanf("%d", &decimal);
                while (decimal <1 || decimal==0) {
                    printf("Apenas números positivos podem ser convertidos.\n");
                    printf("Digite o número decimal:\n ");
                    scanf("%d", &decimal);
                }
                printf("O número decimal %d é equivalente a: ", decimal);
                decimalParaRomano(decimal);
                printf(" em romano.\n");
                break;

            case '3':
                printf("Saindo...\n");
                break;

            default:
                printf("Escolha inválida, TENTE NOVAMENTE!\n");
        }
    }while(escolha != 3);
}
