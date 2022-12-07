<!-- vscode-markdown-toc -->
* 1. [Copying value type variables and classes](#Copyingvaluetypevariablesandclasses)
	* 1.1. [Copying reference tyoes and data privacy](#Copyingreferencetyoesanddataprivacy)
* 2. [Understanding `null` values and nullable types](#Understandingnullvaluesandnullabletypes)
	* 2.1. [The `null`-conditional operator](#Thenull-conditionaloperator)
	* 2.2. [Using nullable types](#Usingnullabletypes)
* 3. [Using `ref` and `out` parameters](#Usingrefandoutparameters)
	* 3.1. [Creating `ref` parameters](#Creatingrefparameters)
	* 3.2. [Creating `out` parameters](#Creatingoutparameters)
* 4. [`Stack` and `Heap`](#StackandHeap)
* 5. [The `System.Object` class](#TheSystem.Objectclass)
* 6. [Boxing](#Boxing)
* 7. [Unboxing](#Unboxing)
* 8. [Casting data safely](#Castingdatasafely)
	* 8.1. [`is` operator](#isoperator)
	* 8.2. [`as` operator](#asoperator)
	* 8.3. [`switch` statement revisited](#switchstatementrevisited)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Copyingvaluetypevariablesandclasses'></a>Copying value type variables and classes

###  1.1. <a name='Copyingreferencetyoesanddataprivacy'></a>Copying reference tyoes and data privacy 

##  2. <a name='Understandingnullvaluesandnullabletypes'></a>Understanding `null` values and nullable types
- Look at the following example:
  - A Circle `c1` is created
  - Then `c2` is created.
  - But `c1` is assigned to `c2`
  - Now, no object references to `c1`!
``` cs
Circle c1 = new Circle(30);
Circle c2 = new Circle(45);

c2 = c1; 
```
- When nothing refers an object the runtime can reclaim the memory by performing an operation known as `garbage collection`.
- `garbage collection` is potencially time-consuming operation.
  - Do not create objects that are never used because doing so is a waste of time and resources.


###  2.1. <a name='Thenull-conditionaloperator'></a>The `null`-conditional operator
- It is applied appending a `?` in the name of the object and before the method call. e.g. `obj?.Method()`
  - It ignores the statement if the variable is null.

``` cs
// Object instantiated as null
Circle c = null;
// Null-conditional operator
// This will print: "The area of circle c is " because c is null
Console.WriteLine($"The area of circle c is {c?.Area}")
```

###  2.2. <a name='Usingnullabletypes'></a>Using nullable types
- The `null` value is useful for reference type. `null` is itself a reference
- To apply `null` to value types you need to assign it into `nullable`
  - To do this, append a `?` in the value type, as the example.
  - `nullable` types can be evaluated in conditionals as `if( i == null)`
- You cannot use a `nullable` variable as a parameter to a method.


``` cs
int? i = null; // nullable type

if(i != null)
{
	//...
}
```

- `nullable` types has 2 properties:
  -  `.HasValue` : a boolean that returns if a value was assigned.
  -  `.Value` : (read only) returns its value assigned.

``` cs
int? i = null;

if(!i.HasValue)
{
	Console.WriteLine("No value in variable. 28 is set by default");
	i = 28;
}
else
{
	Console.WriteLine($"value: {i.Value}");
}
```


##  3. <a name='Usingrefandoutparameters'></a>Using `ref` and `out` parameters

###  3.1. <a name='Creatingrefparameters'></a>Creating `ref` parameters
- It passes a reference to tha actual argument rather than a copy of the argument.
- Using `ref` anything, anything you do to the parameter you also do to the original argument because the parameter and the argument both reference the same data.


``` cs
int i = 3;

void changeByReference(ref int i)
{
    Console.WriteLine($" - i: {i}");
    i = 99;
    Console.WriteLine($" - i changed: {i}");
}

changeByReference(ref i);
Console.WriteLine($" - i out of function: {i}"); // it shall print 99
```
- The output is presented below:

``` console
 - i: 3
 - i changed: 99
 - i out of function: 99
```

###  3.2. <a name='Creatingoutparameters'></a>Creating `out` parameters
- When you pass an `out` parameter to a method, the method MUST assign a value to it before it finishes or returns.

``` cs
int i; //uninitilized variable

void changeByOut(out int i)
{
    i = 99;
    Console.WriteLine($" - i changed: {i}");
}

changeByOut(out i);
Console.WriteLine($" - i out of function: {i}");
```
- The output is presented below:
  
``` console
 - i changed: 99
 - i out of function: 99
```

##  4. <a name='StackandHeap'></a>`Stack` and `Heap`

##  5. <a name='TheSystem.Objectclass'></a>The `System.Object` class

##  6. <a name='Boxing'></a>Boxing

##  7. <a name='Unboxing'></a>Unboxing

##  8. <a name='Castingdatasafely'></a>Casting data safely

###  8.1. <a name='isoperator'></a>`is` operator

###  8.2. <a name='asoperator'></a>`as` operator

###  8.3. <a name='switchstatementrevisited'></a>`switch` statement revisited