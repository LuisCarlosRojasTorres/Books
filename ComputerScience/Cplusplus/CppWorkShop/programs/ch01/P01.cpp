/* REMEMBER: To compile...
g++ <dummyName>.cpp -o <dummyName>
*/


#include<iostream>
#include<string>
int main (){
    std::string ageString;
    int ageInt;
    std::cout << "Age " << std::endl;
    getline(std::cin , ageString); // 123456
	ageInt = std::stoi(ageString);
    std::cout << "Age:" << ageString << std::endl; // Prints 123456
    return 0;
}