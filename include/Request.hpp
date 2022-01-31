#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <istream>
#include <string>
#include <ostream>
#include <sstream>
#include <vector>

class Request {

    private:

        std::vector<std::pair<int, std::string>> matchedSentences;

    public:

        Request();

        void binarySearch(std::string sentence);


};

#endif