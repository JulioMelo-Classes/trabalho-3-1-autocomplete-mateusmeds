#include <iostream>
#include <fstream>
#include <string>

#include "Database.hpp"

using namespace std;

Database::Database(string databaseFile) {
    this->databaseFile = databaseFile;
    this->setDatabase();
}


void Database::setDatabase() {
    fstream file(databaseFile);

    pair<int, string> tempValue;

    string sentence;
    int frequency;

    int count;
    file >> count;

    for (int i = 0; i < count; i++) {
        file >> frequency;
        file >> sentence;

        string restSentence;
        getline(file, restSentence);

        tempValue.first = frequency;
        tempValue.second = sentence + restSentence;

        this->sentences.push_back(tempValue);
    }

    // for (auto teste : this->sentences) {
    //     cout << teste.first << "|" << teste.second << "|" <<endl;
    // }
}