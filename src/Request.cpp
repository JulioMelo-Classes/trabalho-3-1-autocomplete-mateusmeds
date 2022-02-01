#include <iostream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm> 

#include "Request.hpp"

using namespace std;

Request::Request() {

}

Request::Request(Database *database) {
    this->database = database;
}

bool Request::sortByFrequency(std::pair<int, std::string> &p1, std::pair<int, std::string> &p2) {
    return (p1.first > p2.first);
}


void Request::search(string sentence) {
    //Resetando a lista de sentenças encontradas
    this->matchedSentences.clear();

    //Percorrendo a lista de sentenças da base de dados
    for (auto &matchSentence : this->database->getSentences()) {
        //Verifica se há ocorrência da sentença digitada na sentença atual do loop
        size_t found = matchSentence.second.find(this->toLowerTransform(sentence));

        //Verifica se o valor é diferente de npos (-1)
        if (found != std::string::npos) {
            this->matchedSentences.push_back(matchSentence);
        }
    }
    
    //Ordenando as sentenças pela frequência em ordem decrescente
    sort(this->matchedSentences.begin(), this->matchedSentences.end(), sortByFrequency);
}

string Request::toLowerTransform(std::string str) {
    string newStr;
    for (int i = 0; i < str.size(); i++) {
        newStr += tolower(str[i]);
    }
    return newStr;
}

std::vector<std::pair<int, std::string>> Request::getMatchedSentences() {
    return this->matchedSentences;
}
