all:
	g++ -std=c++17 -g main.cpp src/**.cpp -Wall -Wextra -o main -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network 