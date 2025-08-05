#include "square_grid.h"

// East, West, North, South
std::array<GridLocation, 4> SquareGrid::DIRS = {
    GridLocation{1, 0}, GridLocation{-1, 0},
    GridLocation{0, -1}, GridLocation{0, 1}};

std::vector<GridLocation> SquareGrid::neighbors(GridLocation id) const {
    std::vector<GridLocation> results;

    for (GridLocation dir : DIRS) {
        GridLocation next{id.x + dir.x, id.y + dir.y};
        if (in_bounds(next) && passable(next)) {
            results.push_back(next);
        }
    }

    // see [ugly paths] section for an explanation:
    if ((id.x + id.y) % 2 == 0) {
        std::reverse(results.begin(), results.end());
    }

    return results;
}

void DrawGrid::add_rect(SquareGrid &grid, int x1, int y1, int x2, int y2) {
    for (int x = x1; x < x2; ++x) {
        for (int y = y1; y < y2; ++y) {
            grid.walls.insert(GridLocation{x, y});
        }
    }
}

SquareGrid DrawSquareGrid::make_diagram() {
    SquareGrid grid(30, 15);
    add_rect(grid, 3, 3, 5, 12);
    add_rect(grid, 13, 4, 15, 15);
    add_rect(grid, 21, 0, 23, 7);
    add_rect(grid, 23, 5, 26, 7);
    return grid;
}

void SquareGridBFS::drawGrid() {
    DrawSquareGrid dg;
    SquareGrid grid = dg.make_diagram();
    draw_grid(grid);
}

void SquareGridBFS::BFS_nogoal() {
    DrawSquareGrid dg;
    SquareGrid grid = dg.make_diagram();
    GridLocation start{7, 8};
    auto parents = BFS_withoutgoal(grid, start);
    draw_grid(grid, nullptr, &parents, nullptr, &start);
}

void SquareGridBFS::BFS_goal() {
    DrawSquareGrid dg;
    GridLocation start{8, 7}, goal{17, 2};
    SquareGrid grid = dg.make_diagram();
    auto came_from = BFS_withgoal(grid, start, goal);
    draw_grid(grid, nullptr, &came_from, nullptr, &start, &goal);
}
