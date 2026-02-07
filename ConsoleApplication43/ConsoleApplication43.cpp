#include <iostream>
#include <cstring>

using namespace std;

class Product {
private:
    char* name;
    int amount;
    char* type;

public:
    Product() {
        name = new char[1];
        name[0] = '\0';
        type = new char[1];
        type[0] = '\0';
        amount = 0;
        std::cout << "constructor default" << this << endl;
    }

    Product(const char* n, int q, const char* t) {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        type = new char[strlen(t) + 1];
        strcpy_s(type, strlen(t) + 1, t);
        amount = q;
        std::cout << "constructor " << this << endl;
    }

    Product(const Product& sample) {
        name = new char[strlen(sample.name) + 1];
        strcpy_s(name, strlen(sample.name) + 1, sample.name);

        type = new char[strlen(sample.type) + 1];
        strcpy_s(type, strlen(sample.type) + 1, sample.type);

        amount = sample.amount;
        std::cout << "constructor copy " << this << endl;
    }

    ~Product() {
        delete[] name;
        delete[] type;
        std::cout << "destructor " << this << endl;
    }

    void set_name(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    const char* get_name() const {
        return name;
    }

    void set_amount(int q) {
        amount = q;
    }

    int get_amount() const {
        return amount;
    }

    void set_type(const char* t) {
        delete[] type;
        type = new char[strlen(t) + 1];
        strcpy_s(type, strlen(t) + 1, t);
    }

    const char* get_type() const {
        return type;
    }

    void show() const {
        cout << "Product = " << name << "; Amount = " << amount << "; Type = " << type << endl;
    }
};

int main() {
    Product p1("Chair", 10, "mebel");
    Product p2 = p1;

    Product* p3 = new Product("dsdsd", 5, "ffff");
    Product* ptr = &p1;
    ptr->show();

    void (Product:: * funcPtr)() const;
    funcPtr = &Product::show;

    (p2.*funcPtr)();
    (p3->*funcPtr)();

    delete p3;
}
