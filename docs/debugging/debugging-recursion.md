# Debugging Recursive CodeQL Predicates

Suppose we have a recursive predicate without a return value and we want to learn wich code elements does the recursion hit when it holds. 

First we can rewrite the predicate (in a new test query) to return a string. When recursion stops `result=currentElement` should hold. When recursion happens, `result=currentElement+mySelf(nextElement, ...)`.

Here is an example recursive predicate:

```codeql
predicate recursive(SomeClass e, int depth){
  (depth=0 and e.isWeThereYet()) or
  (depth > 0 and recursive(e.getARecursionTarget(), depth-1))
}
```

We can translate this to:

```codeql

string recursive(SomeClass e, int depth){
  (result=e.getName() and depth=0 and e.isWeThereYet()) or
  (depth > 0 and result=recursive(e.getARecursionTarget(), depth-1) )
}

from SomeClass target, string path
where path=recursive(target, 10)
select target, path
```

`bindingvars` is **not** required!

