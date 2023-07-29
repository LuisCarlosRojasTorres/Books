<!-- vscode-markdown-toc -->
* 1. [Anatomy of Cpp](#AnatomyofCpp)
	* 1.1. [Cpp Build Pipeline](#CppBuildPipeline)
* 2. [Preprocessor directives](#Preprocessordirectives)
	* 2.1. [Include](#Include)
	* 2.2. [Macros](#Macros)
		* 2.2.1. [For Data](#ForData)
		* 2.2.2. [For Functionality](#ForFunctionality)
	* 2.3. [Conditional Compilation](#ConditionalCompilation)
* 3. [Basic I O Statements](#BasicIOStatements)
* 4. [Function](#Function)
	* 4.1. [Passing by Value, Passing by Reference](#PassingbyValuePassingbyReference)
	* 4.2. [Function Overloading](#FunctionOverloading)
	* 4.3. [Default Parameters](#DefaultParameters)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='AnatomyofCpp'></a>Anatomy of Cpp

###  1.1. <a name='CppBuildPipeline'></a>Cpp Build Pipeline
1. **Preprocessor**: It resolves any preprocessor directive in the code.
2. **Compilation**: Source code is converted int o a `binary` (i.e. object files `.o` or `.obj` depending on the platform)
3. **Linker**: Links all the binaries and create a final executable.

Remember: To compile with `g++`:
`g++ -std=c11 -Wall -fmax-errors=10 -Wextra program.cpp -o program`

##  2. <a name='Preprocessordirectives'></a>Preprocessor directives

###  2.1. <a name='Include'></a>Include
- `#include <iostream>`: For system headers.
- `#include "headerFile.h"`: Directs the preprocessor to start its search locally.
	- Generally used to include your own project header.

###  2.2. <a name='Macros'></a>Macros

####  2.2.1. <a name='ForData'></a>For Data

``` cpp
#include<iostream>
#define LOBO "SOU LOBO"
int main (){
    std::cout << LOBO << std::endl;
    return 0;
}
```

####  2.2.2. <a name='ForFunctionality'></a>For Functionality

``` cpp
#include<iostream>
#define SOMA(a,b) (a+b)
int main (){
    std::cout << SOMA(5,7) << std::endl;
    return 0;
}
```

- To deactivate the macro use `#undef `

``` cpp
#include<iostream>
#define SOMA(a,b) (a+b)
int main (){
    std::cout << SOMA(5,7) << std::endl;

    #undef SOMA
    std::cout << SOMA(5,7) << std::endl; //ERROR
    return 0;
}
```
###  2.3. <a name='ConditionalCompilation'></a>Conditional Compilation 
- `#ifdef/#endif` are used to check if a macro was defined before is used.

``` cpp
#include<iostream>
#define LOBO "SOU LOBO"
int main (){
    #ifdef LOBO
		std::cout << LOBO << std::endl;
	#endif

	#undef LOBO

	#ifdef LOBO
		//This is not executed
		std::cout << LOBO << std::endl;
	#endif

    return 0;
}
```

- `#ifndef` checks if the macro is not defined.

##  3. <a name='BasicIOStatements'></a>Basic I O Statements
- `std::cout<<` 
- `std::cin>>` will stop capturing input when it enconters a terminating character (`space tab` or `new line`)

``` cpp
#include<iostream>
#include<string>
int main (){
    std::string name;
    int age;
    std::cout << "Name " << std::endl; // Luis Rojas
    std::cin >> name;
    std::cout << "Name:" << name << std::endl; // Prints Luis
    return 0;
}
```

- `getline` is used to capture a whole line.
``` cpp
#include<iostream>
#include<string>
int main (){
    std::string name;
    int age;
    std::cout << "Name " << std::endl;
    getline(std::cin , name); // Luis Rojas
    std::cout << "Name:" << name << std::endl; // Prints Luis
    return 0;
}
```
-  NOTE: The `getline` **converts the input into a string**. To convert a string to int use `std::stoi` i.e. `"1" -> 1`
``` cpp
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
```

- To start a new line or insert a blank one use `\n` or `std::endl`


##  4. <a name='Function'></a>Function
- It has two parts:
  - **function declaration**: contains the most basic information about how that function will work. They are usually located at headers `.h` file.
    - return type 
    - name of the function
    - parameters
  - **function definition**: contains the implementation. THey are located at `.cpp` files
- A function is declared as follows:
`<returnType> nameOfTheFunction( parameterType1, parameterType2, ...)` 

###  4.1. <a name='PassingbyValuePassingbyReference'></a>Passing by Value, Passing by Reference

- **Passing by Value** that means that the function is working with a copy of the argument.
- **Passing by Reference** this used the actual variable. It called writing `&` before the variable name.
- 
``` cpp
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
```

###  4.2. <a name='FunctionOverloading'></a>Function Overloading
- This provides more than one version of the function
- Lets say we want a function that multiplies integers, its declaration will be:
``` cpp
int multiplication(int, int);
```
- But if we try to multiply `double` they will be converted into `int` lossing precision. So we need specific functions for these arguments. 
``` cpp
int multiplication(int, int);
double multiplication(double, double);
```
- The compiler will now which function to call.

###  4.3. <a name='DefaultParameters'></a>Default Parameters
- This permits that some arguments in functions will be **optional**. The formar is the following:
`<returnType> nameOfTheFunction( Type1 param1, Type2 param2 = defaultValue1, Type3 param3 = defaultValue2...)` 
- The optional parameters shall starts from the right. So for example: ` int multiply( int a, int b = 10)`
  - Can be called as:
    - `multiply( 3 , 4)` which sets `b = 4`, so it returns `12`.
    - `multiply( 3)` which implies `b = 10`, so it returns `30`.

