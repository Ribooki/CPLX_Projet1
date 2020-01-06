CC = gcc -g
CFLAGS = -W -Wall -pedantic -ansi -std=c99
EXEC = main
FILE = files/1-FullIns_3
SRC = main.c graphUtils.c utils.c verification.c maximal.c maximum.c satUtils.c desertToSAT.c SATToDesert.c
OBJ = $(SRC:.c=.o)
SUPPR = *.o tmpOUT.txt tmpSAT.cnf

all:$(EXEC)

main: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: graphUtils.h utils.h verification.h maximal.h maximum.h satUtils.h desertToSAT.h SATToDesert.h

%.o: %.c
		@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: gdb run valgrind clean mrproper

gdb:
	@gdb ./$(EXEC)

run:
	@./$(EXEC) $(FILE)

valgrind:
	valgrind -v --leak-check=full --track-origins=yes ./$(EXEC) $(FILE)

clean:
	@rm -rf $(SUPPR)

mrproper: clean
	@rm -rf $(EXEC)
