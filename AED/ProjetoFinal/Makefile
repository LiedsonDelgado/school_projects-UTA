# Makefile para o projeto C-Trivia
# Makefile responsavel por construir o executável do quiz a partir dos fontes em `src/`.

# caminho para todos os .c's na oasta src
SRC = src/*.c

# Flags de inclusão para o compilador (diretórios com headers)
# faz inclusão  de todos  os headers na pasta libs
INCLUDES = -Ilibs

# Caminho do executável gerado
EXE = build/quiz

# Marca `run` como alvo não relacionado a arquivo
.PHONY: run

# Alvo padrão para gerar o executável.
# Dependencias:
# Depende de todos os arquivos fonte encontrados por `wildcard $(SRC)`.
# depende dos  diretorios criados  pelo  comando dirs
$(EXE): libs $(wildcard $(SRC))
	gcc -o $(EXE) $(SRC) $(INCLUDES)

run: $(EXE)
	./$(EXE)
	./main

# comando  respensavel por criar os diretorios
dirs:
	mkdir build data

help:
	@echo "Available targets:"
	@echo "  make        - build the executable"
	@echo "  make run    - run the quiz"
	@echo "  make help   - show this help message"
	@echo "  make welcome- show a short welcome and quick instructions"
	@echo ""
	@echo "On Windows using MinGW/MSYS you may need to run 'mingw32-make help'."

welcome:
	@echo "Welcome to C-Trivia!"
	@echo "To see available commands run: make help"
	@echo "On Windows with MinGW, use: mingw32-make help"