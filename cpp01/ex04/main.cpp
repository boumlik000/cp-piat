#include "main.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " filename s1 s2\n";
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error opening input file: " << filename << "\n";
        return 1;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error creating output file: " << filename << ".replace\n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) 
    {
        std::string replacedLine;
        std::string::size_type start = 0;
        std::string::size_type pos;
        while ((pos = line.find(s1, start)) != std::string::npos) {
            replacedLine.append(line, start, pos - start);
            replacedLine.append(s2);
            start = pos + s1.size();
        }
        replacedLine.append(line, start, line.size() - start);
        outputFile << replacedLine << "\n";
    }

    return 0;
}
