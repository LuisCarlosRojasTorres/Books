
## Running tasks asynchronously

### Running tasks synchronously
``` cs 
using System.Diagnostics;

using System;
using System.Threading.Tasks.Dataflow;

Console.WriteLine(" RUNNING METHODS SYNCHRONOULY");
OutputThreadInfo();
Stopwatch timer = Stopwatch.StartNew();

// Os metodos sao chamados sequencialmente
MethodA();
MethodB();
MethodC();
Console.WriteLine($" Time elapsed: {timer.ElapsedMilliseconds:#,##0}ms");

//Methods
static void OutputThreadInfo()
{
    Thread t = Thread.CurrentThread;

    Console.WriteLine(
        " >> Thread id: {0}, Priority: {1}, Background: {2}, Name: {3}",
        t.ManagedThreadId, t.Priority, t.IsBackground, t.Name ?? "null"
    );    
}

static void MethodA()
{
    Console.WriteLine(" >>>>>>>>>>>>>>>>>>>>>>>");
    Console.WriteLine(" >> Starting Method A...");
    OutputThreadInfo();
    Thread.Sleep(3000);
    Console.WriteLine(" >> Finished Method A...");
}

static void MethodB()
{
    Console.WriteLine(" >>>>>>>>>>>>>>>>>>>>>>>");
    Console.WriteLine(" >> Starting Method B...");
    OutputThreadInfo();
    Thread.Sleep(2000);
    Console.WriteLine(" >> Finished Method B...");
}

static void MethodC()
{
    Console.WriteLine(" >>>>>>>>>>>>>>>>>>>>>>>");
    Console.WriteLine(" >> Starting Method C...");
    OutputThreadInfo();
    Thread.Sleep(1000);
    Console.WriteLine(" >> Finished Method C...");
}
```

- A saida do programa eh apresentada a seguir

```
 RUNNING METHODS SYNCHRONOULY
 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method A...
 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >> Finished Method A...
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method B...
 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >> Finished Method B...
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method C...
 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >> Finished Method C...
 Elapsed time: 6,003ms
```

- Como esperado o tempo que demorou foi de aprox: `3000 + 2000 + 1000 = 6000` milliseconds.

### Running multiple methods asynchronously using tasks
- A classe `Thread` permite criar `new Threads` e gerenciar eles. (porem eh um pouco complicado fazer isso diretamente)
- A classe `Task` is a **thread wrapper** which ease the creation and management of threads (moreover it allows the code to execute `aynchronously`). 
- To run the previous code asynchronously it is only necessary to modify the method call and use `Task` instead.
- There are three ways to create a task:

``` cs
Console.WriteLine(" RUNNING METHODS ASYNCHRONOULY in Multiple Threads");
OutputThreadInfo();
Stopwatch timer = Stopwatch.StartNew();

Task taskA = new(MethodA); //1 way
taskA.Start();

Task taskB = Task.Factory.StartNew(MethodB); //2 way
Task taskC = Task.Run(MethodC); //3 way

Console.WriteLine($" Time elapsed: {timer.ElapsedMilliseconds:#,##0}ms");
```

```
RUNNING METHODS ASYNCHRONOULY in Multiple Threads
 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method A...
 >> Thread id: 4, Priority: Normal, Background: True, Name: .NET ThreadPool Worker
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method B...
 >> Thread id: 6, Priority: Normal, Background: True, Name: .NET ThreadPool Worker
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method C...
 >> Thread id: 7, Priority: Normal, Background: True, Name: .NET ThreadPool Worker
 Time elapsed: 10ms
```

- The message `>> Finished Method ...` does not exist in the console output!!.
   - The main method only calls the Tasks and continue until its end. When that happens, **the task are not finished*!!*.
   - To solve this we can use the following three methods:
      - `t.Wait()`: This waits for the task instance named `t` to complete execution.
      - `Task.WaitAny(Task[])`: It waits until one of the tasks in the array completes
      - `Task.WaitAll(Task[])`: It waits until all the tasks in the array completes

#### Examples with t.Wait   
   
- This will take `6018` ms. Each Task begins after the previous one is finished.

``` cs
Task taskA = new(MethodA);
taskA.Start();
taskA.Wait();

Task taskB = Task.Factory.StartNew(MethodB);
taskB.Wait();

Task taskC = Task.Run(MethodC);
taskC.Wait();      
```

- On the other hand this will take `3018` ms. All threads are called and the process finishes when the longest thread (thread C has a `3000`ms sleep) is completed.

```
Task taskA = new(MethodA);
taskA.Start();

Task taskB = Task.Factory.StartNew(MethodB);

Task taskC = Task.Run(MethodC);

taskA.Wait();
taskB.Wait();
taskC.Wait();
```

#### Examples with Wait.Any
- This takes 1000 ms because as soon as the first thread finishes the main thread too.
``` cs
Task taskA = new(MethodA);
taskA.Start();

Task taskB = Task.Factory.StartNew(MethodB);

Task taskC = Task.Run(MethodC);

Task[] tasks = { taskA, taskB, taskC };
Task.WaitAny(tasks);
```

- Output
   - It can be observed that as soon as the one thread is completed the main thread finishes.
```
RUNNING METHODS ASYNCHRONOULY in Multiple Threads

 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method A...
 >> Thread id: 4, Priority: Normal, Background: True, Name: .NET ThreadPool Worker
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method B...
 >> Thread id: 6, Priority: Normal, Background: True, Name: .NET ThreadPool Worker
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method C...
 >> Thread id: 7, Priority: Normal, Background: True, Name: .NET ThreadPool Worker
 >> Finished Method C...
 Time elapsed: 1,039ms
```
#### Examples with Wait.All
- If the `WaitAny` is replaced by `WaitAll`. The time elapsed will be `3014` ms.

``` cs
Task.WaitAny(tasks);
```
