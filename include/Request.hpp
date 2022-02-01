#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <istream>
#include <string>
#include <ostream>
#include <sstream>
#include <vector>

#include "Database.hpp"

class Request {

    private:
        
        Database *database;

        //Armazena temporáriamente as sentenças correspondentes encontradas
        std::vector<std::pair<int, std::string>> matchedSentences;

        /**
         * @brief Responsável por ordenar a lista de frequências de forma decrescente
         * 
         * @param p1 
         * @param p2 
         * @return true 
         * @return false 
         */
        static bool sortByFrequency(std::pair<int, std::string> &p1, std::pair<int, std::string> &p2);

    public:

        Request();

        Request(Database *database);

        /**
         * Responsável por realizar a busca por sentenças correspondentes na base de dados
         * 
         * @param sentence 
         */
        void search(std::string sentence);

        /**
         * Transforma uma string em minúscula
         * 
         * @param str 
         * @return std::string 
         */
        std::string toLowerTransform(std::string str);

        /**
         * @brief Lista de sentenças correspondentes
         * 
         * @return std::vector<std::pair<int, std::string>> 
         */
        std::vector<std::pair<int, std::string>> getMatchedSentences();
};

#endif