<!-- vscode-markdown-toc -->
* 1. [if-else](#if-else)
	* 1.1. [Ternary operator](#Ternaryoperator)
* 2. [switcch-case](#switcch-case)
* 3. [Loops](#Loops)
	* 3.1. [while](#while)
	* 3.2. [do While](#doWhile)
	* 3.3. [for](#for)
	* 3.4. [ranged-based for loop](#ranged-basedforloop)
* 4. [breaks-continue](#breaks-continue)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='if-else'></a>if-else

``` cpp
if (booleanExpression)
{
	//Code here
}
else if(booleanExpression)
{
	//Code here
}
else
{
	//Code here
} 
```

###  1.1. <a name='Ternaryoperator'></a>Ternary operator

`<dummyVariable> = <booleanCondition> ? valueIfTrue : valueIfFalse;`


##  2. <a name='switcch-case'></a>switcch-case
- It evalueates the different possibilities of a single variable.
- LIMITATION? it can only be used with whole numbers and `enum` values. 
  - NO `string`
  - NO `float`
- `break`: signals the end of the code for a specific case.

``` cpp 
switch (condition)
{
	case value1:
		// Code here.
	break;
	case value2:
		// Code here.
	break;
	// ...
	default:
		// THis code is called if non of the other cases match
	break/
}
```
##  3. <a name='Loops'></a>Loops

###  3.1. <a name='while'></a>while

``` cpp
while(booleanExpression)
{
	//Code here
}
```

###  3.2. <a name='doWhile'></a>do While

``` cpp
do
{

}
while(booleanExpression);
```

###  3.3. <a name='for'></a>for

``` cpp
for (int i = 0; i < n; i++)
{

}
```

###  3.4. <a name='ranged-basedforloop'></a>ranged-based for loop
- For collection:

``` cpp
for (int i : collection)
{
	// Source code
}
```

##  4. <a name='breaks-continue'></a>breaks-continue
- `break`: exits the current loop
- `continue`: skip over the current loop iteration but remain in the loop.