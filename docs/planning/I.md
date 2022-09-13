# Phase I: Basic Two-Operand Calculator

## MVP
The minimum viable product will be a basic calculator that receives a string input containing two integer operands and an operator and outputs an integer result of the operation performed.

## Input
- Input will be read in from the **system arguments**.
- A character string containing an integer: x followed by an operator followed by another integer: y.
- x and y must conform to bounds of c++ integer primative (32-bit).
    - Lower Bound: **-2,147,483,648**
    - Upper Bound:  &nbsp; **2,147,483,647**
    - x and y must conform to regular expression: `\-?\d{1,10}`
- Allows basic arithmetic operators:
    - multiplication: \*
    - division: \\
    - addition: +
    - subtraction: -
    - operator must conform to regular expression: `[\*\/\+\-]`

## Output
- Output is logged to the **console**.
- An integer that results from the operation applied to the two operands x and y above (see above for bounds).
- This return value will be congruent with c++ behavior for these operator for integer operand types.

## Expected Errors
- ### x:
    - Missing Operand: `"must include integer operand x"`
    - Parsing error: `"unable to parse value ${x} as an integer"`
- ### y:
    - Missing Operand: `"must include integer operand y"`
    - Parsing Error: `"unable to parse value ${y} as an integer"`
- ### operator:
    - Missing Operator: `"must include an operator {*, /, +, -}"`
    - Parsing Error: `"unable to parse value ${operator} as a valid operator`
- ### runtime:
    - divide by zero: `"unable to divide by zero"`

## Implementation
- ### `namespace Boyos`:
    - `int evaluate(const char* x, const char* op, const char* y)`
        - throws: any expected error (except missing)
    - `int parseOperand(const char* x)`
        - throws: Parsing Error
    - `namespace Error`:
        - `const char* missingOperand(const char* x, const char* variable)`
        - `const char* parsingOperand(const char* x, const char* variable)`
        - `const char* parsingOperator(const char* op, const char* variable)`
        - `const char* MISSING_OPERATOR`
        - `const char* DIVIDE_BY_ZERO`

## Testing
Use test driven development. Aim for 100% statement, function, and branch coverage. Note exceptions. Work starting from integration testing and then unit testing.
- Look into [Catch2 Framework](https://github.com/catchorg/Catch2) for either current phase or future phase.