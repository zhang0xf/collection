#include "simple_graph.h"
#include "square_grid.h"
#include "weight_grid.h"

void simpleGraphTest() {
    SimpleGraph graph{{
        {'A', {'B'}},
        {'B', {'C'}},
        {'C', {'B', 'D', 'F'}},
        {'D', {'C', 'E'}},
        {'E', {'F'}},
        {'F', {}},
    }};

    SimpleGraphBFS bfs;

    std::cout << "Reachable from A:\n";
    bfs.BFS(graph, 'A');
    std::cout << "Reachable from E:\n";
    bfs.BFS(graph, 'E');
}

void squareGridBFS() {
    SquareGridBFS bfs;
    bfs.drawGrid();
    bfs.BFS_nogoal();
    bfs.BFS_goal();
}

void weightGridBFS() {
    WeightGridBFS bfs;
    bfs.dijkstra();
    bfs.Astar();
}

int main() {
    simpleGraphTest();
    squareGridBFS();
    weightGridBFS();
    return 0;
}
