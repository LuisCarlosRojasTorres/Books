#include<iostream>
#include<array>

int main()
{
    std::array<int, 5> myArray {11,22,33,44,55};
    std::cout << "Size: " << std::size(myArray) << std::endl;
    std::cout << "Address: " << &myArray[0] << std::endl;
    std::cout << "Address: " << &myArray[1] << std::endl;
    std::cout << "Address: " << &myArray[2] << std::endl;
    std::cout << "Address: " << &myArray[3] << std::endl;
    std::cout << "Address: " << &myArray[4] << std::endl;
    return 0;
}

