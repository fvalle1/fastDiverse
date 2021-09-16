#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

template <typename T>
void append_diversity(std::vector<T> &data, T value){
    if (std::find(data.begin(), data.end(), value)==data.end())
    {
        data.push_back(value);
    }
}

template <typename T>
void loadFile(const char* filename){
    std::ifstream file(filename, std::ios::in);
    if(!file.is_open()){
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::vector<std::vector<T>> diversities;

    std::string line;

    //header
    std::string entry;

    std::getline(file, line);
    std::stringstream ss(line);
    std::getline(ss, entry, ',');
    while (std::getline(ss, entry, ','))
    {
        diversities.emplace_back(std::vector<T>());
    }

    //data
    while (std::getline(file, line))
        {
            std::stringstream ss(line);

            //index
            std::getline(ss, entry, ',');

            int iter = 0;

            while (std::getline(ss, entry, ','))
            {
                append_diversity<T>(diversities[iter], static_cast<T>(std::stoi(entry)));
                iter++;
            }
        }

    std::vector<long int> diversity_count;

    for (auto &diversity : diversities){
        diversity_count.push_back(diversity.size());
    }

    std::ofstream outfile("diversity.csv", std::ios::out);


    for(auto &diversity : diversity_count){
        outfile << diversity << std::endl;
    }

    outfile.close();
}