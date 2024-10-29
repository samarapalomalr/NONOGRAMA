#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Inclui a biblioteca para usar isalpha e toupper
#include "arquivo_nono.h" // Inclui o cabeçalho do arquivo_nono.h onde está definida a estrutura Nonogramajogo e suas funções

// Função principal do jogo Nonograma
// Recebe o nome do arquivo de inicialização do nonograma como argumento
int main(int argc, char *argv[]) {
    // Verifica se o número de argumentos está correto (espera-se 2: nome do executável e nome do arquivo de inicialização)
    if (argc != 2) {
        // Se o número de argumentos estiver incorreto, exibe uma mensagem de uso correto e encerra o programa
        fprintf(stderr, "Uso correto: %s <inicializa.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Inicializa o nonograma com o arquivo fornecido como argumento
    Nonogramajogo Nonograma;
    inicializarNonogramajogo(&Nonograma, argv[1]);

    // Variáveis para armazenar as coordenadas do jogador e o comando inserido
    int Linha, Coluna;
    char JogadorAtual = '.';
    char Comando[10];

    printf("Bem-vindo ao Nonograma!\n\n");
    // Exibe os comandos aceitos e instruções para o usuário
    printf("Comandos Aceitos:\n");
    printf("  'A' a 'Z': Preenche a célula com um quadrado pintado\n");
    printf("  '.':       Limpa a célula (espaço em branco)\n");
    printf("  'S':       Resolve automaticamente o Nonograma\n");
    printf("  'salva nomeArquivoSalvo': Salva o estado do jogo\n" "  em um arquivo texto\n");
    printf("  'sair':    Sai do jogo\n");
    printf("\nPara preencher ou limpar células, utilize as coordenadas!\n");
    printf("Exemplo: x AA (linha A, coluna A)\n\n");

    // Loop principal do jogo
    while (1) {
        // Imprime o estado atual do nonograma
        imprimirNonogramajogo(&Nonograma);

        printf("\n\nDigite um comando: ");
        scanf("%s", Comando);

        // Processa o comando inserido pelo jogador
        if (strcmp(Comando, "x") == 0 || strcmp(Comando, ".") == 0 || strcmp(Comando, "-") == 0) {
            char coordenada[3];
            scanf(" %s", coordenada);

            // Verifica se as coordenadas têm o formato correto e se são letras
            if (strlen(coordenada) == 2 && isalpha(coordenada[0]) && isalpha(coordenada[1])) {
                // Converte as letras para maiúsculas e mapeia para índices de matriz
                Linha = toupper(coordenada[0]) - 'A';
                Coluna = toupper(coordenada[1]) - 'A';

                // Verifica se a jogada é válida
                if (Linha >= 0 && Linha < Nonograma.Linha && Coluna >= 0 && Coluna < Nonograma.Coluna) {
                    realizarJogo(&Nonograma, Linha, Coluna, Comando[0]);

                    // Verifica se o jogador ganhou
                    if (verificarSeGanhou(&Nonograma)) {
                        printf("\n\nParabéns! Você ganhou o jogo!\n");
                        return EXIT_SUCCESS;
                    } 

                    // Alterna o caracter do jogador
                    JogadorAtual = (JogadorAtual == 'x') ? '-' : 'x';
                } else {
                    printf("\nCoordenada inválida. Tente novamente.\n\n");
                }
            } else {
                printf("\nFormato de coordenada inválido. Use o formato 'A-Z'.\n\n");
            }
        } else if (strcmp(Comando, "sair") == 0) {
            // Se o jogador desejar sair, exibe uma mensagem e encerra o programa
            printf("\n\nSaindo do Nonograma..\n");
            return EXIT_FAILURE;
        } else if (strcmp(Comando, "salvar") == 0) {
            char Arquivo2[25]; // Nome do arquivo de salvamento
            scanf(" %s", Arquivo2);
            salvar(&Nonograma, Arquivo2);
        } else if (strcmp(Comando, "resolver") == 0) {
            // Resolve automaticamente o nonograma e salva o resultado
            resolverNonograma(&Nonograma);
            salvar(&Nonograma, "nonograma_resolvido.txt");

        } else {
            // Se o comando inserido pelo jogador for inválido, exibe uma mensagem de erro
            printf("\nComando inválido");
            printf("\nComandos aceitos: x, -, ., sair, salvar, resolver\n\n");
        }
    }

    // Retorna sucesso caso o programa encerre normalmente.
    return EXIT_SUCCESS;
}
