#include "RPN.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: only one argument required.\n"
        << "Usage: ./RPN \"<expression>\".\n";
        return (EXIT_FAILURE);
    }

    RPN test(av[1]);


    return EXIT_SUCCESS;
}