#include <iostream>
#include <vector>
#include <string>

class tempo {
private:
    int horas_;
    int minutos_;
public:
    tempo() :horas_(0), minutos_(0) {};
    tempo(int horas, int minutos) :horas_(horas), minutos_(minutos) {}
    void resetar(int horas = 0, int minutos = 0) {
        horas_ = horas;
        minutos_ = minutos;
    }//vamos resolver isso com funções amigas
    void imprimir()const; //não use isso, use o friend tempo operator<<
    tempo operator+(const tempo& t);
    tempo operator+(int num);
    friend tempo operator+(int num, const tempo& t);
    friend std::istream& operator>>(std::istream& in,tempo& temp) {
        in >> temp.horas_>> temp.minutos_;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& o,const tempo& temp) {
        o<< "isso aqui esta com " << temp.horas_ << " horas e " << temp.minutos_ << " minutos\n";
        return o;
    }
 };


std::size_t quadrado(const std::size_t& input) {
    return input * input;
}

void print(const std::size_t& input, std::size_t(*ptr)(const std::size_t&)) {
    std::cout << "o valor ao quadrado do numero fornecido e " << ptr(input);
}

int* vetor_position(const std::vector<int>& vet, const int& pos) {
    int* vetor_temp{ new int[vet.size() - pos] };
    int j{};
    for (auto i = vet.begin() + pos; i != vet.end(); ++i) {
        vetor_temp[j] = *i;
        j++;
    }
 
    for (std::size_t i{}; i < vet.size() - pos; ++i)
        std::cout << vetor_temp[i] << '\n';
    return vetor_temp;
}

int main() {
    /*  int* eita;
      int* (*ptr_function)(const std::vector<int> &, const int&);
      ptr_function = vetor_position;
      eita = ptr_function({1,2,3,4,5,6,7,8,9,10,5}, 2);
      print(66, quadrado);
      system("pause");
      delete[]eita;
      */
    tempo eita{ 1,30 };
    std::cout << eita;
    std::cin >> eita;
    std::cout << eita;
    return 0;
}