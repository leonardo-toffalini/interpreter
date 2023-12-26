repl: src/lexer.c src/main.c src/repl.c src/token.c
	clang -o repl -g src/lexer.c src/main.c src/repl.c src/token.c

clean:
	rm -f repl *.o
