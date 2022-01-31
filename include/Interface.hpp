#ifndef INTERFACE_H
#define INTERFACE_H
#include <istream>
#include <ostream>
#include <sstream>

class Interface {

    private:

        /**
         * Variável para armazenar a frase que o usuário digitar
         */
        std::string sentenceTyped;

                /**
         * Imprime a mensagem que aparece para o usuário digitar a sentença
         */
        std::string printIntroMessage();

        /**
         * Imprime a mensagem que aparece para o usuário como resultado da pesquisa
         */
        std::string printResponseMessage();

        /**
         * Imprime as posíveis sentenças que combinam com a pesquisa do usuário
         */
        std::string printMatchCorrespondence();

    public:

        Interface();
        
        /**
         * Responsável por controlar a entrada e saída de dados
         * @param inputStream cin
         * @param outputStream cout
         */
        void start(std::istream &inputStream, std::ostream &outputStream);

};

#endif