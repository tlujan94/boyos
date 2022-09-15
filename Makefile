boyos: boyos.cpp
	g++ -o boyos boyos.cpp

test: boyos test.cpp
	g++ -o test test.cpp
	
clean:
	rm boyos