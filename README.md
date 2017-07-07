Alpha Compiler
==============

A compiler for a javascript-like language called `Alpha`.

Build
-----

Using a terminal, navigate in the project folder and type:

```sh
make
```

This will compile and link all files and libraries into a single file `alpha_compiler`.

Run
---

One can either launch the compiler typing input in real time, using the keyboard as the input stream and when done end with an EOF (ctrl + D):

```sh
./alpha_compiler
```

Alternatively the compiler can be launched with an existing Alpha program saved in a file by simply redirecting the input stream.

Using an example Alpha program found in file `simple-program.alpha`, one could do it like this.

```sh
./alpha_compiler < simple-program.alpha > simple-program.debug
```

This will save the compiler's output to the binary file `out.abc`  and also save debug info in a separate file `simple-program.debug`.

The binary executable `out.abc` is then ready to be executed by the Alpha [Virtual Machine](https://github.com/maninak/alpha_vm).

Example
-------

With the following Alpha program:

```js
function add (a, b) {
  print (a+b);
}

a = 5;
b = 10;

add(a, b);
```

Here's the output of the debug output of the alpha compiler:

```
1: stmts -> empty
1: funcname -> ID
1: funcprefix -> FUNCTION funcname
1: ids -> empty 
1: ids -> ',' ID ids
1: idlist -> ID ids
1: funcargs -> '(' idlist ')'
1: stmts -> empty
2: lvalue -> ID
2: lvalue -> ID
2: primary -> lvalue
2: term -> primary
2: expr -> term
2: lvalue -> ID
2: primary -> lvalue
2: term -> primary
2: expr -> term
expr -> expr '+' expr
2: exprs -> empty
2: elist -> expr exprs
2: callsuffix -> normcall
2: primary -> call
2: term -> primary
2: expr -> term
2: stmt -> expr;
truelist for expr: [ ]
falselist for expr: [ ]
2: stmts -> stmts stmt
3: block-> '{' stmts '}' 
3: funcbody -> block
3: funcdef -> funcprefix funcargs funcbody
3: stmt -> funcdef
3: stmts -> stmts stmt
5: lvalue -> ID
5: const -> NUMBER
5: primary -> const
5: term -> primary
5: expr -> term
5: assignexpr -> lvalue=expr
5: expr -> assignexpr
truelist for assignexpr: [ ]
falselist for assignexpr: [ ]
5: stmt -> expr;
truelist for expr: [ ]
falselist for expr: [ ]
5: stmts -> stmts stmt
6: lvalue -> ID
6: const -> NUMBER
6: primary -> const
6: term -> primary
6: expr -> term
6: assignexpr -> lvalue=expr
6: expr -> assignexpr
truelist for assignexpr: [ ]
falselist for assignexpr: [ ]
6: stmt -> expr;
truelist for expr: [ ]
falselist for expr: [ ]
6: stmts -> stmts stmt
8: lvalue -> ID
8: lvalue -> ID
8: primary -> lvalue
8: term -> primary
8: expr -> term
8: lvalue -> ID
8: primary -> lvalue
8: term -> primary
8: expr -> term
8: exprs -> empty
8: exprs -> ',' expr exprs
8: elist -> expr exprs
8: callsuffix -> normcall
8: primary -> call
8: term -> primary
8: expr -> term
8: stmt -> expr;
truelist for expr: [ ]
falselist for expr: [ ]
8: stmts -> stmts stmt
8: program -> stmts

--- SYMBOL TABLE PRINTOUT -------------------------------------------------------------------

line: 0 scope: 0	Program	Library Function	'cos'
line: 0 scope: 0	Program	Library Function	'sin'
line: 0 scope: 0	Program	Library Function	'strtonum'
line: 0 scope: 0	Program	Library Function	'argument'
line: 0 scope: 0	Program	Library Function	'sqrt'
line: 0 scope: 0	Program	Library Function	'objecttotalmembers'
line: 0 scope: 0	Program	Library Function	'objectcopy'
line: 0 scope: 0	Program	Library Function	'print'
line: 0 scope: 0	Program	Library Function	'totalarguments'
line: 0 scope: 0	Program	Library Function	'input'
line: 0 scope: 0	Program	Library Function	'typeof'
line: 0 scope: 0	Program	Library Function	'objectmemberkeys'
line: 1 scope: 1	Formal	Formal  Argument		'b'
line: 1 scope: 1	Formal	Formal  Argument		'a'
line: 1 scope: 0	Program	User Function		'add'
line: 2 scope: 1	Local	Variable		'_t2'
line: 2 scope: 1	Local	Variable		'_t1'
line: 5 scope: 0	Program	Variable		'_t2'
line: 5 scope: 0	Program	Variable		'_t1'
line: 5 scope: 0	Program	Variable		'a'
line: 6 scope: 0	Program	Variable		'b'

--- QUAD INSTRUCTIONS PRINTOUT ---------------------------------------------------------------
Quad      OpCode              Arg1                Arg2                Result             Label
----------------------------------------------------------------------------------------------
Total Quads = 7

0:        funcstart           add                                                        
1:        add                 a                   b                   _t1                
2:        funcend             add                                                        
3:        assign              5.000000                                a                  
4:        assign              a                                       _t1                
5:        assign              10.000000                               b                  
6:        assign              b                                       _t1                
INSTRUCTIONS
Inst              OP           Arg1           Arg2	         Result	  Line
   0       enterfunc                                        programfunc(0)  1

   1             add         formal(1)         formal(0)          local(0)  2

   2        exitfunc                                        programfunc(0)  3

   3          assign         number(0)                           global(13)  5

   4          assign         global(13)                           global(14)  5

   5          assign         number(1)                           global(16)  6

   6          assign         global(16)                           global(14)  6

String Array

Number Array
0: 5.000000
1: 10.000000

Library Functions Array

User Functions Array
0: T-ad:0 Loc:2 add

```