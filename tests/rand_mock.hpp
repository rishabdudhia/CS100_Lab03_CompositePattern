#ifndef __RAND_MOCK_HPP__
#define __RAND_MOCK_HPP__

#include "../header/base.hpp"
#include "iostream"
#include <sstream>
#include <iomanip>

using namespace std;

class RandMock : public Base {
    public:
        RandMock () { }
        virtual double evaluate() {return rand; }
        virtual std::string stringify()
            {
                ostringstream ss;
                ss << rand;
                return ss.str();
            }
    private:
        double rand = 31;
};

#endif //__RAND_MOCK_HPP__

