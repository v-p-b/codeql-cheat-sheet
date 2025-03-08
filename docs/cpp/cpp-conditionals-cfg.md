# Control-Flow of Conditionals

## IfStmt - `if` Statements  

### Successors Originate from the Condition

```ql
import cpp

from IfStmt i, Stmt s
where s = i.getConditon().getATrueSuccessor()
select s
```

Example Result:

```c hl_lines="2-5 9"
if (my_rand()) 
{
    printf("simple_block 1\n");
    printf("simple_block 2\n");
}

void simple_no_block(){
    if (my_rand()) 
        printf("simple_no_block\n");
    printf("return\n");
}


```

The following query will not yield results:

```ql
import cpp

from IfStmt i, Stmt s
where s = i.getATrueSuccessor()
select s
```

### Get Children to Access Elements of Successors

```ql
import cpp

from IfStmt i, Stmt s
where s = i.getConditon().getATrueSuccessor()
select s.getAChild()
```

Will return the individual `printf()`s from the following statement (instead of the whole code block):

```c hl_lines="3 4"
if (my_rand()) 
{
    printf("simple_block 1\n");
    printf("simple_block 2\n");
}
```

### False Successors are not Necessarily Part of `if`

This query:

```ql
import cpp

from IfStmt i, Stmt s
where s = i.getCondition().getAFalseSuccessor+()
select s
```
...will return this (there is an `else` statement):

```c hl_lines="9-12"
void simple_block()
{
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

...but also this (no `else` statement):

```c hl_lines="3"
void simple_no_block(){
    if (my_rand()) printf("simple_no_block\n");
    printf("return\n");
}
```

## GotoStmt - `goto` Statements  

This query will return:

```ql
import cpp

from GotoStmt gs
select gs.getASuccessor+()
```

... all of the following:

```c hl_lines="2 13 14 15"
void 
simple_block_goto() // The function itself!
{
    if (my_rand()) {
      printf("simple_block 1\n");
      printf("simple_block 2\n");
    } else {
      printf("simple_block else 1\n");
      printf("simple_block else 2\n");
      goto label;
    }
    printf("unconditional\n");
    label: //The label
      printf("return\n"); // The statements after the label
    // The invisible return
}


```
