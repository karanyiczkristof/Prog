#include "Zh.h"
#include <sstream>

Zh::Zh(const std::string &a) : input(a), _end(false){
    if(input.fail()) throw Zh::IOException();
}

void Zh::first() {
    next();
}

bool Zh::end() const {
    return _end;
}

Gyros Zh::current() const {
    return gyros;
}

void Zh::next() {
    read();
    _end = Status::abnorm == status;
}

void Zh::read() {
    std::string line;
    if(std::getline(input, line))
    {
        status = Status::norm;
        std::string day;
        std::stringstream ss(line);
        ss >> day >> gyros.income;
        if(gyros.income > 70000)
        {
            gyros.moreThan70k = true;
        } else {
            gyros.moreThan70k = false;
        }
        std::string foodtype;
        bool onion = false;
        bool chili = false;
        gyros.order = 0;
        while(ss >> foodtype >> onion >> chili)
        {
            gyros.order++;

        }

    } else{
        status = Status::abnorm;
    }
}
