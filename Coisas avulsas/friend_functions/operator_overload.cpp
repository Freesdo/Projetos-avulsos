#include <iostream>
using std::cout;
using std::cin;

class operacao {
private:
    int id_;
    std::string str_;
    float ff_;
public:
    operacao() :id_(0), ff_(0) {}
    operacao(const int& id, const std::string& str, const float& ff) :id_(id), str_(str), ff_(ff) {}
    operacao operator+(const operacao& some);
    inline void getatributos()const { cout << id_ << " " << str_ << " " << ff_ << "\n"; }
    int getid()const { return id_; }
    std::string getstr()const { return str_; }
    float getff()const { return ff_; }
};

operacao operacao::operator+(const operacao& some) {
    id_ = id_ + some.getid();
    str_.append(some.getstr());
    ff_ += some.getff();
    return *this;
}

int main() {
    operacao e(2, "eita", 3.12f);
    operacao f(4, " bicho", 9.11f);
    operacao g;
    g = f + e;
    g.getatributos();
    return 0;
}