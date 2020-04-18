#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char **argv) {
    std::string line;
    std::string key;
    int count = 0;
    while (getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> key;
       count++;
    }
    std::cout << key << '\t' << std::to_string(count) << '\n';
    return 0;
}
