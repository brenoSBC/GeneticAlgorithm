#include "chromosome.hpp"

using namespace std;

const vector<pair<int,int>> Chromosome::possible_genes = {
    { -1, 0 }, // UP
    {  1, 0 }, // DOWN
    { 0,  1 }, // RIGHT
    { 0, -1 }, // LEFT
    { -1, 1 }, // UP RIGHT
    { -1,-1 }, // UP LEFT
    { 1,  1 }, // DOWN RIGHT
    { 1, -1 }  // DOWN LEFT
};

Chromosome Chromosome::make_first_moves(int num_moves) {
    Chromosome chromo;
    for (int i = 0; i < num_moves; i++) {
        int rand_index = rand() % possible_genes.size();
        chromo.genes.push_back(possible_genes[rand_index]);
    }
    return chromo;
}
