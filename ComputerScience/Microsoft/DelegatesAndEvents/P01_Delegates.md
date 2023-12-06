
## What is it?
- It holds references to methods with the **same signature** (same arguments and return type).
      
## What is its purpose?
- To define **callback methods**
    - You can pass a method as arguments to other methods using `delegates`.
     
## Important Concepts
- It is define using the following syntax `delegate <type> <MethodName>(<Type1> t1, <Type2> t2...)`   

### How to use
- Create a delegate:

``` cs 
delegate void DummyDelegate(string input);
```
### Use1

``````