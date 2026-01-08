# LangDev: Building a Programming Language from Scratch

A progressive journey through compiler and interpreter construction, implementing **HOC (Higher Order Calculator)** - from a simple arithmetic calculator to a full Turing-complete programming language with functions, arrays, and control flow.

## Overview

This project demonstrates the fundamental principles of language design and implementation through incremental development. Each stage builds upon the previous, introducing one major concept at a time. The implementation uses C with Yacc/Bison for parsing, culminating in a stack-based virtual machine with bytecode compilation.

**Final Product**: Vex - a complete scripting language supporting user-defined functions, recursion, arrays, and procedural programming.

## Learning Goals

- Understand lexical analysis and tokenization
- Master parsing techniques and grammar design
- Learn symbol table management
- Implement bytecode compilation and virtual machines
- Handle control flow and backpatching
- Build function call mechanisms and activation records
- Explore memory management for arrays and local variables

## Stage Progression

### Stage 1: Foundation - Basic Calculator
**Concept**: Expression evaluation and operator precedence

**Features**:
- Arithmetic operators: `+`, `-`, `*`, `/`, `%`, `^`
- Unary minus
- Parentheses for grouping
- Floating-point numbers

**Learning Focus**: Lexer basics, grammar rules, direct interpretation

**Example**:
```
2 + 3 * 4    → 14
(2 + 3) * 4  → 20
```

---

### Stage 2: State - Variables and Memory
**Concept**: Storing and retrieving values

**Features**:
- 26 single-letter variables (a-z)
- Assignment operator `=`
- Special variable `_` (last result)
- Error recovery with `setjmp`/`longjmp`

**Learning Focus**: Memory management, semantic values, error handling

**Example**:
```
x = 5
y = x * 2
y + 10       → 20
```

---

### Stage 3: Extensibility - Symbol Table and Built-ins
**Concept**: Dynamic symbol management and library functions

**Features**:
- Unlimited named variables
- Built-in math functions: `sin`, `cos`, `sqrt`, `ln`, `exp`, `atan`, `abs`, etc.
- Mathematical constants: `PI`, `E`, `GAMMA`, `DEG`, `PHI`
- System command execution
- Function dispatch mechanism

**Learning Focus**: Hash tables, linked lists, dynamic lookup, function pointers

**Example**:
```
angle = PI / 4
print sin(angle)
sqrt(2) + sqrt(3)
```

---

### Stage 4: Performance - Bytecode Virtual Machine
**Concept**: Two-phase execution (compilation + interpretation)

**Features**:
- Bytecode compilation during parsing
- Stack-based virtual machine
- Separation of parse-time and run-time
- Instruction set architecture

**Learning Focus**: Code generation, VM design, stack operations, fetch-decode-execute cycle

**Architecture**:
```
Source Code → Parser → Bytecode → Virtual Machine → Result
```

---

### Stage 5: Control - Turing Completeness
**Concept**: Control flow and conditional execution

**Features**:
- Control structures: `while`, `if-else`, `for`
- Relational operators: `>`, `>=`, `<`, `<=`, `==`, `!=`
- Logical operators: `&&`, `||`, `!`
- Statement blocks with `{}`
- `break` and `continue`
- Single-line comments: `//`

**Learning Focus**: Backpatching, forward references, loop implementation, short-circuit evaluation

**Example**:
```c
// Calculate factorial
x = 5
fact = 1
while (x > 0) {
    fact = fact * x
    x = x - 1
}
print fact   → 120
```

---

### Vex: Functions - Complete Language
**Concept**: User-defined functions and data structures

**Features**:
- User-defined functions: `func name(params) { body }`
- Procedures (void functions): `void name(params) { body }`
- Arrays: `arr name[size]`, indexing, `len()`
- Recursive function calls
- Call stack with activation frames
- Parameter access: `$1`, `$2`, `$3`
- Input: `read()`
- String literals

