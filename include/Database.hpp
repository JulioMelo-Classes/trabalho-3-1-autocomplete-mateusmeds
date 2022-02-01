#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <istream>
#include <string>
#include <ostream>
#include <sstream>
#include <vector>

class Database {

    private:

        std::string databaseFile;
        
        std::vector<std::pair<int, std::string>> sentences; 

        /**
         * Responsável por inserir os dados na base de dados
         */
        void setDatabase();

        /**
         * @brief Responsável por ordenar alfabeticamente a lista de sentenças
         * 
         * @param p1 
         * @param p2 
         * @return true 
         * @return false 
         */
        static bool sortBySentence(std::pair<int, std::string> &p1, std::pair<int, std::string> &p2);

    public:

        Database(std::string databaseFile);

        /**
         * @brief Retorna as sentenças
         * 
         * @return std::vector<std::pair<int, std::string>> 
         */
        std::vector<std::pair<int, std::string>> getSentences();

        /**
         * @brief Transforma uma string em minúscula
         * 
         * @param str 
         * @return std::string 
         */
        std::string toLowerTransform(std::string str);

};

#endif