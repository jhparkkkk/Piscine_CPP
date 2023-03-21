#include "Spellbook.hpp"

Spellbook::Spellbook() {}
Spellbook::~Spellbook() {
    if (this->arr.size() > 0)
	{
		std::map<std::string, ASpell *>::iterator it = this->arr.begin();
		std::map<std::string, ASpell *>::iterator ite = this->arr.end();
		while (it != ite)
		{
			delete it->second;
			it++;
		}
	}
}

void    Spellbook::learnSpell(ASpell *aspell_ptr)
{
    if (aspell_ptr)
        arr.insert(std::pair<std::string, ASpell*>(aspell_ptr->getName(), aspell_ptr->clone()));
}

void    Spellbook::forgetSpell(std::string const & spell_name)
{
    std::map<std::string, ASpell*>::iterator it = arr.find(spell_name);
    if (it != arr.end())
        delete it->second;
    arr.erase(spell_name);
}

ASpell *Spellbook::createSpell(std::string const & spell_name)
{
    std::map<std::string, ASpell*>::iterator it = arr.find(spell_name);
    if (it != arr.end())
        return arr[spell_name];
    return NULL;
}