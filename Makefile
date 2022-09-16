boyos: boyos.cpp
	g++ -o boyos boyos.cpp

test: boyos test.cpp src/engine.cpp src/errors/invalid_operand.cpp src/errors/missing_operand.cpp src/errors/missing_operator.cpp
	g++ -o test test.cpp src/engine.cpp src/errors/invalid_operand.cpp src/errors/missing_operand.cpp src/errors/missing_operator.cpp
	
clean:
	rm boyos test