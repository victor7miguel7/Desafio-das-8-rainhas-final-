//AVISE SE MEXER NO CODIGO
#include <stdio.h>
#include <stdlib.h>
//Define um tabuleiro de dimensões 8.
#define N 8
// Função responsável por imprimir o tabuleiro na tela de tamanho N por N.
void print_tabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //Para cada posição (i,j) do tabuleiro, a função verifica se existe uma rainha nessa posição, comparando o valor da matriz tabuleiro[i][j] com o valor 1 e coloca um "R" caso tenha, caso contrário coloca ".".
            //Utiliza-se um operador ternário
            printf("%c ", tabuleiro[i][j] == 1 ? 'R' : '.');
        }
        printf("\n");
    }
    printf("\n");
}
//A função eh_valido recebe um tabuleiro de tamanho N por N, a linha e a coluna que se deseja verificar se é possível colocar uma rainha.
int eh_valido(int tabuleiro[N][N], int linha, int coluna) {
    // Verifica a coluna atual, percorre todas as linhas do tabuleiro, até a linha     atual, e verifica se há uma rainha na coluna "coluna". Se houver, retorna 0,       indicando que não é possível colocar uma rainha nessa posição.
    for (int i = 0; i < linha; i++) {
        if (tabuleiro[i][coluna] == 1) {
            return 0;
        }
    }
    // Verifica a diagonal principal acima da posição atual, o for decrementa tanto a linha quanto a coluna a cada iteração até que uma das condições (i < 0 ou j < 0) seja verdadeira; o if verifica se há uma rainha na posição atual (tabuleiro[i][j] == 1). Se houver, significa que existe uma rainha na diagonal principal, e a função retorna 0 indicando que a posição atual não é válida para colocar uma nova rainha.
    for (int i = linha, j = coluna; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j] == 1) {
            return 0;
        }
    }
    // Verifica a diagonal secundária acima da posição atual, seguindo a mesma lógica anterior
    for (int i = linha, j = coluna; i >= 0 && j < N; i--, j++) {
        if (tabuleiro[i][j] == 1) {
            return 0;
        }
    }
    //Se não houver nenhuma rainha na coluna ou nas diagonais acima da posição atual, retorna 1, indicando que é possível colocar uma rainha nessa posição.
    return 1;
}
//Recebe um tabuleiro de tamanho N x N, um inteiro linha que representa a linha atual que estamos verificando, e um ponteiro para um inteiro conta, que é usado para contar quantas soluções foram encontradas. 
void resolve_n_rainhas(int tabuleiro[N][N], int linha, int* conta) {
  //Esse if verifica se já chegamos à última linha do tabuleiro, ou seja, se já posicionamos uma rainha em cada linha possível. Se for esse o caso, uma solução foi encontrada e a função imprime o número da solução (*conta) e o tabuleiro completo usando a função print_tabuleiro. Depois, o contador é incrementado em 1 (*conta)++ e a função retorna.  
  if (linha == N) {
        printf("Solução %d:\n", *conta);
        print_tabuleiro(tabuleiro);
        (*conta)++;
        return;
    }
    //Esse for percorre todas as colunas da linha atual ("linha") do tabuleiro e verifica se é possível posicionar uma rainha nessa posição usando a função eh_valido. Se for possível, uma rainha é colocada nessa posição (tabuleiro[linha][coluna] = 1) e a função é chamada recursivamente para a próxima linha (linha+1). Se não for possível, a próxima coluna é verificada. Após todas as colunas serem verificadas, a rainha é removida dessa posição (tabuleiro[linha][coluna] = 0) e o loop continua na próxima linha.
    //Algoritmo de backtracking
    for (int coluna = 0; coluna < N; coluna++) {
        if (eh_valido(tabuleiro, linha, coluna)) {
            tabuleiro[linha][coluna] = 1;
            resolve_n_rainhas(tabuleiro, linha+1, conta);
            tabuleiro[linha][coluna] = 0;
        }
    }
}
//Função main
int main() {
    //Matriz tabuleiro de tamanho N por N com valores iniciais 0, que será usada para armazenar a posição das rainhas.
    int tabuleiro[N][N] = {0};
    //Como o ponteiro é argumento para uma função, é necessário ter certeza de que ele aponta para um valor válido(no caso o valor escolhido foi 1)
    int conta = 1;
    //Chamada a função resolve_n_rainhas passando como argumentos a matriz tabuleiro, o valor 0 que representa a linha inicial que será verificada e um ponteiro para a variável conta.
    resolve_n_rainhas(tabuleiro, 0, &conta);
    //Retorna o valor 0, indicando que o programa foi executado com sucesso.
    return 0;
}
