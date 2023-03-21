#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!\n";
}

std::string const & Warlock::getName() const { return this->name; }

std::string const & Warlock::getTitle() const { return this->title; }

void    Warlock::setTitle(std::string const & title)
{
    this->title = title;
}

void    Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void    Warlock::learnSpell(ASpell * aspell_ptr)
{
    book.learnSpell(aspell_ptr);
}

void    Warlock::forgetSpell(std::string const & spell_name)
{
    book.forgetSpell(spell_name);
}

void    Warlock::launchSpell(std::string const & spell_name, ATarget const & atarget_ref)
{
    ATarget *test_1 = 0;
    if (test_1 == &atarget_ref)
        return;
    ASpell *test_2 = book.createSpell(spell_name);
    if (test_2)
        test_2->launch(atarget_ref);
}
