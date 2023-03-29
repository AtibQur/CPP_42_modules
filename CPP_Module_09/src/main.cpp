#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
       std::cout << "2 files are needed, try again" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange BTC(argv[1]);
        BTC.loadfile();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
