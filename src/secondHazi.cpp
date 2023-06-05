#include "secondHazi.h"

#include <sstream>

secondHazi::secondHazi(const std::string &a) : input(a), _end(false){
    if(input.fail()) throw secondHazi::IOException();
}

void secondHazi::first() {
    next();
}

bool secondHazi::end() const {
    return _end;
}

Covid secondHazi::current() const {
    return covid;
}

void secondHazi::next() {
    read();
    _end = Status::abnorm == status;
}

void secondHazi::read() {
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
        if(covid.olds > 1000){
            covid.moreThanOneK = true;
        } else {
            covid.moreThanOneK = false;
        }
    } else{
        status = Status::abnorm;
    }
}


