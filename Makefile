OBJS := main.o linklist.o

EXEC := a

#CFLAGS += -g

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)
clean:
	rm $(OBJS) $(EXEC)
