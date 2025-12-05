#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>

struct Chromosome {

    std::vector<std::pair<int,int>> genes;
    int fitness = 0;

    static const std::vector<std::pair<int,int>> possible_genes;

    static Chromosome make_first_moves(int num_moves);
};

#endif
