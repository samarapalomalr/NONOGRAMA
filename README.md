# Nonograma

## Demonstração do Jogo

![Demonstração do Nonograma]
https://images.app.goo.gl/FJChtz8y6Tp6gz6v8 


## Descrição do Projeto

O Nonograma é um jogo de lógica que consiste em preencher uma grade com quadrados pretos e espaços em branco, de acordo com dicas numéricas fornecidas nas linhas e colunas. 
O objetivo é descobrir a figura oculta a partir dessas dicas, seguindo as regras específicas que definem como os quadrados devem ser preenchidos.

### Regras do Jogo

1. As dicas fornecem a quantidade de quadrados consecutivos que devem ser preenchidos em cada linha e coluna.
2. As dicas devem ser seguidas rigorosamente para que o jogador consiga decifrar a figura correta.
3. O jogador pode interagir com o jogo por meio de comandos para preencher, limpar ou verificar o estado da matriz.

## Funcionalidades

- Criação de um Nonograma com dimensões definidas.
- Interação do jogador para preencher e limpar células.
- Salvamento do estado atual do jogo em um arquivo.
- Verificação de vitória: o jogo avalia se todas as células foram preenchidas corretamente de acordo com as dicas.

## Modularização do Projeto

O projeto está estruturado de forma modular, facilitando a manutenção e a compreensão do código. As principais partes do projeto incluem:

- **main.c**: Ponto de entrada do programa, gerenciando a interação do usuário e o fluxo principal do jogo.
- **nonograma.h/c**: Contém as definições da estrutura do Nonograma e as funções relacionadas à criação, manipulação e exibição do jogo.
- **salvar.h/c**: Função para salvar o estado atual do Nonograma em um arquivo.
- **imprimir.h/c**: Função para exibir a matriz do Nonograma e instruções para o usuário.

## Como Compilar e Executar

Para compilar o projeto, use o seguinte comando:

```bash
make

Em seguida, execute o programa com: ./nonograma inicializa.txt
