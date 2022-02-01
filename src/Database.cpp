#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype> 

#include "Database.hpp"

using namespace std;

Database::Database(string databaseFile) {
    this->databaseFile = databaseFile;
    this->setDatabase();
}

//Referência: https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/
bool Database::sortBySentence(pair<int, string> &p1, pair<int, string> &p2) {
    return (p1.second < p2.second);
}

string Database::toLowerTransform(std::string str) {
    string newStr;
    for (int i = 0; i < str.size(); i++) {
        newStr += tolower(str[i]);
    }
    return newStr;
}


void Database::setDatabase() {
    fstream file(databaseFile);

    //Responsável por armazenar, temporariamente, o par (frequencia, sentença)
    pair<int, string> tempValue;

    string sentence;
    int frequency;

    //Jogando o número da primeira linha no lixo
    int count;
    file >> count;

    for (int i = 0; i < count; i++) {
        file >> frequency;
        file >> sentence;

        //Armazena o resto da sentença temporariamente
        string restSentence;
        getline(file, restSentence);

        tempValue.first = frequency;
        tempValue.second = this->toLowerTransform(sentence + restSentence);

        this->sentences.push_back(tempValue);
    }

    //Ordenando a lista de sentenças alfabeticamente
    sort(this->sentences.begin(), this->sentences.end(), sortBySentence);
}

std::vector<std::pair<int, std::string>> Database::getSentences() {
    return this->sentences;
}