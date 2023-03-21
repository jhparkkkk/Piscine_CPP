#pragma once 
#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
    private:
        TargetGenerator(TargetGenerator const & o);
        TargetGenerator & operator=(TargetGenerator const & o);
        std::map<std::string, ATarget *> arr;

    public:
        TargetGenerator();
        ~TargetGenerator();

        void    learnTargetType(ATarget * atarget_ptr);
        void    forgetTargetType(std::string const & target_name);
        ATarget* createTarget(std::string const & target_name);
};