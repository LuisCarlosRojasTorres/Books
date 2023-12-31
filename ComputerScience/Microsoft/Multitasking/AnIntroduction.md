
## Running tasks asynchronously

### Running tasks synchronously
``` cs 
using System.Diagnostics;

using System;
using System.Threading.Tasks.Dataflow;

Console.WriteLine(" RUNNING METHODS SYNCHRONOULY");
OutputThreadInfo();
Stopwatch timer = Stopwatch.StartNew();

// Os metodos sao chamados sequencialmente
MethodA();
MethodB();
MethodC();
Console.WriteLine($" Time elapsed: {timer.ElapsedMilliseconds:#,##0}ms");

//Methods
static void OutputThreadInfo()
{
    Thread t = Thread.CurrentThread;

    Console.WriteLine(
        " >> Thread id: {0}, Priority: {1}, Background: {2}, Name: {3}",
        t.ManagedThreadId, t.Priority, t.IsBackground, t.Name ?? "null"
    );    
}

static void MethodA()
{
    Console.WriteLine(" >>>>>>>>>>>>>>>>>>>>>>>");
    Console.WriteLine(" >> Starting Method A...");
    OutputThreadInfo();
    Thread.Sleep(3000);
    Console.WriteLine(" >> Finished Method A...");
}

static void MethodB()
{
    Console.WriteLine(" >>>>>>>>>>>>>>>>>>>>>>>");
    Console.WriteLine(" >> Starting Method B...");
    OutputThreadInfo();
    Thread.Sleep(2000);
    Console.WriteLine(" >> Finished Method B...");
}

static void MethodC()
{
    Console.WriteLine(" >>>>>>>>>>>>>>>>>>>>>>>");
    Console.WriteLine(" >> Starting Method C...");
    OutputThreadInfo();
    Thread.Sleep(1000);
    Console.WriteLine(" >> Finished Method C...");
}
```

- A saida do programa eh apresentada a seguir

```
 RUNNING METHODS SYNCHRONOULY
 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method A...
 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >> Finished Method A...
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method B...
 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >> Finished Method B...
 >>>>>>>>>>>>>>>>>>>>>>>
 >> Starting Method C...
 >> Thread id: 1, Priority: Normal, Background: False, Name: null
 >> Finished Method C...
 Elapsed time: 6,003ms
```

- Como esperado o tempo que demorou foi de aprox: `3000 + 2000 + 1000 = 6000` milliseconds.

### Running multiple methods asynchronously using tasks

