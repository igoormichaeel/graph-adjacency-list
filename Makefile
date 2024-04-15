SRC = ./src
OBJ = ./obj
BIN = ./bin
APPS = ./apps
INCLUDE = ./include
FLAGS = -Wall -pg
# FLAGS = -Wall -pg -O3 -fopt-info-vec -fopt-info-vec-missed


all: graphADT myapps

graphADT: \
	$(OBJ)/graph.o \
	$(OBJ)/list.o \
	$(OBJ)/queue.o \
	$(OBJ)/stack.o

myapps: \
	$(BIN)/teste_perfilamento

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

init:
	mkdir $(BIN) $(OBJ)

run:
	$(BIN)/teste_perfilamento 1250

clean:
	rm -rf $(BIN)/* $(OBJ)/*
	clear


# COMANDOS PARA PERFILAMENTO:
# gprof teste_perfilamento gmon_20000.out -Qdotp100 -Qdotp120 | gprof2dot > dotp_gprof_20000.dot
# dot -Tpng -odotp_gprof_20000.png dotp_gprof_20000.dot