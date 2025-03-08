import cpp

from IfStmt i, Stmt s
where s = i.getCondition().getATrueSuccessor+()
select s.getAChild()