# Nome do executável
TARGET = nonograma

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g

# Arquivos de origem e cabeçalhos
SRCS = main.c arquivo_nono.c
HDRS = arquivo_nono.h

# Arquivo de inicialização
INIT_FILE = inicializa.txt

# Gera o executável
$(TARGET): $(SRCS) $(HDRS) $(INIT_FILE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Copia o arquivo de inicialização para o diretório de build
install: $(TARGET)
	cp $(INIT_FILE) .

# Limpa arquivos compilados
clean:
	rm -f $(TARGET) $(INIT_FILE)
