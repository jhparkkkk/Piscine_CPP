#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file.\n";
        return (EXIT_FAILURE);
    }

    BitcoinExchange test(av[1]);

    return EXIT_SUCCESS;
}