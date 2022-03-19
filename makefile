main: functions.o
	g++ -o main main.cpp functions.o
functions:
	g++ -c functions.cpp
clean:
	del *.o main.exe studentai*.txt rezultatai.txt
debug:
	del   kieti*.txt nuskriausti*.txt