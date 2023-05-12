# Makefile

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
SRC = ${wildcard src/*.c}
HEA = ${wildcard header/*.h}

all: main.exe

main.exe: ${SRC}
	${CC} ${CFLAGS} $^ -o $@

.PHONY: clean

clean:
	rm main.exe
	rm -rf .vscode/

# End