OBJS := main.o linklist.o

EXEC := a

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)
clean:
distclean:
	rm $(OBJS) $(EXEC)
