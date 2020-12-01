#include "compiler/file-reader.h"

int main() {
    FileReader fs("../test.mon");
    fs.read();

    return 0;
}