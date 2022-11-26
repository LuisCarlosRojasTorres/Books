<!-- vscode-markdown-toc -->
* 1. [Creating Methods](#CreatingMethods)
	* 1.1. [Method declaration](#Methoddeclaration)
	* 1.2. [Expression-bodied methods](#Expression-bodiedmethods)
* 2. [Understanding Scope](#UnderstandingScope)
	* 2.1. [Local Scope](#LocalScope)
	* 2.2. [Overloading methods](#Overloadingmethods)
* 3. [Nesting methods](#Nestingmethods)
* 4. [Optional parameters and named arguments](#Optionalparametersandnamedarguments)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='CreatingMethods'></a>Creating Methods
- A `method` is a named sequence of statements.
- Its name should be a meaningful identifier that indicates its overall purpose.

###  1.1. <a name='Methoddeclaration'></a>Method declaration
- Its syntax is presented below:

``` cs
returnType NameOfTheMethod  (parameterType1 parameter1, ...){
	// Body of the method
}
```

- If the method does not return a value, its `returnType` is `void`.
- If the method return a value, its `returnType` shall be the variable type that `returns`.

``` cs 
int Test(int a, int b) { //returnType is int
    return a + b; // returns an int
}
```

###  1.2. <a name='Expression-bodiedmethods'></a>Expression-bodied methods
- For methods that:
  - are very simple
  - performing a single task
  - or returning the results of a calculation without involving any additional logic.
- They can still take parameters and return values.
- Its syntax is presented below:

``` cs
returnType NameOfTheMethod  (parameterType1 parameter1, ...){
	// Body of the method
}
```

- If the method does not return a value, its `returnType` is `void`.
- If the method return a value, its `returnType` shall be the variable type that `returns`.

``` cs 
// Common method
int Test(int a, int b) {
    return a + b; 
}
// expression bodied method
int Test(int a, int b) => a + b;
```

- Differences:
  - The use of `=>` operator to reference the expression that forms the body of the method.
  - Absence of `return` a statement.
  - NO DIFFERENCE in functionality, is merely a syntactic convenience.

##  2. <a name='UnderstandingScope'></a>Understanding Scope
- The scope of a variable is simply the region of the program in which that variable is usable.
- The `{ }` that form the body of a method define the scope of the method.
  - Any variables declared inside the body are scoped to the method; they disappear when the method ends and can be accessed only by the code running in that method i.e., `local variables`.

##  3. <a name='Nestingmethods'></a>Nesting methods
- When you want to break a large method into smaller pieces.
  - Each piece can b implemented as a `helper` method.
  - Its `helper` methods has `local scope`, so it only be called inside the larger method.
    - This prevents `helper` methods to be called accidentally. 

``` cs
int Test3(int a, int b, int c)
{
    int Test2(int a, int b) { //helper method
        return a + b;
    }

    //return a + b + c;
    return Test2(a, Test2(b, c));
}

Console.WriteLine(Test3(4, 5, 6));
```

## Recursive Methods 

``` cs
long Factorial(int value)
{    
	if(value == 1 && value > 0){
		return 1;
	}
	else{
		return value*Factorial(value-1);
	}    
}
```
##  4. <a name='Optionalparametersandnamedarguments'></a>Optional parameters and named arguments
- Parameters with `=` are called `optional parameters` e.g., `int a = 3`.
- if no value is given to `optional parameters`, it will take the values defined in the method definition
- You shall specify all mandatory parameters before any `optional parameters`.
- Two examples of methods with `optional parameters` are presented below.

``` cs
int Test2(int a, int b=5, int c=7)
{
    return a + (b * c);
}

int Test3(int a=3, int b=5, int c=7)
{
    return a + (b * c);
}
```
- Example of methods callings with `optional parameters`
``` cs
Console.WriteLine(Test3()); //a=3, b=5, c=7 result 38
Console.WriteLine(Test3(11)); //a=11, b=5, c=7 result 46
Console.WriteLine(Test3(11,13)); //a=11, b=5, c=7 result 102
``` 

- Example of methods callings with `named arguments`
``` cs
//named arguments
Console.WriteLine(Test3(b: 3)); //a=3,b=3,c=7 returns 24
Console.WriteLine(Test3(c: 11)); //a=3,b=5,c=11 returns 58
``` 