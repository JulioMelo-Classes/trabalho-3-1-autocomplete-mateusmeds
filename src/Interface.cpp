#include <istream>
#include <ostream>
#include <sstream>

#include "Interface.hpp"

using namespace std;

Interface::Interface() {

}

void Interface::start(istream &inputStream, ostream &outputStream) {
	string sentence;

	while (!inputStream.eof())
	{
        outputStream << this->printIntroMessage();
        getline(inputStream, sentence);

        //Apagar
        //outputStream << sentence << endl;

        if (!inputStream.eof()) {
            outputStream << this->printResponseMessage() << endl;
        }
  	}
}

string Interface::printIntroMessage() {
    return ">>> Digite uma palavra e aperte [ENTER] para pesquisar (ou CTRL + D para sair): ";
}

string Interface::printMatchCorrespondence() {
    return " ";
}

string Interface::printResponseMessage() {
    return ">>> As combinações são:";
}