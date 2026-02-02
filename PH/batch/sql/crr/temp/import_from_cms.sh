#!/bin/sh
#########required file##########
#create_table.sql
#sp_crr_jnl_insert_from_cms.sql
#TMP_CRR_CARRY_OLD_BALANCE_DATA_TABLE.ctl
#TMP_CRR_CARRY_OLD_BALANCE_DATA_TABLE.ldr

if [ -z "$1" ]; then
echo 'usage:<txn date> <optional:1 new import, 0(default) old>'
exit 1
fi
ldr=TMP_CRR_CARRY_OLD_BALANCE_DATA_TABLE.ldr

if [ "$2" == "1" ];
then
	echo $'\nInitailizing...'
	sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID >/dev/null << eof
		drop table if exists tmp_crr_carry_old_balance;
		drop function is exists tmp_sp_crr_jnl_insert_from_cms;
		@create_table.sql;
		@sp_crr_jnl_insert_from_cms.sql;
		exit;
eof
	sqlldr $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID control=TMP_CRR_CARRY_OLD_BALANCE_DATA_TABLE.ctl
fi

echo $'\nRunning...'

sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID << eof
	set serveroutput ON
	set feedback off
	set verify off
	set linesize 250
	set pagesize 250
	variable ret number;
	begin
	:ret:=tmp_sp_crr_jnl_insert_from_cms($1);
	end;
	/
	exit :ret; 
eof
Result=$?
echo "return=$Result"
if [ $Result == '0' ];
then
	echo 'PARTIALLY SUCCESS!'
elif [ $Result == '1' ];
then
	sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID >/dev/null << eof
		drop table tmp_crr_carry_old_balance;
		drop function tmp_sp_crr_jnl_insert_from_cms;
		exit;
eof
	rm *log
	echo 'ALL SUCCESS! TABLE AND FUNCTION DROPED'
else
	echo 'Import FAILED...'
fi
echo ''
