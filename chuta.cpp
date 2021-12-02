
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "letra_existe.hpp"

extern std::map<char, bool> chutou;
extern std::vector<char> chutes_errados;

void chuta()
{
    std::cout << "Seu chute: ";
    char chute;
    std::cin >> chute;

    chutou[chute] = true;

    if (letra_existe(chute))
    {
        std::cout << "Voc� acertou! Seu chute est� na palavra. " << std::endl;
    }
    else
    {
        std::cout << "Voc� errou! Seu chute n�o est� na palavra. " << std::endl;
        chutes_errados.push_back(chute);
    }

    std::cout << std::endl;
}