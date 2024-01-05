## What is it?
-  It creates a continuation that will execute asynchronously once the target task has been completed.
        
## What is its purpose?
- To call many methods (one after another) asynchronally (from the main thread) using only one task.
      
## Important Concepts
- `task.Result` property, which blocks the main threads until the task is completed and the result is available.
  - This can block can be avoided using `ContinueWith`

- The `ContinuationWith` can be called in different statements.

``` cs
var task = Task.Run(() => DummyMethod(dummyArgument));
task.ContinueWith((task) =>
{
    //task.Result;    
});
```

- The `ContinuationWith` can also be called in the statements.

``` cs
var task = Task.Run(() => DummyMethod(dummyArgument))
    .ContinueWith((task) =>
    {
        //task.Result;    
    });
```

### How to use

This example shows how the main thread is not blocked when the Task.Result is used.

#### In diferent statements

1. Create a `DummyMethod` to be run in the `Task`

``` cs
static int DummyMethod(int n)
{
    int n2 = n * n;
    Console.WriteLine(" - DummyMethodWithParameters:...");
    Thread.Sleep(5000);
    Console.WriteLine($" - DummyMethodWithParameters: n*n={n2}");
    Console.WriteLine(" - DummyMethodWithParameters:...done");
    return n2;
}
```

2. Create the `Task.Run`

``` cs 
var task = Task.Run(() => DummyMethod(10));
```

3. Call `ContinueWith` in **another statements**

``` cs
task.ContinueWith((task) =>
{
    Console.WriteLine(" - TaskContinuation");
    Thread.Sleep(3000);
    //This statement usually blocks the main thread...
    result = task.Result;
    Console.WriteLine(" - TaskContinuation...done");
});
```

4. Create a method to wait the task to be finished.

``` cs 
while (result == 0)
{
    Console.WriteLine("Main Thread: Waiting for the result...");
    Thread.Sleep(1000);                
}

Console.WriteLine($"Main Thread: result = {result}");
```

- Full Code 

``` cs
 public class Program
 {
     static int DummyMethod(int n)
     {
         int n2 = n * n;
         Console.WriteLine(" - DummyMethodWithParameters:...");
         Thread.Sleep(5000);
         Console.WriteLine($" - DummyMethodWithParameters: n*n={n2}");
         Console.WriteLine(" - DummyMethodWithParameters:...done");
         return n2;
     }

     static void Main(string[] args)
     {
         var result = 0;
         
         
         var task = Task.Run(() => DummyMethod(10));

         task.ContinueWith((task) =>
         {
             Console.WriteLine(" - TaskContinuation");
             Thread.Sleep(3000);
             result = task.Result;
             Console.WriteLine(" - TaskContinuation...done");
         });
         
         while (result == 0)
         {
             Console.WriteLine("Main Thread: Waiting for the result...");
             Thread.Sleep(1000);                
         }

         Console.WriteLine($"Main Thread: result = {result}");
     }
 }
```

- Output

```
 - DummyMethodWithParameters:...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
 - DummyMethodWithParameters: n*n=100
 - DummyMethodWithParameters:...done
 - TaskContinuation
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
 - TaskContinuation...done
Main Thread: result = 100
```

#### At same statement

1. Create a `DummyMethod` to be run in the `Task`

``` cs
static int DummyMethod(int n)
{
    int n2 = n * n;
    Console.WriteLine(" - DummyMethodWithParameters:...");
    Thread.Sleep(5000);
    Console.WriteLine($" - DummyMethodWithParameters: n*n={n2}");
    Console.WriteLine(" - DummyMethodWithParameters:...done");
    return n2;
}
```

2. Create the `Task.Run` and call the `ContinueWith`

``` cs 
var task = Task.Run(() => DummyMethod(10))
    .ContinueWith((task) =>
    {
        Console.WriteLine(" - TaskContinuation");
        Thread.Sleep(3000);
        result = task.Result;
        Console.WriteLine(" - TaskContinuation...done");
    });
```

3. Create a method to wait the task to be finished.

``` cs 
while (result == 0)
{
    Console.WriteLine("Main Thread: Waiting for the result...");
    Thread.Sleep(1000);                
}

Console.WriteLine($"Main Thread: result = {result}");
```

- Full Code 

``` cs
 public class Program
 {
     static int DummyMethod(int n)
     {
         int n2 = n * n;
         Console.WriteLine(" - DummyMethodWithParameters:...");
         Thread.Sleep(5000);
         Console.WriteLine($" - DummyMethodWithParameters: n*n={n2}");
         Console.WriteLine(" - DummyMethodWithParameters:...done");
         return n2;
     }

     static void Main(string[] args)
     {
         var result = 0;
         
         
         var task = Task.Run(() => DummyMethod(10));

         task.ContinueWith((task) =>
         {
             Console.WriteLine(" - TaskContinuation");
             Thread.Sleep(3000);
             result = task.Result;
             Console.WriteLine(" - TaskContinuation...done");
         });
         
         while (result == 0)
         {
             Console.WriteLine("Main Thread: Waiting for the result...");
             Thread.Sleep(1000);                
         }

         Console.WriteLine($"Main Thread: result = {result}");
     }
 }
```

- Output

```
 - DummyMethodWithParameters:...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
 - DummyMethodWithParameters: n*n=100
 - DummyMethodWithParameters:...done
 - TaskContinuation
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
Main Thread: Waiting for the result...
 - TaskContinuation...done
Main Thread: result = 100
```