<!-- vscode-markdown-toc -->
* 1. [V082 - What are classes](#V082-Whatareclasses)
* 2. [V083 - Intro to classes](#V083-Introtoclasses)
* 3. [V084 - Constructors and Deconstructors](#V084-ConstructorsandDeconstructors)
* 4. [V085 - Intro to inheritance](#V085-Introtoinheritance)
* 5. [V086 - Inheritance](#V086-Inheritance)
* 6. [V087 - Interfaces](#V087-Interfaces)
* 7. [V088 - Overriding](#V088-Overriding)
* 8. [V089 - QObject Class](#V089-QObjectClass)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

** How to add classes in QT6??**
- For an empty new project the `CMakeList.txt` shows the following:

``` cmake
add_executable(dummyProject
  main.cpp  
)
```
- If a `DummyClass` is added header and source file shall be added in the `CMakeList.txt` .
``` cmake
add_executable(dummyProject
  main.cpp  
  DummyClass.h
  DummyClass.cpp
)
```
- Then Build the Project `Ctrl+B` and thats all.

##  1. <a name='V082-Whatareclasses'></a>V082 - What are classes
- Nothing to add
##  2. <a name='V083-Introtoclasses'></a>V083 - Intro to classes
- When writing a header e.g. `dummy.h`:
  - You can add code to any function declaration with: `Right click / Refactor / Add definition in <dummy>.cpp`
  - Press `F4` to change from header to source view and viceversa.

- It is recommended to use classes which inherits from `QObject`. So for the `Animal` class the default Qt header is:

``` cpp 
#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>

class Animal : public QObject
{    
    Q_OBJECT
public:
    // This constructor sets that if the PARENT obj is destroyed the CHILD object is also destroyed.
    explicit Animal(QObject *parent = nullptr);

signals:

};

#endif // ANIMAL_H
```

- The default constructor for the previous class is:

``` cpp
#include "Animal.h"

Animal::Animal(QObject *parent)
    : QObject{parent}
{

}
```

##  3. <a name='V084-ConstructorsandDeconstructors'></a>V084 - Constructors and Deconstructors
- Nothing to add (same as Cpp)

##  4. <a name='V085-Introtoinheritance'></a>V085 - Intro to inheritance
- Nothing to add (same as Cpp)

##  5. <a name='V086-Inheritance'></a>V086 - Inheritance
- Nothing to add (same as Cpp)

##  6. <a name='V087-Interfaces'></a>V087 - Interfaces
- A contract between objects. (same concept) as `Interfaces` in `C#` 
  - It contains only a header `.h` with `virtual functions`.
    - Virtual functions has the form:
      - `virtual <DataType> dummyName(parameters) = 0;`


##  7. <a name='V088-Overriding'></a>V088 - Overriding
- Nothing to add (same as Cpp)

##  8. <a name='V089-QObjectClass'></a>V089 - QObject Class
- When a class inherits from `QObject` it has all the functionalities describes in the Qt Documentation for `QObject`.
