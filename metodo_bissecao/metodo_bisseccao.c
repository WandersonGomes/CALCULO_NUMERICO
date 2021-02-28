#include <stdio.h>

//FUNCAO
double funcao(double x) {
    return (x*x*x) - (9 * x) + 1; //x^3 - 9x + 1
}

//METODO DA BISSECCAO
double metodoBisseccao(double a, double b, double precisao, int max_iteracoes) {
    int iteracao = 0;
    double x = 0.00;
    double aux = 0.00;

    //garantir que o b seja maior do que o a
    if (b < a) {
        aux = b;
        b = a;
        a = aux;
    }

    if ((funcao(a) * funcao(b)) > 0) {
        printf("Atencao: nao existe raizes para a funcao neste intervalo.\n");
        return 0.00;
    }

    if ((b - a) < precisao)
        return (a + b)/2;
    
    for (iteracao = 1; iteracao <= max_iteracoes; iteracao++) {
        x = (a + b)/2;
        
        printf("\nX%d = %lf, F(X%d) = %lf, a = %lf, b = %lf\n", iteracao, x, iteracao, funcao(x), a, b);

        if ((funcao(a) * funcao(x)) > 0) {
            a = x;
        } else {
            b = x;
        }

        if ((b - a) < precisao) {
            return (a + b)/2;
        }
    }

    return (a + b)/2;
}

//PROGRAMA PRINCIPAL
int main() {
    //intervalo
    double a = 0.00, b = 0.00;
    //precisao
    double precisao = 0.00;
    //max iteracoes
    int max_iteracoes = 0;
    //raiz encontrada
    double raiz_encontrada = 0.00;

    //leitura dos dados
    printf("Informe o valor de a: ");
    scanf("%lf", &a);
    printf("Informe o valor de b: ");
    scanf("%lf", &b);

    do {
        printf("Informe a precisao desejada: ");
        scanf("%lf", &precisao);
        if (precisao <= 0.00)
            printf("Error: precisao invalida! Tente novamente.\n");
    } while (precisao <= 0.00);

    do {
        printf("Informe o numero maximo de iteracoes: ");
        scanf("%d", &max_iteracoes);
        if (max_iteracoes <= 0.00)
            printf("Error: valor invalido! Tente novamente.\n");
    } while (max_iteracoes <= 0.00);

    //calculo
    raiz_encontrada = metodoBisseccao(a, b, precisao, max_iteracoes);

    //apresentacao dos dados
    printf("\nA RAIZ ENCONTRADA FOI: %lf\n", raiz_encontrada);

    return 0;
}