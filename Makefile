all: 
	hello-cpp-world hello-c-world tic-tac-toe lobby-sample random-sample game-menu zoo-keeper hang-man sample-test black-jack

%: %.cc
	g++ -std=c++11 $< -o $@
	
%: %.c
	gcc $< -o $@

game-menu: game-menu.cc
	g++ -std=c++11 $< -o $@

clean:
	rm * .exe *.o