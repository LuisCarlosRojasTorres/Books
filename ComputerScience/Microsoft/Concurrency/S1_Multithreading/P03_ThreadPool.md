## What is it?
- It is managed pool of `background` threads (called **worker** thread) that can be used to execute tasks concurrently. 
    - The worker threads are optimized for short-running tasks.

## What is its purpose?
- To reuse threads and avoid the overhead of creating and destroying threads for each task, which is very expensive in terms of time and resources.

## Important Concepts
- The `ThreadPool` provides the `QueueUserWorkItem` method which accepts the `WaitCallback` delegate as aparameter.
  
``` cs
public delegate void WaitCallback(object? state);
```

- To add a method to the queue of threads:

``` cs
ThreadPool.QueueUserWorkItem(dummyInput =>
    {
        //code here...        
    }
);
```

### How to use

#### Using Methods
1. Create a `static void` method:

``` cs
static void DummyMethod(int n)
{
    Console.WriteLine(" - DummyMethodWithParameters...");
    Thread.Sleep(2000);
    Console.WriteLine($" - DummyMethodWithParameters: n={n}");
    Console.WriteLine(" - DummyMethodWithParameters...done");
}
```

2. Add the method to the `ThreadPool`:

``` cs
static void Main(string[] args)
{
    // Set DummyInput value    
    int dummyInputValue = 10;
    // Add method to the threadPool
    ThreadPool.QueueUserWorkItem(dummyInput =>
        {
            DummyMethod(dummyInputValue);
        }
    );

    //Wait to threadPool to complete
    Console.ReadLine();

}
```

- Full code:

``` cs 
public class Program
{
    static void DummyMethod(int n)
    {
        Console.WriteLine(" - DummyMethodWithParameters...");
        Thread.Sleep(2000);
        Console.WriteLine($" - DummyMethodWithParameters: n={n}");
        Console.WriteLine(" - DummyMethodWithParameters...done");
    }

    static void Main(string[] args)
    {
        int dummyInputValue = 10;
        ThreadPool.QueueUserWorkItem(dummyInput =>
            {
                DummyMethod(dummyInputValue);
            }
        );

        Console.ReadLine();
    }
}
```
#### Using ParameterizedThreadStart Delegate

1. Create a `static void` method:

``` cs
ParameterizedThreadStart parameterizedThreadStart = (object? o) => {
    Console.WriteLine(" - DummyMethodWithParameters...");
    Thread.Sleep(2000);
    Console.WriteLine($" - DummyMethodWithParameters: o={o}");
    Console.WriteLine(" - DummyMethodWithParameters...done");
};
```

2. Add the method to the `ThreadPool`:

``` cs
static void Main(string[] args)
{
    // Set DummyInput value    
    int dummyInputValue = 10;
    // Add delegate to the threadPool
    ThreadPool.QueueUserWorkItem(dummyInput =>
        {
            parameterizedThreadStart(dummyInputValue);           
        }
    );

    //Wait to threadPool to complete
    Console.ReadLine();

}
```

- Full code:

``` cs 
public class Program
{
    static void Main(string[] args)
    {
     ParameterizedThreadStart parameterizedThreadStart = (object? o) => {
         Console.WriteLine(" - DummyMethodWithParameters...");
         Thread.Sleep(2000);
         Console.WriteLine($" - DummyMethodWithParameters: o={o}");
         Console.WriteLine(" - DummyMethodWithParameters...done");
     };

     int dummyInputValue = 10;
     ThreadPool.QueueUserWorkItem(dummyInput =>
         {
             parameterizedThreadStart(dummyInputValue);             
         }
     );

     Console.ReadLine();
    }
}
```