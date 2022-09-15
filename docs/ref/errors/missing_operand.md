# **`class`** `missing_operand` #
## extends ##
 - std::exception

## files ##
 - `src/errors/missing_operand.h`
 - `src/errors/missing_operand.cpp`

## data member ##
 - `const char var[64]`: name of missing operand

 ## constructor ##
 ### `missing_operand(const char* var)` ###
 - `var`: name of missing operand

 ## method ##
 ### `const char* what()`
  - `return`: "missing operand: ${var}"
