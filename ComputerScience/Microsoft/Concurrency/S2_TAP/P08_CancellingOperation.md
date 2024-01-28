## What is it?
- A type of variable to request a cancellation in an asynchronous method.
        
## What is its purpose?
- To implement (manually) a mechanism to check for cancellation requests inside a `Task`   

## Important Concepts
- It is necessary a `CancellationTokenSource` to generate a `token`
- if you want an asynchronous operation to be cancellable, in the operation, you need to explicitly check for cancellation requests using the `IsCancellationRequested` property of the CancellationToken object, and stop running if it returns true.

### How to use
1. Create a method that will run for a long time e.g. forever.
   1. Implement a conditional to verify if `token.IsCancellationRequested` is true

``` cs
static void DummyMethod(CancellationToken token)
{
    int counter = 0;
    while (!token.IsCancellationRequested) 
    {
        Thread.Sleep(1000);
        Console.WriteLine($" - Second: {counter}"); 
        counter++;
    }
}
```

2. Initialize the `Cancellation Token`
``` cs
CancellationTokenSource cts = new();
```

3. Assign the method to a task to run 
``` cs
var task = Task.Run(() => DummyMethod(cts.Token));
```

4. Implement a mechanism to call the `Cancel` method of the `CancellationToken`

``` cs
Console.WriteLine("Press 'c' to cancel.");
while (true)
{
    var keyInfo = Console.ReadKey(true);
    if (keyInfo.KeyChar == 'c')
    {
        if (task.Status == TaskStatus.Running)
        {
            cts.Cancel();
            Console.WriteLine("Canceling the task...");
            break;
        }
    }
    // quit if the task has been completed
    if (task.Status == TaskStatus.RanToCompletion)
    {
        break;
    }
}
```

- FullCode
``` cs 
public class Program
{
    static void DummyMethod(CancellationToken token)
    {
        int counter = 0;
        while (!token.IsCancellationRequested) 
        {
            Thread.Sleep(1000);
            Console.WriteLine($" - Second: {counter}"); 
            counter++;
        }
    
    }
    static void Main(string[] args)
    {
        CancellationTokenSource cts = new();
        
        var task = Task.Run(() => DummyMethod(cts.Token));

        Console.WriteLine("Press 'c' to cancel.");
        while (true)
        {
            var keyInfo = Console.ReadKey(true);
            if (keyInfo.KeyChar == 'c')
            {
                if (task.Status == TaskStatus.Running)
                {
                    cts.Cancel();
                    Console.WriteLine("Canceling the task...");
                    break;
                }
            }
            // quit if the task has been completed
            if (task.Status == TaskStatus.RanToCompletion)
            {
                break;
            }
        }
    }
```

- Output
```
Press 'c' to cancel.
 - Second: 0
 - Second: 1
 - Second: 2
 - Second: 3
 - Second: 4
 - Second: 5
Canceling the task...
```