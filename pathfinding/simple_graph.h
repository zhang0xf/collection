#pragma once
#include <unordered_map>
#include <vector>

struct SimpleGraph {
    std::unordered_map<char, std::vector<char>> edges;

    std::vector<char> neighbors(char id) {
        return edges[id];
    }
};

class SimpleGraphBFS {
public:
    void BFS(SimpleGraph graph, char start); // 广度优先
};
