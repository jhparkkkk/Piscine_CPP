#ifndef RPN_HPP
 #define RPN_HPP

#include <iostream>
#include <stack>

class   RPN
{
    public:
        RPN(std::string const &);
        RPN(RPN const &);
        RPN& operator=(RPN const &);
        ~RPN();

        bool    isOperator(const char);
        bool    isOperand(const char);
        void    refaktorExpression();
        void    calculate();
        int     makeOperation(const char);

        int     add(int, int);
        int     substract(int, int);
        int     multiply(int, int);
        int     divide(int, int);

        class RpnException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NaNException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        std::stack<int> _c;
        std::string _expr;

        char static const _operatorType[4];
        int (RPN::*_f[4])(int, int);

        RPN();
};
#endif