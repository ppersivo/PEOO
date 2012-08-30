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
#include <cstdlib>  // Para as  funcoes rand() e srand().
#include <time.h>   // Para a funcao time().

using std::cout;
using std::endl;

/* Prototipos das funcoes */
void initRandomSeed();
long double randomReal(long double low, long double high);
long double calcularPi(int quantidade);
bool lancarDardo();
void showResult(int quantidade, long double pi);


int
main()
{
    showResult(10000, calcularPi(10000));

    return 0;
}

/*
 * Calcula o valor de PI pela integracao de Monte Carlo.
 * Entrada: Recebe como argumento o numero de vezes que um dardo
 *          deve ser lancado para calcular a aproximacao de PI.
 * Saída: O valor aproximado de PI.
 */
long double
calcularPi(int quantidade)
{
    bool acertouAlvo = false;
    double alvo = 0.0;          // Numero de dardos que acertaram o alvo.

    // Lancamento dos dardos e contagem dos acertos.
    for (int i=0;i<quantidade;i++)
      {

        acertouAlvo = lancarDardo();

        if (acertouAlvo)
          {
            alvo += 1.0;
          }

      }

    // Calculando o valor de PI e retornando-o.
    return 4.0*(alvo/quantidade);
}

/*
 * Inicializa a semente para geracao de numeros aleatorios.
 * Utilizada por randomReal().
 */
void
initRandomSeed()
{
    static bool initialized = false;

    if (!initialized)
      {
        srand(int(time(NULL)));
        initialized = true;
      }
}

/*
 * Gera um numero aleatório do tipo long double.
 * Utilizada por lancarDardo().
 * Entrada: Valores inicial e final do intervalo em que o numero
 *          aleatorio gerado deve estar.
 * Saida: Numero aleatorio do tipo long double no intervalo especificado.
 */
long double
randomReal(long double low, long double high)
{
    initRandomSeed();

    long double d = (rand() / (double(RAND_MAX) + 1));
    long double s = (d * (high - low));

    return (low + s);
}

/*
 * Simula o lancamento de dardos em uma placa tamanho 2x2 e alvo de raio 1
 * com centro em (0,0)
 * Saida: Retorna TRUE se o dardo ACERTOU o alvo.
          Retorna FALSE se o dardo ERROU o alvo.
 */
bool
lancarDardo()
{
    // A placa que sustenta o alvo tem lado de tamanho 2.
    // Portanto os numeros aleatorios estarao na faixa 0..2 .
    long double x = randomReal(0, 2.0);
    long double y = randomReal(0, 2.0);

    // Posicionando o centro da placa no ponto (0,0).
    x -= 1;
    y -= 1;

    // Verificando se o dardo acertou o alvo.
    // O alvo eh um circulo de raio 1.
    bool noAlvo = (x*x + y*y) < 1.0;

    if (noAlvo)
      {
        // Se acertou o alvo.
        return true;
      }

    return false;
}

/*
 * Exibe o resultado do programa na tela.
 * Entrada: Quantidade de lancamentos e o valor aproximado de PI.
 */
void
showResult(int quantidade, long double pi)
{
    cout.precision(10);

    cout << "O valor de PI, por Integracao de Monte Carlo, " << endl;
    cout << "com " << quantidade << " lancamentos: " << pi << endl;
}
