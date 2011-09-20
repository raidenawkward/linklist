SRC := $(shell ls ./*.c)
OBJS = $(SRC:.c=.o)

TAR_EXEC := a
TAR_LIB := linklist.so
TAR_ALIB := linklist.a

CFLAGS += -g

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TAR_EXEC)
	$(CC) $(CFLAGS) $(OBJS) -shared -o $(TAR_LIB)
	ar -r $(TAR_ALIB) $(OBJS)
clean:
	rm $(OBJS) $(TAR_EXEC) $(TAR_LIB) $(TAR_ALIB)
