#ifndef __MOCK_FUNCS_HPP__
#define __MOCK_FUNCS_HPP__

#include "../header/base.hpp"
#include "iostream"
#include <sstream>
#include <iomanip>

class SevenOpMock: public Base {
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
};

class SevenF: public Base {
    public:
        SevenF() { }

        virtual double evaluate() { return 7; }
        virtual string stringify() { return "7"; }
};

class NegFiveOpMock: public Base {
    public:
       NegFiveOpMock() { }

        virtual double evaluate() { return -5; }
        virtual string stringify() { return "-5"; }
};

class fiveOpMock: public Base {
    public:
       fiveOpMock() { }

        virtual double evaluate() { return 5; }
        virtual string stringify() { return "5"; }
};

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { }

        virtual double evaluate() { return 0; }
        virtual string stringify() { return "0"; }
};

class PosDivisionTwentyoneBySevenOpMock: public Base {
    public:
       PosDivisionTwentyoneBySevenOpMock() { }

        virtual double evaluate() { return (21/7); }
        virtual string stringify() { return "(21/7)"; }
};

class NegDivisionTwentyoneByThreeOpMock: public Base {
    public:
       NegDivisionTwentyoneByThreeOpMock() { }

        virtual double evaluate() { return (-21/3); }
        virtual string stringify() { return "(-21/3)"; }
};

class NegDivisionSevetyFiveByFifteenOpMock: public Base {
    public:
       NegDivisionSevetyFiveByFifteenOpMock() { }

        virtual double evaluate() { return (-75.5/15); }
        virtual string stringify() { return "(-75.5/15)"; }
};

class PosADD15plus3: public Base {
    public:
       PosADD15plus3() { }

        virtual double evaluate() { return (18); }
        virtual string stringify() { return "(15+3)"; }
};
class PosADD12plus19: public Base {
    public:
       PosADD12plus19() { }

        virtual double evaluate() { return (31); }
        virtual string stringify() { return "(12+19)"; }
};
class NegplusPos: public Base {
    public:
       NegplusPos() { }

        virtual double evaluate() { return (12); }
        virtual string stringify() { return "(-3+15)"; }
};
class PosSubtraction: public Base {
    public:
       PosSubtraction() { }

        virtual double evaluate() { return (3); }
        virtual string stringify() { return "(10-7)"; }
};
class NegSubtraction: public Base {
    public:
       NegSubtraction() { }

        virtual double evaluate() { return (-3); }
        virtual string stringify() { return "(7-10)"; }
};
class Negpowthree: public Base {
    public:
       Negpowthree() { }

        virtual double evaluate() { return (-8); }
        virtual string stringify() { return "((-2)**(3))"; }
};
class Negpowtwo: public Base {
    public:
       Negpowtwo() { }

        virtual double evaluate() { return (4); }
        virtual string stringify() { return "((-2)**(2))"; }
 };
 class Pospowfour: public Base {
    public:
       Pospowfour() { }

        virtual double evaluate() { return (81); }
        virtual string stringify() { return "((3)**(4))"; }
};
#endif
