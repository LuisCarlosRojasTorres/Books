## What is it?
- Events are something that occurs in a program.
  - An `event` has an encapsulated `delegate`.
        
## What is its purpose?
- Events allow a class or object to notify other classes or objects when something occurs.
      
## Important Concepts
- Publisher: The class that raises (or sends) the event.
- Subscriber: The classes that receive (or handle) the event are called subscribers. 
  - EventHandler: the method of the classes that handle the event.

- For a events that dont pass data to subscribers:
``` cs 
public delegate void EventHandler(object sender, EventArgs e);
```

### How to use: without parameters

### How to use: with parameters

