#ifndef __EIGHT_TIMES_SEVEN_MOCK_HPP__
#define __EIGHT_TIMES_SEVEN_MOCK_HPP__

#include "../header/base.hpp"
#include "iostream"
#include <sstream>
#include <iomanip>

using namespace std;

class EightTimesSevenMock : public Base {
    public:
        EightTimesSevenMock () { }
        virtual double evaluate() {return (eight*seven); }
        virtual std::string stringify()
            {
                ostringstream ss;
                ss << "(8*7)";
                return ss.str();
            }
    private:
        double eight = 8;
        double seven = 7;
};

#endif //__EIGHT_TIMES_SEVEN_MOCK_HPP__

