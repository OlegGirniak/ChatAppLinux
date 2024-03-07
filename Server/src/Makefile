CXX = g++
CPPFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lstdc++

app: main.o Server.o
	$(CXX) $(CPPFLAGS) -o app main.o Server.o $(LDFLAGS)

main.o: main.cpp Server.h
	$(CXX) $(CPPFLAGS) -c main.cpp

Server.o: Server.cpp Server.h
	$(CXX) $(CPPFLAGS) -c Server.cpp

clean:
	rm -f app *.o