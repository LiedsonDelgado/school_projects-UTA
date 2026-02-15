# Makefile para o projeto C-Trivia
# Makefile responsavel por construir o executável do quiz a partir dos fontes em `src/`.

# Caminhos
SRC = src
BUILD = build
TEST = test
INCLUDES = -Ilibs

# Caminho dos executáveis
EXE = $(BUILD)/quiz
TESTS = $(BUILD)/quizTests

.PHONY: help dirs run

dirs:
	@mkdir -p build data

# --- Criação de diretórios ---
$(EXE): $(BUILD)/main.o $(BUILD)/quiz.o $(BUILD)/util.o
	gcc -o $(EXE) $(BUILD)/main.o $(BUILD)/quiz.o $(BUILD)/util.o

# --- Executável de testes ---
$(TESTS): $(BUILD)/tests.o $(BUILD)/quiz.o $(BUILD)/util.o
	gcc -o $(TESTS) $(BUILD)/tests.o $(BUILD)/quiz.o $(BUILD)/util.o 

# --- Objetos ---
$(BUILD)/main.o: $(SRC)/main.c
	gcc -g -c $(SRC)/main.c $(INCLUDES) -o $(BUILD)/main.o

$(BUILD)/quiz.o: $(SRC)/quiz.c
	gcc -g -c $(SRC)/quiz.c $(INCLUDES) -o $(BUILD)/quiz.o

$(BUILD)/util.o: $(SRC)/util.c
	gcc -g -c $(SRC)/util.c $(INCLUDES) -o $(BUILD)/util.o

$(BUILD)/tests.o: $(TEST)/tests.c
	gcc -g -c $(TEST)/tests.c $(INCLUDES) -o $(BUILD)/tests.o

# --- Rodar executáveis
run:$(EXE)
	./$(EXE)

tests:$(TESTS)
	./$(TESTS)

help:
	@echo "WELCOME TO  C-TRIVIA"
	@echo "Available targets:"
	@echo "  make        - build the executable"
	@echo "  make run    - run the quiz"
	@echo "  make tests    - run the tests"
	@echo "  make dirs    - create build and data directories"
	@echo "  make help   - show this help message"
	@echo ""
	@echo "On Windows using MinGW/MSYS you may need to run 'mingw32-make help'."

