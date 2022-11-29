<!-- vscode-markdown-toc -->
* 1. [Implementing Asynchronous methods](#ImplementingAsynchronousmethods)
	* 1.1. [Defining Asynchronous methods: The problem](#DefiningAsynchronousmethods:Theproblem)
	* 1.2. [Defining Asynchronous methods: The solution](#DefiningAsynchronousmethods:Thesolution)
	* 1.3. [Defining Asynchronous methods that return values](#DefiningAsynchronousmethodsthatreturnvalues)
	* 1.4. [Asynchronous methods gotchas](#Asynchronousmethodsgotchas)
	* 1.5. [Tasks, memory allocation and efficiency](#Tasksmemoryallocationandefficiency)
* 2. [Using PLINQ to parallelize declarative data access](#UsingPLINQtoparallelizedeclarativedataaccess)
* 3. [Synchronizing concurrent access to data](#Synchronizingconcurrentaccesstodata)
	* 3.1. [Locking data](#Lockingdata)
	* 3.2. [Synchronization primitives for coordinating tasks](#Synchronizationprimitivesforcoordinatingtasks)
	* 3.3. [Cancelling Synchronization](#CancellingSynchronization)
	* 3.4. [The concurrent collection classes](#Theconcurrentcollectionclasses)
	* 3.5. [Using a concurrent collection and a lock to implement thread-safe data access](#Usingaconcurrentcollectionandalocktoimplementthread-safedataaccess)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='ImplementingAsynchronousmethods'></a>Implementing Asynchronous methods

###  1.1. <a name='DefiningAsynchronousmethods:Theproblem'></a>Defining Asynchronous methods: The problem

###  1.2. <a name='DefiningAsynchronousmethods:Thesolution'></a>Defining Asynchronous methods: The solution

###  1.3. <a name='DefiningAsynchronousmethodsthatreturnvalues'></a>Defining Asynchronous methods that return values

###  1.4. <a name='Asynchronousmethodsgotchas'></a>Asynchronous methods gotchas

###  1.5. <a name='Tasksmemoryallocationandefficiency'></a>Tasks, memory allocation and efficiency

##  2. <a name='UsingPLINQtoparallelizedeclarativedataaccess'></a>Using PLINQ to parallelize declarative data access

##  3. <a name='Synchronizingconcurrentaccesstodata'></a>Synchronizing concurrent access to data

###  3.1. <a name='Lockingdata'></a>Locking data

###  3.2. <a name='Synchronizationprimitivesforcoordinatingtasks'></a>Synchronization primitives for coordinating tasks

###  3.3. <a name='CancellingSynchronization'></a>Cancelling Synchronization

###  3.4. <a name='Theconcurrentcollectionclasses'></a>The concurrent collection classes

###  3.5. <a name='Usingaconcurrentcollectionandalocktoimplementthread-safedataaccess'></a>Using a concurrent collection and a lock to implement thread-safe data access