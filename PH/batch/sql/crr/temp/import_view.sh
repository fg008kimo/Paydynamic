#/bin/sh

sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_apl_deposit_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_rec_deposit_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_vod_rec_deposit_view.sql

sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_apl_settle_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_del_settle_view.sql

sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_apl_payout_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_gen_payout_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_vod_apl_payout_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_vod_gen_payout_view.sql

sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_apl_mbt_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_apl_off_2_mbt_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_apl_mbt_2_off_view.sql

sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_apl_pbt_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_apl_off_2_pbt_view.sql
sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_apl_pbt_2_off_view.sql

sqlplus $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID < create_crr_psp_2_mb_view.sql

