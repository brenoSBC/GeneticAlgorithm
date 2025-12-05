#include "genetic.hpp"

using namespace std;

Chromosome tournament(vector<Chromosome> population, int k) {

    int best = rand() % population.size();

    for(int i = 1; i < k; ++i) {
        int rand_index = rand() % population.size();
        if(population[rand_index].fitness > population[best].fitness) {
            best = rand_index;
        }
    }
    return population[best];
}

Chromosome crossover(Chromosome c1, Chromosome c2) {

    Chromosome child;
    child.genes = c1.genes;

    int cut =  rand() % c1.genes.size();

    for(int i = cut; i < c1.genes.size(); ++i) {
        child.genes[i] = c2.genes[i];
    }
    return child;
}

void mutate(Chromosome& chromo, float mutation_rate) {

    for(auto& genes : chromo.genes) {
        if((rand() % 1000) < (mutation_rate * 1000)) {
            int rand_index = rand() % Chromosome::possible_genes.size();
            genes = Chromosome::possible_genes[rand_index];
        }
    }
}
