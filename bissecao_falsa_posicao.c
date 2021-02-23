//DISCIPLINA DE CALCULO NUMERICO
//PROF. LUCAS CAMPOS
//ALUNO: WANDERSON GOMES DA COSTA
//INSTITUICAO: IFCE - CAMPUS TIANGUA
//SEMESTRE: 2021.1
//IMPLEMENTACAO EM C DO METODO DA BISSECAO E DA FALSA POSICAO
#include <stdio.h>

//FUNCAO A SER ANALISADA
double funcao(double x){
	return ((x*x*x) + (7*x*x) - (6*x) + 1);
}

//FUNCAO QUE RETORNA O VALOR ABSOLUTO DO NUMERO (MODULO)
double modulo(double numero) {
	return (numero < 0) ? (-1)*numero : numero;
}

//METODO DA BISSECCAO
double metodoBissecao(double a, double b, long long int max_iteracao, double erro) {
	double auxiliar = 0.00;
	double meio = 0.00;
	long long int iteracao = 0;

	//teste do teorema de Bolzano
	if ((funcao(a) * funcao(b)) > 0) {
		printf("ATENCAO: NO INTERVALO DADO NAO EXISTE RAIZES!\n");
		return 0.00;
	}

	//configura para que o valor de b seja o maior
	if (b < a) {
		auxiliar = b;
		b = a;
		a = auxiliar;
	}

	//calcula o primeiro meio
	meio = a + (b - a)/2;

	//aplica o metodo da bissecao
	while ((modulo(funcao(b) - funcao(a)) > erro) && (modulo(funcao(meio)) > erro) && (iteracao <= max_iteracao)) {
		//apresenta a tabela
		printf("A = %lf, B = %lf, MEIO = %lf, ITERACAO = %lld\n", a, b, meio, iteracao);
		
		//atualiza os dados
		if ((funcao(a) * funcao(meio)) < 0)
			b = meio;
		else
			a = meio;

		meio = a + (b - a)/2;

		iteracao++;
	}

	return meio;
}

//METODO DA FALSA POSICAO
double metodoFalsaPosicao(double a, double b, long long int max_iteracao, double erro) {
	double auxiliar = 0.00;
	double posicao = 0.00;
	long long int iteracao = 0;

	//teste do teorema de Bolzano
	if ((funcao(a) * funcao(b)) > 0) {
		printf("ATENCAO: NO INTERVALO DADO NAO EXISTE RAIZES!\n");
		return 0.00;
	}

	//configura para que o valor de b seja o maior
	if (b < a) {
		auxiliar = b;
		b = a;
		a = auxiliar;
	}

	//calcula a primeira posicao
	posicao = (a*funcao(b) - b*funcao(a))/(funcao(b) - funcao(a));

	//aplica o metodo da bissecao
	while ((modulo(funcao(b) - funcao(a)) > erro) && (modulo(funcao(posicao)) > erro) && (iteracao <= max_iteracao)) {
		//apresenta a tabela
		printf("A = %lf, B = %lf, POSICAO = %lf, ITERACAO = %lld\n", a, b, posicao, iteracao);
		
		//atualiza os dados
		if ((funcao(a) * funcao(posicao)) < 0)
			b = posicao;
		else
			a = posicao;

		posicao = (a*funcao(b) - b*funcao(a))/(funcao(b) - funcao(a));

		iteracao++;
	}

	return posicao;
}

//PROGRAMA PRINCIPAL
int main() {
	//dados necessarios
	double a = 0.00, b = 0.00;
	long long int max_iteracao = 0;
	double erro = 0.00, raiz = 0.00;

	//leitura dos dados
	printf("Informe o valor de (a): ");
	scanf("%lf", &a);
	printf("Informe o valor de (b): ");
	scanf("%lf", &b);
	printf("Informe o maximo de iteracoes: ");
	scanf("%lld", &max_iteracao);
	printf("Informe o valor do erro: ");
	scanf("%lf", &erro);

	//calculo da raiz pelo metodo da bissecao
	printf("\nMETODO BISSECAO\n");
	raiz = metodoBissecao(a, b, max_iteracao, erro);
	
	//apresenta o resultado
	printf("\nRAIZ = %.20lf\n", raiz);
	
	//calculo da raiz pelo metodo da falsa posicao
	printf("\nMETODO FALSA POSICAO\n");
	raiz = metodoFalsaPosicao(a, b, max_iteracao, erro);
	
	//apresenta o resultado
	printf("\nRAIZ = %.20lf\n", raiz);

	return 0;
}