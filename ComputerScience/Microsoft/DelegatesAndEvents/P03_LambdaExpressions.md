## What is it?
- It is an improved **anonymous method**.
        
## What is its purpose?
- To be used with a `delegate`.
  - It is better for writing code.
        
## Important Concepts
- It uses `=>` aka the `lambda operator`
- It has to types:
  - Expression lambda: `(<type1> i1, <type2> i2, ...) => expression`    
  - Statement lambda: `(parameters) => { statement1; }`    
- If there is no parameters: `() => `

### How to use

#### Expression lambda
- Sintax `(<type1> i1, <type2> i2, ...) => expression`

``` cs
//Lambda: (int x) => x * x;
var square = (int x) => x * x;
```

#### Statement lambda
- Sintax: `(parameters) => { statement1; }`

``` cs
var square = (int x) =>
{
    return x * x;
};
```

#### Capturing outer variables
- **Use outer variables incurs small performance.**
- It can use any variables including local variables, parameters, and members that are accessible from the location where the lambda expression is defined.

```
int factor = 5;
var multiplier = (int x) => x * factor;
var result = multiplier(5);
Console.WriteLine(result); // 25
```

- NOTE: It’s important to note that the lambda expression evaluates the captured variables when it is executed, not when the variables were captured. For example:

#### Static lambda expressions
- It is only to ensure that the lambda expression does not capture any variable.

``` cs
var square = static (int x) => x * x;
```