# Setting Variable Values

## `Assignment` Type

> A non-overloaded binary assignment operation, including =, +=, &=, etc.
- [Assignment](https://codeql.github.com/codeql-standard-libraries/cpp/semmle/code/cpp/exprs/Assignment.qll/type.Assignment$Assignment.html)

## `AssignExpr` Type

> A non-overloaded assignment operation with the operator =.
- [AssignExpr](https://codeql.github.com/codeql-standard-libraries/cpp/semmle/code/cpp/exprs/Assignment.qll/type.Assignment$AssignExpr.html)

This is an `AssignExpr`: 

```c
a = b;
```

This is **not** an `AssignExpr` (but it is an `Assignment`):

```c
a += b;
```

## `Initializer` Type

This is an `Initializer`, **not** an `Assignment`:

```c
int i = 1;
```

## `VariableAccess` Type

This is a `VariableAccess`, **not** an `Assignment`:

```c
i++;
```

This is also a `VariableAccess`, but the `isModified()` predicate doesn't hold:

```c
return i == 0;
```
