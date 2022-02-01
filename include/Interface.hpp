#ifndef INTERFACE_H
#define INTERFACE_H
#include <istream>
#include <ostream>
#include <sstream>

#include "Request.hpp"

class Interface {

    private:

        Request request;

        /**
         * @brief Variável para armazenar a frase que o usuário digitar
         */
        std::string sentenceTyped;

        /**
         * @brief Imprime a mensagem que aparece para o usuário digitar a sentença
         */
        std::string printIntroMessage();

        /**
         * @brief Imprime a mensagem que aparece para o usuário como resultado da pesquisa
         */
        std::string printResponseMessage();

        /**
         * @brief Imprime a mensagem quando não encontra sentença correspondente
         */
        std::string printEmptyMessage();


    public:

        Interface();
        
        /**
         * @brief Responsável por controlar a entrada e saída de dados
         * 
         * @param inputStream cin
         * @param outputStream cout
         */
        void start(std::istream &inputStream, std::ostream &outputStream, Request *request);
};

#endif