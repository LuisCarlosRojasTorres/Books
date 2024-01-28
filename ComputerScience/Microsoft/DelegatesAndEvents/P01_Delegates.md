
## What is it?
- It holds references to methods with the **same signature** (same arguments and return type).
      
## What is its purpose?
- To define **callback methods**
    - You can pass a method as arguments to other methods using `delegates`.
     
## Important Concepts
- It is define using the following syntax `delegate <type> <MethodName>(<Type1> t1, <Type2> t2...)`   

### How to use
- Create a delegate:

``` cs 
delegate void DummyDelegate(string input);
```
- Create a method with same signature

``` cs 
// This method has same signature as DummyDelegate
static void SayHello(string x)
{
    Console.WriteLine($" - Hi {x}");
}

// This method has same signature as DummyDelegate
static void SayBye(string x)
{
    Console.WriteLine($" - Bye {x}");
}
```
#### Initialization1

``` cs 
// Assign method
DummyDelegate dummyDelegate = new DummyDelegate(SayHello);
// To call the method referenced by the `delegate`
dummyDelegate.Invoke("Rufo");

Greeting greeting = new Greeting(SayHi);
greeting.Invoke("John");
```


#### Initialization2

``` cs 
// Assign method
DummyDelegate dummyDelegate = SayHello;
// To call the method referenced by the `delegate`
dummyDelegate("Rufo");
```

#### Add a method to a Delegate
- for first method use `=` e.g. `dummyDelegate = SayHello`
- for the other use `+=` e.g. `dummyDelegate += SayBye`

#### Remove a method from Delegate
- use `-=` e.g. `dummyDelegate -= SayHello`

#### Delegate as an argument of a method
- A powerful feature indeed!

``` cs 
//This method has a DummyDelegate as argument so it can receive SayHello
// and SayBye methods as arguments.
static void Greetings(List<string> names, DummyDelegate dummyDelegate)
{
    var results = new List<int>();

    foreach (var name in names)
    {
        dummyDelegate(name);        
    }    
}

//To call the method...
var names = new List<string> { "Luis", "Jessyca", "Lobo", "Rufa"};
Greetings(names, SayHello);
```



