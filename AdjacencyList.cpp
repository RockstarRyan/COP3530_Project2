#include "AdjacencyList.h"

// Inserts a new
bool AdjacencyList::insert(const string& from, const string& to) {
    graph[from].push_back(to);
    if (graph.find(to) == graph.end()) {
        graph[to] = {};
    }

    return true;
}

string AdjacencyList::pageRank(unsigned int p) {
    map<string,double> pageRanks;
    map<string,double> pageRanksPrev;
    string output;

    // Get initial page ranks
    for (const auto& page : graph) {
        pageRanks[page.first] = 1.0 / (double)graph.size();
    }

    // Power iterations
    for (auto i = 1; i < p; i++) {
        pageRanksPrev = pageRanks;
        pageRanks = {};
        output += "Iteration "+ std::to_string(i)+"\n";
        for (const auto& page : graph) {
            for (const auto& toLink : page.second) {
                // from = page.first, to = toLink
                output += "("+toLink+" += "+std::to_string((1.0 / (double)page.second.size()))+" * "+std::to_string(pageRanksPrev[toLink])+")\n";
                pageRanks[toLink] += (1.0 / (double)page.second.size()) * pageRanksPrev[page.first];
            }
        }
    }

    // Format output
    for (const auto& pageRank : pageRanks) {
        string rank = std::to_string(pageRank.second + .005);
        output += pageRank.first+" "+rank.substr(0,rank.find('.')+3)+"\n";
    }
    return output;
}

string AdjacencyList::testOutput() {
    string output;
    for (const auto& page : graph) {
        output += page.first+" ->";
        for (const auto& toLink : page.second) {
            output += " "+toLink+",";
        }
        output += "\n";
    }
    return output;
}