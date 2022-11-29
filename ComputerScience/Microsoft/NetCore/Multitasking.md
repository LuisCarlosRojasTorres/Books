<!-- vscode-markdown-toc -->
* 1. [Why?](#Why)
* 2. [Implementing multitasking](#Implementingmultitasking)
	* 2.1. [Tasks, threads and the ThreadPool](#TasksthreadsandtheThreadPool)
	* 2.2. [Creating, running, and using controlling tasks](#Creatingrunningandusingcontrollingtasks)
		* 2.2.1. [Creating without parameters](#Creatingwithoutparameters)
		* 2.2.2. [Creating with parameters](#Creatingwithparameters)
		* 2.2.3. [Creating and Running a Task](#CreatingandRunningaTask)
		* 2.2.4. [Assigning more than one task](#Assigningmorethanonetask)
		* 2.2.5. [Synchronize tasks](#Synchronizetasks)
	* 2.3. [Abstracting tasks by using the `Parallel` class](#AbstractingtasksbyusingtheParallelclass)
		* 2.3.1. [`Parallel.For`](#Parallel.For)
		* 2.3.2. [`Parallel.ForEach<T>`](#Parallel.ForEachT)
		* 2.3.3. [`Parallel.Invoke`](#Parallel.Invoke)
	* 2.4. [Recomendatiosn for `Parallel` class use](#RecomendatiosnforParallelclassuse)
* 3. [Cancelling tasks and handling exceptions](#Cancellingtasksandhandlingexceptions)
	* 3.1. [Cancelling a `Parallel.For` and a `Parallel.ForEach` loop](#CancellingaParallel.ForandaParallel.ForEachloop)
	* 3.2. [Handling task exceptions by using the `AggregateException` class](#HandlingtaskexceptionsbyusingtheAggregateExceptionclass)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Why'></a>Why?
Two reasons:
- To Improve responsiveness: Do many things simultanously.
- To Improve scalability: Decompose a process to be performed in parallel and run concurrently.

##  2. <a name='Implementingmultitasking'></a>Implementing multitasking 
- Multitasking is the ability to do many things at the same time.
- Requires some considerations:
  - Design: 
    - How to decompose an app into a set of concurrent operations.
  - Language issues:
    - How arrange a set of operations to run concurrently in multiple processor.
    - How to ensure the software is performing only as many concurrent operations as there are processor available.
    - Detection of blocked operations and how to handle this.
    - How to determine when one or more concurrent operations have completed.
- The **Design** part for multitasking is fundamental, otherwise it does not matter how many processor cores you use, the application will not run faster than it would on a single-core machine.
- The `Task` class and a collection of associated types in the `System.Threading.Tasks` namespace solve the **Language issues**

###  2.1. <a name='TasksthreadsandtheThreadPool'></a>Tasks, threads and the ThreadPool
- `Task` is an abstraction of a concurrent operation (it runs a block of code).
  - Internally are implemented using `threads` and the `ThreadPool` class.
- It provides a powerfull abstraction for threading with whhich you can distinguish between:
  - the degree of parallelization in an application (the `tasks`)
  - the units of parallelization (the `threads`)
- It optimizes the number of `threads` required to implement a set of concurrent tasks and schedules them efficiently according to the number of available processors.
- `ThreadPool` implemments a number of optimizations and uses a `work-stealing`  algorithm to ensure that `threads` are schedules efficiently.
  
So, all you have to do in you code is divide, or partition, your application into `tasks` that can be run in parallel.

###  2.2. <a name='Creatingrunningandusingcontrollingtasks'></a>Creating, running, and using controlling tasks

####  2.2.1. <a name='Creatingwithoutparameters'></a>Creating without parameters
- The `Task` constructor is `overloaded` but all versions require an `Action delegate` ([link](/ComputerScience/Microsoft/NetCore/DecouplingApplicationLogic.md#1-understanding-delegates)).
- The `Task object` invokes its delegate when it is scheduled to run.
- To start the `Task` use the `.Start()` method

``` cs
Task task = new Task(doWork);
//...
private void doWork()
{
    // the task runs this code when it is started
}

task.Start();
```
####  2.2.2. <a name='Creatingwithparameters'></a>Creating with parameters
- It is possible using a delegate that take an `object` parameter, i.e., `Action<object>`

``` cs
Action<object> action;
action = doWorkWithObjects;
object parameterData = ....;
Task task = new Task(action, parameterData);
//...
task.Start();
//..
private void doWorkWithObject(object o)
{
    // the task runs this code when it is started
}
```


####  2.2.3. <a name='CreatingandRunningaTask'></a>Creating and Running a Task
- `Task` class provides the static `Run` method to set an `Action delegates` and start immediately.
  - It returns a reference to the `Task` object.

``` cs
Task task = Task.Run(()=> doWork);
```

####  2.2.4. <a name='Assigningmorethanonetask'></a>Assigning more than one task
- Once a task finishes, another task can be scheduled immediately to continue.
  - This is possible using the `ContinueWith` method.
    1. The `Action` performed by the task object completes
    2. The scheduler automatically creates a new `Task` object to run, the actions especified by the `ContinueWith` methods.
``` cs 
Task task = Task(method1);
task.Start();
Task newTask = task.ContinueWith(method2);

private void method1()
{
    //
}
private void method2()
{
    //
}
```
- The `ContinueWith` is heavily overloaded, and can take `TaskContinuationOption` value parameters.
- `TaskContinuationOption` type is an enumeration that includes:
  - `NotOnCanceled`: continuation should only run only if the previous action completes and is not canceled.
    - `OnlyOnCanceled`: continuation should only run only if the previous action is canceled.
  - `NotOnFaulted`: continuation should only run only if the previous action completes and does not throw an unhandled exception.
    - `OnlyOnFaulted`: continuation should only run only if the previous action completes and does not throw an unhandled exception.
  - `NotOnRanToCompletion`: continuation should only run only if the previous action does not complete successfully (canceled or throw an exception).
    - `OnlyOnRanToCompletion`: continuation should only run only if the previous action complete successfully.

####  2.2.5. <a name='Synchronizetasks'></a>Synchronize tasks
- The `task` class provides the `Wait` method, which implements a simple task coordination mechanism.
  - It suspends execution of the current thread until the specified task completes.
  - An example is presented below:
  - 
``` cs
Task task = ...;
task.Start();

task.Wait();
```

- Two another methods can be used:
  - `WaitAll(task1,...)` waits until all specified tasks have completed
  - `WaitAny(task1,...)` waits until at least one of the specified tasks has completed
``` cs
Task task1 = ...;
Task task2 = ...;
task1.Start();
task2.Start();

task.WaitAll(task1, task2);
//or
task.WaitAny(task1, task2);
```

###  2.3. <a name='AbstractingtasksbyusingtheParallelclass'></a>Abstracting tasks by using the `Parallel` class
- the `Parallel` class:
  - Parallelize some common programming constructs without having to redesign an application.
  - Internally, creates its own `Task` objects, synchronize them automatically when they have completed.
  - It provides a small a set of static methods that you can use to indicade that code should be run in parallel if possible.

####  2.3.1. <a name='Parallel.For'></a>`Parallel.For`
- Loop in which iterations can run in parallel by using `tasks`.
- Specify:
  - `int startValue`
  - `int endValue`
  - Reference to `Method(int i)` that takes an interger parameter
- The method is executed for every value between the startValue and one below the endValue specified, and the parameter of the method is populated with an integer that specifies the current value.
- Recommended for **outer loops**
``` cs 
Parallel.For(startValue, endValue, Method);

private void Method(int i)
{
    // Perform loop processing
}
```
####  2.3.2. <a name='Parallel.ForEachT'></a>`Parallel.ForEach<T>`
- Specify:
  - A collection that implements the `IEnumerable<T>` generic interface
  - Reference to a method that takes a single parameter of type `T`

####  2.3.3. <a name='Parallel.Invoke'></a>`Parallel.Invoke`
- It executes a set of parameterless method calls as parallel tasks.
- Specify:
  - List of delegated methods calls (or lambda expressions)
    - These methods has no parameters and do not `return` values.

``` cs
Method1();
Method2();
Method3();

Parallel.Invoke(Method1, Method2, Method3);
```

###  2.4. <a name='RecomendatiosnforParallelclassuse'></a>Recomendatiosn for `Parallel` class use
- `Parallel` class parallelize CPU-bound, independend areas of code.
- If the methods are not CPU-bonded, parallelizing it might not improve performance
- Parallel operation should be independent (`thread-safe`)
- General rules:
  - `Parallel.For` and `Parallel.ForEach`:
    - Each iteration of the loop is independent
  - `Parallel.Invoke`:
    - Methods called are independent and application does not depend on them being run in a particular sequence.
    - For computational intensive operations


##  3. <a name='Cancellingtasksandhandlingexceptions'></a>Cancelling tasks and handling exceptions

- The `Task` class implements a `cooperative cancellation` strategy, which consist in:
  - Enable a task to select a convenient point to stop
  - Enable to undo any work that has performed before the cancellation if necessary.
  - A `cancellation token`, i.e., a structure that represents a request to cancle one or more tasks.
    - The method that a task runs should include a `System.Threading.CancellationToken` parameter.
    - To cancel the task sets the Boolean `IsCancellationRequested` to `true`
      - The method can query this property at various points during its processing. So if the property is true the method can undo any changes if necessary and then finish.
      - THe method should examine the `cancellation token` in a task frequently. At least every `10 ms`.
- It provides a **high degree of control** over the cancellation processing
- Multiple tasks can be cancelled by the same `cancellation token`
- Steps:
  1. Create a `System.Threading.CancellationTokenSource` object.
  2. Obtain a `CancellationToken` querying the `Token` property of previous object
  3. Pass the `CancellationToken` object as a parameter to any methods started by tasks that the software creates and runs.
  4. If the software needs to cancel the tasks: 
     1. Call the `Cancel` method of the `CancellationTokenSource` object. This method sets the `IsCancellationRequested` property of the `CancellationTokenSouce` passed to all the tasks.
     2. The method that is run by the task, queries the `IsCancellationRequested` property. If the property is `true` the method terminates.

``` cs
//Step1
CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
//Step2
CancellationToken cancellationToken = cancellationTokenSource.Token; 
//Step3
Task myTask = Task.Run(()=> Method(cancellationToken));

//...
if(someConditionToCancelTheTask)
{
    //Step4.1
    cancellationTokenSource.Cancel();
}


//Method run by the task
private void Method(CancellationToken token)
{
    //...
    if(token.IsCancellationRequested)
    {
        //Tidy up and Terminates the method
        return
    }
    //...
}
```

###  3.1. <a name='CancellingaParallel.ForandaParallel.ForEachloop'></a>Cancelling a `Parallel.For` and a `Parallel.ForEach` loop
- Steps:
  1. Pass a `ParallelLoopState` parameter to the method that is run by the `task`.
  2. Set a condition to stop.
     1. Call the `Stop` method of the `ParallelLoopState` parameter.
  
``` cs
Parallel.For(0,100,Method);

//Step1
private void Method(int i, ParallelLoopState p)
{
    //Step2
    if(...) 
    {
        //Step2.1
        p.Stop();
    }
}
```

###  3.2. <a name='HandlingtaskexceptionsbyusingtheAggregateExceptionclass'></a>Handling task exceptions by using the `AggregateException` class
- When a task is using `Task.Wait` methods, any exception thrown by the methods that tasks are running are grouped together into a `AggregateException` exception.
  - `AggregateException` acts as a wrapper for a collection of exceptions.
- To `catch` the specific exception, `AggregateException` provides the `Handle` method.
  - The `Handle` method takes a `Func<Exception, bool>` delegate which refereces a method that takes an `Exception` object as its parameter and returns a `bool`.
  - When `Handle` is called, the `referencedMethod` runs for each exception in the collection in the `AggregateException` object.
    - If the `referencedMethod` handles the exception, it returns `true`. Otherwise returns `false`
    - Any unhandled exception are bundled together into a new `AggregateException` exception, and this exception is thrown.
- A code example is presented below:

``` cs
try
{
    Task task1 = Task.Run(...);
    Task task2 = Task.Run(...);
    Task.WaitAll(task1,task2);    
}
catch (AggregateException ae)
{
    ae.Handle(referencedMethod)
}

private bool referencedMethod(Exception e)
{
    if(e is DivideByZeroException)
    {
        displayErrorMessage("Division by zero ocurred");
        return true;
    }
    if(e is IndexOutOfRangeException)
    {
        displayErrorMessage("Array of Index out of bounds");
        return true;
    }
    return false;
}
```

### Using continuations with canceled and faulted tasks
- To perform additional work when a task is canceled or raises an unhandled exception.
- Steps:
  1.  Use the `ContinueWith` 
      1.  Reference a method for the `cancellationWork`
      2.  Use appropriate `TaskContinuationOptions`. e.g., `OnlyOnCanceled`

``` cs
Task task = new Task(method1);
//Step1
task.ContinueWith(cancellationWork, TaskContinuationOptions.OnlyOnCanceled);
task.Start();

private void method1()
{

}
private void cancellationWork(Task task)
{
        
}
```