. /home/php3dev/.setenv

#JOB_PATH=$MY_HOME/Doc/data_conv_test
#LOG_PATH=${JOB_PATH}/log

#DATE=`date +%Y%m%d_%k%M%S`

#cd $JOB_PATH

ORACLE_USER=dbconv;
ORACLE_PASSWORD=dbconv;
ORACLE_SID=DBCONV;


sqlldr $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID control=par_txn_data.ctl 

#log=${LOG_PATH}/data_conv_${DATE}.log

