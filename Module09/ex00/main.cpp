#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: only one argument required.\n"
        << "Usage: ./btc \"<file>\".\n";
        return (EXIT_FAILURE);
    }

    BitcoinExchange test(av[1]);


    return EXIT_SUCCESS;
}