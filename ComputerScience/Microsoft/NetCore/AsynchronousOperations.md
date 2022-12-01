<!-- vscode-markdown-toc -->
* 1. [Why](#Why)
* 2. [Implementing Asynchronous methods](#ImplementingAsynchronousmethods)
	* 2.1. [Defining Asynchronous methods: The problem](#DefiningAsynchronousmethods:Theproblem)
	* 2.2. [Defining Asynchronous methods: The solution](#DefiningAsynchronousmethods:Thesolution)
	* 2.3. [Defining Asynchronous methods that return values](#DefiningAsynchronousmethodsthatreturnvalues)
	* 2.4. [Asynchronous methods gotchas](#Asynchronousmethodsgotchas)
	* 2.5. [Tasks, memory allocation and efficiency](#Tasksmemoryallocationandefficiency)
* 3. [Using PLINQ to parallelize declarative data access](#UsingPLINQtoparallelizedeclarativedataaccess)
* 4. [Synchronizing concurrent access to data](#Synchronizingconcurrentaccesstodata)
	* 4.1. [Locking data](#Lockingdata)
	* 4.2. [Synchronization primitives for coordinating tasks](#Synchronizationprimitivesforcoordinatingtasks)
	* 4.3. [Cancelling Synchronization](#CancellingSynchronization)
	* 4.4. [The concurrent collection classes](#Theconcurrentcollectionclasses)
	* 4.5. [Using a concurrent collection and a lock to implement thread-safe data access](#Usingaconcurrentcollectionandalocktoimplementthread-safedataaccess)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Why'></a>Why 

Two reasons:
- To Improve responsiveness: Do many things simultanously. `Tasks` achieve this, performing operations in parallel and improving throughput in compute-bound applications.
- To Improve scalability: Decompose a process to be performed in parallel and run concurrently. `Asynchronous operations` achieve this, leaving the user interface thread free to handle user interactions.
  - Responsiveness is important! UI operates by using a single thread of execution. User expects an application to respond when they interact with the UI, even if the application is currently *performing a large and complex calculation*.
  - Blocking user interaction while waiting for an ` ` that might take an indeterminate time to happen IS NOT A GOOD PRACTICE!


##  2. <a name='ImplementingAsynchronousmethods'></a>Implementing Asynchronous methods
- An `Asynchronous method`: 
  - it does not block the current thread on which it starts to run.
  - when called:
    1. return control to the calling environment
    2. it uses a background thread, enabling the caller to continue running on the current thread.
- It uses:
  - `async` method modifier:
  - `await` operator: it releases the current thread and wait for a task to complete in the background. When the task finishes, control return to the method which continues the next statement.


###  2.1. <a name='DefiningAsynchronousmethods:Theproblem'></a>Defining Asynchronous methods: The problem
- If a very time consuming process is invoked from the UI (i.e., by clicking something), the UI will become unresponsive until this method completes.
- In the example below:
  - To change the `message.Text`, the software shall complete the three methods before.

``` cs
private verySlowMethod()
{
    fistLongOperation();
    secondLongOperation();
    thirdLongOperation();

    message.Text = "Process completed" // UI - command
}
```
###  2.2. <a name='DefiningAsynchronousmethods:Thesolution'></a>Defining Asynchronous methods: The solution
- Use instead:
  - `async` modifier: indicated that a method continas functionality that can be run asynchronously.
  - `await` operator: specifies the points at which this asynchronouly functionality should be performed.
- The solution to the method in the previous section is presented below:

``` cs
private async verySlowMethod()
{
    await method1();
    await method2();
    await method3();

    message.Text = "Process completed" // UI - command
}
//long operations
private void method1()
{
    //...
}
private void method2()
{
    //...
}
private void method3()
{
    //...
}
```

This code is pretty similar to the original version.
- When the `C#` compiler encounters the `await` operator in an `async` method, it reformats the operand that follows this operator as a tasks that runs on the **same thread** as the `async` method.
  - The remainder of the code is converted into a continuation that runs when the task completes, again **running on the same thread!!!**.
  - `await` operator can only be used inside `async` methods.
- The structure for an `await` statement is:
  - `await awaitableObject;`
  - where `awaitableObject` shall be a `Task` or a method that `return` it. So the methods shall be modified as presented below:

``` cs
private Task method1()
{
    Task t = Task.Run(() => {/* code from original version of the method*/});
    return t
}
```

- In case that the `method` can be decomposed into more than one `Tasks`, it shall be modified as follows:
``` cs
private async Task method1()
{
    Task t1 = Task.Run(() => {/* first part of the code from original version of the method*/});
    Task t2 = Task.Run(() => {/* second part of the code from original version of the method*/});
    
    await t1;
    await t2;
  // No return statement is required!
}
```
- NOTE1: No `return` statements is required in the `async Task` method.
- NOTE2: If you don't include an `await` statement in an `async` method, the method is simply a reference `Task`  thet performs the code in the body of the method. So, ***IT DOES NOT ACTUALLY RUN ASYNCHRONOUSLY**


###  2.3. <a name='DefiningAsynchronousmethodsthatreturnvalues'></a>Defining Asynchronous methods that return values

###  2.4. <a name='Asynchronousmethodsgotchas'></a>Asynchronous methods gotchas

###  2.5. <a name='Tasksmemoryallocationandefficiency'></a>Tasks, memory allocation and efficiency

##  3. <a name='UsingPLINQtoparallelizedeclarativedataaccess'></a>Using PLINQ to parallelize declarative data access

##  4. <a name='Synchronizingconcurrentaccesstodata'></a>Synchronizing concurrent access to data

###  4.1. <a name='Lockingdata'></a>Locking data

###  4.2. <a name='Synchronizationprimitivesforcoordinatingtasks'></a>Synchronization primitives for coordinating tasks

###  4.3. <a name='CancellingSynchronization'></a>Cancelling Synchronization

###  4.4. <a name='Theconcurrentcollectionclasses'></a>The concurrent collection classes

###  4.5. <a name='Usingaconcurrentcollectionandalocktoimplementthread-safedataaccess'></a>Using a concurrent collection and a lock to implement thread-safe data access