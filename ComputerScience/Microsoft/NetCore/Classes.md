<!-- vscode-markdown-toc -->
* 1. [Defining and using a class](#Definingandusingaclass)
* 2. [Controlling accessability](#Controllingaccessability)
	* 2.1. [Working with constructor](#Workingwithconstructor)
	* 2.2. [Overlading constructor](#Overladingconstructor)
	* 2.3. [Partial classes](#Partialclasses)
	* 2.4. [Deconstruction an object](#Deconstructionanobject)
* 3. [Understanding static methods and data](#Understandingstaticmethodsanddata)
	* 3.1. [Creating a shared field](#Creatingasharedfield)
	* 3.2. [Creating a static field by using the `const` keyword](#Creatingastaticfieldbyusingtheconstkeyword)
	* 3.3. [Understanding static classes](#Understandingstaticclasses)
	* 3.4. [Static `using` classes](#Staticusingclasses)
* 4. [Anonymous classes](#Anonymousclasses)

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
- It uses the `new` keyword because:
  - `C#` does not provide the syntax for assigning literal class values to variables.
  - allocates and manages memory for variables of class types by the runtime.

``` cs
Circle c;			//create
c = new Circle();   //initialize
```

##  2. <a name='Controllingaccessability'></a>Controlling accessability
- You can modify the definition of a field or method with the `public` and `private` keywords.
- Similar to `C++`. However, must repeat the keyword for every field and method declaration.

``` cs
class Circle
{
	private int radius;

	public double Area()
	{
		return Math.PI*redius*radius;

	}
}
```

###  2.1. <a name='Workingwithconstructor'></a>Working with constructor

- `constructor` is a special method that runs automatically when you create an instance of a class.
  - It has the same name as the class.
  - It can take parameters, but it cannot return a value (not even `void`). 
- If you dont write one explicitly, the compiler automatically generates a `default` constructor for you.
 
 ``` cs
class Circle
{
	private int radius;

	public Circle()
	{
		radius = 0;
	}
	public double Area()
	{
		return Math.PI*redius*radius;

	}
}
```

###  2.2. <a name='Overladingconstructor'></a>Overlading constructor
Constructors can be overloaded. 

``` cs
class Circle
{
	private int radius;

	public Circle() // constructor
	{
		radius = 0;
	}
	public Circle(int initialRadius) //overload constructor
	{
		radius = initialRadius;
	}
	public double Area()
	{
		return Math.PI*redius*radius;

	}
}
```

###  2.3. <a name='Partialclasses'></a>Partial classes
- You can split the source code for a class into separate files.
  - you can organized the definition of a large class into smaller pieces that are easier to manage.

``` cs
// File1.cs
partial class Circle
{
	public Circle() // constructor
	{
		radius = 0;
	}
	public Circle(int initialRadius) // overload constructor
	{
		radius = initialRadius;
	}
}
//File2.cs
partial class Circle
{
	private int radius;
	public double Area()
	{
		return Math.PI*redius*radius;
	}
}
```

- Methods that belong to a class and that operate on the data belonging to a particular instance of class are called `instance methods`.
- NOTE:
  - `private` works at the class level and not at the object level.
  - Two objects that are instances of the same class can access each other's private date, 
    - but objects that are instances of another class cannot.
  - Prefixing a variable with `this` means *the field in this object*.

###  2.4. <a name='Deconstructionanobject'></a>Deconstruction an object
- A `deconstructor` enables you to examine an object and extract the values of its fields.
	- It is always named `Deconstruct`
	- It must be a `void` method
	- It must take one or more parameters.
	- The parameters are marked with the `out` modifier.
    	- If you assign values to them, these values will be passed back to the caller.
  	- The code in the body of the method assigns the values to be returned to the parameters.

``` cs
class Point
{
	private int x,y;
	...
	public void Deconstruct(out int x, out int y)
	{
		x = this.x;
		y = this.y;
	}
}
```
##  3. <a name='Understandingstaticmethodsanddata'></a>Understanding static methods and data
- Not all methods naturally belong to an instance of a class.
- If you declare a method or a field as `static`, you can call the method or access the dield by using the name of the class.
- No instance is required.

``` cs
class Math
{
	public static double Sqrt(double d)
	{
		//...
	}
	//...
}
```

###  3.1. <a name='Creatingasharedfield'></a>Creating a shared field
- A single instance of a field that is shared among all objects created from a single class.
- In the example below:
  - The static field `NumCircles`  in the `Circle` class is incremented by the `Circle` constructor every time a new `Circle` object is created.
  - All `Circle` objects share the same instance of the `NumCircles` field.
  - DO NOT USE `this.` because `NumNircles` does not belong to a specific object. 

``` cs
class Circle
{
	private int radius;
	public static int NumOfCircles = 0;
	public Circle()
	{
		radius = 0;
		NumOfCircles++; // DO NOT USE THIS.
		//...
	}
	//...
	public Circle(int initialRadius)
	{
		radius = initialRadius;
		NumOfCircles++; // DO NOT USE THIS.
		//...
	}
}
```

###  3.2. <a name='Creatingastaticfieldbyusingtheconstkeyword'></a>Creating a static field by using the `const` keyword
- Prefixing the class field with the `const` keyword, you can declare that a field is `static` **but that its value can never change**.

``` cs
class Math
{
	//...
	public const double PI = 3.141592;
	//...
}
```

###  3.3. <a name='Understandingstaticclasses'></a>Understanding static classes
- A `static` class 
  - can contain only static members.
  -  holds utility methods and fields.
  -  cannot contain any instance data or methods.
  -  
###  3.4. <a name='Staticusingclasses'></a>Static `using` classes
- When you use a `static` method, you must specify the class to which belongs.
  - `static using` statements enable you to bring a class into scope and omit the class name when accessing static members.

``` cs
using static System.Console;

WriteLine("Hola Rufo");
WriteLine("Withouth the using static, it will be Console.WriteLine(Hola Rufo)");
```

##  4. <a name='Anonymousclasses'></a>Anonymous classes