#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char **argv) {
    std::string line;
    while (getline(std::cin, line)) {
        std::string word;
        std::string key;
        std::stringstream ss(line);
        ss >> key;
        while (ss >> word) {
            std::cout << word << '\t' << std::to_string(1) << '\n';
        }
    }
    return 0;
}

