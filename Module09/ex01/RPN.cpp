#include "RPN.hpp"
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
/*......................... CONSTRUCTORS & DESTRUCTOR ..........................*/

RPN::RPN() {}

RPN::RPN(std::string const & arg) : _expr(arg)
{
    try {refaktorExpression(); }
    catch (InvalidNumberException & e) {
        std::cerr << e.what() << "\n"; return; }

    _f[0] = &RPN::add;
    _f[1] = &RPN::substract;
    _f[2] = &RPN::multiply;
    _f[3] = &RPN::divide;

    try { calculate(); }
    catch (RpnException & e) {
        std::cerr << e.what() << "\n"; }
    catch (NaNException & e) {
        std::cerr << e.what() << "\n"; }
}

RPN::RPN( RPN const & src) { *this = src;}

RPN & RPN::operator=(RPN const & o) {
    this->_c = o._c;
    return  *this; }

RPN::~RPN( void ) {}

/*......................... PUBLIC MEMBER FUNCTIONS ..........................*/

bool   RPN::isOperator(const char c)
    { return (c == '+'|| c == '-'|| c == '*'|| c == '/'); }

bool RPN::isOperand(const char c)
    { return (std::isdigit(c)); }

void    RPN::refaktorExpression() {
    // checks if number is less than 10
    std::string::iterator it = _expr.begin();
    while (it != _expr.end())
    {
        if (isdigit(*it) && isdigit(*(it + 1)) && (it+1) != _expr.end())
            throw(InvalidNumberException());
        it++;
    }
    // refaktor string by removing space characters
    _expr.erase(std::remove_if(_expr.begin(), _expr.end(), ::isspace), _expr.end());}

int RPN::makeOperation(const char c) {
    long long v2 = _c.top();
    _c.pop();
    if (_c.empty())
        throw (RpnException());
    long long v1 = _c.top();
    _c.pop();

    int i = 0;
    while(i < 4 && _operatorType[i] != c) i++;
    
    long long res;
    switch (i)
    {
        case 0:
            res = (this->*_f[i])(v1, v2); break;
        case 1:
            res = (this->*_f[i])(v1, v2); break;
        case 2:
            res = (this->*_f[i])(v1, v2); break;
        case 3:
            if (!v2 || (!v1 && !v2))
                throw (NaNException());
            res = (this->*_f[i])(v1, v2); break;
    }
    if (res > INT_MAX || res < INT_MIN)
    {
        std::cerr << "Error: not a valid number.\n";
        exit(1);
    }
    return res;
}

void    RPN::calculate() {
    std::string::const_iterator it = _expr.begin();
    if (!isOperand(*it))
        throw RpnException();
    while (it != _expr.end()) {
        if (isOperand(*it))
            _c.push((*it - '0'));
        else if (isOperator(*it))
            _c.push(makeOperation(*it));
        ++it;
    }

    if (_c.size() != 1)
        throw (RpnException());
    std::cout << _c.top() << "\n";
}

long long RPN::add(long long v1, long long v2) { return v1 + v2; }

long long RPN::substract(long long v1, long long v2) { return v1 - v2; }

long long RPN::multiply(long long v1, long long v2) { return v1 * v2; }

long long RPN::divide(long long v1, long long v2) { return v1 / v2; }

/*............................. NON MEMBER FUNCTIONS ..........................*/

const char RPN::_operatorType[4] = {'+', '-', '*', '/'};

/*............................... EXCEPTIONS ..................................*/

const char * RPN::RpnException::what() const throw() { return "Error"; }

const char * RPN::NaNException::what() const throw() { return "NaN"; }

const char * RPN::InvalidNumberException::what() const throw() { return "Error"; }

/*----------------------------------- NOTES --------------------------------------

    checks if expression is valid
    std::string::iterator it = _expr.begin();
    while (it != _expr.end())
    {
        if (!isspace(*it) && !isspace(*(it + 1)) && (it+1) != _expr.end())
            throw(InvalidNumberException());
        it++;
    }

*/