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
- Nothing to add
##  3. <a name='V084-ConstructorsandDeconstructors'></a>V084 - Constructors and Deconstructors

##  4. <a name='V085-Introtoinheritance'></a>V085 - Intro to inheritance

##  5. <a name='V086-Inheritance'></a>V086 - Inheritance

##  6. <a name='V087-Interfaces'></a>V087 - Interfaces

##  7. <a name='V088-Overriding'></a>V088 - Overriding

##  8. <a name='V089-QObjectClass'></a>V089 - QObject Class

