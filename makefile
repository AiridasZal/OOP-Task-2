main: functions.o studentas.o
	g++ -o main main.cpp functions.o studentas.o -O3
functions:
	g++  -c functions.cpp
studentas:
	g++ -c studentas.cpp
clean:
	del *.o main.exe studentai*.txt rezultatai.txt
debug:
	del   kieti*.txt nuskriausti*.txt