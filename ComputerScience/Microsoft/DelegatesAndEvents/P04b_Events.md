## What is it?
- How to implement a class with many events
        
## What is its purpose?
- To implement a class which runs independently but shall notify to other classes about its internal state.
      
## Important Concepts
- The key is to keep in mind all the signatures of the delegates e.g.:

``` cs
delegate void Dummy1EventHandler();
delegate int Dummy2EventHandler(int a, int b);
```

### How to use
1. Create the `delegates` for the program

``` cs 
delegate void Dummy1EventHandler();
delegate int Dummy2EventHandler(int a, int b);
```

2. Create a publisher which have `EventsHandlers` for te delegates and methods that call the `EventHandlers`

``` cs 
class DummyPublisher
{
    // An Event has a delegate encapsulated
    public event Dummy1EventHandler? dummy1EventHandler;
    public event Dummy2EventHandler? dummy2EventHandler;

    public void DummyMethod1()
    {
        Console.WriteLine(" - DummyPublisher: DummyMethod1");

        if (dummy1EventHandler != null)
        {
            dummy1EventHandler();
        }
    }

    public void DummyMethod2(int a, int b)
    {
        Console.WriteLine(" - DummyPublisher: DummyMethod2");

        if (dummy2EventHandler != null)
        {
            dummy2EventHandler(a,b);
        }
    }
}
```

3. Create a subscriber with methods with same signature as `delegates`

``` cs
class DummySubscriber
{
    public static void SubscriberMethod1()
    {
        Console.WriteLine(" - DummySubscriber: SubscriberMethod1");
    }

    public static int SubscriberMethod2(int a, int b)
    {
        Console.WriteLine(" - DummySubscriber: SubscriberMethod2 with data");
        Console.WriteLine($" - DummySubscriber: a = {a}");
        Console.WriteLine($" - DummySubscriber: b = {b}");
        Console.WriteLine($" - DummySubscriber: result = {a+b}");
        return a + b;
    }
}
```

4. Assign the `subscriberMethods` to `publisherEventHandlers`. Then call the methods.

``` cs
static void Main(string[] args)
{
    var dummy = new DummyPublisher();

    dummy.dummy1EventHandler += DummySubscriber.SubscriberMethod1;
    dummy.dummy2EventHandler += DummySubscriber.SubscriberMethod2;
    
    dummy.DummyMethod1();
    int var1 = 5, var2 = 7;
    dummy.DummyMethod2(var1, var2);
}
```

- FullCode

``` cs 
internal class Program
{
    delegate void Dummy1EventHandler();
    delegate int Dummy2EventHandler(int a, int b);

    class DummyPublisher
    {
        // An Event has a delegate encapsulated
        public event Dummy1EventHandler? dummy1EventHandler;
        public event Dummy2EventHandler? dummy2EventHandler;

        public void DummyMethod1()
        {
            Console.WriteLine(" - DummyPublisher: DummyMethod1");

            if (dummy1EventHandler != null)
            {
                dummy1EventHandler();
            }
        }

        public void DummyMethod2(int a, int b)
        {
            Console.WriteLine(" - DummyPublisher: DummyMethod2");

            if (dummy2EventHandler != null)
            {
                dummy2EventHandler(a,b);
            }
        }
    }

    class DummySubscriber
    {
        public static void SubscriberMethod1()
        {
            Console.WriteLine(" - DummySubscriber: SubscriberMethod1");
        }

        public static int SubscriberMethod2(int a, int b)
        {
            Console.WriteLine(" - DummySubscriber: SubscriberMethod2 with data");
            Console.WriteLine($" - DummySubscriber: a = {a}");
            Console.WriteLine($" - DummySubscriber: b = {b}");
            Console.WriteLine($" - DummySubscriber: result = {a+b}");
            return a + b;
        }
    }

    static void Main(string[] args)
    {
        var dummy = new DummyPublisher();

        dummy.dummy1EventHandler += DummySubscriber.SubscriberMethod1;
        dummy.dummy2EventHandler += DummySubscriber.SubscriberMethod2;
            
        dummy.DummyMethod1();
        int var1 = 5, var2 = 7;
        dummy.DummyMethod2(var1, var2);
    }
}
```