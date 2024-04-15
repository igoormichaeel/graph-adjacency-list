SRC = ./src
OBJ = ./obj
BIN = ./bin
APPS = ./apps
INCLUDE = ./include
# FLAGS = -Wall -pg
FLAGS = -Wall -pg -O3 -fopt-info-vec -fopt-info-vec-missed


all: graphADT myapps

graphADT: \
	$(OBJ)/graph.o \
	$(OBJ)/list.o \
	$(OBJ)/queue.o \
	$(OBJ)/stack.o

myapps: \
	$(BIN)/teste_tempo

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

init:
	mkdir $(BIN) $(OBJ)

run:
# $(BIN)/teste_tempo
	$(BIN)/teste_perfilamento

clean:
	rm -rf $(BIN)/* $(OBJ)/*
	clear