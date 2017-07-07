#ifndef _MANAGE_C_
#define _MANAGE_C_

#include "../include/manage.h"

int		 currentScope = 0;

char 	newName[32];
char 	defaultFuncPrefix[] 	= "_func";
char 	defaultTempVarPrefix[] 	= "_t";
int  	unnamedFuncCount 	 	= 0;
int 	tempVarCount = 0;		// A count of the active temp vars

void initManager(){
	mySymTab 	 		= createSymbolTable();
	curFuncStack 		= createSymbolStack();
	scopeOffsetStack 	= createIntStack   ();
}


/********** program **********/
void manage_stmts() {
	printf("%d: program -> stmts\n",yylineno);
}

/********** stmts **********/
void manage_stmts_stmt() {
	printf("%d: stmts -> stmts stmt\n",yylineno);
}

void manage_stmts_empty() {
	printf("%d: stmts -> empty\n",yylineno);
}

/********** stmt **********/
void manage_stmt_expr(Expr * expr) {
	printf("%d: stmt -> expr;\n",yylineno);
	assert(expr);
	
	Expr * boolExprResult = newexpr(var_e);
	boolExprResult->sym = newtemp();
	
	printf("truelist for expr: "); printIntStack(expr->truelist); //TODO delete
	printf("falselist for expr: "); printIntStack(expr->falselist); //TODO delete
	
	int nextQuad  = nextquadlabel();
	if (expr->type == boolexpr_e){
		backpatch(expr->truelist,  nextQuad);
		backpatch(expr->falselist, nextQuad+2);
		emit(assign, newexpr_constbool(1), NULL, boolExprResult, 0);
		emit(jump, NULL, NULL, NULL, nextQuad+3);
		emit(assign, newexpr_constbool(0), NULL, boolExprResult, 0);
	}
	else {
		backpatch(expr->truelist,  nextQuad);
		backpatch(expr->falselist, nextQuad);		
	}
	
	resetTempVarCount();
}

void manage_stmt_if() {
	printf("%d: stmt -> if\n",yylineno);
}

void manage_stmt_while() {
	printf("%d: stmt -> while\n",yylineno);
}

void manage_stmt_forstmt() {
	printf("%d: stmt -> forstmt\n",yylineno);
}

void manage_stmt_returnstmt() {
	printf("%d: stmt -> returnstmt\n",yylineno);
}

void manage_stmt_brk() {
	printf("%d: stmt -> break\n",yylineno);
}

void manage_stmt_cntnue() {
	printf("%d: stmt -> continue\n",yylineno);
}

void manage_stmt_block() {
	printf("%d: stmt -> block\n",yylineno);
}

void manage_stmt_funcdef() {
	printf("%d: stmt -> funcdef\n",yylineno);
}

void manage_stmt_UNRECOGNIZED() {
	printf("%d: stmt -> unrecognized\n",yylineno);
}

void manage_stmt_error() {
	/*inform about error*/
}

void manage_stmt_semicolumn() {
	printf("%d: stmt -> ;\n",yylineno);
}

/********** expr **********/
Expr * manage_expr_assignexpr(Expr * expr) {
	printf("%d: expr -> assignexpr\n",yylineno);
	printf("truelist for assignexpr: "); printIntStack(expr->truelist); //TODO delete
	printf("falselist for assignexpr: "); printIntStack(expr->falselist); //TODO delete
	return expr;
}

void manage_expr_expr_plus_expr() {
	printf("%d: expr -> expr+expr\n",yylineno);
}

void manage_expr_expr_minus_expr() {
	printf("%d: expr -> expr-expr\n",yylineno);
}

void manage_expr_expr_star_expr() {
	printf("%d: expr -> expr*expr\n",yylineno);
}

void manage_expr_expr_div_expr() {
	printf("%d: expr -> expr/expr\n",yylineno);
}

void manage_expr_expr_mod_expr() {
	printf("%d: expr -> expr percent expr\n",yylineno);
}

void manage_expr_expr_greater_expr() {
	printf("%d: expr -> expr>expr\n",yylineno);
}

void manage_expr_expr_GREATER_EQ_expr() {
	printf("%d: expr -> expr>=expr\n",yylineno);
}

