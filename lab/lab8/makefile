all: circleProgram

circleProgram: driver.c ppm.c shape.c
	gcc -Wall -o circleProgram driver.c ppm.c shape.c -lm -Wall

run: circleProgram
	./circleProgram input.txt output.ppm

clean:
	rm -f circleProgram
