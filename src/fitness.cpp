#include "fitness.hpp"

using namespace std;

int calculate_fitness(vector<pair<int, int>> moves, vector<vector<char>> map) {
    
    int score = 0;

    int x = 0;
    int y = 0;

    for (int i = 0; i < moves.size(); i++) {

        int dx = moves[i].first;
        int dy = moves[i].second;

        int new_x = x + dx;
        int new_y = y + dy;

        if (new_x < 0 || new_x >= map.size() || new_y < 0 || new_y >= map[0].size()) {
            score -= 10;
            continue;
        }

        if (i > 0) {
            if (dx == 1 && dy == 1) score += 100;   // down-right
            if (dx == -1 && dy == 1) score += 2;    // up-right
            if (dx == 1 && dy == -1) score -= 10;   // down-left
            if (dx == -1 && dy == -1) score -= 10;  // up-left
        }

        x = new_x;
        y = new_y;

        if (map[x][y] == 'P') {
            return 1000000000;
        }
    }
    return score;
}
