# Java

## Basic Java tools

Most Java developers use an IDE to edit and compile Java code.  The IDE simplifies
build and run tasks by executing the compiler and Java runtime with the correct
arguments.

If you have a grasp of how the compiler works from the command line, configuring
your IDE will be easy.  If you aren't familar with the command line tools, using an IDE
will be a random and confusing experience.  Consequently we're going to write a few
short programs using a text editor and the command line tools directly.

For this section, use a normal text editor like vim or emacs.  Do not use an IDE.

We will be using the following command line tools that are included with the JDK:

* javac - Java compiler: compiles .java files to .class files
* java - Java virtual machine. Runs .class files
* jar - Java archive. Tool that packages directories into a .jar file (similar to a ZIP file)

### Classes, compilation, and execution

Tasks:

* Create a "src" directory that will store your .java files
* Write a file called "Hello.java" in the src dir with a main method that prints "hello world"
* In a shell:
  * cd to the src dir
  * Use "javac" to compile Hello.java:  javac Hello.java
  * Use "java" to run Hello.class: java Hello

Questions:

* What file(s) does the compiler (javac) generate on disk?

##Hello.class

* If you cd up a directory (so that you're in the parent of the src dir), can you still run Hello?
  * Hint: Run "java -help" - try the "-cp" switch

##java -cp src/ Hello

* Do you still need the .java file in order to run the compiled Hello program?
  * Hint: try moving the Hello.java file to /tmp and re-run the program, then move Hello.java back to src

##No you dont

### Packages and classpath

Tasks:

* Create an "out" directory that is a peer to the "src" directory

```
    ./
      src/
      out/
```

* Create a subdirectory in "src" called "calc":  mkdir -p src/calc
* Create a file "src/calc/Calc.java" and paste in the lines below:

```
package calc;
public class Calc {
    public static int add(int a, int b) {
        return a+b;
    }
}
```

* Edit "src/Hello.java" and add this line to the top of the file:

`import calc.Calc;1

* Edit "src/Hello.java" and add this line inside your existing main() method:

`System.out.println("10 + 100 = " + Calc.add(10, 100));`

Questions:

* How do you compile Calc.java?

##javac calc/Calc.java

* Can you still compile Hello.java?  If not, what's the error?

##Yes

* Can you still run Hello after compiling it?  If not, what's the error?

##Yes

* If you were compiling and running Hello from the src dir, try repeating these
  steps from the parent dir.  What switches to javac and java do you need to use?

##javac -cp src/ src/Hello.java

##java -cp src/ Hello

### Adding methods

Tasks:

* Edit "Calc.java" and add a "subtract" method:

```
public static int subtract(int a, int b) {
    // TODO: implement this. Hint: look at the add() method.
}
```

* Edit "Hello.java" and add a line to main() that calls Calc.subtract
* Recompile Hello.java and Calc.java
* Run Hello.java and paste the output

