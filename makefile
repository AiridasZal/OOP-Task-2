main: functions.o
	g++ -O3 -o main main.cpp functions.o
functions:
	g++ -O3 -c functions.cpp
clean:
	del *.o main.exe studentai*.txt rezultatai.txt
debug:
	del   kieti*.txt nuskriausti*.txt