comp: src/lexer.c src/main.c src/repl.c src/token.c
	clang -o comp -g src/lexer.c src/main.c src/repl.c src/token.c

clean:
	rm -f comp *.o
