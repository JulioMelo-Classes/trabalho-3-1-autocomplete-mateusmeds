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

        static bool sortBySentence(std::pair<int, std::string> &p1, std::pair<int, std::string> &p2);

    public:

        Database(std::string databaseFile);


};

#endif