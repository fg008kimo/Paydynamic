sqlldr $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID control=IP_FILTER_DATA_TABLE.ctl

#1 prepare IP_FILTER_DATA_TABLE.ldr
#     (format: A space followed by starting ip followed by delimiter | followed by ending ip followed by delimiter | followed by ip location name)
#2 run load_ip_datta.sh
#3 check data
