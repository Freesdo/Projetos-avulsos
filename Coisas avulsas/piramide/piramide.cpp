#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#endif

void magica(const short int input);

int main()
{   
    #ifdef _WIN32
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    #endif
    short int input{};
    std::cout << "qual o tamanho (em pontos) você quer que a base da sua pirâmide tenha? ";
    std::cin >> input;
    magica(input);
    std::cout << "\ncabooo\n ";
    return 0;
}

void magica(const short int input) {
    char ponto = '.';
    for (std::size_t i{}; i < input; ++i) {
        for (std::size_t j{static_cast<std::size_t>(input)}; j > i; --j) {
            std::cout << ' ';
        }
        for (std::size_t h{}; h < i; h++)
            std::cout << ponto<<' ';
        std::cout << '\n';
    }
}
