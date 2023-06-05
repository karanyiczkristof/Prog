#ifndef OEP_FIRSTHAZI_H
#define OEP_FIRSTHAZI_H

#include <string>
#include <exception>
#include <fstream>

struct Covid {
    std::string date;
    int news;
    int olds;
    bool moreThan;
};


class firstHazi {
public:
    enum class Status {
        norm, abnorm
    };

    firstHazi(const std::string &a);

    class IOException : public std::exception {

    };

    void first();

    void next();

    Covid current() const;

    bool end() const;

private:
    void read();
    Status status;
    std::ifstream input;
    Covid covid;
    bool _end;
};



#endif
