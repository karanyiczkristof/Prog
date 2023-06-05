#include "firstHazi.h"
#include <sstream>

firstHazi::firstHazi(const std::string &a) : input(a), _end(false){
    if(input.fail()) throw firstHazi::IOException();
}

void firstHazi::first() {
    next();
}

bool firstHazi::end() const {
    return _end;
}

Covid firstHazi::current() const {
    return covid;
}

void firstHazi::next() {
    read();
    _end = Status::abnorm == status;
}

void firstHazi::read() {
    std::string line;
    if(std::getline(input, line))
    {
        status = Status::norm;
        std::stringstream ss(line);
        ss >> covid.date >> covid.news;
        if(covid.news > 5000)
        {
            covid.moreThan = true;
        } else{
            covid.moreThan = false;
        }
        std::string name;
        int count=0;
        covid.olds = 0;
        int closeToDeath;
        while(ss >> name >> count >> closeToDeath)
        {
            covid.olds += count;

        }

    } else{
        status = Status::abnorm;
    }
}


