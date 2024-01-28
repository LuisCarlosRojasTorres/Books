## What is it?
- It represents an asynchronous operation that can be executed in various ways.
        
## What is its purpose?
- Ease asynchronous code implementation
  - Include `async/await` keywords and the Task-based API.

## Important Concepts
- The create and initialize a `task`, a `DummyMethod` (with or without parameters) shall be referenced using lambda functions.
    - Under the hood, a `ThreadPool` is created.
``` cs
var task = new Task(() => DummyMethod());
```
- To run, (after initialization) the `Start` method shall be called.
  - When used, the task cannot return a value.
- The initialization and `Start` method can be called at same time using the `Run` method.
  - The task can return a value i.e. `Task.Result`.


### How to use

#### Using Start
- Note: When using `Start`, a Task cannot return a value.
1. Creating a `DummyMethod`

``` cs
static int DummyMethod(int n)
{
    Console.WriteLine(" - DummyMethodWithParameters:...");
    Thread.Sleep(2000);
    Console.WriteLine($" - DummyMethodWithParameters: n={n}");
    Console.WriteLine(" - DummyMethodWithParameters:...done");
    return n;
}
```

2. Creating a `Task` with a lambda expression

``` cs
int dummyInputValue = 15;
var task1 = new Task(() => DummyMethod(dummyInputValue));
```

3. Call the `Start` method of the `Task`

``` cs
task1.Start();
```

- Full code:

``` cs
public class Program
{
    static int DummyMethod(int n)
    {
        Console.WriteLine(" - DummyMethodWithParameters:...");
        Thread.Sleep(2000);
        Console.WriteLine($" - DummyMethodWithParameters: n={n}");
        Console.WriteLine(" - DummyMethodWithParameters:...done");
        return n;
    }

    static void Main(string[] args)
    {
        int dummyInputValue = 15;
        // 
        var task1 = new Task(() => DummyMethod(dummyInputValue));
        task1.Start();

        Console.WriteLine("Start the main program...");
        // This statement is required to wait for the task
        Console.ReadLine();
    }
} 
```

- Output:
```
Start the main program...
 - DummyMethodWithParameters:...
 - DummyMethodWithParameters: n=15
 - DummyMethodWithParameters:...done
```
#### Using Run
- Run = Initialization + Start
- When used `Run`, The `Task` it can return `Result` value.

1. Creating a `DummyMethod`
2. Call the `Run` method of the `Task`. With this the programm will wait until the Task return a value.

``` cs
static void Main(string[] args)
{
    int dummyInputValue = 15;
    var task2 = Task.Run(() => DummyMethod(dummyInputValue));

    Console.WriteLine("Start the main program...");
    Console.WriteLine($" - Task.Run: Result = {task2.Result}");
}
```

- Output:
```
Start the main program...
 - DummyMethodWithParameters:...
 - DummyMethodWithParameters: n=15
 - DummyMethodWithParameters:...done
 - Task.Run: Result = 15
```
