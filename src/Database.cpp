#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 

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

    sort(this->sentences.begin(), this->sentences.end(), sortBySentence);

    //Apagar
    // for (auto teste : this->sentences) {
    //     cout << teste.first << "|" << teste.second << "|" <<endl;
    // }
}

