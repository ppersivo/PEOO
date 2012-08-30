/*
 * UNIVERSIDADE ESTADUAL DO CEARA - CIENCIAS DA COMPUTACAO
 * Programacao Estruturada e Orientada ao Objeto
 * ------------------------------
 * LAB: 1
 * Questao: 03
 * Nome: Paulo Henrique Persivo Alcantara
 * Matricula: 0831549
 * ------------------------------
 */

/*
 * Arquivo: questao3.cpp
 * ------------------------------
 * Calcula da raiz digital de um dado argumento.
 * Entrada: Numero para calcular a raiz digital.
 * Saida: Raiz digital do numero escolhido pelo usuario.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototipo das funcoes */
int getNumber();
int somaDigitos(int number);
int raizDigital(int number);
void showResult(int number, int raiz);

int main(){
    int number;
    int raiz;

    number = getNumber();
    raiz = raizDigital(number);
    showResult(number, raiz);

    return 0;
}

/*
 * Esta funcao requisita um numero ao usuario para calcular a raiz digital do mesmo.
 * Saida: O numero fornecido pelo usuario.
 */
int getNumber(){
    int number = 0;

    cout << "Informe o numero para calcular a raiz digital: ";
    cin >> number;
    cout << endl;

    return number;
}

/*
 * Esta funcao soma os digitos de um numero passado como argumento.
 * Usada por raizDigital() para somar os digitos em cada fase do calculo.
 */
int somaDigitos(int number){
    int soma = number % 10;

    if( number/10 > 0 ){
        soma += somaDigitos(number/10);
    }
    return soma;
}

/*
 * Esta funcao calcula a raiz digital do numero passado como argumento.
 */
int raizDigital(int number){
    int raiz = 0;

    raiz = somaDigitos(number);

    if(raiz > 9){
        raiz = raizDigital(raiz);
    }

    return raiz;
}

/*
 * Esta funcao exibe o resultado da execucao do programa.
 */
void showResult(int number, int raiz){
    cout << "Raiz digital de " << number << " : " << raiz << endl;
}
