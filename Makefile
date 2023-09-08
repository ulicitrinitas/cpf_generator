# Nome do seu programa
TARGET = cpf_gen

# Compilador
CC = clang++

# Opções de compilação
CFLAGS = -Wall -Wextra -pedantic -O2

# Bibliotecas
LIBS = -lpthread -lsodium -lm

# Diretórios de inclusão
INCLUDES = -I # Substitua pelo caminho correto para os headers

# Diretórios de arquivos de origem e objeto
SRCDIR = src
OBJDIR = obj

# Lista de arquivos de origem
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Lista de arquivos de objeto
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Compilação do programa
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

# Regra para compilar arquivos de objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

# Limpar arquivos de objeto e o executável
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

# Phony target para evitar conflitos com arquivos chamados "clean"
.PHONY: clean
