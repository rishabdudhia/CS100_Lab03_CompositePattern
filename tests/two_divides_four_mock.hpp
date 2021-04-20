#ifndef __TWO_DIVIDES_FOUR_MOCK_HPP__
#define __TWO_DIVIDES_FOUR_MOCK_HPP__

#include "../header/base.hpp"
#include "iostream"
#include <sstream>
#include <iomanip>

using namespace std;

class TwoDividesFourMock : public Base {
    public:
        TwoDividesFourMock () { }
        virtual double evaluate() {return (four / two); }
        virtual std::string stringify()
            {
                ostringstream ss;
                ss << "(4/2)";
                return ss.str();
            }
    private:
        double two = 2;
        double four = 4;
};

#endif //__TWO_DIVIDES_FOUR_MOCK_HPP__

