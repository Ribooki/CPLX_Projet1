CC = gcc -g
CFLAGS = -W -Wall -pedantic -ansi -std=c99
EXEC = main
FILE =
SRC = main.c graphUtils.c utils.c verification.c maximal.c maximum.c satUtils.c desertToSAT.c
OBJ = $(SRC:.c=.o)

all:$(EXEC)

main: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: graphUtils.h utils.h verification.h maximal.h maximum.h satUtils.h desertToSAT.h

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
