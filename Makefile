boyos: boyos.cpp src/engine.cpp src/errors/divide_by_zero.cpp src/errors/invalid_operand.cpp src/errors/invalid_operator.cpp src/errors/missing_operand.cpp src/errors/missing_operator.cpp
	g++ -o boyos boyos.cpp src/engine.cpp src/errors/divide_by_zero.cpp src/errors/invalid_operand.cpp src/errors/invalid_operator.cpp src/errors/missing_operand.cpp src/errors/missing_operator.cpp

test: boyos test.cpp src/engine.cpp src/errors/divide_by_zero.cpp src/errors/invalid_operand.cpp src/errors/invalid_operator.cpp src/errors/missing_operand.cpp src/errors/missing_operator.cpp
	g++ -o test test.cpp src/engine.cpp src/errors/divide_by_zero.cpp src/errors/invalid_operand.cpp src/errors/invalid_operator.cpp src/errors/missing_operand.cpp src/errors/missing_operator.cpp
	
clean:
	rm boyos test