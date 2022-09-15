# **`class`** `engine` #

## files ##
 - `engine.h`
 - `engine.cpp`

## member variables ##
 - `static const int _BUFFER_SIZE`: number of operand characters permitted
 - `char _lhs[_BUFFER_SIZE]`: left-hand-side operand
 - `char _rhs[_BUFFER_SIZE]`: right-hand-side operand
 - `char _operator`: operator

 ## constructor(s) ##
 ### `engine(int argc, const char** argv)` ###
 - `argc`: number of arguments
 - `argv`: array of c-string arguments

 ## method(s) ##
 ### `void _validate(int argc)`
  - `argc`: number of arguments
  - throws: `missing_operand`; `missing_operator`