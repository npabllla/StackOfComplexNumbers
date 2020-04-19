#include "complex.h"
#include <iostream>
using namespace std;

class Stack {
    class Entry {
    public:
        Complex value;
        Entry* prev;
        Entry() {
            prev = nullptr;
        }
        Entry(Complex value) {
            this->value = value;
            prev = nullptr;
        }
    };

    int count;
    Entry* top;

public:

    Stack();
    Stack(const Stack &compStack);
    void Push(Complex);
    Complex Pop();
    bool isEmpty();
    void clear();
    const Complex& get(const int &pos) const;
    int size() const;
    bool elements();
    //void Show();
    void readComplex(const std::string filename);
    void writeComplex(const std::string filename);
    Complex operator^(char);
    ~Stack();
};
