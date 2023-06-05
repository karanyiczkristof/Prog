#include "Zh.h"

#include <iostream>

int main() {
    try{
        Zh first("inp.txt");
        bool yes = false;
        int daycount=0;
        for(first.first(); !first.end(); first.next()) {
            Gyros current = first.current();
            if(current.moreThan70k) {
                yes = true;
            }
            if(current.order > 10){
                daycount++;
            }
        }
        if(yes)
        {
            std::cout << "yes" << " " << daycount << std::endl;
        } else {
            std::cout << "no" << " " << daycount << std::endl;
        }

    } catch (Zh::IOException &w) {
        std::cout << "Warning!" << std::endl;
    }


    return 0;
}
