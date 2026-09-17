# c-math-tokenizer

A C-based math string tokenizer and parser using the Shunting-Yard algorithm

## Description

The goal of this project is to calculate basic arithmetic expressions in mathematical order.
For example it can calculate:
`1 + 2 - (1 + 3) ^ 2 - 1 - 2 / 3`
The evaluator converts infix arithmetic expressions into Reverse Polish Notaion(RPN) using Shunting Yard algorithm, enabling efficient single-pass calculation via a stack and queue

Custom implementations of Stack and Queue data structures are used to process operators based on their precedence:

-   **Operator stack:** Holds operators during parsing.
-   **Output queue:** Receives numbers and operators in RPN order.

## Features

-   Supports basic arithmetic operators: `+`, `-`, `/`, `*`, `^` (power operator).
-   Evaluates operators based on precedence and parentheses grouping to ensure correct order of operations.

## Requirements

-   C compiler(gcc or clang)
-   cmake and make

## How to run

-   Clone repository

````git clone [https://github.com/antonafonix/c-math-evaluator.git](https://github.com/antonafonix/c-math-evaluator.git)
cd c-math-evaluator ```
- Compile
``` mkdir build && cd build && cmake .. && make```
- To run
```./math_tool "1 + 2 - (1 + 3) ^ 2 - 1 - 2 / 3" ```
NOTE: include your expression in ""

````
