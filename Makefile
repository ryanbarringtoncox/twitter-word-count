CPP = g++
CFLAGS = -Wall -Wextra -Werror

all: test

test: twitter_word_count.cpp
	$(CPP) $(CFLAGS) -o test $^

clean:
	rm -f *.o;
	rm -f test; 
	rm -f output.txt
