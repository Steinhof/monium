#ifndef MONIUM_FILE_READER_H
#define MONIUM_FILE_READER_H

#include <string>
#include <utility>

struct FileReader {

public:
    FileReader() = default;

    static void read(const std::string& fileName);

private:
    std::string fileName;

    static void trim(std::string &line);
};


#endif //MONIUM_FILE_READER_H
