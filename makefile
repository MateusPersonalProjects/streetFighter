# Compiler
CC = gcc

# Compiler flags 
CFLAGS = -Wall -Wextra

# Allegro libs
LIBS = $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 allegro_image-5 allegro_audio-5 allegro_acodec-5 --libs --cflags)

# Binary name 
TARGET = streetfighter

# All the code 
SRC = main.c display.c character.c keyboard.c misc.c player.c environment.c matchInterface.c attacks_SpecialMoves.c characSelecMenu.c ./fightersDefines/ryu.c ./fightersDefines/ken.c ./fightersDefines/chunli.c ./fightersDefines/guile.c

# All objects
OBJ = $(SRC:.c=.o)

# Default
all: $(TARGET)

# To compile the binary 
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

# Clear the room
clean:
	rm -f *~ $(OBJ)

# Clear the room with a broom of fire
purge: clean
	rm -f $(TARGET)

