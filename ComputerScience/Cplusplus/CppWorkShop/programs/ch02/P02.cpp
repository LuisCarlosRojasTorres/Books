/* REMEMBER: To compile...
g++ <dummyName>.cpp -o <dummyName>
*/

#include<iostream>
#include<string>

void PassingByValue(int);
void PassingByReference(int&);

int main (){
    int n1 = 3;
    int n2 =5;
    PassingByValue(n1);
    PassingByReference(n2);

    std::cout << n1 << std::endl; // Returns 3
    std::cout << n2 << std::endl; // Returns 25
    return 0;
}

void PassingByValue(int n){
    n=n*n;
}
void PassingByReference(int &n){
    n=n*n;
}