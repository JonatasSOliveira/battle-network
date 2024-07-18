# Flags do compilador
CXXFLAGS = -I src/include -std=c++20
LDFLAGS = -L src/lib -std=c++20
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

# Lista de arquivos fonte
SOURCES = main.o $(wildcard src/application/*/*.cpp) $(wildcard src/adapters/*/*/*.cpp) $(wildcard src/domain/*/*/*.cpp) $(wildcard src/utils/*/*.cpp)

# Objetos gerados a partir dos arquivos fonte
OBJECTS = $(SOURCES:.cpp=.o)

# Nome do executável
EXECUTABLE = main

# Regra para compilar os objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para compilar o executável
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

# Regra para limpar os arquivos intermediários e o executável
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
