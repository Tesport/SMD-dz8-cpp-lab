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
        std::cout << "constructor default was called by \"" << this << "\" this object" << endl;
    }

    Product(const char* n, int q, const char* t) {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        type = new char[strlen(t) + 1];
        strcpy_s(type, strlen(t) + 1, t);
        amount = q;
        std::cout << "constructor was called by \"" << this << "\" this object" << endl;
    }

    Product(const Product& sample) {
        name = new char[strlen(sample.name) + 1];
        strcpy_s(name, strlen(sample.name) + 1, sample.name);

        type = new char[strlen(sample.type) + 1];
        strcpy_s(type, strlen(sample.type) + 1, sample.type);

        amount = sample.amount;
        std::cout << "constructor copy was called by \"" << this << "\" this object" << endl;
    }

    ~Product() {
        delete[] name;
        delete[] type;
        std::cout << "destructor was called by \"" << this << "\" this object" << endl;
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
    Product a("Mouse", 12, "Electronics");
    Product b("Keyboard", 7, "Electronics");
    Product c = a;
    Product d;
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;
    Product* arr[4];
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;
    arr[3] = &d;

    for (int i = 0; i < 4; i++)
        arr[i]->show();
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;

    cout << "Ykazatel na komponenty-funcziu: \n";
    void (Product:: * f)() const = &Product::show;


    Product* p = new Product("Monitor", 4, "Electronics");

    arr[1]->set_amount(20);
    (arr[1]->*f)();
    (p->*f)();
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;
    delete p;
}
