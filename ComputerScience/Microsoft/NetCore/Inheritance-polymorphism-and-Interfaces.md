<!-- vscode-markdown-toc -->
* 1. [Inheritance](#Inheritance)
	* 1.1. [Using inheritance](#Usinginheritance)
		* 1.1.1. [The `System.Object` class revisited](#TheSystem.Objectclassrevisited)
		* 1.1.2. [Calling `base-class` constructors](#Callingbase-classconstructors)
		* 1.1.3. [Assigning classes](#Assigningclasses)
		* 1.1.4. [Declaring new methods](#Declaringnewmethods)
		* 1.1.5. [Declaring `virtual` methods](#Declaringvirtualmethods)
		* 1.1.6. [Declaring `override` methods](#Declaringoverridemethods)
		* 1.1.7. [Understanding `protected` access](#Understandingprotectedaccess)
	* 1.2. [Creating extension methods](#Creatingextensionmethods)
* 2. [Interfaces](#Interfaces)
	* 2.1. [Understanding `interfaces`](#Understandinginterfaces)
		* 2.1.1. [Defining](#Defining)
		* 2.1.2. [Implementing](#Implementing)
		* 2.1.3. [Referencing a `class` through its `interface`](#Referencingaclassthroughitsinterface)
		* 2.1.4. [Working with multiple `interfaces`](#Workingwithmultipleinterfaces)
		* 2.1.5. [`interfaces` restrictions](#interfacesrestrictions)
* 3. [`abstract` classes](#abstractclasses)
* 4. [`sealed` classes](#sealedclasses)

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
- If a `base-class` and a `derived-class` happen to declare two methods that have the same signature, you will receive a warning when you compile the application.
  - Method signature: This refers to the name of the method and the number and types of its parameters, **but not its return type**
    - So, if two methods have the same name and that take the same list of parameters, they have the same **signature**
- A method in the `derived-class` hides a method in the `base-class` that has the same signature.
  - It also generates a `warning` telling that the method of `base-class` is hidden.

``` cs
class BaseClass
{
    public returnType1 SomeMethod(parameters)
	{
		//...
	}
}
// Then 
class DerivedClass : BaseClass
{
    public returnType2 SomeMethod(parameters)
	{
		// This method has the same signature as its base class, 
		// the COMPILER WILL GENERATE A WARNING FOR THIS
	}
}
```
- To eliminate this `warning` use the `new` keyword. This is obviously not recommended!
``` cs
class BaseClass
{
    public returnType1 SomeMethod(parameters)
	{
		//...
	}
}
// Then 
class DerivedClass : BaseClass
{
    new public returnType2 SomeMethod(parameters)
	{
		// This method has the same signature as its base class, 
		// the COMPILER WILL GENERATE A WARNING FOR THIS
	}
}
```

####  1.1.5. <a name='Declaringvirtualmethods'></a>Declaring `virtual` methods
- A method that is intended to be overridden is called a `virtual` method.
  - `override`:
    - It is a mechanism for providing different implementations of the same method, but in a class-specific manner
    - It is a useful programming concept
  - `hide`:
    - It replaces one method with another
    - It is often an error.
- The use of `virtual` keyword is presented below:

``` cs
public/private virtual returnType NameOfMethod(parameters)
{
	// virtual method in base-class
}
```

####  1.1.6. <a name='Declaringoverridemethods'></a>Declaring `override` methods
- To declare another implementation of the `virtual base-class` method, the `override` method shall be used.
- To call the `base-class` version of the method, the `base.NameOfMethod` shall be called.
- This is presented in the following code:


``` cs
public/private override returnType NameOfMethod(parameters)
{
	// override method in derived-class
	// to call the base-class version of the method
	// base.Name
	base.NameOfMethod(parameters);
}
```

Rules:
- A `virtual` method cannot be `private`.
- A `override` method cannot be `private`. Moreover a `class` cannot change the protection level of a method that inherits
  - `protected` level can be used.
- Both methods shall have the same `signature` (i.e., same name, number and type of parameters) 
  - They also shall `return` the same type
- Only `virtual` methods can be `override`. Otherwise, you get a `compile-error`
- An `override` method is implicitly `virtual` and can itself be overriden in a further `derived` class.
- If the `override` keyword is not used, the method will be `hide` instead of `override`

####  1.1.7. <a name='Understandingprotectedaccess'></a>Understanding `protected` access
- It is useful that only the `derive-class` has access to some `base-class` methods. This is achieved using the `protected` access.
- It works like this:
  - If a class `A` is derived from another class `B`:
    - It can access the `protected` class members of class `B`
       So, for class `A` a `protected` member of class `B` is effectively `public`
  - If a class `A` is not derived from another class `B`:
    - It cannot access the `protected` class members of class `B`
      - So, for class `A` a `protected` member of class `B` is effectively `private`
- It is possible to access a `protected base-class` member, not only in a `derived-class` but also in classes derived from the `derived-class`.


###  1.2. <a name='Creatingextensionmethods'></a>Creating extension methods
- It quickly extend a type whithout affecting existing code.
- To extent a `class` or `structure` method with additional `static` methods.
  1. Create a `static class`
  2. Create a `static` method.
      1. Its parameter shall have `this + NameOfClass + nameOfVariable`
  3. Implement the method.
  4. To use it, use the `.` operator plus the `ExtentionMethod`
``` cs
// Class1.cs
internal class Class1
{
    //...
}
// Class2.cs
internal static class Class2 //1
{
    public static void ExtentionMethod(this Class1 t) { // 2 and 2.1
        // 3
    }
}
// Program.cs
Class1 class1 = new Class1();
class1.ExtentionMethod(); // 4
```

##  2. <a name='Interfaces'></a>Interfaces 
- It does not contain any code or data.
- It let you to separate the names and signatures of the methods of a class from implementation.
###  2.1. <a name='Understandinginterfaces'></a>Understanding `interfaces`

####  2.1.1. <a name='Defining'></a>Defining
- An `interface` is syntactically similar to defining a `class`
- It uses the `interface` keyword
- It never specifies access modifiers i.e.; no `private` , `public` or `protected`
- As a suggestion its name should begin with `I` letter e.g, `INameOfInterface`
- Again, its methods have no implementation
  - It cannot contain any data/fields.
- An example is presented below:

``` cs
interface INameOfInterface
{
	returnType NameOfMethod(parameters);
}
```

####  2.1.2. <a name='Implementing'></a>Implementing
- `class` or `struct` which inherits from an `interface` shall implements all the methods declared in the `interface`
- The syntaxis is similar to `class inheritance`

``` cs
// INameOfInterface.cs
interface INameOfInterface
{
	returnType NameOfMethod(parameters);
}
// NameOfClass.cs
class NameOfClass : INameOfInterface
{
	returnType NameOfMethod(parameters)
	{
		// implementation of method
	}
}
```

- **Rules:**
  - Method names and return types match exactly.
    - Any `parameter` shall match exactly
  - All methods of the interface should not have an access qualifier.
- If a `class` inherits from another `class` and an `interface` at same time. The `base-class` shall be specified first then the `interface`.
- This is presented below:

``` cs
interface NameOfInterface
{
	//...
}
class NameOfBaseClass
{
	//...
}
class NameOfDerivedClass : NameOfBaseClass, NameOfInterface
{
	//...
}
```

- `interface extention`: An `interface A` which inherits from an `interface B`. 
  - A class which inherits from interface A. It shall implement all the metods in `interface A` and `interface B`.
  
####  2.1.3. <a name='Referencingaclassthroughitsinterface'></a>Referencing a `class` through its `interface`
- An object can be referenced to a variable defined as an `interface` that the object's `class` implements.
- This let you to defined methods that can take different types as parameters, as long as the types implements a specified `interfaces`.

``` cs
void Method(IExampleOfInterface exampleOfInterface);
```

- It is possible to verify if an object is an instance of a `class` that implements a specific `interface` by using the `is` operator.
	- However, if an `object` is referenced through an `interface`, only the methods that are visible through the `interface` can be called.


``` cs
if(object1 is IExampleOfInterface)
{
	IExampleOfInterface exampleOfInterface = object1;
}
```

####  2.1.4. <a name='Workingwithmultipleinterfaces'></a>Working with multiple `interfaces`
- A class can implement many `interfaces`
  - There is no a specific ordeed to declare the `interfaces` 
    - However, if it is also implementing a `class`, the `className` shall go first.

``` cs
interface IInterface01
{

}
interface IInterface02
{

}
class BaseClass01
{

}

class ExampleOfClass : BaseClass01, IInterface01, IIInterface02
{
	//Implementation goes here
}

```
**Explicit implementation of Interfaces**
- When an class inherits from more than `interfaces`, it is probable that two or more `interfaces` could have a method with same name.
  - To explicitly implement each of the methods, the name of the `interface` shall have to be included.
    - This is achieved with the `.` operator e.g., `NameOfInterface.NameOfMethod`
- An example of this is presented below:


``` cs
interface IInterface01
{
	void Method(parameters){}
}
interface IInterface02
{
	void Method(parameters){}
}

class ExampleOfClass : IInterface01, IIInterface02
{
	//Explicit implementation
	void IInterface01.Method(parameters) // 
	{
		//...
	}
	//Explicit implementation
	void IInterface02.Method(parameters){
		//...
	}
}
```

Notes:
- It is recommended to explicitly implement interfaces when possible.
- TO ACCESS to these methods, the object has to be referenced to an appropiate `interface`.
  - An example of this is presented below:

``` cs
//Program.vs
ExampleOfClass dummy = new ExampleOfClass();

Interface1 interface1 = dummy as IInterface1; 
Interface2 interface2 = dummy as IInterface2;

interface1.Method(); 
interface2.Method();
```
####  2.1.5. <a name='interfacesrestrictions'></a>`interfaces` restrictions
- It is impossible to define any `field` in an `interface`, not even `static fields`.
  - `field`: an implementation detail of a class or structure.
- It is impossible to define a `constructor` in an `interface`
- It is impossible to define a `destructor` in an `interface`
- It is impossible to specify `access modifiers` for any methods.
  - All methods in an `interface` are implicitly `public`
- It is impossible to nest any type (e.g., `enum`, `struct`, `classes` or `interfaces`) inside an interface
- An interface cannot inherit from a `structure` or a `class`


##  3. <a name='abstractclasses'></a>`abstract` classes
- It can contain code and data.
  - Avoid `code repetition` between classes that implement `interfaces`
- It cannot be instantiated
- It uses the `abstract` keyword
- It can contain `abstract methods`
  - They cannot be `private`
  - These are similar to `virtual methods` but do not have implementation.
  - A `derived-class` shall `override` these methods.
- An example is presented below:

``` cs
abstract class ExampleOfClass
{
	public abstract void Method(parameters); //No implementation	
}
```
##  4. <a name='sealedclasses'></a>`sealed` classes

- To prevent a `class` from being used as a `base-class`
  - If any class tries to use a `sealed class ` as a `bass-class`, it will generate a `compile-error`
- The `sealed` keyword is used as follows:
``` cs
sealed class ExampleOfClass : IInterface1, IInterface2
{

}
```

### `sealed` methods
- It declares an individual method (in an `unsealed` class) as `sealed`.
- Only methods declared with the `override` keyword can be `sealed`.
- So, the keywords used in this section can be understood as follows:
  - `interface`: introduces the name of a method
  - `virtual`: first implementation of the method
  - `override`: another implementation of the method
  - `sealed`: last implementation of the method
