# Graph
A Graphing tool written with FreeGLUT

# Table of Contents
1. [Build and Run](#build)
2. [Usage](#use)
3. [Possible Functions](#fun)
4. [Warnings](#warnings)

# Build and Run <a name=build></a>
To build simply execute: 
`. build`

To run `./graph`

**NOTE: In older hardware, this may give SIGSEGV. So I would suggest you run it with GDB (***GNU Debugger***)**

```
$ gdb -ex=r --args ./graph <optional args>
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
Starting program: ./graph 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff6170640 (LWP 18579)]
[New Thread 0x7ffff596f640 (LWP 18580)]
[New Thread 0x7ffff516e640 (LWP 18581)]
[New Thread 0x7ffff496d640 (LWP 18582)]
```

# Usage <a name=use></a>
In order to graph a function, you must write the function interms of `i`
in the C++ format. Possible functions are listed bellow.
Then you must rebuild the program. Example:
```
example.dat:
1 pow(i, 3)
2   + log(i);
```

# Possible Functions: <a name=fun></a>
## All unary operators are allowed
## C++ Specific functions
```
acos(a); inverse cosine of a
asin(a); inverse sine of a
atan(a); inverse tangent of a
atan2(a, b); inverse tan of (a / b)
ceil(a); ceil value of a
cos(a); cosine of a
cosh(a); cosine hyperbolic of a
exp(a); e^a
fabs(a); absolute value of a
floor(a); floor value of a
fmod(a); modulus of a
frexp(); Avoid this function unless you know how to handle it
ldexp(); Avoid this function unless you know how to handle it
log(a); natural log (log base e) of a
log10(); log base 10 of a
modf(); Avoid this function unless you know how to handle it
pow(a, b); raise a to the power of b
sin(a); sine of a
sinh(a); sine hyperbolic of a
sqrt(a); square root of a
tan(a); tangent of a
tanh(a); tangent hyperbolic of a
```
# **Warnings** <a name=warnings></a>
**The Rendering gets broken when the window gets fiddled upon (minimize, resize, etc.).**