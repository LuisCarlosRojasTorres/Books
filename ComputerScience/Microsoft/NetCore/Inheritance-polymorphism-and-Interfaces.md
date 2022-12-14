<!-- vscode-markdown-toc -->
* 1. [Inheritance](#Inheritance)
	* 1.1. [Using inheritance](#Usinginheritance)
		* 1.1.1. [The `System.Object` class revisited](#TheSystem.Objectclassrevisited)
		* 1.1.2. [Calling `base-class` constructors](#Callingbase-classconstructors)
		* 1.1.3. [Assigning classes](#Assigningclasses)
		* 1.1.4. [Declaring new methods](#Declaringnewmethods)
		* 1.1.5. [Declaring `virtual` methods](#Declaringvirtualmethods)
		* 1.1.6. [Declaring `override` methods](#Declaringoverridemethods)
		* 1.1.7. [Understanding extension methods](#Understandingextensionmethods)
	* 1.2. [Creating extension methods](#Creatingextensionmethods)
* 2. [Interfaces](#Interfaces)
	* 2.1. [Understanding `interfaces`](#Understandinginterfaces)
		* 2.1.1. [Defining](#Defining)
		* 2.1.2. [Implementing](#Implementing)
		* 2.1.3. [Referencing a `class` through its `interface`](#Referencingaclassthroughitsinterface)
		* 2.1.4. [Working with multiple `interfaces`](#Workingwithmultipleinterfaces)
		* 2.1.5. [`interfaces` restrictions](#interfacesrestrictions)
* 3. [`abstract` classes](#abstractclasses)
	* 3.1. [`abstract` methods](#abstractmethods)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->


##  1. <a name='Inheritance'></a>Inheritance
- It is a tool to avoid repetition when defining different classes that have some features in common and are quite clearly related to one another.


###  1.1. <a name='Usinginheritance'></a>Using inheritance
- A `class` is not allowd to derive from two or more classes.
- The `derived-class` inherits from the `base-class`.
  - The methods in the `base-class` become part of the `derived-class`.
- The `derived-class` can also be used as a `base-class` to create a `derived` subclass. 
  - unless the `sealed` keyword is used.
- In `C#` inheritance is always implicitly `public`.
- Al this is presented in the example below:


``` cs
class DerivedClass : BaseClass
{
    //...
}
// Then 
class DerivedSubClass : DerivedClass
{
    //...
}
```

####  1.1.1. <a name='TheSystem.Objectclassrevisited'></a>The `System.Object` class revisited
- All classes implicitly derive from `System.Object`
- So both implementations are similar as presented below:

``` cs
class ClassExample // inherits from System.Object implicitly
{
	// implementation
}

class ClassExample : System.Object
{
	// implementation
}
```
####  1.1.2. <a name='Callingbase-classconstructors'></a>Calling `base-class` constructors
- The `derived-class` automaticaaly contains all the methods and fields from the `base-class`.
- It is a good practice for the constructor of a class to call the constructor of its `base-class`.
  - This is achieved using the `base` keyword.
  - If the `base-class` constructor is not explicitly called in a `derived-class` constructor, the compiler inserts a call to the `default` `base-class` constructor i.e., `base()`. This is showed below:

``` cs
class DerivedClassExample
{
	public DerivedClassExample(derivedClassParameters)
	{
		// default base constructor implicitly called
	}		
}

class DerivedClassExample
{
	public DerivedClassExample(derivedClassParameters) : base() 
	{
		// default base constructor explicitly called
	}
}
```
- A general call for a `base-class` contructor is showed below:


``` cs
class BaseClassExample
{
	public BaseClass(baseClassParameters)
	{
		//...
	}
}

class DerivedClassExample
{
	public DerivedClassExample(derivedClassParameters)
		: base(baseClassParameters)
	{
		//...
	}
}
```

####  1.1.3. <a name='Assigningclasses'></a>Assigning classes

- It is possible to refer to an object from a variable of a different type as long as the type used in a `class` that is higher up the inheritance hierarchy.
	- i.e., A `derived-class` to a `base-class`.

``` cs
DerivedClassExample derivedClass = new DerivedClassExample();
BaseClassExample baseClass = derivedClass;
```

- It is also possible to do the inverse i.e, a `base-class` to a `derived-class`. 
  - This has an **important limitation**: It can only access to methods and fields that are defined by the `base-class`
  - Any additional method defined in the `derived-class` are not visible.


``` cs
BaseClassExample baseClass = new BaseClassExample();
DerivedClassExample derivedClass = baseClass;
```

- A `based-class` can be assigned to a `derived-class`. 
  - This can be helped using the `as` operator.
  - So this returns null in case that `base-class` is not a `DerivedClassExample` type.

``` cs
DerivedClassExample derivedClass = new DerivedClassExample();
BaseClassExample baseClass = derivedClass;

// ...
DerivedClassExample derivedClass2 = baseClass as DerivedClassExample;
```

####  1.1.4. <a name='Declaringnewmethods'></a>Declaring new methods

####  1.1.5. <a name='Declaringvirtualmethods'></a>Declaring `virtual` methods

####  1.1.6. <a name='Declaringoverridemethods'></a>Declaring `override` methods

####  1.1.7. <a name='Understandingextensionmethods'></a>Understanding extension methods

###  1.2. <a name='Creatingextensionmethods'></a>Creating extension methods

##  2. <a name='Interfaces'></a>Interfaces 

###  2.1. <a name='Understandinginterfaces'></a>Understanding `interfaces`

####  2.1.1. <a name='Defining'></a>Defining

####  2.1.2. <a name='Implementing'></a>Implementing

####  2.1.3. <a name='Referencingaclassthroughitsinterface'></a>Referencing a `class` through its `interface`

####  2.1.4. <a name='Workingwithmultipleinterfaces'></a>Working with multiple `interfaces`

####  2.1.5. <a name='interfacesrestrictions'></a>`interfaces` restrictions

##  3. <a name='abstractclasses'></a>`abstract` classes

###  3.1. <a name='abstractmethods'></a>`abstract` methods