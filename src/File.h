#ifndef HAZI3_FILE_H
#define HAZI3_FILE_H

#include "Entry.h"

class File : public Entry{
private:
    int size;

public:
    File(int size);

    ~File();

    int GetSize() const override;
};


#endif
