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

##  3. <a name='BasicIOStatements'></a>Basic I O Statements

##  4. <a name='Function'></a>Function

###  4.1. <a name='PassingbyValuePassingbyReference'></a>Passing by Value, Passing by Reference

###  4.2. <a name='FunctionOverloading'></a>Function Overloading

###  4.3. <a name='DefaultParameters'></a>Default Parameters

