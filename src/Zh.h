#ifndef ZH_ZH_H
#define ZH_ZH_H

#include <string>
#include <exception>
#include <fstream>

struct Gyros{
    int income;
    bool moreThan70k;
    int order;
};

class Zh {
public:
    enum class Status {
        norm, abnorm
    };

    Zh(const std::string &a);

    class IOException : public std::exception {

    };

    void first();

    void next();

    Gyros current() const;

    bool end() const;

private:
    void read();
    Status status;
    std::ifstream input;
    Gyros gyros;
    bool _end;
};


#endif
