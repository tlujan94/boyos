# `boyos` API Refrence #

## Overview ##
`boyos` is a command-line calculator tool that can perform basic 2-operand operations of the set {multiplication - `*`, division - `/`, modulo - `%`, addition - `+`, subtraction `-`}. Each operand must be parsable as `int` (see bellow). The output of the application will be a string representation of `int` if the operation was successfull, or an `error` (see bellow) message otherwise.

## Terms ##
Throughout the rest of this document, we will refer to the following terms.
- lhs := x in the input of form `x + y = z`
- rhs := y in the input of form `x + y = z`

## `int` ##
Each operatand `lhs` and `rhs` must be parsable as a 32-bit integer and have a string that conforms to the following:
- cannot contain any non-digit numbers (sign character excluded)
- sign must be first character if included
- maximum value of: `+2147483647`
- minimum value of: `-2147483648`
- no leading zeros: (i.e.) `01`

## `errors` ##
- `cannot divide by zero`: `rhs` cannot equal zero for `/` and `` operations.
- `invalid operand`: `lhs` or `rhs` cannot be parsed into in `int`.
- `invalid operator` : the operator given is invalid or unsupported.
- `missing operand` : `lhs` or `rhs` are missing from the command-line arguments.
- `missing operator` : missing operator from command-line arguments.

## Example ##
input: `./boyos 1 + 2`

output: `3`