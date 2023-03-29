#include "RPN.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: only one argument required.\n"
        << "Usage: ./RPN \"<expression>\".\n";
        return (1);
    }

    RPN test(av[1]);

    return (0);
}