void manage_expr_expr_less_expr() {
	printf("%d: expr -> expr<expr\n",yylineno);
}

void manage_expr_expr_LESS_EQ_expr() {
	printf("%d: expr -> expr<=expr\n",yylineno);
}

void manage_expr_expr_EQ_expr() {
	printf("%d: expr -> expr==expr\n",yylineno);
}

void manage_expr_expr_NOT_EQ_expr() {
	printf("%d: expr -> expr!=expr\n",yylineno);
}

void manage_expr_expr_AND_expr() {
	printf("%d: expr -> expr&&expr\n",yylineno);
}

void manage_expr_expr_OR_expr() {
	printf("%d: expr -> expr||expr\n",yylineno);
}

Expr * manage_expr_term(Expr * term) {
	printf("%d: expr -> term\n",yylineno);
	return term;
}

/********** term  **********/
Expr * manage_term_expr_parenthesis(Expr * expr) {
	printf("%d: term -> '(' expr')'\n",yylineno);
	return expr;
}

void manage_term_UMINUS_expr() {
	printf("%d: term -> -expr uminus\n",yylineno);
}

void manage_term_NOT_expr() {
	printf("%d: term -> NOT expr\n",yylineno);
}

void manage_term_PLUS_PLUS_lvalue(struct Expr * term) {
	printf("%d: term -> ++lvalue\n",yylineno);
	assert(tempSymbol);
	if (tempSymbol->symbolType == FUNC || tempSymbol->symbolType == LIB_FUNC) {
		printf("%d: #ERROR: Cannot increment const function identifier \"%s\".\n ",
				yylineno, tempSymbol->name);
	}
}

void manage_term_lvalue_PLUS_PLUS(struct Expr * term) {
	printf("%d: term -> lvalue++\n",yylineno);
	assert(tempSymbol);
	if (tempSymbol->symbolType == FUNC || tempSymbol->symbolType == LIB_FUNC) {
		printf("%d: #ERROR: Cannot increment const function identifier \"%s\".\n ",
				yylineno, tempSymbol->name);
	}
}

void manage_term_MINUS_MINUS_lvalue(struct Expr * term) {
	printf("%d: term -> --lavalue\n",yylineno);
	assert(tempSymbol);
	if (tempSymbol->symbolType == FUNC || tempSymbol->symbolType == LIB_FUNC) {
		printf("%d: #ERROR: Cannot decrement const function identifier \"%s\".\n ",
				yylineno, tempSymbol->name);
	}
}

void manage_term_lvalue_MINUS_MINUS(struct Expr * term) {
	printf("%d: term -> lvalue--\n",yylineno);
	assert(tempSymbol);
	if (tempSymbol->symbolType == FUNC || tempSymbol->symbolType == LIB_FUNC) {
		printf("%d: #ERROR: Cannot increment const function identifier \"%s\".\n ",
				yylineno, tempSymbol->name);
	}
}

Expr * manage_term_primary(Expr * primary) {
	printf("%d: term -> primary\n",yylineno);
	return primary;
}

