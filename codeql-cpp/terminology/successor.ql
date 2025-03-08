import cpp

from ControlFlowNode predecessor, ControlFlowNode successor
where predecessor=successor.getAPredecessor() and
successor.getEnclosingStmt().getEnclosingFunction().getName()="simple_block"
select predecessor, successor