**Learning Focus**: Call stack, activation records, parameter passing, recursion, array storage

**Example**:
```c
// Recursive factorial
func fact(n) {
    if (n == 0) {
        return 1
    } else {
        return n * fact(n-1)
    }
}
print fact(5)   → 120

// Array sorting
arr numbers[5]
void sort() {
    for(i = 0; i < len(numbers); i++) {
        for(j = i+1; j < len(numbers); j++) {
            if(numbers[i] > numbers[j]) {
                temp = numbers[i]
                numbers[i] = numbers[j]
                numbers[j] = temp
            }
        }
    }
}
```

---

## Quick Start

### Build any stage:
```bash
cd Stage1    # or Stage2, Stage3, Stage4, Stage5, Vex
make
```

### Run interactive mode:
```bash
./hoc1       # Stage 1
./hoc2       # Stage 2
./hoc3       # Stage 3
./hoc4       # Stage 4
./hoc5       # Stage 5
./hoc6       # Vex
```

### Run from file:
```bash
./hoc5 < fact.txt
./hoc6 < bubsort.txt
```

## Architecture Evolution

| Stage | Execution Model | Data Structures | Key Components |
|-------|----------------|-----------------|----------------|
| 1 | Direct interpretation | None | Lexer, Parser |
| 2 | Direct interpretation | Fixed array (26 vars) | + Error handling |
| 3 | Direct interpretation | Linked list (symbol table) | + Function dispatch |
| 4 | **Bytecode VM** | Symbol table + Stack | + Code generator, VM |
| 5 | Bytecode VM | Symbol table + Stack | + Control flow, Backpatching |
| Vex | Bytecode VM | Symbol table + Stack + Call frames | + User functions, Arrays |

## Conceptual Progression

```
Simple Calculator
    ↓ Add memory
Variables & Assignment
    ↓ Add extensibility
Symbol Table & Functions
    ↓ Add compilation
Bytecode Virtual Machine
    ↓ Add control flow
Turing-Complete Language
    ↓ Add user functions
Complete Programming Language
```

## Key Innovations by Stage

**Stage 1-2**: Foundation and state
- Lexical analysis and parsing
- Operator precedence
- Variable storage

**Stage 3**: Modularity
- Dynamic symbol resolution
- Function pointers for built-ins
- Constant folding

**Stage 4**: Two-phase execution
- Parse once, execute many times
- Clear separation of concerns
- Optimization opportunities

**Stage 5**: Algorithmic power
- Loops enable iteration
- Conditionals enable decision-making
- Turing completeness achieved

**Vex**: Abstraction and reuse
- Code modularity through functions
- Recursion enables elegant algorithms
- Arrays enable data structure manipulation
- First-class procedures

## Documentation

- **CLAUDE.md**: Comprehensive technical reference for working with this codebase
- **Stage1/HOC_EXPLAINED.md**: Deep dive into lexer, parser, and state machines (1273 lines)
- **Stage5/README.md**: Complete architecture guide with VM internals (1548 lines)
- Each stage directory contains implementation-specific details

## Technology Stack

- **Language**: C
- **Parser Generator**: Yacc/Bison (LALR(1) parsing)
- **Execution Model**: Stack-based virtual machine
- **Type System**: Dynamically typed (double-precision floating point)

## Project Structure

```
LangDev/
├── Stage1/          # Basic calculator
├── Stage2/          # Variables
├── Stage3/          # Symbol table
├── Stage4/          # Bytecode VM
├── Stage5/          # Control flow
├── Vex/             # User functions and arrays
├── CLAUDE.md        # Technical reference
└── README.md        # This file
```

## Educational Value

This project is ideal for:
- Computer science students learning compilers
- Developers interested in language implementation
- Anyone wanting to understand how programming languages work under the hood

The incremental approach makes complex concepts accessible by building them up one piece at a time, with each stage being a complete, working implementation.

---

**Start with Stage 1 and progress through each stage to build your understanding from the ground up.**
