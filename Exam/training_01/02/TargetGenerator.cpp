#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
    if (arr.size() > 0)
    {
        std::map<std::string, ATarget *>::iterator it = arr.begin();
        std::map<std::string, ATarget *>::iterator ite = arr.end();

        while (it != ite)
        {
            delete it->second;
            ++it;
        }
        arr.clear();
    }
}

void    TargetGenerator::learnTargetType(ATarget * atarget_ptr)
{
    if (atarget_ptr)
        arr.insert(std::pair<std::string, ATarget *>(atarget_ptr->getType(), atarget_ptr->clone()));
}

void    TargetGenerator::forgetTargetType(std::string const & target)
{
    std::map<std::string, ATarget*>::iterator it = arr.find(target);
    if (it != arr.end())
        delete it->second;
    arr.erase(target);
}

ATarget *TargetGenerator::createTarget(std::string const & target)
{
    std::map<std::string, ATarget*>::iterator it = arr.find(target);
    if (it != arr.end())
        return arr[target];
    return NULL;
}

