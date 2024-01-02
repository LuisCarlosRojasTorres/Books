## What is it?
- Events are something that occurs in a program.
  - An `event` has an encapsulated `delegate`.
        
## What is its purpose?
- Events allow a class or object to notify other classes or objects when something occurs.
      
## Important Concepts
- Publisher: The class that raises (or sends) the event.
- Subscriber: The classes that receive (or handle) the event are called subscribers. 
  - EventHandler: the method of the classes that handle the event.

- For a events that dont pass data to subscribers the signature of the `EventHandler` is the following:
``` cs 
public delegate void EventHandler(object sender, EventArgs e);
```

### How to use: without parameters
- Create a publisher class with an `EventHandler`:
  - `EventArgs.Empty` provides a value to use with an event that does not have event data.

``` cs 
class DummyPublisher
{
    public event EventHandler dummyEvent;

    public void DummyMethod()
    {
        Console.WriteLine(" - DummyMethod");
        
        // If there are methods referenced in the delegate:
        // Otherwise nothing happens
        if(dummyEvent != null)
        {
            dummyEvent(this, EventArgs.Empty);
        }
   
```

- Create a subscriber class with a method with the same signature of the `EventHandler`

``` cs 
class DummySubscriber
{
    //Same EventHandler signature
    public static void SubscriberMethod(object sender, EventArgs e)
    {
        Console.WriteLine($" - SubscriberMethod");
    }}
```

- Reference the `SubscriberMethod` to `EventHandler` delegate:

``` cs 
class Program
{
    static void Main(string[] args)
    {
        var dummyPublisher = new DummyPublisher();

        // Reference to EventHandler delegate
        dummyPublisher.dummyEvent += DummySubscriber.SubscriberMethod;        

        //Raise the event
        dummyPublisher.DummyMethod();
    }
}
```

### How to use: with parameters

