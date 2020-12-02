#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "file-reader.h"

void FileReader::read() {
    try {
        std::ifstream readStream;

        // open the file stream
        readStream.open(this->fileName);

        // check if opening a file failed
        if (readStream.fail()) {
            readStream.close();
            throw std::runtime_error("Can't open file");
        }

        std::string line;
        while (std::getline(readStream, line)) {
            FileReader::compress(line);
            std::cout << line;
        }

        readStream.close();
    } catch (const std::exception &e) {
        std::cout << e.what();
    }
}

void FileReader::compress(std::string &line) {
    std::erase(line, ' ');
}
