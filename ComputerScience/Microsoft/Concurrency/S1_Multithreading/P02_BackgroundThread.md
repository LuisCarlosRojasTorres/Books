## What is it?

- **Background thread**: If an application is terminated, any running background threads will be stopped so that the process can shut down.  
- **Foreground thread**: It will prevent the managed process fom terminating if they are running. It executes with the same priority as the main thread.

## What is its purpose?
- For not critical applications:
  - Time-consuming operations: like file I/O, network operations, or database queries without obstructing the main UI thread.
  - Background processing: Tasks that don’t need user input, including data synchronization, backup, or maintenance, can be carried out in the background using background threads.

## Important Concepts
- To change a thread from **foreground** to **background**, you use the `IsBackground` property of the Thread object. 
  - The property shall be changed before the thread is started!

``` cs 
dummyThread.IsBackground = true;
```

### How to use

#### Configuring a backgroung thread
The process is similar to a foreground thread, the only difference is the change of the `IsBackgroung` property.

1. Create a thread object.
``` cs 
var dummyThread = new Thread(dummyDelegate);
```

2. Set the `IsBackground` property
``` cs 
dummyThread.IsBackground = true;
dummyThread.Start();
```
3. Call the `Start` method
``` cs 
dummyThread.Start();
```

- Full code:

``` cs 
public class Program
{
    static void DummyMethod()
    {
        for (int i = 0; i < 10; i++)
        {
            Thread.Sleep(100);
            Console.WriteLine(" - DummyMethod in Background thread running...");
        }
    }

    static void Main(string[] args)
    {
        var dummyThread = new Thread(DummyMethod);
        dummyThread.IsBackground = true;
        dummyThread.Start();

        // Do some work in the main thread
        for (int i = 0; i < 2; i++)
        {
            Thread.Sleep(100);
            Console.WriteLine("Main thread running...");
        }
    }
}
```

- The output is :

```
Main thread running...
Background thread running...
Main thread running...
```

- So, the program ends before the Background thread finishes. 
- On the other hand, if the `IsBackground` property is commented the output will be:

```
Main thread running...
 - DummyMethod in Background thread running...
 - DummyMethod in Background thread running...
Main thread running...
 - DummyMethod in Background thread running...
 - DummyMethod in Background thread running...
 - DummyMethod in Background thread running...
 - DummyMethod in Background thread running...
 - DummyMethod in Background thread running...
 - DummyMethod in Background thread running...
 - DummyMethod in Background thread running...
 - DummyMethod in Background thread running...
```


