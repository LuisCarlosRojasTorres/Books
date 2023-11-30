A bash which needs an argument.

``` bash
#!/bin/bash

VAR=${1}

if [ ${VAR} -eq 1 ] ; then
   echo "LOBO LOBO LOBO"
   exit 0
elif [ ${VAR} -eq 2 ] ; then
   echo "TIAA RUFAAA"
   exit 0
else 
   echo "RUFITO"
   exit 1
fi
```

- csharp code to call the bash
``` cs
using System.Diagnostics;

ProcessStartInfo info = new ProcessStartInfo();
info.FileName = "Test.bash";
info.Arguments = "1";
info.UseShellExecute = false;
info.RedirectStandardOutput = true;

Process process= new Process();
process.StartInfo = info;

process.Start();

StreamReader streamReader= process.StandardOutput;

Console.WriteLine($" EROR CSHarp : {streamReader.ReadLine()}");
```
