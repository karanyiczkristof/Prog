#include "FileSystem.h"


FileSystem::FileSystem(std::vector<Entry *> list) {
    entries = list;
}

FileSystem::~FileSystem() {
    for(Entry* entry : entries){
        delete entry;
    }
}

std::vector<Entry *> FileSystem::GetEntries() const {
    return entries;
}
