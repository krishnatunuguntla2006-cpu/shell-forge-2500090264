CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I. -Iinclude
LIBS = -lreadline

SRCS = $(wildcard src/*.c)
TARGET = shellforge

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET)
