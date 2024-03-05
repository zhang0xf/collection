#include <queue>
#include <unordered_set>
#include <iostream>
#include "simple_graph.h"

void SimpleGraphBFS::BFS(SimpleGraph graph, char start) {
    std::queue<char> frontier;
    frontier.push(start);

    std::unordered_set<char> reached;
    reached.insert(start);

    while (!frontier.empty()) {
        char current = frontier.front();
        frontier.pop();

        std::cout << "visiting: " << current << "\n";

        for (char next : graph.neighbors(current)) {
            if (reached.find(next) == reached.end()) {
                reached.insert(next);
                frontier.push(next);
            }
        }
    }
}