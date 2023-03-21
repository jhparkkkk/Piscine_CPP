#pragma once 
#include "ATarget.hpp"
#include <iostream>

class BrickWall : public ATarget
{
    public:
        BrickWall();
        ~BrickWall();

        virtual ATarget *clone() const;
};