#include "inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange     btc;

    if (argc != 2)
    {
        std::cerr << "Error: Usage: ./btc <input file>." << std::endl;
        return 1;
    }

    try
    {
        btc.loadDataBase("data.csv");
        btc.processInput(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
