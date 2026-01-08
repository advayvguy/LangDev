# Vex Language Specification

**Version**: 1.0
**Date**: January 2026

## Table of Contents

1. [Introduction](#introduction)
2. [Lexical Conventions](#lexical-conventions)
3. [Data Types](#data-types)
4. [Variables](#variables)
5. [Operators](#operators)
6. [Expressions](#expressions)
7. [Statements](#statements)
8. [Control Flow](#control-flow)
9. [Functions](#functions)
10. [Arrays](#arrays)
11. [Built-in Functions](#built-in-functions)
12. [Input/Output](#inputoutput)
13. [Comments](#comments)
14. [Complete Grammar](#complete-grammar)

---

## Introduction

**Vex** is a dynamically-typed, imperative programming language with support for functions, recursion, and arrays. It is designed for numerical computation and scripting tasks.

### Key Features

- Dynamic typing (all numbers are double-precision floating-point)
- User-defined functions with recursion support
- First-class procedures (void functions)
- Dynamic arrays
- Rich set of mathematical functions
- C-like syntax

### Hello World

```c
print "Hello, World!\n"
```

### Simple Calculation

```c
x = 5
y = 10
result = x + y
print "Result: ", result, "\n"
```

---

## Lexical Conventions

### Identifiers

Identifiers are names for variables, functions, and arrays.

**Syntax**: Must start with a letter (`a-z`, `A-Z`) or underscore (`_`), followed by any combination of letters, digits, or underscores.

**Examples**:
```c
x
myVariable
_temp
count123
totalSum
```

**Invalid**:
```c
123abc      // Cannot start with digit
my-var      // Hyphen not allowed
my var      // Space not allowed
```

### Keywords

The following words are reserved and cannot be used as identifiers:

```
if          else        while       for
func        void        return      arr
print       read        break       continue
len
```

### Literals

#### Numeric Literals

Vex supports integer and floating-point literals.

**Examples**:
```c
42          // Integer
3.14159     // Floating-point
.5          // Leading decimal point (0.5)
1.0e10      // Scientific notation
```

#### String Literals

Strings are enclosed in double quotes and support escape sequences.

**Examples**:
```c
"Hello"
"Hello, World!\n"
"Tab\there"
"Quote: \""
```

**Escape Sequences**:
- `\n` - Newline
- `\t` - Tab
- `\r` - Carriage return
- `\b` - Backspace
- `\f` - Form feed
- `\\` - Backslash
- `\"` - Double quote

### Special Symbols

```
(  )  [  ]  {  }
,  ;  =
+  -  *  /  %  ^
<  >  <=  >=  ==  !=
&&  ||  !
++  --
$
```

---

## Data Types

Vex has a simple type system:

| Type | Description | Example |
|------|-------------|---------|
| **Number** | Double-precision floating-point | `42`, `3.14`, `-7.5` |
| **Array** | Ordered collection of numbers | `arr data[10]` |
| **String** | Text (for I/O only) | `"Hello"` |
| **Function** | User-defined function | `func add(a,b) {...}` |
| **Procedure** | Void function (no return value) | `void print_msg() {...}` |

**Note**: All arithmetic is performed using double-precision floating-point numbers. There is no separate integer type.

---

## Variables

### Declaration and Assignment

Variables are created on first assignment and do not require explicit declaration.

**Syntax**:
```c
identifier = expression
```

**Examples**:
```c
x = 5               // Create x and assign 5
name = "Alice"      // Error: strings only for I/O
y = x * 2           // Create y, compute from x
z = y + 10          // Create z
```

### Special Variable

The underscore `_` stores the result of the last expression evaluated interactively.

**Example** (in REPL):
```c
> 2 + 3
5
> _ * 2
10
```

### Scope

- **Global variables**: Declared outside functions, accessible everywhere
- **Local variables**: Function parameters are local to that function
- **Shadowing**: Local variables can shadow global variables with the same name

**Example**:
```c
x = 100             // Global x

func test() {
    x = 5           // Local x (shadows global)
    print x, "\n"   // Prints: 5
}

test()
print x, "\n"       // Prints: 100 (global unchanged)
```

---

## Operators

### Arithmetic Operators

| Operator | Description | Example | Result |
|----------|-------------|---------|--------|
| `+` | Addition | `5 + 3` | `8` |
| `-` | Subtraction | `10 - 4` | `6` |
| `*` | Multiplication | `7 * 6` | `42` |
| `/` | Division | `15 / 3` | `5` |
| `%` | Modulo (remainder) | `17 % 5` | `2` |
| `^` | Exponentiation | `2 ^ 10` | `1024` |
| `-` | Unary negation | `-5` | `-5` |

**Examples**:
```c
result = (2 + 3) * 4        // 20
power = 2 ^ 8               // 256
remainder = 10 % 3          // 1
negative = -42              // -42
```

### Comparison Operators

| Operator | Description | Example | Result |
|----------|-------------|---------|--------|
| `==` | Equal to | `5 == 5` | `1` (true) |
| `!=` | Not equal to | `5 != 3` | `1` (true) |
| `<` | Less than | `3 < 5` | `1` (true) |
| `>` | Greater than | `5 > 3` | `1` (true) |
| `<=` | Less than or equal | `5 <= 5` | `1` (true) |
| `>=` | Greater than or equal | `5 >= 3` | `1` (true) |

**Note**: Comparison operators return `1` for true and `0` for false.

**Examples**:
```c
x = 10
y = 20

if (x < y) {                // True (1)
    print "x is less than y\n"
}

isEqual = (x == y)          // 0 (false)
```

### Logical Operators

| Operator | Description | Example | Result |
|----------|-------------|---------|--------|
| `&&` | Logical AND | `1 && 0` | `0` (false) |
| `||` | Logical OR | `1 || 0` | `1` (true) |
| `!` | Logical NOT | `!0` | `1` (true) |

**Truth Values**:
- `0` is false
- Any non-zero value is true

**Examples**:
```c
x = 5
y = 10

if (x > 0 && y > 0) {       // Both positive
    print "Both positive\n"
}

if (x == 0 || y == 0) {     // At least one is zero
    print "At least one is zero\n"
}

if (!(x > 100)) {           // x is not greater than 100
    print "x is not greater than 100\n"
}
```

### Increment/Decrement Operators

| Operator | Description | Example | Result |
|----------|-------------|---------|--------|
| `++` | Post-increment | `x++` | Returns `x`, then increments |
| `--` | Post-decrement | `x--` | Returns `x`, then decrements |

**Examples**:
```c
x = 5
y = x++                     // y = 5, x = 6
z = x--                     // z = 6, x = 5
```

### Operator Precedence

Listed from highest to lowest precedence:

1. `^` (exponentiation) - right associative
2. `-` (unary), `!` (logical NOT)
3. `*`, `/`, `%`
4. `+`, `-` (binary)
5. `<`, `>`, `<=`, `>=`, `==`, `!=`, `++`, `--`
6. `&&` (logical AND)
7. `||` (logical OR)
8. `=` (assignment) - right associative

**Examples**:
```c
result = 2 + 3 * 4          // 14 (not 20)
result = (2 + 3) * 4        // 20 (parentheses override)
result = 2 ^ 3 ^ 2          // 512 (2^(3^2), right-associative)
```

---

## Expressions

An expression is a combination of values, variables, operators, and function calls that evaluates to a value.

### Primary Expressions

```c
42                          // Literal
x                           // Variable
PI                          // Constant
```

### Arithmetic Expressions

```c
x + y
a * b - c
2 * (x + y)
```

### Function Call Expressions

```c
sin(PI / 2)                 // Built-in function
factorial(5)                // User-defined function
```

### Array Access Expressions

```c
data[0]                     // First element
matrix[i * 3 + j]           // Computed index
```

### Assignment Expressions

```c
x = 10                      // Simple assignment
data[i] = value             // Array element assignment
$1 = newValue               // Parameter assignment
```

---

## Statements

### Expression Statement

Any expression followed by a newline or semicolon.

```c
x = 5
y + 2
print "Hello\n"
```

### Compound Statement (Block)

A sequence of statements enclosed in braces.

```c
{
    x = 5
    y = 10
    print x + y, "\n"
}
```

### Empty Statement

A statement can be empty (just a newline or semicolon).

```c

// Empty line
```

---

## Control Flow

### If Statement

**Syntax**:
```c
if (condition)
    statement

if (condition)
    statement
else
    statement
```

**Examples**:
```c
// Simple if
if (x > 0) {
    print "Positive\n"
}

// If-else
if (x > 0) {
    print "Positive\n"
} else {
    print "Non-positive\n"
}

// Nested if
if (x > 0) {
    if (x < 10) {
        print "Between 0 and 10\n"
    }
}

// Chained if-else
if (x > 0) {
    print "Positive\n"
} else {
    if (x < 0) {
        print "Negative\n"
    } else {
        print "Zero\n"
    }
}
```

### While Loop

**Syntax**:
```c
while (condition)
    statement
```

**Examples**:
```c
// Count from 1 to 10
i = 1
while (i <= 10) {
    print i, "\n"
    i = i + 1
}

// Sum of numbers
sum = 0
i = 1
while (i <= 100) {
    sum = sum + i
    i = i + 1
}
print "Sum: ", sum, "\n"
```

### For Loop

**Syntax**:
```c
for (initialization; condition; increment)
    statement
```

**Examples**:
```c
// Count from 0 to 9
for (i = 0; i < 10; i++) {
    print i, "\n"
}

// Sum of array elements
sum = 0
for (i = 0; i < len(arr); i++) {
    sum = sum + arr[i]
}

// Nested loops (multiplication table)
for (i = 1; i <= 10; i++) {
    for (j = 1; j <= 10; j++) {
        print i * j, "\t"
    }
    print "\n"
}
```

### Break Statement

Exit the innermost loop immediately.

**Syntax**:
```c
break
```

**Example**:
```c
// Find first negative number
for (i = 0; i < len(arr); i++) {
    if (arr[i] < 0) {
        print "First negative at index ", i, "\n"
        break
    }
}
```

### Continue Statement

Skip to the next iteration of the innermost loop.

**Syntax**:
```c
continue
```

**Example**:
```c
// Print only positive numbers
for (i = 0; i < len(arr); i++) {
    if (arr[i] <= 0) {
        continue
    }
    print arr[i], "\n"
}
```

---

## Functions

### Function Definition

**Syntax**:
```c
func function_name(parameter1, parameter2, ...) {
    statements
    return expression
}
```

**Examples**:
```c
// Function with no parameters
func pi() {
    return 3.14159265
}

// Function with one parameter
func square(x) {
    return x * x
}

// Function with multiple parameters
func add(a, b) {
    return a + b
}

// Function with multiple return points
func abs(x) {
    if (x < 0) {
        return -x
    } else {
        return x
    }
}
```

### Procedure Definition

Procedures are functions that do not return a value (like `void` functions in C).

**Syntax**:
```c
void procedure_name(parameter1, parameter2, ...) {
    statements
    return
}
```

**Examples**:
```c
// Procedure with no parameters
void greet() {
    print "Hello, World!\n"
    return
}

// Procedure with parameters
void printSum(a, b) {
    print "Sum: ", a + b, "\n"
}

// Procedure can return early
void checkPositive(x) {
    if (x <= 0) {
        print "Not positive\n"
        return
    }
    print "Positive: ", x, "\n"
}
```

### Function Calls

**Syntax**:
```c
function_name(argument1, argument2, ...)
```

**Examples**:
```c
result = square(5)              // 25
sum = add(3, 7)                 // 10
greet()                         // Prints "Hello, World!"
printSum(10, 20)                // Prints "Sum: 30"
```

### Return Statement

**Syntax**:
```c
return expression               // For functions
return                          // For procedures
```

**Examples**:
```c
func max(a, b) {
    if (a > b) {
        return a
    } else {
        return b
    }
}

void sayHello() {
    print "Hello\n"
    return
}
```

**Note**: If a function reaches the end without an explicit `return`, it returns implicitly (behavior undefined for functions, normal for procedures).

### Recursion

Functions can call themselves recursively.

**Examples**:
```c
// Factorial
func factorial(n) {
    if (n <= 1) {
        return 1
    } else {
        return n * factorial(n - 1)
    }
}

print factorial(5), "\n"        // 120

// Fibonacci
func fib(n) {
    if (n <= 1) {
        return n
    } else {
        return fib(n-1) + fib(n-2)
    }
}

print fib(10), "\n"             // 55

// Greatest common divisor
func gcd(a, b) {
    if (b == 0) {
        return a
    } else {
        return gcd(b, a % b)
    }
}

print gcd(48, 18), "\n"         // 6
```

### Parameter Access

Parameters can be accessed by name or by position using `$n` notation.

**By Name**:
```c
func add(a, b) {
    return a + b
}
```

**By Position**:
```c
func add(a, b) {
    return $1 + $2              // $1 is first param, $2 is second
}
```

**Mixed** (useful for variadic-style functions):
```c
func printArgs(a, b, c) {
    print "First: ", $1, "\n"
    print "Second: ", b, "\n"
    print "Third: ", $3, "\n"
}
```

### Parameter Assignment

You can modify parameters using `$n = value` syntax.

**Example**:
```c
func increment(x) {
    $1 = $1 + 1
    return $1
}

y = 5
result = increment(y)           // result = 6, y still 5 (pass by value)
```

**Note**: Parameters are passed by value, so modifying a parameter does not affect the original variable.

---

## Arrays

### Array Declaration

**Syntax**:
```c
arr array_name[size]
```

**Examples**:
```c
arr data[10]                    // Array of 10 elements
arr matrix[100]                 // Array of 100 elements
arr small[5]                    // Array of 5 elements
```

**Note**: Arrays are indexed from 0 to size-1.

### Array Initialization

**Empty Declaration**:
```c
arr data[10]
// Elements are uninitialized
```

**Direct Initialization**:
```c
arr numbers[] = [1, 2, 3, 4, 5]
arr primes[] = [2, 3, 5, 7, 11, 13]
```

### Array Access

**Syntax**:
```c
array_name[index]
```

**Examples**:
```c
arr data[5]

data[0] = 10                    // Set first element
data[1] = 20                    // Set second element
data[4] = 50                    // Set last element

x = data[0]                     // Get first element
y = data[2]                     // Get third element

// Computed index
i = 2
value = data[i]                 // Get element at index i
data[i + 1] = 100               // Set element at index i+1
```

### Array Length

**Syntax**:
```c
len(array_name)
```

**Examples**:
```c
arr data[10]
n = len(data)                   // n = 10

for (i = 0; i < len(data); i++) {
    data[i] = i * i
}
```

### Array Examples

**Fill array with values**:
```c
arr data[10]
for (i = 0; i < len(data); i++) {
    data[i] = i * 2
}
```

**Sum of array elements**:
```c
arr numbers[] = [1, 2, 3, 4, 5]
sum = 0
for (i = 0; i < len(numbers); i++) {
    sum = sum + numbers[i]
}
print "Sum: ", sum, "\n"        // Sum: 15
```

**Find maximum in array**:
```c
arr data[5]
// ... fill array ...

max = data[0]
for (i = 1; i < len(data); i++) {
    if (data[i] > max) {
        max = data[i]
    }
}
print "Maximum: ", max, "\n"
```

**Reverse an array**:
```c
void reverse(arr, n) {
    for (i = 0; i < n/2; i++) {
        temp = arr[i]
        arr[i] = arr[n - 1 - i]
        arr[n - 1 - i] = temp
    }
}

arr numbers[] = [1, 2, 3, 4, 5]
reverse(numbers, len(numbers))
```

**Note**: Arrays are passed by reference to functions, so modifications inside functions affect the original array.

---

## Built-in Functions

### Mathematical Functions (Single Argument)

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `sin(x)` | Sine (radians) | `sin(PI/2)` | `1.0` |
| `cos(x)` | Cosine (radians) | `cos(0)` | `1.0` |
| `atan(x)` | Arctangent (returns degrees) | `atan(1)` | `45.0` |
| `ln(x)` | Natural logarithm | `ln(E)` | `1.0` |
| `log(x)` | Base-10 logarithm | `log(100)` | `2.0` |
| `exp(x)` | Exponential (e^x) | `exp(1)` | `2.718282` |
| `sqrt(x)` | Square root | `sqrt(16)` | `4.0` |
| `int(x)` | Floor (round down) | `int(3.7)` | `3.0` |
| `abs(x)` | Absolute value | `abs(-5)` | `5.0` |

**Examples**:
```c
// Trigonometry
angle = PI / 4
print "sin(45°) = ", sin(angle), "\n"       // 0.707107

// Logarithms
print "ln(10) = ", ln(10), "\n"             // 2.302585
print "log(1000) = ", log(1000), "\n"       // 3.0

// Rounding
print "int(5.9) = ", int(5.9), "\n"         // 5.0
print "int(-3.2) = ", int(-3.2), "\n"       // -4.0
```

### Mathematical Functions (Two Arguments)

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `atan2(y,x)` | Arctangent of y/x (returns degrees) | `atan2(1,1)` | `45.0` |

**Example**:
```c
// Compute angle in degrees
angle = atan2(1, 1)             // 45 degrees
print "Angle: ", angle, "°\n"
```

### Mathematical Functions (No Arguments)

| Function | Description | Example | Result (approx) |
|----------|-------------|---------|-----------------|
| `rand()` | Random number in [0,1) | `rand()` | `0.347` (varies) |

**Examples**:
```c
// Generate random number between 0 and 1
r = rand()

// Random integer from 1 to 100
n = int(rand() * 100) + 1

// Simulate dice roll
dice = int(rand() * 6) + 1
```

### Mathematical Constants

| Constant | Description | Value |
|----------|-------------|-------|
| `PI` | Pi (π) | `3.14159265358979323846` |
| `E` | Euler's number (e) | `2.71828182845904523536` |
| `GAMMA` | Euler-Mascheroni constant (γ) | `0.57721566490153286060` |
| `DEG` | Radians to degrees (180/π) | `57.29577951308232087680` |
| `PHI` | Golden ratio (φ) | `1.61803398874989484820` |

**Examples**:
```c
// Circle calculations
radius = 5
circumference = 2 * PI * radius
area = PI * radius ^ 2

// Convert radians to degrees
radians = PI / 3
degrees = radians * DEG             // 60 degrees

// Exponential growth
initial = 100
rate = 0.05
time = 10
final = initial * exp(rate * time)
```

---

## Input/Output

### Print Statement

**Syntax**:
```c
print expression
print expression1, expression2, ...
```

**Examples**:
```c
// Print a value
print 42

// Print multiple values
print "x = ", x, "\n"

// Print with newline
print "Hello, World!\n"

// Print expressions
print "Sum: ", 2 + 3, "\n"

// Print array elements
for (i = 0; i < len(arr); i++) {
    print arr[i], " "
}
print "\n"
```

**Note**: Numbers are printed in shortest form. Use escape sequence `\n` for newlines.

### Read Function

**Syntax**:
```c
variable = read()
read(variable)
```

**Examples**:
```c
// Read a single number
print "Enter a number: "
x = read()

// Read using function call form
print "Enter age: "
read(age)

// Read multiple values
print "Enter two numbers: "
a = read()
b = read()

// Read array elements
arr data[5]
print "Enter 5 numbers:\n"
for (i = 0; i < len(data); i++) {
    print "data[", i, "] = "
    data[i] = read()
}
```

**Note**: `read()` expects numeric input. Non-numeric input causes an error.

---

## Comments

### Single-Line Comments

**Syntax**:
```c
// comment text
```

**Examples**:
```c
// This is a comment
x = 5           // This is also a comment

// Calculate factorial
func fact(n) {
    // Base case
    if (n <= 1) {
        return 1
    }
    // Recursive case
    return n * fact(n-1)
}
```

**Note**: Comments extend from `//` to the end of the line. Multi-line comments are not supported.

---

## Complete Grammar

### Formal Grammar (BNF-style)

```bnf
<program>       ::= <statement-list>

<statement-list>::= <statement>
                  | <statement-list> <newline> <statement>

<statement>     ::= <expression>
                  | <assignment>
                  | <function-def>
                  | <procedure-def>
                  | <array-decl>
                  | <if-stmt>
                  | <while-stmt>
                  | <for-stmt>
                  | <return-stmt>
                  | <print-stmt>
                  | <break-stmt>
                  | <continue-stmt>
                  | <block>

<block>         ::= '{' <statement-list> '}'

<expression>    ::= <number>
                  | <identifier>
                  | <string>
                  | <constant>
                  | <expression> <binary-op> <expression>
                  | <unary-op> <expression>
                  | <identifier> '++'
                  | <identifier> '--'
                  | '(' <expression> ')'
                  | <function-call>
                  | <array-access>
                  | <builtin-call>
                  | '$' <number>

<binary-op>     ::= '+' | '-' | '*' | '/' | '%' | '^'
                  | '<' | '>' | '<=' | '>=' | '==' | '!='
                  | '&&' | '||'

<unary-op>      ::= '-' | '!'

<assignment>    ::= <identifier> '=' <expression>
                  | <array-access> '=' <expression>
                  | '$' <number> '=' <expression>

<function-def>  ::= 'func' <identifier> '(' <param-list> ')' <newline> <statement>

<procedure-def> ::= 'void' <identifier> '(' <param-list> ')' <newline> <statement>

<param-list>    ::= ε
                  | <identifier>
                  | <identifier> ',' <param-list>

<function-call> ::= <identifier> '(' <arg-list> ')'

<arg-list>      ::= ε
                  | <expression>
                  | <expression> ',' <arg-list>

<array-decl>    ::= 'arr' <identifier> '[' <expression> ']'
                  | 'arr' <identifier> '[' ']' '=' '[' <arg-list> ']'

<array-access>  ::= <identifier> '[' <expression> ']'

<if-stmt>       ::= 'if' '(' <expression> ')' <newline> <statement>
                  | 'if' '(' <expression> ')' <newline> <statement> 'else' <newline> <statement>

<while-stmt>    ::= 'while' '(' <expression> ')' <newline> <statement>

<for-stmt>      ::= 'for' '(' <expression> ';' <expression> ';' <expression> ')' <newline> <statement>

<return-stmt>   ::= 'return'
                  | 'return' <expression>

<print-stmt>    ::= 'print' <print-list>

<print-list>    ::= <expression>
                  | <string>
                  | <print-list> ',' <expression>
                  | <print-list> ',' <string>

<break-stmt>    ::= 'break'

<continue-stmt> ::= 'continue'

<builtin-call>  ::= <builtin-name> '(' ')'
                  | <builtin-name> '(' <expression> ')'
                  | <builtin-name> '(' <expression> ',' <expression> ')'
                  | 'len' '(' <identifier> ')'
                  | 'read' '(' ')'

<builtin-name>  ::= 'sin' | 'cos' | 'atan' | 'atan2' | 'ln' | 'log'
                  | 'exp' | 'sqrt' | 'int' | 'abs' | 'rand'

<constant>      ::= 'PI' | 'E' | 'GAMMA' | 'DEG' | 'PHI'

<identifier>    ::= <letter> <ident-chars>

<ident-chars>   ::= ε
                  | <ident-char> <ident-chars>

<ident-char>    ::= <letter> | <digit> | '_'

<letter>        ::= 'a'..'z' | 'A'..'Z' | '_'

<digit>         ::= '0'..'9'

<number>        ::= <digit-seq>
                  | <digit-seq> '.' <digit-seq>
                  | '.' <digit-seq>

<digit-seq>     ::= <digit>
                  | <digit> <digit-seq>

<string>        ::= '"' <string-chars> '"'

<string-chars>  ::= ε
                  | <string-char> <string-chars>

<string-char>   ::= any character except '"' or newline
                  | '\n' | '\t' | '\r' | '\b' | '\f' | '\\' | '\"'

<newline>       ::= '\n'
```

---

## Example Programs

### Example 1: Factorial Calculator

```c
// Calculate factorial of a number
func factorial(n) {
    if (n <= 1) {
        return 1
    } else {
        return n * factorial(n - 1)
    }
}

print "Enter a number: "
x = read()
result = factorial(x)
print "Factorial of ", x, " is ", result, "\n"
```

**Sample Run**:
```
Enter a number: 5
Factorial of 5 is 120
```

### Example 2: Prime Number Checker

```c
// Check if a number is prime
func isPrime(n) {
    if (n <= 1) {
        return 0
    }
    if (n <= 3) {
        return 1
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0
    }

    i = 5
    while (i * i <= n) {
        if (n % i == 0 || n % (i+2) == 0) {
            return 0
        }
        i = i + 6
    }
    return 1
}

print "Enter a number: "
x = read()

if (isPrime(x)) {
    print x, " is prime\n"
} else {
    print x, " is not prime\n"
}
```

### Example 3: Array Statistics

```c
// Calculate mean and standard deviation
arr data[100]
n = 0

func mean(arr, n) {
    sum = 0
    for (i = 0; i < n; i++) {
        sum = sum + arr[i]
    }
    return sum / n
}

func stddev(arr, n, avg) {
    sum = 0
    for (i = 0; i < n; i++) {
        diff = arr[i] - avg
        sum = sum + (diff ^ 2)
    }
    return sqrt(sum / n)
}

print "How many numbers? "
n = read()

print "Enter numbers:\n"
for (i = 0; i < n; i++) {
    print "data[", i, "] = "
    data[i] = read()
}

avg = mean(data, n)
sd = stddev(data, n, avg)

print "Mean: ", avg, "\n"
print "Standard Deviation: ", sd, "\n"
```

### Example 4: Bubble Sort

```c
// Sort an array using bubble sort
arr numbers[20]
n = 0

void swap(arr, i, j) {
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
}

void bubbleSort(arr, n) {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j, j+1)
            }
        }
    }
}

print "How many numbers? "
n = read()

print "Enter numbers:\n"
for (i = 0; i < n; i++) {
    numbers[i] = read()
}

bubbleSort(numbers, n)

print "Sorted array: "
for (i = 0; i < n; i++) {
    print numbers[i], " "
}
print "\n"
```

### Example 5: Recursive Binary Search

```c
// Binary search in sorted array
arr data[100]
n = 0

func binarySearch(arr, target, low, high) {
    if (low > high) {
        return -1
    }

    mid = int((low + high) / 2)

    if (arr[mid] == target) {
        return mid
    } else {
        if (arr[mid] > target) {
            return binarySearch(arr, target, low, mid-1)
        } else {
            return binarySearch(arr, target, mid+1, high)
        }
    }
}

print "How many numbers? "
n = read()

print "Enter sorted numbers:\n"
for (i = 0; i < n; i++) {
    data[i] = read()
}

print "Search for: "
target = read()

index = binarySearch(data, target, 0, n-1)

if (index >= 0) {
    print "Found at index ", index, "\n"
} else {
    print "Not found\n"
}
```

---

## Error Handling

### Runtime Errors

Vex reports the following runtime errors:

- **Division by zero**: `x / 0`
- **Undefined variable**: Using a variable before assignment
- **Array out of bounds**: `arr[100]` when array has 10 elements
- **Type errors**: Using non-number where number expected
- **Function not found**: Calling undefined function
- **Argument count mismatch**: Wrong number of arguments
- **Non-numeric input**: Reading non-number with `read()`

**Example**:
```c
x = 10 / 0              // Error: cant divide by 0
y = undefinedVar        // Error: is not defined
arr[100] = 5            // Error: illegal reference
```

### Error Recovery

When an error occurs:
1. An error message is printed to stderr
2. Execution returns to the top level (interactive mode) or terminates (file mode)
3. Global state is preserved in interactive mode

---

## Best Practices

### 1. Use Meaningful Names

```c
// Good
func calculateArea(radius) {
    return PI * radius ^ 2
}

// Bad
func f(r) {
    return PI * r ^ 2
}
```

### 2. Add Comments

```c
// Calculate the nth Fibonacci number
func fib(n) {
    // Base cases
    if (n <= 1) {
        return n
    }
    // Recursive case
    return fib(n-1) + fib(n-2)
}
```

### 3. Initialize Variables

```c
sum = 0                 // Initialize before use
for (i = 0; i < 10; i++) {
    sum = sum + i
}
```

### 4. Check Bounds

```c
func getElement(arr, index) {
    if (index < 0 || index >= len(arr)) {
        print "Index out of bounds\n"
        return 0
    }
    return arr[index]
}
```

### 5. Use Helper Functions

```c
// Break complex logic into smaller functions
func isPrime(n) { ... }
func findPrimes(arr, n) { ... }
func printPrimes(arr, n) { ... }

// Instead of one large function
```

---

## Limitations

### Current Limitations

1. **No strings as first-class values**: Strings can only be used in `print` statements
2. **No multidimensional arrays**: Only 1D arrays are supported
3. **No structures/records**: No composite data types
4. **No local arrays**: Arrays must be global
5. **No variadic functions**: Fixed parameter count
6. **No default parameters**: All parameters must be provided
7. **No operator overloading**: Operators work only on numbers
8. **No closures**: Functions cannot capture outer variables
9. **No modules/imports**: All code must be in one file
10. **Limited error messages**: Errors may be cryptic

### Workarounds

**Simulate 2D arrays**:
```c
// Use 1D array with index calculation
arr matrix[9]           // 3x3 matrix
matrix[i*3 + j] = value // Access element (i,j)
```

**Simulate structures**:
```c
// Use parallel arrays
arr names[10]
arr ages[10]
arr scores[10]

names[0] = 1            // ID as number
ages[0] = 25
scores[0] = 95.5
```

---

## Summary

Vex is a simple yet powerful language suitable for:
- Numerical computation
- Algorithm implementation
- Mathematical modeling
- Educational purposes
- Rapid prototyping

**Key Strengths**:
- Easy to learn
- C-like syntax
- Support for recursion
- Dynamic arrays
- Rich mathematical library

**Getting Started**:
1. Write your program in a `.txt` file
2. Run: `./hoc6 < program.txt`
3. Or use interactive mode: `./hoc6`

Happy coding with Vex!
