/*
 * UNIVERSIDADE ESTADUAL DO CEARA - CIENCIAS DA COMPUTACAO
 * Programacao Estruturada e Orientada ao Objeto
 * ------------------------------
 * LAB: 1
 * Questao: 02
 * Nome: Paulo Henrique Persivo Alcantara
 * Matricula: 0831549
 * ------------------------------
 */

/*
 * Arquivo: questao2.cpp
 * ------------------------------
 * Este programa calcula o valor aproximado de PI pela Integracao de Monte Carlo.
 * Entrada: Nenhuma
 * Saida: Valor aproximado de PI
 */

#include <iostream>
#include <cstdlib>  // Para as  funcoes rand(), srand() e exit().
#include <time.h>   // Para a funcao time().

void initRandomSeed();
long double randomReal(long double low, long double high);
long double calcularPi(int quantidade);
bool lancarDardo();
void showResult(int quantidade, long double pi);
void error(std::string msg);

int main(){
    long double pi = 0.0;
    int quantidade = 10000;

    pi = calcularPi(quantidade);
    showResult(quantidade, pi);

    return 0;
}

/*
 * Funcao:
 * Uso:
 * ------------------------------
 * Calcula o valor de PI pela integracao de Monte Carlo
 */
long double calcularPi(int quantidade){
    bool acertouAlvo = false;
    double alvo = 0.0;

    for(int i=0;i<quantidade;i++){
        acertouAlvo = lancarDardo();
        if(acertouAlvo){
            alvo += 1.0;
        }
    }

    return 4.0*(alvo/quantidade);
}

/*
 * Funcao:
 * Uso:
 * ------------------------------
 * Inicializa a semente para geração de numeros aleatorios.
 */
void initRandomSeed() {
    static bool initialized = false;
    if (!initialized) {
        srand(int(time(NULL)));
        initialized = true;
    }
}

/*
 * Funcao:
 * Uso:
 * ------------------------------
 * Gera um numero long double aleatório.
 */
long double randomReal(long double low, long double high) {
    initRandomSeed();

    long double d = rand() / (double(RAND_MAX) + 1);
    long double s = d * (high - low);
    return low + s;
}

/*
 * Funcao:
 * Uso:
 * ------------------------------
 * Simula o lancamento de dardos em uma placa tamanho 2x2 e alvo de raio 1
 * com centro em (0,0)
 */
bool lancarDardo(){
    long double x = randomReal(0, 2.0);
    long double y = randomReal(0, 2.0);

    x -= 1;
    y -= 1;

    if((x*x + y*y) < 1.0){
        return true;
    }

    return false;
}

/*
 * Funcao:
 * Uso:
 * ------------------------------
 * Exibe o resultado do programa na tela.
 */
void showResult(int quantidade, long double pi){
    std::cout.precision(10);
    std::cout << "O valor de PI, por Integracao de Monte Carlo, " << std::endl;
    std::cout << "com " << quantidade << " lancamentos: " << pi << std::endl;
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
