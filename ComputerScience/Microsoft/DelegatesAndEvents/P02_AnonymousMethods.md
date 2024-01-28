## What is it?
- A non-explicitly created method.
        
## What is its purpose?
- To be used with a `delegate`
  - It is recomended when defining a new method is not necessary because you only use it once. 
      
## Important Concepts
- Sintax:

``` cs
delegate (<type> input>) { return <implementation>};
```

### How to use
- To use it with a `delegate`:

``` cs 
delegate int DummyDelegate(int x);

class Program
{
    public static void Main(string[] args)
    {
        DummyDelegate dummyDelegate = delegate (int x) { return x * x; };

        Console.WriteLine(dummyDelegate(5)); // 100
    }
}
```
