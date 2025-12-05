#include "read_map.hpp"

using namespace std;

vector<vector<char>> read_map(const string& path) {

    vector<vector<char>> map;
    string line;

    fstream file(path, ios::in);

    if(!file.is_open()) {
        cerr << "Error : " << path << "\n";
        return map;
    }

    while(getline(file, line)) {
        vector<char> row;
        for(char c : line) {
            row.push_back(c);
        }
        map.push_back(row);
    }
    file.close();

    return map;
}

void print_map(vector<vector<char>>& map) {

    for(const auto& row : map) {
        for(char c : row) {
            cout << c;
        }
        cout << "\n";
    }
}
