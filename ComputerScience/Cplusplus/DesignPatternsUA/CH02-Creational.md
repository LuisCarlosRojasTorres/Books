<!-- vscode-markdown-toc -->
* 1. [Creational Pattern](#CreationalPattern)
	* 1.1. [Singleton](#Singleton)
		* 1.1.1. [Implementation](#Implementation)
	* 1.2. [Factory Method](#FactoryMethod)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='CreationalPattern'></a>Creational Pattern

###  1.1. <a name='Singleton'></a>Singleton 
- Describes a way to **create an object**.
- This design pattern only has **one object** of a class.
- This single object is **globally accessible** within the program.
- In order to do this, create another instance of a Singleton class has to be impossible. So **how to do this?**.

####  1.1.1. <a name='Implementation'></a>Implementation
- A `private constructor`, so it cannot be called from outside the class. 
  - Declare class variable `static Singleton *uniqueInstance` which refers to the one instance of the class.
  - Create a public method `static Singleton *getInstance()` which will create an instance of this class, but only if an instance does not exist already.


``` cpp

#include <iostream>

class Singleton{
    private:
    static Singleton *uniqueInstance;

    Singleton(){
        // content
        std::cout<<" - Constructed"<<std::endl;
    }

    public:

    static Singleton *getInstance(){
        if(uniqueInstance == nullptr){
            uniqueInstance = new Singleton();
        }
        else{
            std::cout<<" - getInstance"<<std::endl;
        }
        return uniqueInstance;
    }

    void someMethod(){
        std::cout<<" - Method"<<std::endl;
    }
};

Singleton* Singleton::uniqueInstance = nullptr;     

int main(){

    Singleton *s1 = Singleton::getInstance();     
    Singleton *s2 = Singleton::getInstance();

    std::cout << s1 << std::endl;
    
    Singleton *s3 = Singleton::getInstance();
    std::cout << s2 << std::endl;
    s1->someMethod();    
}
```

###  1.2. <a name='FactoryMethod'></a>Factory Method

#### Factory Objects
- Operates like a factory in the real world and creates objects.
- It deals with the problem of creating objects without having to specify the classs (making sw easier to maintain, change, test and reuse).
- 
**Benefits of Factory Objects**

#### Factory Method Pattern 


``` cpp
// Condition-control
if(v1...){
    v2 = ...
}
// Iteration-control
for(v1...){
    v2 = ...
}
// Iteration-control
while(v1...){
    v2 = ...
}
```