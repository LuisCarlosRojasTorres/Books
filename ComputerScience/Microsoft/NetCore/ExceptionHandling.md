<!-- vscode-markdown-toc -->
* 1. [Trying code and catching exceptions](#Tryingcodeandcatchingexceptions)
	* 1.1. [Filtering Exceptions](#FilteringExceptions)
* 2. [Throwing exceptions](#Throwingexceptions)
* 3. [Using `throw` exceptions](#Usingthrowexceptions)
* 4. [Using `finally` block](#Usingfinallyblock)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

- Applications shall be capable of detecting failures and handling them. Two options:
  - Taking appropriate corrective actions
  - Reporting the reasons for the failure in the clearest possible way to the user.
- `try`, `catch` and `finally` statements are used with this purpose.


##  1. <a name='Tryingcodeandcatchingexceptions'></a>Trying code and catching exceptions
- Using `exceptions` and `exception handlers` separates the `errror handling code` from the code that implements the `primary logic of a program`.
- Two things are needed:
  - `try` block:
    - Write the code inside the `try` block.
    - If an error condidiont occurs, execution jumps out of the `try` block to a code designed to `catch` and `handle` the exception.
  - `catch` handlers:
    - It is intended to capture and handle a specific type of exception.
    - You can have multiple `catch` handler after a `try` block. Each one design to trap and process a specific exception.
    - So, if any of the statements in the `try` block causes an `error`, the runtime throws an `exception`. The runtime then examines the `catch` handlers after the `try` block and transfer control directly to the first matching handler.
- An example of the `try-catch` structure is presented below:
``` cs
try
{
    //Statements
}
catch(ExceptionType ex)
{
    //Exception Handlers
    //When a ExceptionType is thrown, the ex variable is populated with an object containing the details of the exception.
}
catch(ExceptionType2 ex)
{
    //Exception Handlers    
}
catch(ExceptionType3 ex)
{
    //Exception Handlers    
}
```
- Once the `catch` handler finishes, the program continues with the first statement that follows the handler.
- If no handler corresponds to the exception, It is called `unhandled`.
- When a ExceptionType is thrown, the ex variable is populated with an object containing the details of the exception.
- `exceptions` are organized into families called `inheritance hierarchies`
  - The general catch handles is called `exception`, you can use it to resume many exceptions in only one.
  - The code presented previously can be compacted into:

``` cs
try
{
    //Statements
}
catch(Exception ex) // General catch handler
{
    //Exception Handlers    
}
```
- When an exception occurs, the runtime uses the first handler it finds that matches the exception and the others are ignored.
    - It is a good practice put more specific `Exceptions` on top and the geneal catch handler at the end.

###  1.1. <a name='FilteringExceptions'></a>Filtering Exceptions
- It is possible to use `catch` handlers only under specific conditions.
  - This conditions are boolean values.

``` cs
bool catchErrors = ...;
try
{
    //...
}
catch(Exception ex) when (catchErrors == true)
{
    //Only handle exceptions if the catchedErrors is true
}
```
##  2. <a name='Throwingexceptions'></a>Throwing exceptions
- In case of a method receives an invalid input, the best practice recommends to `throw an exception`
- This is accomplished using the `throw` keyword and an exception object to throw.

``` cs
Console.WriteLine("1-10 value:");
int value;
value = Convert.ToInt32(Console.ReadLine());

Console.WriteLine($"value:{value}");

if (value > 0 && value < 11)
{
    Console.WriteLine("ok");
}
else {
    // 
    throw new ArgumentException("Too much!!");
}
```

- A more professional implementation requires insert the previous code into a `try` block.

``` cs 
Console.WriteLine("1-10 value:");
int value;
value = Convert.ToInt32(Console.ReadLine());

Console.WriteLine($"value:{value}");

try
{
    if (value > 0 && value < 11)
    {
        Console.WriteLine("ok");
    }
    else
    {
        throw new ArgumentException("Too much!!");
    }
}
catch (ArgumentException aex)
{
    Console.WriteLine("Rufo");
    Console.WriteLine(aex.Message);
}
```

##  4. <a name='Usingfinallyblock'></a>Using `finally` block
- It is always run, whether or not an exceptionhas been thrown.
- A `finally` block occurs immediately after a `try` block or immediately after the last `catch`
- A complete example of `exception handling` which includes `try`, `catch`, `throw` and `finally` is presented below:

``` cs
Console.WriteLine("1-10 value:");
int value;
value = Convert.ToInt32(Console.ReadLine());

Console.WriteLine($"value:{value}");

try
{
    if (value > 0 && value < 11)
    {
        Console.WriteLine("ok");
    }
    else
    {
        throw new ArgumentException("Too much!!");
    }
}
catch (ArgumentException aex)
{
    Console.WriteLine("Rufo");
    Console.WriteLine(aex.Message);
}
finally 
{
    Console.WriteLine("This statement always executes");
}
```
