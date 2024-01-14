build:
	gcc ./src/*.c -lm -lSDL2 -o out

run:
	./out

clean:
	rm ./out