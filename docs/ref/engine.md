# **`class`** `engine` #

## files ##
 - `engine.h`
 - `engine.cpp`

 ## method(s) ##
 ### `static int _parse(const char* a)` ###
 - `a`: c-string represented integer
 - throws: `invalid_operand`
 - `return`: integer value of `a`

 ### `static void _validate(int argc)` ###
  - `argc`: number of arguments
  - throws: `missing_operand`; `missing_operator`