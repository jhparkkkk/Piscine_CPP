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

// void    Warlock::learnSpell(ASpell *spell_ptr)
// {
//     if (spell_ptr)
//         arr.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
// }

// void    Warlock::forgetSpell(std::string spell_name)
// {
//     std::map<std::string, ASpell *>::iterator it = arr.find(spell_name);
//     if (it != arr.end())
//         delete it->second;
//     arr.erase(spell_name);
// }

// void    Warlock::launchSpell(std::string spell_name, ATarget const & target_ref)
// {
//     ASpell* spell = arr[spell_name];
//     if (spell)
//         spell->launch(target_ref);
// }

void    Warlock::learnSpell(ASpell *aspell_ptr)
{
    book.learnSpell(aspell_ptr);
}

void    Warlock::forgetSpell(std::string spell_name)
{
    book.forgetSpell(spell_name);
}

void    Warlock::launchSpell(std::string spell_name, ATarget const & atarget_ref)
{
    ATarget *test = 0;
    if (test == &atarget_ref)
        return ;
    ASpell *test2 = book.createSpell(spell_name);
    if (test2)
        test2->launch(atarget_ref);
}

