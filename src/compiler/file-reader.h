//
// Created by l on 01.12.2020.
//

#ifndef MONIUM_FILE_READER_H
#define MONIUM_FILE_READER_H

#include <string>
#include <utility>

struct FileReader {

public:
    explicit FileReader(std::string fileName) : fileName(std::move(fileName)) {};

    void read();

private:
    std::string fileName;
};


#endif //MONIUM_FILE_READER_H
