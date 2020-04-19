#include "stack.h"
#include <assert.h>
#include <fstream>

Stack::Stack() {
    this->count = 0;
    this->top = nullptr;
}
Stack::Stack(const Stack &compStack)
{
    top = nullptr;
    for(auto compCur = compStack.top; compCur; compCur = compCur->prev)
    {
        Push((compCur->value));
    }

}
void Stack::Push(Complex value){
    Entry* pEntry = new Entry(value); //Entry pEntry = Entry(value)
    assert(pEntry);
    pEntry->prev = this->top;
    this->top = pEntry;
    this->count++;
}

Complex Stack::Pop(){
    assert(count);
    Entry* pEntry = this->top;
    this->top = this->top->prev;
    this->count--;
    Complex value = pEntry->value;
    delete pEntry;
    return value;
}

bool Stack::isEmpty(){
    return this->count == 0;
}

void Stack::clear(){
    Entry* pEntry = this->top;
    auto cur = pEntry;
    while(cur)
    {
        auto tmp = cur;
        cur = cur->prev;
        delete tmp;
    }
    pEntry = nullptr;
    std::cout<<"Now it's clear!";
}
int Stack::size() const{
        int cnt = 0;
        Entry* node;
        for ( node = top; node; node = node->prev )
            ++cnt;
        return cnt;
    }
bool Stack::elements()
{
    return count >= 2;
}
const Complex& Stack::get(const int &pos) const
{
    auto cur = top;
    for(auto i = 0; i < pos && cur; i++, cur = cur->prev);
    if(cur && pos >= 0)
        return (cur->value);
    std::cout << "Not enough elements!" << std::endl;
    return (top->value);
}

Complex Stack::operator^(char op){
    assert(elements());
    Complex a = this->Pop();
    Complex b = this->Pop();
    Complex c;
    if (op == '+') {
        c = a + b;
    }
    else if (op == '-') {
        c = a - b;
    }
    else if (op == '*') {
        c = a * b;
    }
    else if (op == '/') {
        c = a / b;
    }
    else{
        assert(0);
    }
    this->Push(c);
    return c;
}

Stack::~Stack(){
    for (int i = 0; i < this->count; i++) {
        this->Pop();
    }
}


