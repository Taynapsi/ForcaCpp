#include <vector>
#include <string>


extern std::vector<char> chutes_errados;
bool nao_enforcou()
{
    return chutes_errados.size() < 5;
}