<!-- vscode-markdown-toc -->
* 1. [Classes versus Structs](#ClassesversusStructs)
* 2. [Unions](#Unions)
* 3. [Contructors and Destructors](#ContructorsandDestructors)
	* 3.1. [Constructors](#Constructors)
	* 3.2. [Default Constructors](#DefaultConstructors)
	* 3.3. [Parameterized Constructors](#ParameterizedConstructors)
	* 3.4. [Copy Constructors](#CopyConstructors)
	* 3.5. [Shallow copy or Deep Copy](#ShallowcopyorDeepCopy)
	* 3.6. [Copy Assignment Operator](#CopyAssignmentOperator)
	* 3.7. [Destructors](#Destructors)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='ClassesversusStructs'></a>Classes versus Structs

##  2. <a name='Unions'></a>Unions

##  3. <a name='ContructorsandDestructors'></a>Contructors and Destructors

###  3.1. <a name='Constructors'></a>Constructors
- Initialize class member variables
- They have same name as the class
- No return type
- Called automatically whenever an instance of the class the belong is created.

For a class:

``` cpp 
class Persona
{
    public:
        std::string name;
        int age;   
};
```
###  3.2. <a name='DefaultConstructors'></a>Default Constructors
- No paramaters 
- If no implementedm the compiler will create one using the variable default values. i.e `0` for numbers and `empty` for strings.
``` cpp 

class Persona
{
    public:
        std::string name;
        int age;

        Persona(){
            name = "Lobo";
            age = 5;
        }   
};
```

###  3.3. <a name='ParameterizedConstructors'></a>Parameterized Constructors 

``` cpp 
class Persona
{
    public:
        std::string name;
        int age;

        Persona(){
            name = "Lobo";
            age = 5;
        }
        Persona(std::string dname, int dage){
            name = dname;
            age = dage;
        }    
};
```
###  3.4. <a name='CopyConstructors'></a>Copy Constructors

###  3.5. <a name='ShallowcopyorDeepCopy'></a>Shallow copy or Deep Copy

###  3.6. <a name='CopyAssignmentOperator'></a>Copy Assignment Operator

###  3.7. <a name='Destructors'></a>Destructors
- it cleans up when an object is destroyed.