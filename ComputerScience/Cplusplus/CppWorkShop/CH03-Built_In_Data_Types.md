<!-- vscode-markdown-toc -->
* 1. [Data types](#Datatypes)
	* 1.1. [Type Modifiers](#TypeModifiers)
	* 1.2. [Built-in Types](#Built-inTypes)
	* 1.3. [Reference Table](#ReferenceTable)
* 2. [Containers](#Containers)
	* 2.1. [Arrays](#Arrays)
		* 2.1.1. [Initialization](#Initialization)
		* 2.1.2. [Accessing Elements](#AccessingElements)
		* 2.1.3. [Array Memory](#ArrayMemory)
	* 2.2. [Multidimensional Arrays](#MultidimensionalArrays)
	* 2.3. [Vectors](#Vectors)
		* 2.3.1. [Accessing Elements](#AccessingElements-1)
		* 2.3.2. [Initialization](#Initialization-1)
	* 2.4. [Modifying Elements](#ModifyingElements)
* 3. [Classes and Structs](#ClassesandStructs)
	* 3.1. [Classes](#Classes)
	* 3.2. [Structs](#Structs)
	* 3.3. [Access Modifiers](#AccessModifiers)
	* 3.4. [Constructors Destructors](#ConstructorsDestructors)
* 4. [Storage Lifetime](#StorageLifetime)
	* 4.1. [Static](#Static)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

doi 10.1177/2167702617723376
Increase in Depresve Symptoms

##  1. <a name='Datatypes'></a>Data types

###  1.1. <a name='TypeModifiers'></a>Type Modifiers

###  1.2. <a name='Built-inTypes'></a>Built-in Types

###  1.3. <a name='ReferenceTable'></a>Reference Table

##  2. <a name='Containers'></a>Containers

###  2.1. <a name='Arrays'></a>Arrays 
- Arrays are containers of objects. Each object sits next to one another in memory
- The size of an array shall be known at compile time.
- Declaration is:
  - `<Type> arrayName [numberOfElements]`

####  2.1.1. <a name='Initialization'></a>Initialization
- initialization with garbage values.
``` cpp
int arrayName[5]; 
//The array will contain garbage values
```
- Complete initialization with `numberOfElements` and `arrayValues`
``` cpp
int arrayName[5] = {1,2,3,4,5}; 
//The array will contain 1,2,3,4,5
```
- The `numberOfElements` is not necessary if we set all the values.
``` cpp
int arrayName[] = {1,2,3,4,5};
```
- Partial initialization is also possible which sets other values to zero.
``` cpp
int arrayName[5] = {1,2};
//The array will contain 1,2,0,0,0
```

####  2.1.2. <a name='AccessingElements'></a>Accessing Elements
- The elements are accessed using indexes.
- The first element has index `0`, the nth element has `n-1` index.
``` cpp
int arrayName[] = {1,2,3,4,5};
int secondValue = arrayName[1];
```
- To get the size of an array the following statement can be used.+

``` cpp
sizeof(myArray)/sizeof(myArray[0]);
```

- **C++11** has `std::array` which `size` getter function.

``` cpp
#include<iostream>
#include<array>
int main()
{
    std::array<int, 5> myArray {11,22,33,44,55};
    std::cout << "Size: " << myArray.size() << std::endl;
    return 0;
}
```

- **C++17** has `std::size()` which is a function to return the element count of both standard containers.

``` cpp
#include<iostream>
#include<array>

int main()
{
    std::array<int, 5> myArray {11,22,33,44,55};
    std::cout << "Size: " << std::size(myArray) << std::endl;
    return 0;
}
```
####  2.1.3. <a name='ArrayMemory'></a>Array Memory

- To access to the memory address of each element of an Array use `&`
``` cpp
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
```

```
Size: 5
Address: 0x7ffe2b23e7c0
Address: 0x7ffe2b23e7c4
Address: 0x7ffe2b23e7c8
Address: 0x7ffe2b23e7cc
Address: 0x7ffe2b23e7d0
```

###  2.2. <a name='MultidimensionalArrays'></a>Multidimensional Arrays
- The format is the following: `Type dummyName [numOfRows][numOfColums]`
- One example is:

``` cpp
int myArray [3][5] = {{1,2,3,4,5},{2,4,6,8,10},{3,6,9,12,15}};
```

- The numbers for rows and colums could be `#define`s

###  2.3. <a name='Vectors'></a>Vectors
- Dynamic size (defined during runtime).
- it store collections of elements continuously.
- Format: `std::vector<TypeOfVariable> dummyName`


####  2.3.1. <a name='AccessingElements-1'></a>Accessing Elements
- First option:
  - Using indexes `[]`
    ``` cpp
	std::vector<int> integerVector;
	int myFirstElement = integerVector[0];
	int mySecondElement = integerVector[1];
	```
- Second option:
  - Using `.at` function. It is almost the same that using indexes, BUT it throws exceptions instead of undefined behavior.
    ``` cpp
	std::vector<int> integerVector;
	int myFirstElement = integerVector.at(0);
	int mySecondElement = integerVector.at(1);
	```    - 
####  2.3.2. <a name='Initialization-1'></a>Initialization
- Initialization with values:
  - `std::vector<int> dummyVector {1,2,3,4,5};`
- Initialization with repeated values (5 elements all with a value of `1`):
  - `std::vector<int> dummyVector (5,1);`
- It is possible to initialize a vector using an array or another vector.
  - `std::vector<int> dummyVector (dummyArray, dummyArray + dummyArraySize);`
  - `std::vector<int> dummyVector (dummyVector.begin(), dummyVector.end());`

``` cpp
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
```

###  2.4. <a name='ModifyingElements'></a>Modifying Elements
- `push_back`: add an element to the end of the vector.
- `pop_back`: remove an element from the end of a vector.
- `insert` (use iterators): `myVector.erase(myVector.begin()+1)`
- `erase` (use iterators): `myVector.insert(myVector.begin()+2,9)`
  - `begin()`: returns an iterator pointing to the first element in the vector.

##  3. <a name='ClassesandStructs'></a>Classes and Structs

###  3.1. <a name='Classes'></a>Classes 

###  3.2. <a name='Structs'></a>Structs

###  3.3. <a name='AccessModifiers'></a>Access Modifiers

###  3.4. <a name='ConstructorsDestructors'></a>Constructors Destructors

##  4. <a name='StorageLifetime'></a>Storage Lifetime

###  4.1. <a name='Static'></a>Static