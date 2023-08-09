<!-- vscode-markdown-toc -->
* 1. [V40 - Hello world](#V40-Helloworld)
* 2. [V41 - Examining the build process](#V41-Examiningthebuildprocess)
* 3. [V42 - Comments](#V42-Comments)
* 4. [V43 - Coding standards, styles and conventions](#V43-Codingstandardsstylesandconventions)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->


##  1. <a name='V40-Helloworld'></a>V40 - Hello world
- Create a Qt Console project.
- To run on terminal go to `Projects/Run/Run in terminal` 
- To build `Ctrl + b`
- To run `Ctrl + r`
- The `CMakeLists.txt` file tells the CMAKE how to build the project:

``` cmake
cmake_minimum_required(VERSION 3.14)

project(V040 LANGUAGES CXX) # <nameOfProject> <LanguageUsed>

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11) # Can be 11 14 17...
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core) # Importing Cmake modules
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# This adds the executable name
add_executable(V040
  main.cpp
)
target_link_libraries(V040 Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS V040
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
```
- The `main.cpp` file is :

``` cpp 
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
```
So, we can add a `QDebug()` this code:

``` cpp
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Sou Lobo, Loboso!"; //Prints text in console
    return a.exec();
}
```

##  2. <a name='V41-Examiningthebuildprocess'></a>V41 - Examining the build process
- When compiling a project the following messages can be seen in tab `4 Compile Output`:

```
21:22:30: Running steps for project V040...
# The following starts the build process...
21:22:30: Starting: "/home/redtower02/Qt/Tools/CMake/bin/cmake" --build /home/redtower02/Documents/Repositories/qtFiles/Qt6Beginners/S03/build-V040-Desktop_Qt_6_5_1_GCC_64bit-Debug --target all
# THe following will generate the autogen folder with moc_predefs.h
[1/4 55.6/sec] Automatic MOC and UIC for target V040
[2/3 1.9/sec] Building CXX object CMakeFiles/V040.dir/main.cpp.o
[3/3 2.5/sec] Linking CXX executable V040
21:22:31: The process "/home/redtower02/Qt/Tools/CMake/bin/cmake" exited normally.
21:22:31: Elapsed time: 00:01.
```
##  3. <a name='V42-Comments'></a>V42 - Comments

##  4. <a name='V43-Codingstandardsstylesandconventions'></a>V43 - Coding standards, styles and conventions