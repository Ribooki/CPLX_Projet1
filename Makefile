CC = gcc -g
CFLAGS = -W -Wall -pedantic -ansi -std=c99
EXEC = main
FILE =
SRC = main.c graphUtils.c
OBJ = $(SRC:.c=.o)

all:$(EXEC)

main: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: graphUtils.h

%.o: %.c
		@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: gdb run valgrind clean mrproper

gdb:
	@gdb ./$(EXEC)

run:
	@./$(EXEC) $(FILE)

valgrind:
	valgrind -v --track-origins=yes ./$(EXEC) $(FILE)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
