#pragma once
#include <map>
#include "ASpell.hpp"
class SpellBook
{
    private:
        std::map<std::string, ASpell *>  arr;
        SpellBook(SpellBook const & o);
        SpellBook & operator=(SpellBook const & o);
    public:
        SpellBook();
        ~SpellBook();

        void    learnSpell(ASpell * aspell_ptr);
        void    forgetSpell(std::string const & spell_name);
        ASpell  *createSpell(std::string const & spell_name);
};
