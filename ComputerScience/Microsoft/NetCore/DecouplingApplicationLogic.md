<!-- vscode-markdown-toc -->
* 1. [Understanding Delegates](#UnderstandingDelegates)
	* 1.1. [The automated factory scenario](#Theautomatedfactoryscenario)
	* 1.2. [Implementing the factory control system without using delegates](#Implementingthefactorycontrolsystemwithoutusingdelegates)
	* 1.3. [Implementing the factory by using a delegate](#Implementingthefactorybyusingadelegate)
	* 1.4. [Declaring and using a delegate](#Declaringandusingadelegate)
* 2. [Lambda expressions and Delegates](#LambdaexpressionsandDelegates)
	* 2.1. [Creating a method adapter](#Creatingamethodadapter)
* 3. [Enabling notifications by using Events](#EnablingnotificationsbyusingEvents)
	* 3.1. [Declaring an event](#Declaringanevent)
	* 3.2. [Subscribing to an event](#Subscribingtoanevent)
	* 3.3. [Unsuscribing from an event](#Unsuscribingfromanevent)
	* 3.4. [Raising an event](#Raisinganevent)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='UnderstandingDelegates'></a>Understanding Delegates

- A `delegate` is an `object` that refers to a method.
- It fully decouples the application logic in your methods from the application that invoke them.
- A `delegate` "delegates" processing to the referenced method when they are invoked.
- The method refered by a `delegate` can be changed to run a different method each time it executes.
- A `delegate` can refer more than one method at a time. So, when you invoke it all methods to which it refers will run.
- It refers only to methods that matches its signature.
- It can't be invoked if it refer to a invalid method.

- Some `Collections` e.g., `List<T>`, let you to implement some of its methods (e.g. , `Find` or `Exists`) because they had no idea about what should actually constitute a match in the application.
  - You can implement it using a `predicate` i.e, a `delegate` that returns a `boolean` value. 

Note: The `Func<T,...,TResult>` and `Action<T,...>` delegate types
- `Func<T1,T2,...,TResult>`: takes the `T` parametrs and returns a `TResult` value
  - `T1`, `T2`, `...`: are the type of the parameters passed to the `delegate`
  - `TResult`: determined by the context in which the `delegate`  is used
- `Action<T,...>`: performs an action instead of returning a value.

###  1.1. <a name='Theautomatedfactoryscenario'></a>The automated factory scenario

#### Steps to create a delegate
- Select methods with same shape (same `return `type and parameters)
- Declare the `delegate`
- Create an instance of it
- Refer it to a method by using the `+=` operator. (This is tipically done in class constructors).
- For example:
  - We have the following objects and its methods:
    - `obj1` with `method1`
    - `obj2` with `method2`
    - `obj3` with `method3`
  - The code below shows how to create a delegate which includes all this methods to its reference
  - The method `DelegateMethodsCaller()` invokes the delegate which call its referenced methods.
  - If the method that the delegate refers has parameters It should be included in `this.delegateInstance()`
- Trying to invoke a delegate that is uninitialized and does not refer to any method, throws a `NullReferenceException` error.
  
``` cs 
class Controller
{
	delegate void exampleOfDelegate(); //Declaration
	private exampleOfDelegate delegateInstance;

	public Controller()
	{
		// Adding method1 to delegate references
		this.delegateInstance += obj1.method1;
		this.delegateInstance += obj2.method2;
		this.delegateInstance += obj3.method3;

		// Alternative form (too much!)
		this.delegateInstance = new exampleOfDelegate(obj1.method1);
	}

	public DelegateMethodsCaller()
	{
		// This method INVOKES the delegate
		this.delegateInstance();
	}
}
```
- **IMPORTANT**: The `DelegateMethodsCaller` does not need to know how many objects there are nor its methods.
- You can remove a methods from a `delegate` using the `-=` operator

###  1.4. <a name='Declaringandusingadelegate'></a>Declaring and using a delegate
- The previous code was only for learning purposes.
- To effectively implements `delegate` it is necessary to provide complete encapsulation by implementing separate `Add` and `Remove` methods.
  - Steps:
    1. Set the delegate type as `public`: `delegate void exampleOfDelegate()`
    2. `Add`: `public void Add(exampleOfDelegate methodToBeReferenced)` => this.delegateInstance += methodToBeReferenced;
    3. `Remove`: `public void Remove(exampleOfDelegate methodToBeReferenced)` => this.delegateInstance -= methodToBeReferenced;

``` cs
namespace DelegatesTest
{
    internal class Object1
    {
        public void Method1() 
        {
            Console.WriteLine("Object1 method1 called");
        }
    }
	
	internal class Object2
    {
        public void Method2()
        {
            Console.WriteLine("Object2 method2 called");
        }
    }
	
	internal class Object3
    {
        public void Method3()
        {
            Console.WriteLine("Object3 method3 called");
        }
    }
	
	internal class DelegateController
    {
        public delegate void exampleOfDelegate(); // Step1: Set the delegate type as `public`
        private exampleOfDelegate delegateInstance; // Delegate instantiation

        
        public DelegateController()
        {            
        }

		//Step2
		public void Add(exampleOfDelegate methodToBeReferenced) => this.delegateInstance += methodToBeReferenced;
		//Step3
		public void Remove(exampleOfDelegate methodToBeReferenced) => this.delegateInstance -= methodToBeReferenced;


        public void DelegateMethodsCaller()
        {
            this.delegateInstance();
        }
    }
}
```

- With this, the next step is to use the `delegate` in the main program:

``` cs 
Object1 obj1 = new Object1();
Object2 obj2 = new Object2();
Object3 obj3 = new Object3();

DelegateController c = new DelegateController();

Console.WriteLine("Lets Add some references to methods!!");
c.Add(obj1.Method1);
c.Add(obj2.Method2);
c.Add(obj3.Method3);
c.DelegateMethodsCaller();

Console.WriteLine("Lets Remove some references to methods!!");

c.Remove(obj2.Method2);
c.DelegateMethodsCaller();
```
##  2. <a name='LambdaexpressionsandDelegates'></a>Lambda expressions and Delegates

###  2.1. <a name='Creatingamethodadapter'></a>Creating a method adapter

##  3. <a name='EnablingnotificationsbyusingEvents'></a>Enabling notifications by using Events

###  3.1. <a name='Declaringanevent'></a>Declaring an event

###  3.2. <a name='Subscribingtoanevent'></a>Subscribing to an event

###  3.3. <a name='Unsuscribingfromanevent'></a>Unsuscribing from an event

###  3.4. <a name='Raisinganevent'></a>Raising an event