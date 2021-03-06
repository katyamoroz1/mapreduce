#include <iostream>
#include <fstream>
#include <map>
#include <boost/process.hpp>
#include <boost/process/system.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/process/io.hpp>

namespace bp = boost::process;

int main(int argc, char *argv[]) {
    if (!strcmp(argv[1], "map")) {
        bp::system(argv[2], bp::std_out > argv[4], bp::std_err > stderr, bp::std_in < argv[3]);
    } else if (!strcmp(argv[1], "reduce")) {
        std::ifstream in(argv[3]);
        std::string key, value;
        std::map<std::string, std::vector<std::pair<std::string, std::string>>> sort;
        while (in >> key >> value) {
            sort[key].emplace_back(key, value);
        }
        in.close();
        std::ofstream out;
        out.open(argv[4]);
        out.seekp(std::ios::beg);
        out.close();
        for (auto &el : sort) {
            out.open(argv[3]);
            for (auto &pair : el.second) {
                out << pair.first << '\t' << pair.second << '\n';
            }
            out.close();
            bp::ipstream stream;
            bp::system(argv[2], bp::std_out > stream, bp::std_err > stderr, bp::std_in < argv[3]);
            out.open(argv[4], std::ios::app);
            std::string line;
            while (std::getline(stream, line)) {
                out << line << '\n';
            }
            out.close();
        }
    }
    return 0;
}