/********** assignexpr **********/
Expr * manage_assignexpr_lvalue_assign_expr(Expr * lvalue, Expr * expr){
	printf("%d: assignexpr -> lvalue=expr\n",yylineno);
	assert(lvalue);	// TODO not checked if safe to delete
	assert(expr);	// TODO not checked if safe to delete
	
	Expr * assignexpr;
	/* If parsing error in lvalue->ID, then lvalue will be NULL. In that
	 * case we can overlook this wrong assign expression to bypass
	 * segmentation fault
	 */
	if (tempSymbol != NULL){
		if (tempSymbol->symbolType == FUNC ||
				tempSymbol->symbolType == LIB_FUNC) {
			printf("%d: #ERROR: Cannot assign value to constant function "
					"identifier \"%s\".\n", yylineno, lvalue->sym->name);
		}
		// OK!
		if (lvalue->type == tableitem_e){ //case lvalue[index] = expr
			emit(tablesetelem, lvalue, lvalue->index, expr, 0);
			assignexpr = emit_iftableitem(lvalue);
			assignexpr->type = assignexpr_e;
		}	
		else{
			assignexpr = newexpr(assignexpr_e);
			assignexpr->sym = newtemp();
			assignexpr->truelist = expr->truelist;
			assignexpr->falselist = expr->falselist;
			if (expr->type == boolexpr_e){ //TODO every parser rule that has expr must have this if
				int nextQuad  = nextquadlabel();
	printf("truelist for assign expr: "); printIntStack(expr->truelist); //TODO delete
	printf("falselist for assign expr: "); printIntStack(expr->falselist); //TODO delete
				backpatch(expr->truelist,  nextQuad);
				backpatch(expr->falselist, nextQuad+2);
				emit(assign, newexpr_constbool(1), NULL, assignexpr, 0);
				emit(jump, NULL, NULL, NULL, nextQuad+3);
				emit(assign, newexpr_constbool(0), NULL, assignexpr, 0);
			}
			else if (expr->type == boolconst_e && expr->boolconst == 1){				
				backpatch(expr->truelist,  nextquadlabel());
			}
			else if (expr->type == boolconst_e && expr->boolconst == 0){				
				backpatch(expr->falselist,  nextquadlabel());
			}
			emit(assign, expr, NULL, lvalue, 0);	
			emit(assign, lvalue, NULL, assignexpr, 0);
		}
	}
	else {
		/* This scope runs only if user code had reference to id not 
		 * supported by our grammar, e.g. bad case.
		 */
		//TODO signal error
	}
	return assignexpr;
}

/********** primary **********/
struct Expr * manage_primary_lvalue (Expr * lvalue){
	printf("%d: primary -> lvalue\n",yylineno);
	return emit_iftableitem(lvalue);
}

Expr * manage_primary_call (Expr * call){
	printf("%d: primary -> call\n",yylineno);
	return call;
}

Expr * manage_primary_tablemake (Expr * tablemake){
	printf("%d: primary -> tablemake\n",yylineno);
	return tablemake;
}

Expr * manage_primary_par_funcdef (Symbol * funcdef){
	printf("%d: primary -> '('function')'\n",yylineno);
	Expr * primary = newexpr(programfunc_e);
	primary->sym = funcdef;
	return primary;
}

Expr * manage_primary_const (Expr * constant){
	printf("%d: primary -> const\n",yylineno);
	return constant;
}

/********** lvalue **********/
Expr * manage_lvalue_ID(char * tempId) {
	printf("%d: lvalue -> ID\n",yylineno);
	
	tempSymbol = lookup(tempId);
	if (tempSymbol == NULL) { // if symbol was not found in Symbol Table
		tempSymbol = createSymbol(tempId, VAR);
		insert(tempSymbol);
		return lvalue_expr(tempSymbol);
	}
	else if (tempSymbol != NULL) { // if symbol was found in Symbol Table
		if (tempSymbol->declInScope == 0){
			// OK
		}
		else if ((tempSymbol->declInFunc != topSymbol(curFuncStack)) &&
				(tempSymbol->symbolType == VAR
						|| tempSymbol->symbolType == ARG)) { // TODO not tested from != FUNC || != LIB_FUNC
			printf("%d: #ERROR: Cannot access identifier \"%s\", declared in "
					"a different function. ",yylineno,tempId);
			printf("Identifier \"%s\" last declared in line %d.\n",
					tempId, tempSymbol->declInLine);
		}
		else {
			// OK
		}
		return lvalue_expr(tempSymbol);
	}
	else { assert(0); } //no man's land.
	return NULL;
}

struct Expr * manage_lvalue_LOCAL_ID(char * tempId) {
	printf("%d: lvalue -> local ID\n",yylineno);
				
	tempSymbol = lookupInScope(tempId, currentScope);
	if(tempSymbol != NULL) {
		// OK
		return lvalue_expr(tempSymbol);
	}
	else if(tempSymbol == NULL) {
		if (isLibSymbol(tempId)) {
			printf("%d: #ERROR: Cannot declare identifier \"%s\" as local, "
					"with name similar to that of a library function.\n",
					yylineno, tempId);
		}
		else {
			tempSymbol = createSymbol(tempId, VAR);
			insert(tempSymbol);
			return lvalue_expr(tempSymbol);
		}
	}
	else { assert (0); } //no man's land
	return NULL;
}

