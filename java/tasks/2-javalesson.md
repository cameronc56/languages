# Java - Lesson 2

## JARs

JAR (Java ARchive) files are zip files that typically contain compiled Java .class files
(and sometimes other file types).  JAR files are used to package libraries and full
programs so they can be easily distributed.

The `jar` tool that comes with the JDK can be used to create and inspect JAR files.

### Creating a JAR

Open a shell and go to the directory you used during Lesson 1.

Run these commands:

```
javac -cp src src/Hello.java src/calc/Calc.java
jar cf hello.jar -C src .
```

The `javac` line should look familiar.  It compiles the two java files, producing two .class files.

The `jar` command is new.  The `c` flag indicates that we want to create a new JAR file.  The `f` flag
indicates that the following parameter contains the filename to create (`hello.jar`).

`-C src` tells `jar` to change to the `src` directory, and `.` tells `jar` to include all files in the
current directory (`src`).

### Inspecting a JAR

Run this command:  `jar tvf hello.jar`

You should see a list of files.  There are two important things to note:

* The `t` flag tells jar to list the files in the JAR
* The `src/` directory prefix for each file is omitted.  This is because we used the `-C src` flag.
* There is a `META-INF` directory in the jar file that is not present in our src dir.  `jar` created
this for us.  We'll ignore that for now.

### Using the JAR with java

Let's run the Hello program using the JAR file.
cd back to the directory containing `hello.jar` then run:

```
java -cp hello.jar Hello
```

### Compiling classes to a separate directory

Our current `hello.jar` contains the .java files and .class files.
Usually a JAR contains only the compiled .class files.  Let's
recompile our classes and re-create the JAR.

Use the `-d` flag with `javac` to specify a different output directory:

```
mkdir out
javac -d out -cp src src/Hello.java src/calc/Calc.java
jar cf hello.jar -C out .
```

If you run: `jar tvf hello.jar` you'll notice that the `.java` files are no longer
included.

### Using a 3rd party JAR

Let's try writing a program that uses an external JAR file.
We'll use the jBCrypt library to hash passwords.

First, download the jbcrypt.jar:

```
curl -LO https://bitmechanic-temp.s3.amazonaws.com/jbcrypt.jar
```

Next, write a small program that uses it. Paste the contents below into: `src/Crypt.java`

```java
import org.mindrot.jbcrypt.BCrypt;

public class Crypt {
    public static void main(String argv[]) {
        String pw = argv[0];
        System.out.println("Clear text: " + pw);
        System.out.println("    Hashed: " + BCrypt.hashpw(pw, BCrypt.gensalt()));
    }
}
```

Compile it, referencing the jbcrypt.jar file:

```
rm -rf out
mkdir out
javac -d out -cp src src/Crypt.java
```

Why didn't this compile?  Can you fix the `javac` invocation?

Answer: You need to reference the jbcrypt.jar file:

```
javac -d out -cp src:jbcrypt.jar src/Crypt.java
```

To run it, reference the out directory and jbcrypt.jar:

```
java -cp out:jbcrypt.jar Crypt mypassword
```

Note the use of the colon to separate classpath elements.

### Summary

* `javac` and `java` use the `-cp` flag (or CLASSPATH environment variable) to find class files
referenced during compilation or runtime
* Classpath elements are separated with a colon (on Linux or Mac OS) or a semicolon (Windows)

### Exercises

The jbcrypt library has another function that verifies that a clear text string matches a
previously hashed value.  The signature is:

```
boolean matches = BCrypt.checkpw(candidate, hashed);
```

Write a new file: `VerifyPw.java` that accepts two single command line arguments and
tells the user whether the first parameter (the guess) matches the second parameter
(the hash).  Here's an example invocation:

```
# example of a failure.  single quotes are used to prevent bash from expanding the $ sign
java -cp out:jbcrypt.jar VerifyPw cat '$2a$10$RCFqrdsp801VXBv6xS7ul.Wc9nKYM7qfOVCwT1WuGOvbee6qh15eu'
Sorry, 'cat' does not match the hash $2a$10$RCFqrdsp801VXBv6xS7ul.Wc9nKYM7qfOVCwT1WuGOvbee6qh15eu

# example of a match
java -cp out:jbcrypt.jar VerifyPw mypassword '$2a$10$RCFqrdsp801VXBv6xS7ul.Wc9nKYM7qfOVCwT1WuGOvbee6qh15eu'
Success!  mypassword matches the hash $2a$10$RCFqrdsp801VXBv6xS7ul.Wc9nKYM7qfOVCwT1WuGOvbee6qh15eu
```

*Questions:*

* What command did you run to compile `VerifyPw.java`?

##javac -d out -cp src:jbcrypt.jar src/VerifyPw.java

* What command could you run to create a JAR file that includes Crypt.java and VerifyPw.java?

##jar cf passwords.jar -C out/ .

* Use the above JAR file to do the following:
  * Run the Crypt command

##java -cp jbcrypt.jar:passwords.jar Crypt quack

  * Run the VerifyPw command

##java -cp jbcrypt.jar:passwords.jar VerifyPw quack '$2a$alskdflkjasdkljfjklasdljkfdsalj'

* What happens if you omit the `-C` flag when creating the JAR?  Does the resulting JAR still work?  If not, why?

##the jar still works, but you have to set the full path of the files relative to the directory you are running the jar command from.

