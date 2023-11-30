// See https://aka.ms/new-console-template for more information
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




