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

Demo query:
```ql
from ControlFlowNode predecessor, ControlFlowNode successor
where predecessor=successor.getAPredecessor() and
successor.getEnclosingStmt().getEnclosingFunction().getName()="simple_block"
select predecessor, successor
```

Two result pairs:
```c hl_lines="3 4 8 11"
void simple_block(){
    if (my_rand()) {
      printf( // Successor 1.
        "simple_block 1\n" // Predecessor 1.
      );
      printf("simple_block 2\n");
    } else {
      printf( // Predecessor 2.
        "simple_block else 1\n"
      );
      printf("simple_block else 2\n"); // Successor 2.
    }
    printf("return\n");
}

```

### Parent / Child

Relationship of `Stmt`s, parent precedes child in code. Children have at most one parent.

* `getAChild()` returns `Element`s
* `getChildStmt()` returns `Stmt`

Demo query:

```c
from Stmt parent, Stmt child
where parent.getAChild()=child and
child.getEnclosingFunction().getName()="simple_block"
select parent, child
```

A direct child of `if`:

```c hl_lines="8-11"
void simple_block(){
    if (my_rand()) 
    {
      printf("simple_block 1\n");
      printf("simple_block 2\n");
    } 
    else 
    {
      printf("simple_block else 1\n");
      printf("simple_block else 2\n"); 
    }
    printf("return\n");
}
```

Using `getChildStmt()` yields identical results in this case. The `printf()`s can be queried recursively (e.g. `getAChild+()`).



