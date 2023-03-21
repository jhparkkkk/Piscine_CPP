#pragma once
#include <iostream>

class Warlock
{
    private:
        Warlock();
        Warlock(Warlock const & o);
        Warlock & operator=(Warlock const & o);

        std::string name;
        std::string title;

    public:
        Warlock(std::string const & name, std::string const & title);
        ~Warlock();

        std::string const & getName() const;
        std::string const & getTitle() const;

        void    setTitle(std::string const & title);
        void    introduce() const;
};