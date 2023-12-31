CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11 
CHFLAGS = -fprofile-arcs -ftest-coverage



all: clean test


style_check:
	clang-format -n *.c
	clang-format -n *.h
	clang-format -n files/*.c

style_correct:
	clang-format -i *.c
	clang-format -n *.c
	clang-format -i *.h
	clang-format -n *.h
	clang-format -i files/*.c
	clang-format -n files/*.c



s21_decimal.a: s21_decimal
	ar rc s21_decimal.a *.o
	rm *.o
	ranlib s21_decimal.a


s21_decimal: s21_decimal.h
	${CC} ${FLAGS} -c files/*.c

s21_decimal_test.a: s21_decimal_test
	ar rc s21_decimal.a *.o
	rm *.o
	ranlib s21_decimal.a


s21_decimal_test: s21_decimal.h
	${CC} ${FLAGS} ${CHFLAGS} -c files/*.c


test: s21_decimal_test.a s21_decimal_test.c
	$(CC) $(FLAGS) $(CHFLAGS) -c s21_decimal_test.c -lcheck -pthread -lrt
	$(CC) $(FLAGS) $(CHFLAGS) -o test *.o -Lfiles s21_decimal.a -lm -lcheck -lpthread -lrt -lsubunit --coverage
	./test


gcov_report: test
	mkdir -p html
	gcov -b -l -p -c *.gcno 
	gcovr -o html/gcov_report.html --html --html-details
	rm *.gcno
	open html/gcov_report.html


clean:
	rm -rf html/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov_main ./test
