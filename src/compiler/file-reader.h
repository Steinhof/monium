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

    static void compress(std::string &line);
};


#endif //MONIUM_FILE_READER_H
