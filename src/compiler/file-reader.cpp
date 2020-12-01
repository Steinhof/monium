//
// Created by l on 01.12.2020.
//

#include <iostream>
#include <fstream>
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
            std::cout << line;
        }

        readStream.close();
    } catch (const std::exception &e) {
        std::cout << e.what();
    }
}
