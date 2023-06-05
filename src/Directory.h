#ifndef HAZI3_DIRECTORY_H
#define HAZI3_DIRECTORY_H

#include <vector>
#include "Entry.h"

class Directory : public Entry{
public:
    Directory(std::vector<Entry*> list);

    ~Directory();

    int GetSize() const override;

private:
     std::vector<Entry*> entries;
};


#endif
