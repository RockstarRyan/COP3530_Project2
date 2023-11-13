#pragma once

#include <string>
#include <map>
#include <utility>
#include <vector>

using std::string;
using std::map;
using std::vector;

class AdjacencyList {
    map<string,vector<string>> graph = {};
public:
    AdjacencyList() = default;
    bool insert(const string& from, const string& to);
    string pageRank(unsigned int p);
    string testOutput();
};

/*

2 3
a b 1
b c 2
 *
 */
