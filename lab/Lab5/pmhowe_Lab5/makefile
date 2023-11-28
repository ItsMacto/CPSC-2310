all: ppmDriver

ppmDriver: ppmDriver.c ppmUtil.c
	gcc -o ppmDriver ppmDriver.c ppmUtil.c

run: 
	./ppmDriver input.ppm output.ppm

clean:
	rm -f ppmDriver


