# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall 

# Definindo as bibliotecas do Allegro
LIBS = $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 allegro_image-5 allegro_audio-5 allegro_acodec-5 --libs --cflags)

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

# Remove arquivos temporarios
clean:
	rm -f *~ $(OBJ)

# Remove temporarios e o executavel
purge: clean
	rm -f $(TARGET)

