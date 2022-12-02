<!-- vscode-markdown-toc -->
* 1. [Defining and using a class](#Definingandusingaclass)
* 2. [Controlling accessability](#Controllingaccessability)
* 3. [Understanding static methods and data](#Understandingstaticmethodsanddata)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Definingandusingaclass'></a>Defining and using a class
- Classes provide a convenient mechanism for modeling the entities manipulated by applications.
- `Encapsulation` is sometimes referred to as `information hiding`
  - To combine `date` and `methods` within a class. i.e, **support classification**
  - To control the accessibility of the methods and data. i.e., **control the class**

``` cs
class Circle
{
	int radius;

	double Area()
	{
		return Math.PI*redius*radius;

	}
}
```

- Variables in a `class` are called `fields`.
- First create a variable specifying `Circle` as its type.
  - Initialize the variable with some valid data.
- It uses the `new` keyword:
  - how memory for variables of class types is allocated and managed by the runtime.
``` cs
Circle c;			//create
c = new Circle();   //initialize
```




##  2. <a name='Controllingaccessability'></a>Controlling accessability

##  3. <a name='Understandingstaticmethodsanddata'></a>Understanding static methods and data