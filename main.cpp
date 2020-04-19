#include <iostream>
#include "stack.h"
#include <cassert>
using namespace std;

void showStack(const Stack &compStack);
void compare(const Stack &compStack_1, const Stack &compStack_2);

int main() {
    int n;
    cout << "Input count complex numbers ";
    cin >> n;
    Stack s;
    for (int i = 0; i < n; i++) {
        Complex a;
        a.set();
        s.Push(a);
    }
    Complex c1(3,2);
    Complex c2(1,1);
    Complex c3(4,6);
    Stack s2;
    s2.Push(c1);
    s2.Push(c2);
    s2.Push(c3);
    cout << "Complex numbers in Stack2:" << endl;
    showStack(s2);
    //assert(s.size());
    cout << "Complex numbers in Stack1:" << endl;
    showStack(s);
    compare(s,s2);
    cout << "Input:\n+ for sum\n- for subtraction\n* for addition\n/ for division\n$ for exit\n";
    char op = 'q';
    if (!s.elements()) {
        cout << "In stack only one element. Exit program.";
    }
    while (op != '$' && s.elements()){
        cout << "Input operation: ";
        cin >> op;
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            cout << "Undefined operation. Continue..." << endl;
            continue;
        }
        s ^ (op);
        cout << "Complex numbers in Stack after operation:" << endl;
        showStack(s);
        if (!s.elements()) {
            cout << "In stack only one element. Exit program.";
            break;
        }
    }
    return 0;
}

void showStack(const Stack &compStack)
{
    int count = compStack.size();
    for(int i = 0; i < count; i++)
    {
        compStack.get(i).show();
    }

}

void compare(const Stack &compStack_1, const Stack &compStack_2)
{
    int count_1 = compStack_1.size();
    int count_2 = compStack_2.size();
    assert(count_1 == count_2);
    for(int i = 0; i < count_1; i++)
    {
        assert(compStack_1.get(i).get_real() == compStack_2.get(i).get_real());
        assert(compStack_1.get(i).get_imagine() == compStack_2.get(i).get_imagine());
    }

}
