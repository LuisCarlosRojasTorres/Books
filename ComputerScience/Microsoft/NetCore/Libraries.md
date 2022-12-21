<!-- vscode-markdown-toc -->
* 1. [Introduction](#Introduction)
* 2. [Referencing a Project](#ReferencingaProject)
* 3. [Referencing a `dll`](#Referencingadll)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Introduction'></a>Introduction
- A `class library` defines types and methods that are called by an application.
- If the library targets .NET Standard 2.0, it can be called by any .NET implementation (including .NET Framework) that supports .NET Standard 2.0. If the library targets .NET 6, it can be called by any application that targets .NET 6. This tutorial shows how to target .NET 6.
- It can be distributed as a NuGet package or as a component bundled with the application that uses it.
- It can be done in two ways:
  - Referencing a project
  - Referencing a `dll`

## Creating a Class Library
1. In a `black solution`, create a `class library` project
   1. It can be created a custom namespace (e.g., `namespace ClassLibraryExample`) or not (i.e., the namespace is the project default) 
2. Implement a `class` or `static class`
   1. `class`: it can have fields, methods etc...
3. Build the project.

An example is presented below:
``` cs 
namespace ClassLibraryExample
{
    public class Persona
    {
        string name;
        int age;
                
        public Persona(string name = "John Doe", int age = 69)
        {
            this.name = name;
            this.age = age;
        }

        public void PrintInfo()
        {
            Console.WriteLine($"PrintInfo: \n- Name: {this.name} \n- Age: {this.age}!");
        }
    }
}
```

##  2. <a name='ReferencingaProject'></a>Referencing a Project

1. Create a new project
2. In the `solution project`, right-click on `Dependencies`
3. Select the `class library` project, and ok.
4. Now you can use the library!

An example is presented below!

``` cs 
using ClassLibraryExample;


Persona dummy = new Persona();
Persona rufo = new Persona("Rufo",11);

dummy.PrintInfo();
rufo.PrintInfo();
```

##  3. <a name='Referencingadll'></a>Referencing a `dll`