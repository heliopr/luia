build:
	gcc ./src/*.c -lm -lSDL2 -lSDL2_ttf -o out

run:
	./out

clean:
	rm ./out