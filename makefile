# Definindo o compilador
CC = gcc

# Definindo as flags de compilação
CFLAGS = -Wall -Wextra -std=c11 $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 allegro_image-5 --cflags)

# Definindo as bibliotecas
LIBS = $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 allegro_image-5 --libs)

# Nome do executável
TARGET = teste

# Lista de arquivos fonte
SRC = main.c display.c character.c keyboard.c misc.c player.c environment.c matchInterface.c attacks_SpecialMoves.c characSelecMenu.c ./fightersDefines/ryu.c ./fightersDefines/ken.c ./fightersDefines/chunli.c ./fightersDefines/guile.c

# Lista de arquivos objeto
OBJ = $(SRC:.c=.o)

# Regra padrão
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos gerados
clean:
	rm -f $(TARGET) $(OBJ)

