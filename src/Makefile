.PHONY: all clean test s21_math.a gcov_report

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
EXEC = main
TESTEXEC = test

SOURCES= s21_*.c
OBJECTS= s21_*.o

SUITE_CASES_C = tests/suite_s21_*.c
SUITE_CASES_O = tests/suite_s21_*.o

ALLPROJECT = *.c *.h tests/*.c tests/*.h

all: clean s21_math.a
	$(CC) $(CFLAGS) -c main.c -lm
	$(CC) -o $(EXEC) main.o s21_math.a -lm

s21_math.a:
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rcs s21_math.a $(OBJECTS)
	rm -f *.o

test: clean s21_math.a
	$(CC) $(CFLAGS) -c tests/main_tests.c
	$(CC) -c $(CFLAGS) $(SUITE_CASES_C)
	ar rcs suite_cases.a suite_s21_*.o main_tests.o
	rm -f *.o
	$(CC) $(CFLAGS) --coverage -o $(TESTEXEC) s21_math.a suite_cases.a $(SOURCES) -lcheck -lm
	./$(TESTEXEC)

gcov_report: clean test
	gcov test-s21_*.gcda	
	gcovr -b 
	gcovr
	gcovr --html-details -o report.html

check:
	cppcheck --enable=all --force --check-config for details *.c *.h
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c $(ALLPROJECT)
#	CK_FORK=no leaks --atExit -- ./tests
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./$(TESTEXEC)

clean:
	find . -name '*.gcno' -type f -delete
	find . -name '*.gcda' -type f -delete
	find . -name '*.a' -type f -delete
	find . -name '*.o' -type f -delete
	find . -name '*.info' -type f -delete
	find . -name '*.html' -type f -delete
	find . -name '*.css' -type f -delete
	rm -f CPPLINT.cfg
	rm -f $(EXEC)
	rm -f $(TESTEXEC)
	rm -f RESULT_VALGRIND.txt
	rm -rf report
