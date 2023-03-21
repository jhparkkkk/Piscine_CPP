#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {}

void    TargetGenerator::learnTargetType(ATarget* atarget_type)
{
    if (atarget_type)
        arr.insert(std::pair<std::string, ATarget *>(atarget_type->getType(), atarget_type));
}

void    TargetGenerator::forgetTargetType(std::string const & target)
{
    std::map<std::string, ATarget *>::iterator it = arr.find(target);
    if (it != arr.end())
        delete it->second;
    arr.erase(target);
}

ATarget*   TargetGenerator::createTarget(std::string const & target)
{
    std::map<std::string, ATarget *>::iterator it = arr.find(target);
    if (it != arr.end())
        return arr[target];
    return NULL;
}