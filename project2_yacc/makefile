CC = gcc
LEX = flex
YACC = bison
LEX_FILENAME = rust.l
YACC_FILENAME = rust.y
OUTPUT_FILENAME = rust.out
TEST_FILENAME = example.rust
OTHER_SOURCE = union.h

$(OUTPUT_FILENAME): clean lex.yy.o rust.tab.o
	$(CC) lex.yy.o rust.tab.o $(OTHER_SOURCE) -o $(OUTPUT_FILENAME)

lex.yy.o: lex.yy.c rust.tab.h
	$(CC) -c lex.yy.c

rust.tab.o: rust.tab.c
	$(CC) -c rust.tab.c

rust.tab.c rust.tab.h: $(YACC_FILENAME)
	$(YACC) -d $(YACC_FILENAME)

lex.yy.c: $(LEX_FILENAME)
	$(LEX) -o lex.yy.c $(LEX_FILENAME)

clean:
	rm -f lex.yy.c rust.tab.c rust.tab.h  *.o *.out 

run: 
	./$(OUTPUT_FILENAME) < $(TEST_FILENAME)
