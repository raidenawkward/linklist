OBJS := main.o linklist_operation.o linklist_base.o linklist_extern.o

EXEC := a

CFLAGS += -g

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)
clean:
	rm $(OBJS) $(EXEC)
