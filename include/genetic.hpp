#ifndef GENETIC_HPP
#define GENETIC_HPP

#include "chromosome.hpp"
#include <vector>

Chromosome tournament(std::vector<Chromosome> population, int k);

Chromosome crossover(Chromosome c1, Chromosome c2);

void mutate(Chromosome& chromo, float mutation_rate);

#endif