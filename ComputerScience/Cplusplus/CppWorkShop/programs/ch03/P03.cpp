#include <iostream>
#include <array>
#include <vector>

int main()
{
    int dummyArray[10] = {1,2,3,4,5,6,7,8,9,10};

    std::vector<int> dummyVector (dummyArray+3, dummyArray+6);
    std::vector<int> dummyVector2 (dummyVector.begin(), dummyVector.begin()+3);

    for( int i : dummyVector){
        std::cout << "vector1: " << i << std::endl;
    }

    for( int i : dummyVector2){
        std::cout << "vector2: " << i << std::endl;
    }
    return 0;
}