struct Expr * manage_lvalue_DBLCOLON_ID(char * tempId) {
	printf("%d: lvalue -> :: ID\n",yylineno);
				
	tempSymbol = lookupInScope(tempId, 0);				
				
	if (tempSymbol != NULL) {
		//OK
		return lvalue_expr(tempSymbol);
	}
	else if (tempSymbol == NULL) {
		printf("%d: #ERROR: Cannot access undeclared global "
				"identifier \"%s\".\n",yylineno,tempId);
	}
	else { assert (0); } //no man's land
	return NULL;
}

void manage_lvalue_tableitem() {
	printf("%d: lvalue -> tableitem\n",yylineno);
}

/********** tableitem **********/
Expr * manage_tableitem_lvalue_dot_ID(Expr * lvalue, char * ID) {
	printf("%d: memebr -> lvalue . ID\n",yylineno);
	assert(lvalue);
	assert(ID);

	return member_item(lvalue, ID);
}

Expr * manage_tableitem_lvalue_brackets_expr(Expr * lvalue, Expr * expr) {
	printf("%d: memebr -> lvalue '[' expr ']'\n", yylineno);
	assert(lvalue);
	assert(expr);

	lvalue = emit_iftableitem (lvalue);
	Expr* tableitem = newexpr(tableitem_e);
	tableitem->sym = lvalue->sym;
	tableitem->index = expr;
	return tableitem;
}

void manage_tableitem_call_dot_ID() {
	printf("%d: memebr -> call . ID\n",yylineno);
}

void manage_tableitem_call_brackets_expr() {
	printf("%d: memebr -> call '[' expr ']'\n",yylineno);
}

/********** call **********/
/*Expr * manage_call_call_par_elist (Expr * call, ExprList * elist){
	printf("%d: call -> call '(' elist ')'\n",yylineno);
	
	return make_call(call, elist);
}*/

/*Expr * manage_call_lvalue_callsuffix (Expr * lvalue, Expr * callsuffix){
	printf("%d: call -> lvalue callsuffix\n",yylineno);
	assert(lvalue);
	assert(callsuffix);
	
	if (callsuffix->method){
		Expr * self = lvalue;
		lvalue = emit_iftableitem(member_item(self, callsuffix->name));
		addExprListFront(callsuffix->elist, self);
	}
	return make_call(lvalue, callsuffix->elist);
}*/

Expr * manage_call_par_funcdef_normcall (Symbol * funcdef, Expr * normcall){
	printf("%d: call -> '(' funcdef ')'\n",yylineno);
	normcall->type = programfunc_e;
	normcall->sym = funcdef;
	return normcall;
}

/********** callsuffix **********/
Expr * manage_callsuffix_normcall (Expr * normcall){
	printf("%d: callsuffix -> normcall\n",yylineno);
	return normcall;
}

Expr * manage_callsuffix_methodcall (Expr * methodcall){
	printf("%d: callsuffix -> methodcall\n",yylineno);
	return methodcall;
}

/********** normcall **********/
Expr * manage_normcall_par_elist (ExprList * elist){
	printf("%d: normcall -> '('elist ')' \n",yylineno);
	
	Expr * normcall = newexpr(var_e); //TODO not sure. Isn't specified
	normcall->elist = elist;
	normcall->method = 0;
	normcall->name = NULL;
	return normcall;
}

/********** methodcall **********/
Expr * manage_methodcall_DBL_DOT_ID_par_elist (char * id, ExprList * elist){
	printf("%d: methodcall -> .. ID '('elist ')'\n",yylineno);
	
	Expr * methodcall = newexpr(var_e); //TODO not sure. Isn't specified
	methodcall->elist = elist;
	methodcall->method = 1;
	methodcall->name = id;
	return methodcall;
}

/********** elist **********/
void manage_elist_expr_exprs (){
	printf("%d: elist -> expr exprs\n",yylineno);
}

void manage_elist_empty() {
	printf("%d: exprs -> empty\n",yylineno);
}

