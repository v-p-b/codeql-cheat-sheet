# Terminology

## Basic Types

### Expression (`Expr`)

> An expression is a sequence of operators and their operands, that specifies a computation. 
- [cppreference.com](https://en.cppreference.com/w/c/language/expressions)

### Statement (`Stmt`)

> Statements are fragments of the C program that are executed in sequence. 
- [cppreference.com](https://en.cppreference.com/w/c/language/statements)



### Statement Expression (`StmtExpr`)


> A compound statement enclosed in parentheses used as an expression (a GNU extension to C/C++). In the example below, b is the return value from the compound statement.
>int a = ({ int b = c + d; b; });
- [AssignExpr](https://codeql.github.com/codeql-standard-libraries/cpp/semmle/code/cpp/exprs/Expr.qll/type.Expr$StmtExpr.html)

## Relationships

### Successor / Predecessor

Relationship of `ControlFlowNode`s, control flows from predecessor to successor.

### Parent / Child

Relationship of `Stmt`s, parent precedes child in code. Children have at most one parent.

* `getAChild()` returns `Element`s
* `getChildStmt()` returns `Stmt`

