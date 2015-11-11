MAIN = substr
CPPFLAGS = -O2 --std=c++14

run: $(MAIN)
	./$(MAIN) < data > results

program: $(MAIN).cpp
	g++ $(CPPFLAGS) $(MAIN).cpp -o $(MAIN)

clean: $(MAIN)
	rm ./$(MAIN)
