#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
        std::string name;
        std::string effects;

    public:
        ASpell();
        ASpell(std::string name, std::string effects);
        virtual ~ASpell();
        ASpell(ASpell const & o);
        ASpell & operator=(ASpell const & o);

        std::string const & getName() const;
        std::string const & getEffects() const;

        virtual ASpell*clone() const = 0;

        void    launch(ATarget const & atarget_ref) const;
};
