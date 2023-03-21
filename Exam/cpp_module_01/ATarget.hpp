#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    private:
        std::string _type;
    public:
        ATarget();
        ATarget(std::string const & type);
        ATarget(ATarget const & other);
        ATarget & operator=(ATarget const & other);
        virtual ~ATarget();

        std::string const & getType() const;

        void    getHitbySpell(ASpell const & aspell_ref) const;
        virtual ATarget *clone() const = 0;
};

