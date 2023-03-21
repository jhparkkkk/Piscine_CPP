#pragma once 
#include <iostream>

#include "ASpell.hpp"
#include <map>
class Spellbook
{
    private :
        Spellbook(Spellbook const & o);
        Spellbook & operator=(Spellbook const & o);

        std::map<std::string, ASpell *> arr;

    public:
        Spellbook();
        ~Spellbook();

        void    learnSpell(ASpell *aspell_ptr);
        void    forgetSpell(std::string const & spell_name);
        ASpell*    createSpell(std::string const & spell_name);

};