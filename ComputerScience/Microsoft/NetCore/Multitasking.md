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
* 3. [Cancelling tasks and handling exceptions](#Cancellingtasksandhandlingexceptions)

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
##  3. <a name='Cancellingtasksandhandlingexceptions'></a>Cancelling tasks and handling exceptions

