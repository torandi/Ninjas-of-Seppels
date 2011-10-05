OBJS = input.o room.o entity.o door.o game.o file_parser.o screen.o
CFLAGS += -Wall -g 
LDFLAGS += -lncurses

all: seppels 
 
seppels: main.o $(OBJS)
	$(CXX) main.o $(OBJS) $(LDFLAGS) -o $@

parse_test: parse_test.o $(OBJS)
	$(CXX) parse_test.o $(OBJS) $(LDFLAGS) -o $@

clean:
	rm -rf *.o *.d seppels

%.o : %.cpp %.h
	@$(CXX) -MM $(CFLAGS) $< > $*.d
	$(CXX) $(CFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)
