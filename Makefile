# Nome do programa
PROGRAM = ap_mesh

# Diretórios de código-fonte
SRC_DIRS := Sources

# Obtenha todas as fontes em SRC_DIRS
SOURCES := $(shell find $(SRC_DIRS) -name "*.cpp")

# Diretório de build
BUILD_DIR := build_make

# Subdiretórios de build
SUB_DIRS := $(shell find $(SRC_DIRS) -type d)
BUILD_SUB_DIRS := $(patsubst $(SRC_DIRS)%,$(BUILD_DIR)%,$(SUB_DIRS))
# BUILD_SUB_DIRS := $(foreach DIR,$(SUB_DIRS),$(patsubst $(SRC_DIRS)%,$(BUILD_DIR)%,$(DIR)))

# Objetos a serem criados a partir de cada fonte
OBJECTS := $(patsubst $(SRC_DIRS)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Compiladores
CC            = gcc
CXX           = g++
MPICC         = mpicc
MPICXX        = mpicxx
# Define o compilador padrão como MPICXX, se disponível
COMPILER := $(shell command -v $(MPICXX) 2> /dev/null)
ifeq ($(COMPILER),)
    COMPILER := $(CXX)
    $(warning mpicxx não está disponível. Usando g++ como compilador padrão.)
endif

# Variáveis de caminho de inclusão e biblioteca
DIR_ROOTS := .
DIRS := $(shell find $(DIR_ROOTS) -type d \( -name include -o -name src \))
INC_PATH := $(addprefix -I, $(addsuffix /include, $(DIRS)))
LIB_PATH := $(addprefix -L, $(addsuffix /src, $(DIRS)))

# Variáveis de opções de compilação
CXXFLAGS_EXTRA = -O3 -DNDEBUG -march=native -W -Wall -ftree-vectorize -flto -fno-strict-aliasing -Wno-cast-function-type
CXXFLAGS      = -std=c++17 $(CXXFLAGS_EXTRA)
CXXFLAGS_OMP  = -fopenmp $(CXXFLAGS)

# Variáveis de limpeza
GARBAGE_PATTERNS := *.o
GARBAGE := $(foreach DIR,$(BUILD_DIR) $(BUILD_SUB_DIRS),$(addprefix $(DIR)/,$(GARBAGE_PATTERNS)))

# Regra principal para criar o programa
$(BUILD_DIR)/$(PROGRAM): $(OBJECTS)
	@echo "Criando o executável..."
	$(COMPILER) $(INC_PATH) $(CXXFLAGS_OMP) $(LIB_PATH) $^ -o $@

# Regra de construção de objeto
$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.cpp | $(BUILD_DIR) $(BUILD_SUB_DIRS)
	@echo "Criando o objeto $@..."
	$(COMPILER) $(INC_PATH) -c $(CXXFLAGS_OMP) $< -o $@

# Regra para criar o diretório de build e subdiretórios
$(BUILD_DIR) $(BUILD_SUB_DIRS):
	@echo "Criando diretórios de build, se necessário..."
	if [ ! -d $@ ]; then mkdir -p $@; fi

# Regra de limpeza
clean:
	rm -rfv $(GARBAGE) $(BUILD_DIR)/$(PROGRAM)

# Regra para executar o programa
exec:
	./$(BUILD_DIR)/$(PROGRAM)

# Carregar opções adicionais do arquivo .makefileopts, se existir
-include .makefileopts

# make COMPILER=g++

# Regras de depuração
print-%:
	@echo "$*=$($*)"

# Mostra todas as variáveis de ambiente
show-environment:
	env | sort

# Mostra todos os alvos disponíveis
show-targets:
	@echo "Alvos disponíveis:"
	@echo "  make                - Compila e constrói o programa"
	@echo "  make clean          - Remove todos os arquivos gerados pelo make"
	@echo "  make exec           - Executa o programa"
	@echo "  make COMPILER=<CXX> - Especifica o compilador a ser usado (padrão: mpicxx)"
	@echo "  make print-<var>    - Imprime o valor de uma variável"
	@echo "  make show-environment - Imprime todas as variáveis de ambiente usadas pelo make"
	@echo "  make show-targets   - Imprime a lista de alvos disponíveis"

.PHONY: clean exec show-environment show-targets
