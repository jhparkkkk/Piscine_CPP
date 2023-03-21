#pragma once 
#include <iostream>
#include "ATarget.hpp"
#include <map>
class TargetGenerator
{
    private:
        std::map<std::string, ATarget*> arr;
        TargetGenerator(TargetGenerator const & o);
        TargetGenerator & operator=(TargetGenerator const & o);
    
    public:
        TargetGenerator();
        ~TargetGenerator();
        void    learnTargetType(ATarget * atarget_ptr);
        void    forgetTargetType(std::string const & target_type);
        ATarget* createTarget(std::string const & target_type);
};