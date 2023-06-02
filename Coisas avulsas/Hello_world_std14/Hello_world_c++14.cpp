#include <iostream>
#include <memory>
#include <string>
using std::cout;

class myclass {
protected:
    std::shared_ptr<std::string> hellno_;
private:
    int id_;
public:
    myclass() : hellno_(std::make_shared<std::string>()), id_(0) {}
    std::string getstring() { return *hellno_; }
};
class class_filha :public myclass {
public:
    void setstring(const std::string& sttr)noexcept { *hellno_ = sttr; }
    class_filha& operator=(const class_filha& ptrp) {
        *hellno_ = *(ptrp.hellno_);
        return *this;
    }
    friend std::string appendshow(class_filha& filha,std::string str);
    class_filha operator+(std::string(*pointer)(class_filha&,std::string)) {
        *hellno_ = pointer(*this,"World!");
        return *this;
    }
};

std::string appendshow(class_filha& filha,std::string str){
    filha.hellno_->back() != ' ' ? filha.hellno_->append(" " + str) : filha.hellno_->append(str);
    return *filha.hellno_;
}

int main() {
    std::shared_ptr<std::string> ptr{std::make_shared<std::string>("Hello")};
    class_filha hello;
    auto function_{ [ptr](class_filha& hello,std::shared_ptr<std::shared_ptr<std::string>> sptr = nullptr)->std::string {
      sptr = std::make_shared<std::shared_ptr<std::string>>(ptr);
      hello.setstring(**sptr);
      std::shared_ptr<class_filha> ptr_class(std::make_shared<class_filha>(hello));
      *ptr_class = *ptr_class + appendshow;
      return ptr_class->getstring();
    } };
    cout << function_(hello);
    return 0;
}

