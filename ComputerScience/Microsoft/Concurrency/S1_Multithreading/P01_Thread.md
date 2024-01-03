## What is it?
- It represents a single unit of execution within a **process**.
  - A `process` encapsulates all the execution of an application. i.e. an `.exe`
        
## What is its purpose?
- To increase the responsiveness of your application.
- To take advantage of a multiprocessor or multi-core system to increase the application's throughput.

## Important Concepts
- **Managed Threading**: Threads implemented by the `System.Threading.Thread` class.
  - Manage threads has:
    - `ManageThreadId` : An integer that is guaranteed to be unique across all threads and will not change over time.
    - `ThreadState` : It provides the current execution state of the `Thread` object. (e.g. `Aborted`, `Background`, `Running`, `Stopped`, `Unstarted` etc.)
- **Unmanaged Threading**: threads in C++.
- `Thread` class has 4 constructors:
  - `Thread(ThreadStart)`: (For no parameters) Passing the `ThreadStart` delegate
  - `Thread(ParameterizedThreadStart)`: Passing the `ParameterizedThreadStart` delegate which has an `object` parameter
  
### How to use using explicit methods

#### Without Parameters
1. Create a `void` method with no parameters
``` cs 
static void DummyMethod()
    {
        Console.WriteLine(" - DummyMethod...");
        Thread.Sleep(2000);
        Console.WriteLine("done");
    }
```
2. Reference the method to a `ParameterizedThreadStart` delegate.

``` cs
ThreadStart startNoParam = DummyMethod;
```
3. Initialize the `Thread(ThreadStart)` object with the `ThreadStart` delegate as argument.

``` cs
//Initialize the thread
var t1 = new Thread(threadStart);
// Start the threads
t1.Start();
// wait for the thread to complete
t1.Join();
```

- The full code:

``` cs
class Program
{
    static void DummyMethod()
    {
        Console.WriteLine(" - DummyMethod...");
        Thread.Sleep(2000);
        Console.WriteLine("done");
    }
    
    static void Main(string[] args)
    {
        ThreadStart threadStart = DummyMethod;

        //Initialize the thread
        var t1 = new Thread(threadStart);
    
        // Start the threads
        t1.Start();
    
        // wait for the thread to complete
        t1.Join();
    
        Console.WriteLine(" - NoParam Thread done!");
    }
}
```

#### With Parameters
1. Create a `void` method with an `object` parameter


``` cs 
static void DummyMethodWithParameters(object o)
{
    Console.WriteLine(" - DummyMethodWithParameters...");
    Thread.Sleep(2000);
    Console.WriteLine($" - DummyMethodWithParameters: o={o}");
    Console.WriteLine(" - DummyMethodWithParameters...done");
}
```
2. Reference the method to a `ParameterizedThreadStart` delegate.

``` cs
ParameterizedThreadStart startParam = DummyMethodWithParameters!;
```

3. Initialize the `Thread(ThreadStart)` object with the `ThreadStart` delegate as argument.

``` cs
//Initialize the thread
var t2 = new Thread(startParam);
// Start the threads with an obj argument
t2.Start(5);
// wait for the thread to complete
t2.Join();
```

- The full code:

``` cs
class Program
{
    static void DummyMethodWithParameters(object o)
{
    Console.WriteLine(" - DummyMethodWithParameters...");
    Thread.Sleep(2000);
    Console.WriteLine($" - DummyMethodWithParameters: o={o}");
    Console.WriteLine(" - DummyMethodWithParameters...done");
}
    
    static void Main(string[] args)
    {
        ParameterizedThreadStart startParam= DummyMethodWithParameters!;

        //Initialize the thread
        var t2 = new Thread(startParam);
    
        // Start the threads
        t2.Start(5);
    
        // wait for the thread to complete
        t2.Join();
    
        Console.WriteLine(" - WithParam Thread done!");
    }
}
```
