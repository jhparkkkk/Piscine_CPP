#pragma once
#include <map>
#include "ATarget.hpp"
class TargetGenerator
{
    private:
        std::map<std::string, ATarget *>  arr;
        TargetGenerator(TargetGenerator const & o);
        TargetGenerator & operator=(TargetGenerator const & o);

    public:
        TargetGenerator();
        ~TargetGenerator();

        void    learnTargetType(ATarget * atarget_ptr);
        void    forgetTargetType(std::string const & target);
        ATarget  *createTarget(std::string const & target);
};
