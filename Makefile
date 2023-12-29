repl: src/lexer.c src/main.c src/repl.c src/token.c
	clang -o repl -g src/lexer.c src/main.c src/repl.c src/token.c

test: src/tests/lexer_test.c src/tests/test_all.c src/lexer.c src/token.c src/tests/parser_test.c src/parser.c src/statement.c
	clang -o test -g src/tests/lexer_test.c src/tests/test_all.c src/lexer.c src/token.c src/tests/parser_test.c src/parser.c src/statement.c

clean:
	rm -f repl *.o
	rm -f test *.o
