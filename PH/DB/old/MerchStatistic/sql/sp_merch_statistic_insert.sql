create or replace function sp_merch_statistic_insert(
       in_merchant_id                           merch_statistic.merchant_id%type,
       in_txn_ccy				merch_statistic.txn_ccy%type,
       in_txn_country				merch_statistic.txn_country%type,	
       in_txn_date				merch_statistic.txn_date%type,
       in_psp_id				merch_statistic.psp_id%type,
       in_amount				merch_statistic.txn_amount%type,
       in_update_user                           merch_statistic.update_user%type       
)
  RETURN NUMBER IS
Begin
     Update merch_statistic
            Set txn_amount=txn_amount+in_amount,
		txn_count=txn_count+1,
		update_user = in_update_user,
		update_timestamp = sysdate

      Where merchant_id = in_merchant_id
      and   txn_ccy = in_txn_ccy
      and   txn_country = in_txn_country
      and   txn_date = in_txn_date
      and   psp_id = in_psp_id;

     IF SQL%ROWCOUNT = 0 THEN
        insert into merch_statistic
                     (merchant_id,
		      txn_ccy,
		      txn_country,
                      txn_date,
                      psp_id,
                      txn_amount,
                      min_amount,
                      max_amount,
                      create_user,
                      create_timestamp,
                      update_user,
                      update_timestamp)
          values(in_merchant_id,
		     in_txn_ccy,
                     in_txn_country,
		     in_txn_date,
		     in_psp_id,
		     in_amount,
		     in_amount,
		     in_amount,
                     in_update_user,
                     sysdate,
                     in_update_user,
                     sysdate);

          IF SQL%ROWCOUNT = 0 THEN
             RETURN 1;
          ELSE
             RETURN 0;
          END IF;
      Else
	  update merch_statistic
		set min_amount=in_amount
	  where in_amount<min_amount
	  and   merchant_id = in_merchant_id
      	  and   txn_ccy = in_txn_ccy
      	  and   txn_country = in_txn_country
      	  and   txn_date = in_txn_date
      	  and   psp_id = in_psp_id;

	  update merch_statistic
		set max_amount=in_amount
	  where in_amount>max_amount
	  and   merchant_id = in_merchant_id
      	  and   txn_ccy = in_txn_ccy
      	  and   txn_country = in_txn_country
      	  and   txn_date = in_txn_date
      	  and   psp_id = in_psp_id;


          Return 0;
       End If;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_merch_statistic_insert;
/
