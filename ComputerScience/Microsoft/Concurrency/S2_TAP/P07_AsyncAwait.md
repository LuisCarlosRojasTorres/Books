## What is it?
- The `Async` and `Await` operators permit to implement asynchronous methods.
        
## What is its purpose?
- It simplifies asynchronous code.
  - To convert a `task` with many `ContinueWith` into an `async` method with many `await`.
  - It is not necessary to implement something to keep the main thread waiting e.g. `Console.Read()` at the end of the main method.     
- `Async` and `Await` work together:
  - `async` operator: Permits a method (which shall contain `asynchronous` operations) be executed on a separated thread (this allows the method to return immediately without blocking the calling thread).
  - `await` operator: It pauses the thread (which is running the method) to wait for the completion of an asynchronous operation before continuing the current execution.
  
## Important Concepts
- The `await` can be used to wait for a `Task` or `Task<T>` object.
  - `await Task.Delay(5000);`: So it can be used in an `async` method.
- Do not use `async void` unless it’s an event handler.
- This `void` method has a `task` inside so it will run asynchronously. It needs a `Console.Read` (or similar) in the calling method to wait until it finishes.
``` cs
void DummyBigMethod()
{
    var task = Task.Run(() => DummyAsyncMethod1())
        .ContinueWith((task) => DummyAsyncMethod2())
        .ContinueWith((task) => DummyAsyncMethod3());    
}
```

- To change we need to replace every `ContinueWith` with `await`

``` cs
void async Task DummyBigMethod()
{
    await DummyAsyncMethod1();
    await DummyAsyncMethod2();
    await DummyAsyncMethod3();        
}
```

- Always return a `Task` from an `async` method.
- Always await an `async` method to validate the asynchronous operation.

### How to use
- The following example require the following data:
- A `readme.txt` file
```
line01: asdfasdfasdf
line02: xcvxcvbxcvbb
line03: qwerqwerqwer
line04: ertyertyerty
line05: dfghdfghdghh
```
- A program with `task` and `ContinueWith` methods

``` cs
class Program
{
    static void DummyMethod(string filename)
    {
        Console.WriteLine(" - DummyMethod: ");

        // task runs asynchronously
        var task = File.ReadAllLinesAsync(filename);
        task.ContinueWith(t =>
        {
        Console.WriteLine(" - DummyMethod: ContinueWith");
        //This Result blocks the thread which runs the method.
            var lines = t.Result;
            foreach (var line in lines)
            {
                Console.WriteLine(line);
            }
        });

        Console.WriteLine(" - DummyMethod:...done!");
    }


    static void Main()
    {
        //This method is called and call asynchronously the task inside it.
        DummyMethod("readme.txt");
        Console.WriteLine(" - Main Thread: ");
        //Read to wait for the finished thread.
        Console.Read();
    }
}
```

- The output of the program:

```
 - DummyMethod:
 - DummyMethod:...done!
 - Main Thread:
 - DummyMethod: ContinueWith
line01: asdfasdfasdf
line02: xcvxcvbxcvbb
line03: qwerqwerqwer
line04: ertyertyerty
line05: dfghdfghdghh
```

1. Create an `async Task` method to replace the `DummyMethod`
    - Replace the `ContinueWith` (which is used to wait the `ReadAllLinesAsync` method to finish) with an `await`

``` cs
static async Task DummyMethod(string filename)
{
    Console.WriteLine(" - DummyMethod: ");            
    var lines = await File.ReadAllLinesAsync(filename);

    foreach (var line in lines)
    {
        Console.WriteLine(line);
    }
    Console.WriteLine(" - DummyMethod:... done!");
}
```

2. Call the `async` method using an `await` (this, to wait until method completion)

```cs
static async Task Main()
{
    Console.WriteLine(" - Main Thread: ");
    //This pauses Main task until the async method completes
    await DummyMethod("readme.txt");

    Console.WriteLine(" - Main Thread:...done!");    
}
```
- Output
```
 - Main Thread:
 - DummyMethod:
line01: asdfasdfasdf
line02: xcvxcvbxcvbb
line03: qwerqwerqwer
line04: ertyertyerty
line05: dfghdfghdghh
 - DummyMethod:... done!
 - Main Thread:...done!
```

3. What if we dont use await when calling the async method?
   - The program finished before the async method.
   - Output:
   ```
    - Main Thread:
    - DummyMethod:
    - Main Thread:...done!
    line01: asdfasdfasdf
    line02: xcvxcvbxcvbb
   ```
   - One way to "solve" this, is using a `Console.Read()` as follows (which pauses the program and the asyn method has time to finish):
   ```
   static async Task Main()
   {
    Console.WriteLine(" - Main Thread: ");
    DummyMethod("readme.txt");
    Console.WriteLine(" - Main Thread:...done!");
    Console.Read();
   }
   ```