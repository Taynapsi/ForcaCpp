#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <locale.h>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

void imprime_palavra()
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (chutou[letra])
        {
            cout << letra << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

void imprime_cabecalho()
{
    cout << "*************************" << endl;
    cout << "***** Jogo da Forca *****" << endl;
    cout << "*************************" << endl;

    cout << endl;
}
bool letra_existe(char chute)
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (chute == letra)
        {
            return true;
        }
    }
    return false;
}
void chuta()
{
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if (letra_existe(chute))
    {
        cout << "Você acertou! Seu chute está na palavra. " << endl;
    }
    else
    {
        cout << "Você errou! Seu chute não está na palavra. " << endl;
        chutes_errados.push_back(chute);
    }

    cout << endl;
}
void imprime_erros()
{
    cout << "Chutes errados: ";
    for (char letra : chutes_errados)
    {
        cout << letra << " ";
    }
    cout << endl;
}
bool nao_acertou()
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (!chutou[letra])
        {
            return true;
        }
    }
    return false;
}
bool nao_enforcou()
{
    return chutes_errados.size() < 5;
}
void le_arquivo()
{
    ifstream arquivo;
    arquivo.open("palavras.txt");

    int quantidade_palavras;
    arquivo >> quantidade_palavras;

    cout << "O arquivo possui " << quantidade_palavras << " palavras." << endl;

    for(int i = 0; i < quantidade_palavras; i++)
    {
        string palavra_lida;
        arquivo >> palavra_lida;
        cout << "Na linhas " << i << " : " << palavra_lida << endl;
    }

}
int main()
{
    setlocale(LC_ALL, "Portuguese");

    imprime_cabecalho();
    le_arquivo();

    while (nao_acertou() && nao_enforcou())
    {
        imprime_erros();
        imprime_palavra();
        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;
    if (nao_acertou())
    {
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;
    }
}