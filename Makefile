OBJS = main.o screen.o input.o
CFLAGS += -Wall -g 
LDFLAGS += -lncurses

all: seppels 
 
seppels: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

clean:
	rm -rf *.o *.d seppels

%.o : %.cpp %.h
	@$(CXX) -MM $(CFLAGS) $< > $*.d
	$(CXX) $(CFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)
