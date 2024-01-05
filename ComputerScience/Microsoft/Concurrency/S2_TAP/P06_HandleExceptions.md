## What is it?
- It is how the Task wrap any exception that occur.
        
## What is its purpose?
- Avoid crash or unhandled exceptions.      

## Important Concepts

- To propagate all the exceptions to the calling thread, the Task wraps them in an `AggregateException` object.
   - the `Task` will wrap any exceptions that occur within an `AggregationException` object, even if a single exception is raised.

- There are two ways to handle the exception:
1. Loop of `.InnerExceptions` (useful if the task contain nested tasks): Which returns a collection with all the exceptions along the nested tasks.
    - To use it, we call the `.Flatten` method to get an Instance of the `AggregateException` object.

``` cs 
catch (AggregateException ae)
{   
    var innerExceptions = ae.Flatten().InnerExceptions;
    foreach (var e in innerExceptions)
    {
        //..
    }
    
}
```
2. Using lambda expression with `.Handle()` method:

``` cs 
catch (AggregateException ae)
{
    ae.Flatten().Handle(e =>
    {
        if (e is CustomException)
        {
            // Code here
            Console.WriteLine(e.Message);
            return true;
        }
        else
        {
            throw e;
        }
    });
}
```
### How to use


#### Using InnerExceptions
- FullCode

``` cs
public class Program
{
    static decimal Divide(decimal inputUp, decimal inputDown)
    {
        Thread.Sleep(1000);

        return inputUp / inputDown;
    }

    static void Main(string[] args)
    {
        try
        {
            var task = Task.Run(() => Divide(5, 0));
            var result = task.Result;
        }
        catch (AggregateException ae)
        {   
            var innerExceptions = ae.Flatten().InnerExceptions;

            foreach (var e in innerExceptions) 
            {
                if (e is DivideByZeroException)
                {
                    Console.WriteLine($" - InnerExceptions: { e.Message}");  
                }
                else
                {
                    throw e;
                }
            }
        }
    }
}
```

#### Using Handle
- FullCode

``` cs
public class Program
{
    static decimal Divide(decimal inputUp, decimal inputDown)
    {
        Thread.Sleep(1000);

        return inputUp / inputDown;
    }

    static void Main(string[] args)
    {
        try
        {
            var task = Task.Run(() => Divide(5, 0));
            var result = task.Result;
        }
        catch (AggregateException ae)
        {   
            ae.Flatten().Handle(e =>
            {
                if (e is DivideByZeroException)
                {
                    Console.WriteLine(e.Message);
                    return true;
                }
                else
                {
                    throw e;
                }
            });
        }
    }
}
```
