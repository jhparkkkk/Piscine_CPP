#pragma once
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>
class Warlock
{
    private:
        std::string name;
        std::string title;
        std::map<std::string, ASpell *> arr;

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

        void    learnSpell(ASpell *aspell_ptr);
        void    forgetSpell(std::string spell_name);
        void    launchSpell(std::string spell_name, ATarget const & atarget_ref);
};