OBJS := main.o operation.o base.o extern.o

EXEC := a

CFLAGS += -g

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)
clean:
	rm $(OBJS) $(EXEC)
