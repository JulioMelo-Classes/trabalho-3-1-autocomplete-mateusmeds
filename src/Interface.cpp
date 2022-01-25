#include <istream>
#include <ostream>
#include <sstream>

#include "Interface.hpp"

using namespace std;

Interface::Interface() {

}

void Interface::start(istream &inputStream, ostream &outputStream) {
	string sentence, saida;
	while (!inputStream.eof())
	{
        outputStream << this->printIntroMessage();
        getline(inputStream, sentence);
        outputStream<< sentence <<endl;
  	}
}

string Interface::printIntroMessage() {
    return "Digite uma palavra e aperte [ENTER] (ou CTRL + D para sair): ";
}

string Interface::printMatchCorrespondence() {
    return " ";
}

string Interface::printMatchMessage() {
    return " ";
}