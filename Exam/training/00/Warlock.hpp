#pragma once
#include <iostream>

class Warlock
{
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(Warlock const & o);
        Warlock & operator=(Warlock const & o);
    
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        std::string const & getName() const;
        std::string const & getTitle() const;

        void    setTitle(std::string const & title);
        void    introduce() const;
};