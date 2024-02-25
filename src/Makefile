CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17
TEST= ./tests/test.cc
GTESTFLAGS= -lgtest
SRC_LIB = smartcalc
GCOVFLAGS= -fprofile-arcs -ftest-coverage -std=c++17
RDIR = ../release/
APP = $(RDIR)SmartCalc_v2.app
REPORT=GCOVreport
ifeq ($(OS), Linux)
  GTESTFLAGS+= -pthread -lpthread -lm
endif

all: clean install test
	./$(RDIR)/SmartCalc_v2

install:
	mkdir $(RDIR)
	cd $(RDIR); qmake ../src/SmartCalc_v2/SmartCalc_v2.pro
	cd $(RDIR); make
	cd $(RDIR); make clean

uninstall:
	rm -rf $(RDIR)SmartCalc_v2*

dist:
	tar -czf $(RDIR)SmartCalc_v2.tgz $(RDIR)SmartCalc_v2*

test: 
	@$(CC) $(CFLAGS) $(TEST) $(GTESTFLAGS) -g -o testrun
	@./testrun

clean:
	@rm -f testrun GCOVreport 2> /dev/null
	@rm -rf report 2> /dev/null
	@rm -rf test.dSYM
	@rm -rf $(RDIR)


gcov_report: test
	@$(CC) $(GCOVFLAGS) $(TEST) $(GTESTFLAGS) -o $(REPORT)
	@chmod +x $(REPORT)
	@./$(REPORT)
	@lcov --no-external -t "$(REPORT)" -o $(REPORT).info -c -d .
	@genhtml -o report $(REPORT).info
	@rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
	@open ./report/index.html
	@rm $(REPORT)
	@rm -rf *.dSYM

leaks: test
	@valgrind --leak-check=yes ./testrun

