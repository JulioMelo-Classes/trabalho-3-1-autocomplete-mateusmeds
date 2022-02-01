#include <istream>
#include <ostream>
#include <sstream>

#include "Interface.hpp"

using namespace std;

Interface::Interface() {  

}

void Interface::start(istream &inputStream, ostream &outputStream, Request *request) {
	string sentence;

	while (!inputStream.eof())
	{
        //Imprime a mensagemd e introdução
        outputStream << this->printIntroMessage();

        //Lê a sentença que o usuário digitou
        getline(inputStream, sentence);

        //Para não imprimir nada quando o usuário digitar CRTL + D (EOF)
        if (!inputStream.eof()) {

            request->search(sentence);
            
            //Verifica se encontrou sentenças correspondentes
            if (!request->getMatchedSentences().size()) {
                outputStream << this->printEmptyMessage() << endl;
            } else {     
                outputStream << this->printResponseMessage() << endl;
                
                int count = 0;
                for (auto matchSentence : request->getMatchedSentences()) {
                    outputStream << matchSentence.second << endl;

                    if (count == 9) {
                        break;
                    }
                    
                    count++;
                }
            }
        }

        outputStream << "\n\n";
  	}
}

string Interface::printIntroMessage() {
    return ">>> Digite uma palavra e aperte [ENTER] para pesquisar (ou CTRL + D para sair): ";
}

string Interface::printResponseMessage() {
    return ">>> Sugestões:";
}

string Interface::printEmptyMessage() {
    return "\nWhooops! Nenhuma sugestão encontrada :(";
}