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

        long long     add(long long, long long);
        long long     substract(long long, long long);
        long long     multiply(long long, long long);
        long long     divide(long long, long long);

        class RpnException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NaNException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class InvalidNumberException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        std::stack<int> _c;
        std::string _expr;

        char static const _operatorType[4];
        long long (RPN::*_f[4])(long long, long long);

        RPN();
};
#endif