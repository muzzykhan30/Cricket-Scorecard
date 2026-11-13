CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCS = start.c init.c match.c odi.c stats.c t20.c toss.c
OBJS = $(SRCS:.c=.o)
TARGET = cric_app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