/********** exprs **********/
void manage_exprs_comma_expr_exprs() {
	printf("%d: exprs -> ',' expr exprs\n",yylineno);
}

void manage_exprs_empty() {
	printf("%d: exprs -> empty\n",yylineno);
}

/********** tablemake **********/
Expr * manage_tablemake_squarebr_elist (ExprList * elist){
	printf("%d: tablemake -> '[' elist ']'\n",yylineno);
	assert(elist);
	
	Expr * t = newexpr(newtable_e);
	t->sym = newtemp();
	emit(tablecreate, t, NULL, NULL, 0);
	int i =0;
	ExprNode * cur = elist->tail;
	while (cur->next != NULL){
		emit(tablesetelem, t, newexpr_constnum(i++), cur->expr, 0);
		cur = cur->next;
	}
	return t;
}

Expr *  manage_tablemake_squarebr_indexed (ExprDblList * indexed){
	printf("%d: tablemake -> '[' indexed ']'\n",yylineno);	
	assert(indexed);
	
	Expr * t = newexpr(newtable_e);
	t->sym = newtemp();
	emit(tablecreate, t, NULL, NULL, 0);
	ExprDblNode * cur = indexed->tail;
	while (cur->next != NULL){
		emit(tablesetelem, t, cur->key, cur->value, 0);
		cur = cur->next;
	}
	return t;
}

/********** indexed **********/
void manage_indexed_indexedelem_indexedelems() {
	printf("%d: indexed -> indexelement indexelements\n",yylineno);
}

/********** indexedelems **********/
void manage_indexedelems_comma_indexedelem_indexedelems() {
	printf("%d: indexedelems -> ',' indexedelem indexedelems\n",yylineno);
}

void manage_indexedelems_empty() {
	printf("%d: indexedelements -> empty\n",yylineno);
}

/********** indexedelem **********/
void manage_indexedelem_brackets_expr_column_expr() {
	printf("%d: indexedelement -> '{' expr ':' expr '}' \n", yylineno);
}

/********** block **********/
void manage_block_brackets_stmts() {
	printf("%d: block-> '{' stmts '}' \n", yylineno);
}

/********** funcdef **********/
Symbol * manage_funcdef_funcprefix_funcargs_funcbody (Symbol * funcprefix, int funcbody){
	printf("%d: funcdef -> funcprefix funcargs funcbody\n", yylineno);
	assert(funcprefix);

	exitscopespace();
	funcprefix->totalLocals = funcbody;
	int oldOffset = popInt(scopeOffsetStack); // pop saved scope offset
	restorecurrscopeoffset(oldOffset);
	emit(funcend, lvalue_expr(funcprefix), NULL, NULL, 0);
	popSymbol(curFuncStack);
	return funcprefix;
}

Symbol * manage_funcprefix_FUNCTION_funcname (char * funcname){
	printf("%d: funcprefix -> FUNCTION funcname\n", yylineno);
	assert(funcname);

	tempSymbol = newFunctionSymbol(funcname);
	emit(funcstart, lvalue_expr(tempSymbol), NULL, NULL, 0);
	pushInt(scopeOffsetStack, currscopeoffset());
	enterscopespace();
	resetformalargsoffset();
	return tempSymbol;
}

char * manage_funcname_ID (char * ID){
	printf("%d: funcname -> ID\n", yylineno);
	return ID;
}

char * manage_funcname_empty (){
	sprintf(newName, "%d: %s%d", yylineno, defaultFuncPrefix, ++unnamedFuncCount);
	return newName;
}

void manage_funcargs_PAR_idlist_PAR (){
	printf("%d: funcargs -> '(' idlist ')'\n", yylineno);
	enterscopespace();				// Now entering function locals space
	resetfunctionlocalssoffset();	// Start locals from zero
	currentScope--;
}

void manage_funcbody_block (int * funcbody){
	printf("%d: funcbody -> block\n", yylineno);
	*funcbody = currscopeoffset(); 	// Extract total locals
	exitscopespace();				// Exiting function locals space
}

