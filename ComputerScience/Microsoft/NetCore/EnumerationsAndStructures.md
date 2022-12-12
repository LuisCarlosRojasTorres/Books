<!-- vscode-markdown-toc -->
* 1. [Enumerations](#Enumerations)
	* 1.1. [Declaring](#Declaring)
	* 1.2. [Using](#Using)
	* 1.3. [Literal values](#Literalvalues)
	* 1.4. [Underlying type](#Underlyingtype)
* 2. [Structures](#Structures)
	* 2.1. [Declaring](#Declaring-1)
	* 2.2. [Differences between `structures` and `classes`](#Differencesbetweenstructuresandclasses)
	* 2.3. [Declaring `structure` variables](#Declaringstructurevariables)
	* 2.4. [Understanding structure initialization](#Understandingstructureinitialization)
	* 2.5. [Copying structure variables](#Copyingstructurevariables)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

 - This chapter has the purpose to show: **HOW TO CREATE YOUR OWN VALUE TYPES**
- `C#` supports two kinds of value types: `enumerations` and `structures`

##  1. <a name='Enumerations'></a>Enumerations

###  1.1. <a name='Declaring'></a>Declaring
- Its values are limited to a set of symbolic names.
- It is declared outside the class

###  1.2. <a name='Using'></a>Using
``` cs
// enum declaration
enum EnumVariable{ tag1, tag2, tag3, tag4};
class Example
{
    // field example
    private EnumVariable enumField;
    // method parameter example
    public void Method(EnumVariable enumParameter)
    {
        // local variable example
        EnumVariable enumLocal;
    }
}
```

- Before you can read the value of an `enumeration` variable, it must be assigned a value.

``` cs
EnumVariable enumVariable = EnumVariable.tag1; // Values are scoped
Console.WriteLine(enumVariable); // This prints "tag1"
```

- Its values are scoped by its `enumeration` type, i.e.; `EnumVariable.tag1`
- It can be explicitly converted to `string` calling the `.ToString()` method.

###  1.3. <a name='Literalvalues'></a>Literal values
- It associates an integer value with each element of the enumeration.
- It starts at `0` for the first element and goes up in steps of `1`.

``` cs
enum EnumVariable{ tag1, tag2, tag3, tag4};
// its similar to
enum EnumVariable{ tag1 = 0, tag2, tag3, tag4};
```

- To print the literal value you shall to `cast` explicitly to `int`. For example:

``` cs
EnumVariable enumVariable = EnumVariable.tag1; // Values are scoped
Console.WriteLine((int)enumVariable); // This prints "0"
```

- It can be set any constant integer for the initial value in an `enumeration`

``` cs
enum EnumVariable{ tag1 = 55, tag2, tag3, tag4};
// its similar to
enum EnumVariable{ tag1 = 55, tag2 = 56, tag3 = 57, tag4 = 58};
```

- It is possible to give more than one enumeration literal the same underlying value.

``` cs
enum EnumVariable{ tag1, tag2 = tag5, tag3, tag4};
```
###  1.4. <a name='Underlyingtype'></a>Underlying type
- From the previous subsection, the `enumerations literals` use `integer` values. But,
- It is possibleto base an `enumeration` on any of the eight `integer` types:
  - i.e., `byte`, `sbyte`, `short`, `ushort`, `int`, `uint`, `long` and `ulong`.
  - This is done to **save memory**. e.g.; `byte` occupies less memory than `int` but only have a maximum of `256` literals (starting from `0`).
- An example is presented below:


``` cs
enum EnumVariable : byte{ tag1, tag2 = tag5, tag3, tag4};
```

##  2. <a name='Structures'></a>Structures
- `classes` are reference types, i.e; created on hte `HEAP`
  - If the `class` contains so little data, managing the `HEAP` is an **OVERHEAD**
  - In this case is better to define the type as a `structure`. 
- An `structure` is a `value` type.
  - So, it is created on the `STACK`
  - It has its own `fields`, `methods`, `constructors`

NOTE:
- The primitive numeric types `int`, `long` and `float` are aliases for the structures `System.Int32`, `System.Int64` and `System.Single`.


###  2.1. <a name='Declaring-1'></a>Declaring
- Its syntax is similar to `class` 
``` cs
struct StructureExample
{
	private int var1, var2;
	// ...
	public StructureExample( int var1, int var2)
	{
		this.var1 = var1;
		this.var2 = var2;
	}
}
```
- When you copy a `value` type variable: you get two copies of the value.
  - Use `structures`:
    - To implements simple concepts whose main feature is their value rather than the functionality.


- When you copy a `reference` type variable: you get two references to the same object.
  - Use `classes` for more complex data that is too big to copy efficiently.


###  2.2. <a name='Differencesbetweenstructuresandclasses'></a>Differences between `structures` and `classes`
- You cannnot declare a default constructor.
  - The compiler implemments it by itself, so you do not need to. Otherwise, `compile-error`
- If a non-defult constructor is provided. It shall initialize all the fields of the `structure`. Otherwise, `compile-error`
- You cannot initialize instance fields in their declaration. Otherwise, `compile-error`


###  2.3. <a name='Declaringstructurevariables'></a>Declaring `structure` variables
- Once declared an `struct` can be used as any value variable type.

``` cs
struct StructureExample
{
	private int var1, var2;
	// ...
	public StructureExample( int var1, int var2)
	{
		this.var1 = var1;
		this.var2 = var2;
	}
	// ...
}

class Example
{
	private StructureExample structureExample; // structure field

	public void Method(StructureExample structureParameter) // structure as a parameter
	{
		StructureExample structureLocal; // structure as a Local variable
	}
}
```
###  2.4. <a name='Understandingstructureinitialization'></a>Understanding structure initialization
- Default constructor, sets all the values to `0`;

``` cs
StructureExample structureExample = new StructureExample(); // default constructor
```
- Structure created, its fields are unitialized!

``` cs
StructureExample structureExample; // fields are unitialized
```
- Remember: **Custom constructors shall initialize all the fields!!**


###  2.5. <a name='Copyingstructurevariables'></a>Copying structure variables
