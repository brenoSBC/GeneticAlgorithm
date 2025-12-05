#ifndef READ_MAP_HPP
#define READ_MAP_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<char>> read_map(const std::string& path);

void print_map(std::vector<std::vector<char>>& map);

#endif
