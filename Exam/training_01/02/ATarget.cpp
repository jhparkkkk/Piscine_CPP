#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const & type)
{
    this->type = type;
}

ATarget::ATarget(ATarget const & o)
{
    *this = o;
}

ATarget & ATarget::operator=(ATarget const & o)
{
    this->type = o.type;
    return *this;
}

ATarget::~ATarget() {}

std::string const & ATarget::getType() const { return this->type; }

void    ATarget::getHitBySpell(ASpell const & aspell_ref) const
{
    std::cout << this->type << " has been " << aspell_ref.getEffects() << "!\n";
}