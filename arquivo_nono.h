#ifndef NONOGRAMA_H
#define NONOGRAMA_H

#define L 26 // Número máximo de linhas do nonograma
#define C 26 // Número máximo de colunas do nonograma
#define DIMENSOES 26 // Tamanho máximo dos cabeçalhos das linhas e colunas

// Definição da estrutura que representa o estado do jogo do nonograma
typedef struct {
    int Linha; // Número de linhas do nonograma
    int Coluna; // Número de colunas do nonograma
    int CabecalhoLinhas[L][DIMENSOES]; // Cabeçalhos das linhas (números que indicam os blocos preenchidos)
    int CabecalhoColunas[C][DIMENSOES]; // Cabeçalhos das colunas (números que indicam os blocos preenchidos)
    char Matriz[L][C]; // Matriz do nonograma (células preenchidas ou vazias)
} Nonogramajogo;

// Declaração das funções relacionadas ao jogo do nonograma
void inicializarNonogramajogo(Nonogramajogo *Nonograma, char *file);
void imprimirNonogramajogo(Nonogramajogo *Nonograma);
void realizarJogo(Nonogramajogo *Nonograma, int l, int c, char gamer);
void salvar(Nonogramajogo *Nonograma, char *file);
int verificarSeGanhou(Nonogramajogo *Nonograma);
void resolverNonograma(Nonogramajogo *Nonograma);


#endif // Fim do cabeçalho de proteção contra inclusões múltiplas
