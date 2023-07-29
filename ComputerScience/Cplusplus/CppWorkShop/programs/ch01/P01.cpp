#include<iostream>

/* REMEMBER: To compile...
g++ <dummyName>.cpp -o <dummyName>
*/

#define SOMA(a,b) (a+b)
int main (){
    std::cout << SOMA(5,7) << std::endl;

    #undef SOMA
    std::cout << SOMA(5,7) << std::endl;
    return 0;
}