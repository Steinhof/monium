#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "file-reader.h"

void FileReader::read(const std::string& fileName) {
    try {
        std::ifstream readStream;

        // open the file stream
        readStream.open(fileName);

        // check if opening a file failed
        if (readStream.fail()) {
            readStream.close();
            throw std::runtime_error("Can't open file");
        }

        std::string line;
        while (std::getline(readStream, line)) {
            FileReader::trim(line);
            std::cout << line;
        }

        readStream.close();
    } catch (const std::exception &e) {
        std::cout << e.what();
    }
}

void FileReader::trim(std::string &line) {
    std::erase(line, ' ');
}
