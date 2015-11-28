CC	= gcc
CFLAGS	= -Wall -Werror -g -O0 -std=gnu11 
LDFLAGS = -L. 

pebble-notecard: pebble-notecard.o 
	$(CC) $(CFLAGS) -o $@ $^

pebble-notecard.o: pebble-notecard.c pebble-notecard
	$(CC) $(FLAGS) -o $@ $<
	
clean:
	$(RM) pebble-notecard *.o *~ 


	

