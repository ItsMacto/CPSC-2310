all: lab9

lab9: driver.c functions.c
	gcc -Wall -o lab9 driver.c functions.c -Wall

run: lab9
	./lab9 F23Data.csv output.txt

clean:
	rm -f lab9
