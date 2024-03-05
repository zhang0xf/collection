#include "weight_grid.h"

// 创建地图
GridWithWeights DrawWeightSquareGrid::make_diagram() {
    GridWithWeights grid(10, 10);
    add_rect(grid, 1, 7, 4, 9);
    typedef GridLocation L;
    grid.forests = std::unordered_set<GridLocation>{
        L{3, 4}, L{3, 5}, L{4, 1}, L{4, 2},
        L{4, 3}, L{4, 4}, L{4, 5}, L{4, 6},
        L{4, 7}, L{4, 8}, L{5, 1}, L{5, 2},
        L{5, 3}, L{5, 4}, L{5, 5}, L{5, 6},
        L{5, 7}, L{5, 8}, L{6, 2}, L{6, 3},
        L{6, 4}, L{6, 5}, L{6, 6}, L{6, 7},
        L{7, 3}, L{7, 4}, L{7, 5}};
    return grid;
}

void WeightGridBFS::dijkstra() {
    DrawWeightSquareGrid dwg;
    GridWithWeights grid = dwg.make_diagram();
    GridLocation start{1, 4}, goal{8, 3};
    std::unordered_map<GridLocation, GridLocation> came_from;
    std::unordered_map<GridLocation, double> cost_so_far;
    dijkstra_search(grid, start, goal, came_from, cost_so_far);
    draw_grid(grid, nullptr, &came_from, nullptr, &start, &goal);
    std::cout << '\n';
    std::vector<GridLocation> path = reconstruct_path(start, goal, came_from);
    draw_grid(grid, nullptr, nullptr, &path, &start, &goal);
    std::cout << '\n';
    draw_grid(grid, &cost_so_far, nullptr, nullptr, &start, &goal);
}

void WeightGridBFS::Astar() {
    DrawWeightSquareGrid dwg;
    GridWithWeights grid = dwg.make_diagram();
    GridLocation start{1, 4}, goal{8, 3};
    std::unordered_map<GridLocation, GridLocation> came_from;
    std::unordered_map<GridLocation, double> cost_so_far;
    Astar_search(grid, start, goal, came_from, cost_so_far);
    draw_grid(grid, nullptr, &came_from, nullptr, &start, &goal);
    std::cout << '\n';
    std::vector<GridLocation> path = reconstruct_path(start, goal, came_from);
    draw_grid(grid, nullptr, nullptr, &path, &start, &goal);
    std::cout << '\n';
    draw_grid(grid, &cost_so_far, nullptr, nullptr, &start, &goal);
}