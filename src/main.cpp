#include "read_map.hpp"
#include "fitness.hpp"
#include "chromosome.hpp"
#include "genetic.hpp"

#include <iostream>
#include <vector>

using namespace std;

#define PATH "map.txt"
#define POP 300
#define MOVES 300
#define GEN 100

int main() {

    srand(time(0));

    vector<vector<char>> map = read_map(PATH); 
    print_map(map);

    std::vector<Chromosome> population(POP);

    for(int generation = 0; generation < GEN; ++generation) {

        cout << "GENERATION NUMBER: " << generation << "\n";

        if(generation == 0) {

            for(int i = 0; i < POP; ++i) { 
                population[i] = Chromosome::make_first_moves(MOVES);
                population[i].fitness = calculate_fitness(population[i].genes, map);

                 cout << "Chromosome " << i
                    << " fitness=" << population[i].fitness << "\n";
            }
            continue;
        }

        vector<Chromosome> new_population(POP);

        for(int i = 0; i < POP; ++i) {

            Chromosome best_parent1 = tournament(population, 3);
            Chromosome best_parent2 = tournament(population, 3);

            Chromosome child = crossover(best_parent1, best_parent2);

            mutate(child, 0.08);

            child.fitness = calculate_fitness(child.genes, map);

            new_population[i] = child;

            cout << "Child " << i << " fitness = " << child.fitness << "\n";

            if (child.fitness >= 1000000000) {

                cout << "\nTARGET 'P' FOUND IN GENERATION " << generation << " | "
                     << "Child " << i << "\n";

                cout << "\nMOVES:\n";
                for(auto& gene : child.genes) {
                    cout << "( " << gene.first << " ; " << gene.second << " )";
                }
                cout << "\n";

                ofstream out("path.txt");
                for (auto &gene : child.genes) {
                    out << gene.first << " " << gene.second << "\n";
                }
                return 0;
            }
        }
        population = new_population;
    }    

    cout << "\nFINISHED WITHOUT FINDING THE TARGET 'P'\n";

    return 0;
}

