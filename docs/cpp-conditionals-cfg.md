# C++ - Control-Flow of Conditionals

## IfStmt - `if` Statements  

### Successors Originate from the Condition

```ql
import cpp

from IfStmt i, Stmt s
where s = i.getConditon().getATrueSuccessor()
select s
```

Example Result:

```c hl_lines="2"
if (my_rand()) 
{
    printf("simple_block 1\n");
    printf("simple_block 2\n");
}
```

This query will not yield results:

```ql
import cpp

from IfStmt i, Stmt s
where s = i.getATrueSuccessor()
select s
```
