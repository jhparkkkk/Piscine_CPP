// #include "ASpell.hpp"

// ASpell::ASpell() {}

// ASpell::ASpell(std::string const & name, std::string const & effects)
// {
//     this->_name = name;
//     this->_effects = effects;
// }

// ASpell::ASpell(ASpell const & other)
// {
//     *this = other;
// }

// ASpell & ASpell::operator=(ASpell const & other)
// {
//     this->_name = other._name;
//     this->_effects = other._effects;
//     return *this;
// }

// ASpell::~ASpell() {};

// std::string const &ASpell::getName() const
// {
//     return this->_name;
// }

// std::string const &ASpell::getEffects() const
// {
//     return this->_effects;
// }

// void ASpell::launch(ATarget const & atarget_ref) const
// {
//     atarget_ref.getHitbySpell((*this));
// }

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const & name, std::string const & effects)
{
    this->_name = name;
    this->_effects = effects;
}

ASpell::ASpell(ASpell const & other)
{
    *this = other;
}

ASpell & ASpell::operator=(ASpell const & other)
{
    this->_effects = other._effects;
    this->_name = other._name;
    return *this;
}

ASpell::~ASpell() {}

std::string const & ASpell::getName() const
{
    return this->_name;
}

std::string const & ASpell::getEffects() const
{
    return this->_effects;
}

void    ASpell::launch(ATarget const & atarget_ref) const
{
    atarget_ref.getHitbySpell(*this);
}