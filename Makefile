build:
	g++ main.cpp -o main
run:
	./main
bar:
	build run

test:
	./main < /usr/bin/yes > /dev/null

.PHONY: clean
clean:
	rm -rf main a.out