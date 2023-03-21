#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    private:
        std::string name;
        std::string effects;

    public:
        ASpell();
        ASpell(std::string const & name, std::string const & effects);
        ASpell(ASpell const & o);
        ASpell & operator=(ASpell const & o);
        virtual ~ASpell();

        std::string const & getName() const;
        std::string const & getEffects() const;

        void    launch(ATarget const & atarget_ref) const;
        virtual ASpell *clone() const = 0;
};