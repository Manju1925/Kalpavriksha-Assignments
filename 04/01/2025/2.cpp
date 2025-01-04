// Call by reference in Cpp

#include <iostream>
using namespace std;

void modify(int &x) {
    x = 20;
}

int main() {
    int a = 10;
    modify(a);
    cout << a << endl;
    return 0;
}