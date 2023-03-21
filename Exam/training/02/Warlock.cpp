#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!\n";
}
std::string const & Warlock::getName() const
{
    return this->name;
}

std::string const & Warlock::getTitle() const
{
    return this->title;
}

void    Warlock::setTitle(std::string const & title)
{
    this->title = title;
}

void    Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void    Warlock::learnSpell(ASpell *aspell_ptr)
{
    book.learnSpell(aspell_ptr);
}

void    Warlock::forgetSpell(std::string spell_name)
{
    book.forgetSpell(spell_name);
}

void   Warlock::launchSpell(std::string spell_name, ATarget const & atarget_ref)
{
    ATarget const * test = 0;
    if (test == &atarget_ref)
        return;
    ASpell *tmp;
    tmp = book.createSpell(spell_name);
    if (tmp)
        tmp->launch(atarget_ref);
}