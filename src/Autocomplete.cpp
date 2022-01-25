#include <iostream>
#include <list>
#include <vector>
#include <string>

#include "Database.hpp"
#include "Interface.hpp"


using namespace std;

int main(int argc, char *argv[]) {
  // inicialização do sistema
//   Sistema sistema;
//   Executor executor(sistema);

  // o executor recebe o cin e o cout. Ele irá os utilizar para ler as linhas
  // de comando, executar o método correto em "sistema" e exibir as mensagens
//   executor.iniciar(cin, cout);

 //TODO: arquivo de palavras -> argv[1] | arquivo de scores -> argv[2]
    //Forca forca = Forca(argv[1], argv[2]);

    Interface interface;
    Database database(argv[1]);



    interface.start(cin, cout);

  return 0;
}
