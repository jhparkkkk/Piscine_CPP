#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const & type)
{
    this->_type = type;
}

ATarget::ATarget(ATarget const & other)
{
    *this = other;    
}

ATarget & ATarget::operator=(ATarget const & other)
{
    this->_type = other._type;
    return *this;
}

ATarget::~ATarget() {}

std::string const & ATarget::getType() const
{
    return this->_type;
}

void    ATarget::getHitbySpell(ASpell const &aspell_ref) const
{
    std::cout << this->_type << " has been " << aspell_ref.getEffects()  << "!\n";
}
