#pragma once 
#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
    private:
        SpellBook(SpellBook const & o);
        SpellBook & operator=(SpellBook const & o);
        std::map<std::string, ASpell *> arr;

    public:
        SpellBook();
        ~SpellBook();

        void    learnSpell(ASpell * aspell_ptr);
        void    forgetSpell(std::string const & spell_name);
        ASpell* createSpell(std::string const & spell_name);
};