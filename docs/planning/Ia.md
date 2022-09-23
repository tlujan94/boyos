# Phase Ia: Improve Error Handling

## MVP
The current error messages can be improved to give the user more information about the invalid input. See expected errors from original Phase I planning document below. A new class is created to facilitate a single point to handle all the error messaging as this is not straight forward to implement via polymorphic exception handling.

## Current Errors
- `divide_by_zero`: "cannot divide by zero"
- `invalid_operand`: "invalid operand"
- `invalid_operator`: "invalid operator"
- `missing_operand`: "missing operand"
- `missing_operator`: "missing operator"

## Expected Errors
- `divide_by_zero`: "cannot divide by zero"
- `invalid_operand`: "invalid operand: ${x}"
- `invalid_operator`: "invalid operator: ${op}"
- `missing_operand`: "missing (first/second) operand"
- `missing_operator`: "missing operator"

## Implementation
The implementation will create a general exception class that takes an enumeration type as the constructor argument as well as a list of c-string arguments (optional). This will be used to "polymorphically" create a general error at run time that can be caught in the main function of `boyos`. This general exception class will hold a member variable of a existing exception and this will call the messaging function for each respective method.
