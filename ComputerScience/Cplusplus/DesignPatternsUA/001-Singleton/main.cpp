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