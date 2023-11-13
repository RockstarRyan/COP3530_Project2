#include <iostream>
#include <string>
#include <regex>

#include "AdjacencyList.h"

using std::cout;
using std::cin;
using std::string;
using std::regex;
using std::regex_match;

int main() {
    AdjacencyList adjacencyList;

    unsigned int numLines, numIterations;
    cin >> numLines;
    cin >> numIterations;

    string from, to;
    for (auto i = 0; i < numLines; i++) {
        cin >> from;
        cin >> to;
        adjacencyList.insert(from,to);
    }

    //cout << adjacencyList.testOutput();
    cout << adjacencyList.pageRank(numIterations);

    return 0;
}