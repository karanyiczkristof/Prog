#ifndef HAZI3_FILESYSTEM_H
#define HAZI3_FILESYSTEM_H

#include <vector>
#include "Entry.h"

class FileSystem {
private:
    std::vector<Entry*> entries;

public:
    FileSystem(std::vector<Entry *> list);
    ~FileSystem();

    std::vector<Entry *> GetEntries() const;
};


#endif
