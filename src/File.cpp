#include "File.h"

File::File(int size) : size(size) {

}

File::~File() {

}

int File::GetSize() const {
    return size;
}
