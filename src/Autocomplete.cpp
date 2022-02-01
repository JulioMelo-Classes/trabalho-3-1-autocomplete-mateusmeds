#include <iostream>
#include <list>
#include <vector>
#include <string>

#include "Database.hpp"
#include "Interface.hpp"
#include "Request.hpp"



using namespace std;

int main(int argc, char *argv[]) {

    //Verifica se o usuário passou um arquivo como argumento
    if (argc < 2) {
        cout << "Para executar é necessário passar um arquivo txt como argumento!" << endl;
        exit(1);
    }

    Interface interface;
    Database database(argv[1]);
    Request request(&database);


    interface.start(cin, cout, &request);

  return 0;
}
