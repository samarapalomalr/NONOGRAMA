#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo_nono.h"

// Função que realiza a configuração inicial da estrutura de dados que representa o estado do jogo Nonograma
void inicializarNonogramajogo(Nonogramajogo *Nonograma, char *file) {
    // Abre o arquivo fornecido para leitura
    FILE *Arquivotxt = fopen(file, "r");

    // Verifica se o arquivo foi aberto corretamente
    if (Arquivotxt == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    // Lê as dimensões da matriz do Nonograma do arquivo
    fscanf(Arquivotxt, "%d %d", &Nonograma->Linha, &Nonograma->Coluna);

    // Lê os cabeçalhos das linhas do Nonograma
    for (int i = 0; i < Nonograma->Linha; i++) {
        int numCabe = 0;
        // Lê cada número do cabeçalho até encontrar um caractere de nova linha
        while (fscanf(Arquivotxt, "%d", &Nonograma->CabecalhoLinhas[i][numCabe]) == 1) {
            numCabe++;
            // Se encontrarmos um caractere de nova linha, paramos de ler
            if (fgetc(Arquivotxt) == '\n') {
                break;
            }
        }
    }

    // Lê os cabeçalhos das colunas do Nonograma
    for (int j = 0; j < Nonograma->Coluna; j++) {
        int numCabe = 0;
        // Lê cada número do cabeçalho até encontrar um caractere de nova linha
        while (fscanf(Arquivotxt, "%d", &Nonograma->CabecalhoColunas[j][numCabe]) == 1) {
            numCabe++;
            // Se encontrarmos um caractere de nova linha, paramos de ler
            if (fgetc(Arquivotxt) == '\n') {
                break;
            }
        }
    }

    // Lê a matriz do Nonograma do arquivo
    for (int i = 0; i < Nonograma->Linha; i++) {
        for (int j = 0; j < Nonograma->Coluna; j++) {
            fscanf(Arquivotxt, " %c", &Nonograma->Matriz[i][j]);
        }
    }

    // Fecha o arquivo após a leitura
    fclose(Arquivotxt);
}

// Função que imprime a grade do nonograma
void imprimirNonogramajogo(Nonogramajogo *Nonograma) {
    // Exibe a matriz
    for (int i = 0; i < Nonograma->Linha; i++) {
        for (int j = 0; j < Nonograma->Coluna; j++) {
            printf("%1c ", Nonograma->Matriz[i][j]); // Exibe os elementos da matriz
        }
        printf("\n"); // Nova linha após cada linha da matriz
    }
}


// Função que manipula a grade do nonograma
void realizarJogo(Nonogramajogo *Nonograma, int l, int c, char gamer){
    Nonograma->Matriz[l][c] = gamer;
}

// Função para salvar o estado atual do nonograma em um arquivo de texto
void salvar(Nonogramajogo *Nonograma, char *file) {
    FILE *Arquivotxt = fopen(file, "w"); // Abre o arquivo para escrita
    
    // Verifica se o arquivo foi aberto corretamente
    if (Arquivotxt == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        exit(EXIT_FAILURE);
    }

    // Exibindo apenas a matriz
    for (int i = 0; i < Nonograma->Linha; i++) {
        for (int j = 0; j < Nonograma->Coluna; j++) {
            fprintf(Arquivotxt, "%1c ", Nonograma->Matriz[i][j]); // Imprime os elementos da matriz
        }
        fprintf(Arquivotxt, "\n"); // Nova linha após cada linha da matriz
    }

    fclose(Arquivotxt); 
    printf("Matriz do Nonograma salva com sucesso!\n\n");
}


// Função para verificar se o jogador ganhou o jogo, comparando a matriz atual com os cabeçalhos das linhas e colunas
int verificarSeGanhou(Nonogramajogo *Nonograma) {
    // Verifica cada linha
    for (int i = 0; i < Nonograma->Linha; i++) {
        int contador = 0; // Contador para número de segmentos preenchidos
        int tamanhoAtual = 0; // Tamanho do segmento atual
        for (int j = 0; j < Nonograma->Coluna; j++) {
            if (Nonograma->Matriz[i][j] == 'x') {
                tamanhoAtual++; // Incrementa se a célula está preenchida
            } else if (Nonograma->Matriz[i][j] == '.') {
                // Se encontramos um espaço vazio e temos um segmento preenchido
                if (tamanhoAtual > 0) {
                    if (Nonograma->CabecalhoLinhas[i][contador] != tamanhoAtual) {
                        return 0; // Não ganhou
                    }
                    tamanhoAtual = 0; // Reseta o tamanho do segmento
                    contador++; // Passa para o próximo número do cabeçalho
                }
            }
        }
        // Verifica se todos os números foram correspondidos
        if (contador < Nonograma->CabecalhoLinhas[i][0]) {
            return 0; // Não ganhou
        }
    }

    // Verifica cada coluna
    for (int j = 0; j < Nonograma->Coluna; j++) {
        int contador = 0;
        int tamanhoAtual = 0;
        for (int i = 0; i < Nonograma->Linha; i++) {
            if (Nonograma->Matriz[i][j] == 'x') {
                tamanhoAtual++;
            } else if (Nonograma->Matriz[i][j] == '.') {
                if (tamanhoAtual > 0) {
                    if (Nonograma->CabecalhoColunas[j][contador] != tamanhoAtual) {
                        return 0; // Não ganhou
                    }
                    tamanhoAtual = 0;
                    contador++;
                }
            }
        }
        // Verifica se todos os números foram correspondidos
        if (contador < Nonograma->CabecalhoColunas[j][0]) {
            return 0; // Não ganhou
        }
    }

    return 1; // Ganhou
}

// Função para resolver automaticamente o Nonograma
void resolverNonograma(Nonogramajogo *Nonograma) {
    int mudanca = 1; // Variável para rastrear mudanças na matriz

    while (mudanca) {
        mudanca = 0;

        // usar as informações dos cabeçalhos para preencher automaticamente a matriz
        // Certificar de atualizar a matriz em Nonograma->Matriz

        // Verifica se a matriz mudou após preencher uma célula
        // Se sim, atualiza mudanca para 1 para continuar a iteração
    }
}


