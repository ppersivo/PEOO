/*
 * UNIVERSIDADE ESTADUAL DO CEARA - CIENCIAS DA COMPUTACAO
 * Programacao Estruturada e Orientada ao Objeto
 * ------------------------------
 * LAB: 1
 * Questao: 01
 * Nome: Paulo Henrique Persivo Alcantara
 * Matricula: 0831549
 * ------------------------------
 */

/*
 * Arquivo: questao1.cpp
 * ------------------------------
 * Calcula uma aproximacao de PI atraves da Serie de Leibniz.
 * Entrada: Aproximacao desejada pelo usuario.
 * Saida: Valor de PI com a aproximacao escolhida pelo usuario.
 */


#include <iostream>
#include <cstdlib>  // Para a funcao exit() utilizada em error().

/* Prototipos das funcoes */
int getDesiredAproximation();
long double calculatePi(int aproximation);
void showAnswer(int aproximation, long double pi);
void error(std::string msg);

/* Programa principal */
int main(){

    int aprox = getDesiredAproximation();

    showAnswer(aprox,calculatePi(aprox));

    return 0;
}

/*
 * Funcao: GetDesiredAproximation()
 * ------------------------------
 * Essa funcao solicita ao usuario que especifique a quantidade
 * de termos da Serie de Leibniz para a aproximacao de PI.
 */
int getDesiredAproximation(){
    int aproximation = 0;

    std::cout << "Indique a quantidade de termos para aproximar o valor de PI: ";
    std::cin >> aproximation;
    std::cout << std::endl;

    if(aproximation<1){
        error("A quantidade de termos deve ser maior que 0.");
    }

    return aproximation;
}

/*
 * Funcao: CalculatePi()
 * ------------------------------
 * Essa funcao calcula o valor de PI atraves da Serie de Leibniz
 * com a quantidade de termos solicitada pelo usuario.
 */
long double calculatePi(int aproximation){
    long double pi = 0.0;
    long double term = 0.0;     //Armazena o valor do termo sendo calculado
    short int signal = 1;       //Sinal do termo sendo calculado. Valores permitidos {-1, 1}.
    int denominator = 1;                  //Denominador do termo sendo calculado. Somente inteiros positivos impares.

    for(int j = 1; j <= aproximation; j++){
        term = signal*(1.0/denominator);
        pi += term;
        signal = -signal;
        denominator += 2;
    }

    return pi*4;
}

/*
 * Funcao: showAnswer()
 * ------------------------------
 * Essa funcao exibe o valor de PI calculado pela Serie de Leibniz
 * e a quantidade de termos da serie escolhida pelo usuario.
 */
void showAnswer(int aproximation, long double pi){
    std::cout << "PI, aproximado por " << aproximation << " termos da Serie de Leibniz:" << std::endl;
    std::cout.precision(20);
    std::cout << pi << std::endl;
}

/*
 * Funcao: error()
 * Uso: error();
 * ------------------------------
 * Essa funcao exibe uma mensagem de erro.
 */
void error(std::string msg){
    std::cerr << msg << std::endl;
    std::exit(EXIT_FAILURE);
}
