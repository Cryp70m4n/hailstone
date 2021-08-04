install:
	gcc -march=native -O2 -Wall -pipe hailstone.c -o hailstone
	sudo cp hailstone /usr/bin/hailstone 
clean:
	sudo rm -rf ./hailstone /usr/bin/hailstone