Symbol * newFunctionSymbol (char * tempId) {
	assert(tempId);
	tempSymbol = lookupInScope(tempId,currentScope);
					
	if (tempSymbol != NULL) { //if symbol with same name in current scope exists
		printf("%d: #ERROR: Identifier \"%s\" is already declared in the same "
				"scope at line %d.\n",
				yylineno, tempId, tempSymbol->declInLine);
	}
	else if (isLibSymbol(tempId)) {
		printf("%d: #ERROR: Function id \"%s\" is already declared as library "
				"function.\n", yylineno, tempId);
	}
	else {
		tempSymbol = createSymbol(tempId, FUNC);
		insert(tempSymbol);
	}

	pushSymbol(curFuncStack, tempSymbol);
	currentScope++;
	return tempSymbol;
}

/********** const **********/
Expr * manage_const_NUMBER(double number) {
	printf("%d: const -> NUMBER\n",yylineno);
	return newexpr_constnum(number);
}

Expr * manage_const_STR(char * str) {
	printf("%d: const -> STR\n",yylineno);
	return newexpr_conststring(str);
}

Expr * manage_const_NIL() {
	printf("%d: const -> NIL\n",yylineno);
	Expr * e = newexpr(nil_e);
	return e;
}

Expr * manage_const_TRUE() {
	printf("%d: const -> TRUE\n",yylineno);
	return newexpr_constbool(1);
}

Expr * manage_const_FALSE() {
	printf("%d: const -> FALSE\n",yylineno);
	return newexpr_constbool(0);;
}

/********** idlist **********/
void manage_idlist_ID_ids(char * tempId) {
	printf("%d: idlist -> ID ids\n",yylineno);
	tempSymbol = lookupInScope(tempId, currentScope);
	if (tempSymbol != NULL) {
		printf("%d: #ERROR: Redeclaration of formal \"%s\".\n",yylineno,tempId);
	}
	else if (isLibSymbol(tempId)){
		printf("%d: #ERROR: Formal cannot be declared. Identifier \"'%s'\" is a"
				" library function.\n", yylineno, tempId);
	}
	else {
		tempSymbol = createSymbol(tempId, ARG);
		insert(tempSymbol);
		insertFormal(tempSymbol);
	}
}

void manage_idlist_empty() {
	printf("%d: idlist -> empty\n",yylineno);
}

/********** ids **********/
void manage_ids_comma_ID_ids(char * tempId) {
	printf("%d: ids -> ',' ID ids\n",yylineno);
	tempSymbol = lookupInScope(tempId, currentScope);
	if (tempSymbol != NULL) {
		printf("%d: #ERROR: Redeclaration of formal \"%s\".\n",yylineno,tempId);
	}
	else if (isLibSymbol(tempId)){
	}
	else {
		tempSymbol = createSymbol(tempId, ARG);
		insert(tempSymbol);
		insertFormal(tempSymbol);
	}
}

void manage_ids_empty() {
	printf("%d: ids -> empty \n",yylineno);
}

/********** if **********/
void manage_if_ifprefix_stmt (int ifprefix){	
	printf("%d: if -> iprefix stmt\n",yylineno);
	patchlabel(ifprefix, nextquadlabel());
}

void if_ifprefix_stmt_elseprefix_stmt (int ifprefix, int elseprefix){	
	printf("%d: if -> iprefix stmt elseprefix stmt\n",yylineno);
	patchlabel(ifprefix, elseprefix+1);
	patchlabel(elseprefix, nextquadlabel());
}

/********** ifprefix **********/
int manage_ifprefix_IF_par_expr (Expr * expr){
	printf("%d: ifexpr ->IF '(' expr ')'\n",yylineno);
	assert(expr);
	
//	// Savidis code below, I think not partial eval compatible
//	emit(if_eq, expr, newexpr_constbool(1), NULL, nextquadlabel()+2);
//	int ifprefix = nextquadlabel();
//	emit(jump, NULL, NULL, NULL, 0);
//	return ifprefix;
	
	// My code below
	Expr * boolExprResult = newexpr(var_e);
	boolExprResult->sym = newtemp();
		
	printf("truelist: "); printIntStack(expr->truelist); //TODO delete
	printf("falselist: "); printIntStack(expr->falselist); //TODO delete
	
	backpatch(expr->truelist,  nextquadlabel());
	emit(assign, newexpr_constbool(1), NULL, boolExprResult, 0);	
	emit(jump, NULL, NULL, NULL,nextquadlabel()+2);
	
	backpatch(expr->falselist, nextquadlabel());
	emit(assign, newexpr_constbool(0), NULL, boolExprResult, 0);
	
	emit(if_eq, newexpr_constbool(1), boolExprResult, NULL, nextquadlabel()+2);
	emit(jump, NULL, NULL, NULL, 0);
	
	return nextquadlabel()-1;
}

