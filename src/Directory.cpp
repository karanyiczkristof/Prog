#include "Directory.h"

Directory::Directory(std::vector<Entry *> list) {
    entries = list;
}

Directory::~Directory() {
    for(Entry* entry : entries){
        delete entry;
    }
}

int Directory::GetSize() const {
    int s = 0;
    for(Entry* entry : entries){
        s += entry->GetSize();
    }
    return s;
}
