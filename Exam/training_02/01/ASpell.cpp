#include "ASpell.hpp"

ASpell::ASpell() {}
ASpell::~ASpell() {}

ASpell::ASpell(std::string name, std::string effects)
{
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell(ASpell const & o)
{
    *this = o;
}

ASpell & ASpell::operator=(ASpell const & o)
{
    this->name = o.name;
    this->effects = o.effects;
    return *this;
}

std::string const & ASpell::getName() const { return this->name ; }
std::string const & ASpell::getEffects() const { return this->effects ; }

void    ASpell::launch(ATarget const & atarget_ref) const
{
    atarget_ref.getHitBySpell((*this));
}
