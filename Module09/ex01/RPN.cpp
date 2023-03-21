#include "RPN.hpp"


/*......................... CONSTRUCTORS & DESTRUCTOR ..........................*/

RPN::RPN() {}

RPN::RPN(std::string const & arg) : _expr(arg)
{
    refaktorExpression();

    _f[0] = &RPN::add;
    _f[1] = &RPN::substract;
    _f[2] = &RPN::multiply;
    _f[3] = &RPN::divide;

    try { calculate(); }
    catch (RpnException & e) {
        std:: cout << e.what() << "\n";
        exit(1); }
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
    _expr.erase(std::remove_if(_expr.begin(), _expr.end(), ::isspace), _expr.end());}

int RPN::makeOperation(const char c) {
    int v2 = _c.top();
    _c.pop();
    if (_c.empty())
        throw (RpnException());
    int v1 = _c.top();
    _c.pop();

    int idx = 0;
    while(idx < 4 && _operatorType[idx] != c) idx++;
    
    int res;
    switch (idx)
    {
        case 0:
            res = (this->*_f[idx])(v1, v2); break;
        case 1:
            res = (this->*_f[idx])(v1, v2); break;
        case 2:
            res = (this->*_f[idx])(v1, v2); break;
        case 3:
            try { res = (this->*_f[idx])(v1, v2); break; }
            catch (NaNException & e) {
                std:: cout << e.what() << "\n";
                exit(1); }
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

int RPN::add(int v1, int v2) { return v1 + v2; }

int RPN::substract(int v1, int v2) { return v1 - v2; }

int RPN::multiply(int v1, int v2) { return v1 * v2; }

int RPN::divide(int v1, int v2) {
    if (!v2 || (!v1 && !v2))
        throw (NaNException());
    return v1 / v2;
}

/*............................. NON MEMBER FUNCTIONS ..........................*/

const char RPN::_operatorType[4] = {'+', '-', '*', '/'};

/*............................... EXCEPTIONS ..................................*/

const char * RPN::RpnException::what() const throw() { return "Error"; }

const char * RPN::NaNException::what() const throw() { return "NaN"; }
