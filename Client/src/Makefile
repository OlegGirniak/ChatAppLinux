CXX = g++
CPPFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lstdc++

app: main.o Client.o
	$(CXX) $(CPPFLAGS) -o app main.o Client.o $(LDFLAGS)

main.o: main.cpp Client.h
	$(CXX) $(CPPFLAGS) -c main.cpp

Server.o: Client.cpp Client.h
	$(CXX) $(CPPFLAGS) -c Client.cpp

clean:
	rm -f app *.o