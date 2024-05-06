# CalcOpener

A proof of concept DLL file compiled with Visual Studio 2012, designed for penetration testers and IT security professionals. This DLL, when executed, launches the Windows Calculator (calc.exe) using the CreateProcess function.

## Compile it by yourself
Open Visual Studio 12 --> clone respository --> create --> new build.

## Use the compiled version provided
Under "Release", download the compiled DLL file, and run it like:

```
rundll32.exe calc_opened.dll,DllMain
```
This serves as a demonstration of how DLLs can be utilized for simple execution tasks and can be used as a proof of concept instead of employing actual shellcode.
