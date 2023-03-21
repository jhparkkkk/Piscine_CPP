#pragma once
#include <iostream>
#include "ASpell.hpp"
#include <map>

class Warlock
{
    private:
        Warlock();
        Warlock(Warlock const & o);
        Warlock & operator=(Warlock const & o);

        std::string name;
        std::string title;

        std::map<std::string, ASpell*> arr;

    public:
        Warlock(std::string const & name, std::string const & title);
        ~Warlock();

        std::string const & getName() const;
        std::string const & getTitle() const;

        void    setTitle(std::string const & title);
        void    introduce() const;

        void    learnSpell(ASpell *aspell_ptr);
        void    forgetSpell(std::string const & spell_name);
        void    launchSpell(std::string const & spell_name, ATarget const & atarget_ref);
};