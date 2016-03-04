# instance.o: instance.cpp instance.hpp
# 	g++ -c instance.cpp -Wall -Llua-5.3.2/src -Ilua-5.3.2/src -llua -ldl

main: main.cpp main.hpp
	g++ main.cpp -o main -Wall -Llua-5.3.2/src -Ilua-5.3.2/src -llua -ldl

run: main
	./main

clean:
	rm main
	rm instance.o