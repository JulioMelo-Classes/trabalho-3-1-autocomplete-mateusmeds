.DEFAULT_GOAL := all

#quando adicionar uma nova dependencia não esqueça de atualizar aqui!
OBJECTS=build/Database.o build/Interface.o

build/Database.o: src/Database.cpp include/Database.hpp
	g++ -Iinclude src/Database.cpp -c -o build/Database.o

build/Interface.o: src/Interface.cpp include/Interface.hpp
	g++ -Iinclude src/Interface.cpp -c -o build/Interface.o

#para adicionar novas regras apenas siga o formato
#build/usuario.o: src/usuario.cpp include/usuario.h
#	g++ -Iinclude src/usuario.cpp -c

objects: $(OBJECTS)

autocomplete: objects src/Autocomplete.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/Autocomplete.cpp -o build/autocomplete

clean:
	rm build/*.o build/autocomplete

all: autocomplete

run:
	./build/autocomplete
