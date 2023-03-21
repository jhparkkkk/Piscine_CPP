#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:
        std::string type;

    public:
        ATarget();
        ATarget(std::string type);
        virtual ~ATarget();
        ATarget(ATarget const & o);
        ATarget & operator=(ATarget const & o);

        std::string const & getType() const;

        virtual ATarget*clone() const = 0;

        void    getHitBySpell(ASpell const & aspell_ref) const;

};
