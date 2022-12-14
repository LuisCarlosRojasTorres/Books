<!-- vscode-markdown-toc -->
* 1. [Copying value type variables and classes](#Copyingvaluetypevariablesandclasses)
	* 1.1. [Copying reference types and data privacy](#Copyingreferencetypesanddataprivacy)
* 2. [Understanding `null` values and nullable types](#Understandingnullvaluesandnullabletypes)
	* 2.1. [The `null`-conditional operator](#Thenull-conditionaloperator)
	* 2.2. [Using nullable types](#Usingnullabletypes)
* 3. [Using `ref` and `out` parameters](#Usingrefandoutparameters)
	* 3.1. [Creating `ref` parameters](#Creatingrefparameters)
	* 3.2. [Creating `out` parameters](#Creatingoutparameters)
* 4. [`Stack` and `Heap`](#StackandHeap)
	* 4.1. [Using the stack and the heap](#Usingthestackandtheheap)
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
- Value types:
  - This includes the `int`, `float`, `double` and `char`
  - Fixed size
  - Once declared, the compiler generates code that allocates a block of memory to hold a corresponding value. So:
    - `int i` the compiler allocates 4 bytes of memory (32 bits) to hold the integer value.
    - `i = 42` copies `42` to the address of `i`
- Reference type:
  - A `class` is a `reference type`, 
  - `reference types` hold references to blocks of memory
  - When declared, the compiler ***does not** generate code that allocates a block of memory to hold the `reference`
  - Instead, it assigns a small piede of memory that can potentially hold the address of (or a reference to) another block of memory containing the `object`
  - The memory for the actual `object` is allocated only when the `new` keyword is used to create the `object`
- The `string` type is actually a `class`
  - There is no standaed size  for a `string`
    - Allocating memory for a `string` dynamically when the program runs is far more efficient that doing so statically at compile time.

- Look at the following code:
	- The value held by `c` is the address of a `Circle` object in memory.
	- When  `refToC` is created, `c`   is assigned to it.
    	- So now, `refToC` have a copy of the same address as `c`
  	- In resume, there is only one `Circle` object, and both `refToC` and `c` now refer to it.


``` cs
Circle c = new Circle(42);
Circle refToC = c;
```

###  1.1. <a name='Copyingreferencetypesanddataprivacy'></a>Copying reference types and data privacy 
- From the previous section it was clear that:
  - `c2 = c1`, actually copy the reference of `c1` to the `c2`. So, both `c1` and `c2` refers to the same `object`.
- To actually copy the fields of the objects:
  - Create a new instance of the class
  - Then copy the data **field by field**
- Alternativately, a `Clone` method can be implemented in the `class`:
  - A `Clone` method returns another instance of the same class but populated with the same data.
    - This is easy if all the fields are values.
    - If some of its fields are reference types these fields shall have its own `Clone` method. This is called as `deep copy`
      - If the method only copy the references of the field it is called as `shallow copy`.

``` cs
class Circle
{
	private int radius;
	//...
	public Circle Clone()
	{
		Circle clone = new Circle();
		clone.radius = this.radius;
		return clone;
	}
}
```

NOTE: If you create two objects of the same class, they can each access the private data of the other within the code for that class.

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

- **Stack**:
  - All value types are created on the `stack`
  - It is organized like a **stack of boxes** piled on top of one another.
  - When a method is called:
    - Each parameter is placed in a box that is placed on top of the stack.
  - When a method finishes, the boxes are removed from the stack
- **Heap**:
  - All reference types (objects) are created on the `Heap`
    - HOWEVER, the reference to the object is stored in a loval variable on the `stack`
  - It is organized as a large group of boxes around a room.
  - WHen an object is created:
    - The runtime selects a box and allocates it to the object.
    - The runtime also keeps track of the number of references to each box. If no variable is reference it, the runtime marks the box as `not in use`.

###  4.1. <a name='Usingthestackandtheheap'></a>Using the stack and the heap
- The example below explains how the memory is managed:
  1. When the method is called, `parameter` is stored in the `STACK`
  2. Then a variable `c` is created in the `STACK` to store the address of a `Circle` reference type.
  3. The `Circle` reference type es created in the `HEAP` (using the `new` keyword) and then its address is stored (referenced)


``` cs
void Method(int parameter)
{
  Circle c;
  c = new Circle(parameter);
  //..
}
```

##  5. <a name='TheSystem.Objectclass'></a>The `System.Object` class
- All classes are specialized types of `System.Object`.
- It can be used to **create a variable that can refer to any reference type**.
- It has the `object` keyword as an alias for `System.Object`
- Look at the following example:

``` cs
// Created a variable in the STACK that stores an address to a reference type Circle
Circle c;    
// Created an object in the HEAP and assigned its reference to the variable c 
c = new Circle(42); 
// Created a variable in the STACK that stores an address to any reference type
object o;
// reference oc is assigned to c
c = o;
// now c and o which are in the STACK points to the same Circle object
```

##  6. <a name='Boxing'></a>Boxing
- Boxing: the automatic copying of an item from the `stack` to the `heap`.
- An `object` type variable can also refer to a `value` type.
- Look at the example below:

``` cs
int i = 48;
object o = i;
```

What happened here?
- The variable `i` is created on the `stack` and the value `48` is assigned.
- `o` stores the address of any reference type which by definition is on the `heap`
- BUT `i` is on the `stack`... SO:
  - The runtime allocates a piece of memory on the `heap`. 
  - Copies the value of `i` to this piece of memory.
  - Then assigned the address of this piece of memory to the `o` variable.


##  7. <a name='Unboxing'></a>Unboxing
- To obtain the value of the `boxed` copy, you must use what is known as a `cast`.
  - A `cast` checks if convert an item of one type to another is safe before actually making the copy.
  - You shall prefix the `object` variable with the name of the type in parentheses.

``` cs 
int i = 48;
object o = i; 
i = (int) o; //casting statement
```
- In the casting statement, 
  - If the `o` really does refer to a boxed `int` the cast succeds.
  - Otherwise, there is a type mismatch, causin the cast to fail. This throws an `InvalidCastException` exception at runtime.

NOTE: 
- `boxing` and  `unboxing` are expensive operations.
- 
##  8. <a name='Castingdatasafely'></a>Casting data safely
- When using a `cast`, you are saying that "in you opinion": *the date referenced by an object has a specific type* ant *that it is safe to reference the object by using that type*. So, the `C#` compiler will not check that this is the case, but the runtime will.
- `C#` provides the `is` and `as` operators that help to perform casting:

###  8.1. <a name='isoperator'></a>`is` operator
- It verifies that the type of an object is what you expect it to be.
- It takes two operands `ReferenceToAnObject is NameOfTheType`.
  - If the type of the `ReferenceToAnObject` has the `NameOfTheType` type, returns `true`
  - Otherwise, `false`
``` cs
Circle c = new Circle(48);
object obj = c;

if(obj is Circle)
{
  // This cast is safe because it is executed only if obj is a Circle 
  Circle temp = (Circle) obj;
}
```
- A shorter form of the preceding code is:
``` cs
Circle c = new Circle(48);
object obj = c;

if(obj is Circle temp)
{
  // code using temp
}
```
Where:
- The `is` operator creates a new reference variable (called `temp`), and assigns it a reference to the `Circle` object.


###  8.2. <a name='asoperator'></a>`as` operator
- The `as` operator, attempts to cast the object to the specified type.
  - If cast is successful, the cast result is returned 
  - Otherwise, returns `null`


``` cs
Circle c = new Circle(48);
object obj = c;

/*
It tries to perform: (Circle) o 
 If it is possible returns the address of the reference type
 Otherwise returns null
*/
Circle temp = o as Circle; 

if(temp != null)
{
  // Cast was successful
}
```
###  8.3. <a name='switchstatementrevisited'></a>`switch` statement revisited