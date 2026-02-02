DROP VIEW RULE_TXN_LIMIT_VW;

/* Formatted on 6/20/2011 10:54:23 AM (QP5 v5.163.1008.3004) */
CREATE OR REPLACE FORCE VIEW RULE_TXN_LIMIT_VW
(
   CATEGORY,
   VALUE
)
AS
   SELECT rl_min_value AS min_value,
          rl_max_value AS max_value
     FROM rule_txn_limit;

