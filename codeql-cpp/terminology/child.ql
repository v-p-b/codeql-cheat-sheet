import cpp

from Stmt parent, Stmt child
where parent.getAChild()=child and
child.getEnclosingFunction().getName()="simple_block"
select parent, child