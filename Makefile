boyos: boyos.cpp
	g++ -o boyos boyos.cpp

test: boyos test.cpp src/errors/missing_operand.cpp
	g++ -o test test.cpp src/errors/missing_operand.cpp
	
clean:
	rm boyos test