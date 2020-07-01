# Make file for running the project
CC=gcc
CFLAGS= -Wall -g
LDFLAGS = -include
OBJFILES = main.o queue.o stack.o
HEADERS = main.h queue.h stack.h
TARGET = library

all: run 

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c -o $@ $<

${TARGET}: ${OBJFILES}
	${CC} ${CFLAGS} -o ${TARGET} ${OBJFILES}

run: ${TARGET}
	./${TARGET}

.PHONY: all run

clean:
	rm -f $(OBJFILES) $(TARGET) *~
