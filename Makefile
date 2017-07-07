PROJ=alpha_compiler#			# The name of the project and executable
SDIR=./src#				# Path to included .c files'directory
IDIR =./include# 			# Path to included .h files' directory
CC=gcc#	 				# Compiler to be used
CFLAGS=-I$(IDIR) -Wall#			# Compilation flags

ODIR=$(SDIR)/obj# 			# Path to output .o files' directory
LDIR =./lib# 				# Path to library files' directory
LIBS=-lm#				# Additional compilation macros e.g. -lm

# Below is a list of all .h files on which .c files depend
_DEPS = exeOutput.h ExprDblList.h ExprList.h expressions.h handler.h IntStack.h manage.h offsets.h parser.h quads.h SymbolStack.h SymbolTable.h const_tables.h instructions.h generator.h vmarguments.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Below is a list of all .o files on which .c files depend
_OBJ = exeOutput.o ExprDblList.o ExprList.o expressions.o handler.o IntStack.o manage.o offsets.o parser.o quads.o scanner.o SymbolStack.o SymbolTable.o const_tables.o instructions.o generator.o vmarguments.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

################################################################################

# Rule below will automagically link all .o files
$(PROJ): $(OBJ) $(ODIR)/scanner.o	# Only scanner.o needs specific decl
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
	
# Specific rule below is needed only because parser.c depends on parser.y
$(ODIR)/parser.o: $(SDIR)/parser.y	# Specific rule to compile parser
	bison -v --yacc --defines --output=$(SDIR)/parser.c $(SDIR)/parser.y
	$(CC) -c -o $@ $(SDIR)/parser.c

# Specific rule below is needed only because scanner.c depends on al.l
$(ODIR)/scanner.o: $(SDIR)/al.l		# Specific rule to compile scanner
	flex --outfile=$(SDIR)/scanner.c $(SDIR)/al.l
	$(CC) -c -o $@ $(SDIR)/scanner.c

# Rule below will automagically compile all .c files to .o
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Cleans up project
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~	# Clean .o files
	rm -f $(SDIR)/*~			# Clean backups of .c files
	rm -f $(IDIR)/*~			# Clean backups of .h files	
	rm -f ./$(PROJ)				# Clean project executable
	
	rm -f $(SDIR)/scanner.c		# Clean scanner.c file
	rm -f $(SDIR)/parser.output	# Clean parser.output file
	rm -f $(SDIR)/parser.h		# Clean parser.h file
	rm -f out.abc			# Clean generated alpha binary file
