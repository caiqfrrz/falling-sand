all:
	g++ -std=c++17 main.cpp src/**.cpp -o main -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network 