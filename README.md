# Graph
A Graphing tool written with GLUT

# Build and Run
To build simply execute: 
`. build`

To run `./graph`

**NOTE: In older hardware, this may give SIGSEGV. So I would suggest you run it with GDB (***GNU Debugger***)**

**First run**
`gdb ./graph`
**. You will be prompted with a shell. Then type**
`r`
**, which will run the program.**
```
$ gdb ./graph
GNU gdb (GDB) 10.2
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-pc-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./graph...
(No debugging symbols found in ./graph)
(gdb) r # Type r to run
Starting program: ./graph 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff6171640 (LWP 8957)]
[New Thread 0x7ffff5970640 (LWP 8958)]
[New Thread 0x7ffff516f640 (LWP 8959)]
[New Thread 0x7ffff496e640 (LWP 8960)]
```

# Usage
The default graph will be y = x^2. But if a file is specified as an argument, it will plot those points.