/********** elseprefix **********/
int manage_elseprefix_ELSE (){
	printf("%d: elseprefix -> ELSE\n",yylineno);
	int elseprefix = nextquadlabel();
	emit(jump, NULL, NULL, NULL, 0);
	return elseprefix;
}

/********** while **********/
void manage_while_whilestart_whilecond_stmt 
		(int whilestart, int whilecond, Expr * stmt){
	assert(stmt);
	printf("%d: while -> whilestart whilecond stmt\n",yylineno);
	emit(jump, NULL, NULL, NULL, whilestart);
	patchlabel(whilecond, nextquadlabel());
	//TODO uncomment when implemented break-contlists
//	patchlabel(stmt->breaklist->top->value, nextquadlabel()); 
//	patchlabel(stmt->contlist->top->value, whilestart);
}

int manage_whilestart_WHILE (){
	return nextquadlabel();
}

int	manage_whilecond_par_expr (struct Expr * expr){
	printf("%d: whilecond-> '(' expr ')'\n",yylineno);
	emit(if_eq, expr, newexpr_constbool(1), NULL, nextquadlabel()+2);
	int whilecond = nextquadlabel();
	emit(jump, NULL, NULL, NULL, 0);
	return whilecond;
}

/********** forstmt **********/
void manage_forstmt_FOR() {
	printf("%d: forstmt-> FOR '(' elist ';' expr ';' elist ')' stmt\n",yylineno);
}

/********** returnstmt **********/
void manage_returnstmt_RETURN_expr_semicolon(Expr * expr) {
	printf("%d: returnstmt -> RETURN expr ';'\n",yylineno);
	if (isEmptySymbolStack(curFuncStack)){
		printf("%d: #ERROR: Use of 'return' while not in a function.\n",
				yylineno);
	}
	emit(ret, expr, NULL, NULL, 0);
}

void manage_returnstmt_RETURN_semicolon() {
	printf("%d: returnstmt -> RETURN ';'\n",yylineno);
	if (isEmptySymbolStack(curFuncStack)){
		printf("%d: #ERROR: Use of 'return' while not in a function.\n",
				yylineno);
	}
	emit(ret, NULL, NULL, NULL, 0);
}

/********** break **********/
struct Expr * manage_break_BREAK (){
	printf("%d: break -> BREAK ';'\n",yylineno);	
	Expr * brk = newexpr(break_e);
	pushInt(brk->breaklist, nextquadlabel());
	emit(jump, NULL, NULL, NULL, 0);
	return brk;
}

/********** continue **********/
struct Expr * manage_continue_CONTINUE (){
	printf("%d: continue -> CONTINUE ';'\n",yylineno);	
	Expr * cntnue = newexpr(continue_e);
	pushInt(cntnue->contlist, nextquadlabel());
	emit(jump, NULL, NULL, NULL, 0);
	return cntnue;	
}

/********** Temporary Variables **********/
void resetTempVarCount() {tempVarCount = 0;}

struct Symbol * newtemp() {
	sprintf(newName, "%s%d",defaultTempVarPrefix, ++tempVarCount);
	struct Symbol* mySymbol = lookupInScope(newName, currentScope);
	if (mySymbol) { return mySymbol; }
	else {
		mySymbol = createSymbol(newName, VAR);
		insert(mySymbol);
		return mySymbol;
	}
}

int istempname (char * s){
	return * s == '_';
}

int istempexpr (Expr *e){
	assert(e);
	if (e->sym!=NULL && e->sym->name[0] == '_')
		return 1;
	return 0;
}

#endif

