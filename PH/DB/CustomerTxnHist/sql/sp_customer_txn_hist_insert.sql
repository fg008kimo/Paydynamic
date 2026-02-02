DROP FUNCTION sp_customer_txn_hist_insert;

CREATE OR REPLACE FUNCTION sp_customer_txn_hist_insert (
   in_date            customer_txn_hist.cth_date%TYPE,
   in_merchant_id     customer_txn_hist.cth_merchant_id%TYPE,
   in_cust_id         customer_txn_hist.cth_cust_id%TYPE,
   in_code            customer_txn_hist.cth_code%TYPE,
   in_amount	      customer_txn_hist.cth_amount%TYPE,
   in_create_user     customer_txn_hist.cth_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN


   UPDATE customer_txn_hist
      SET cth_counter = cth_counter + 1,
	  cth_amount = cth_amount + in_amount,
          cth_update_user = in_create_user,
          cth_update_timestamp = SYSDATE
      WHERE	cth_date = in_date
	AND	cth_merchant_id = in_merchant_id
	AND	cth_cust_id = in_cust_id
	AND	cth_code = in_code;

   IF SQL%ROWCOUNT = 0
   THEN
      INSERT INTO customer_txn_hist (cth_date,
                                     cth_merchant_id,
                                     cth_cust_id,
                                     cth_code,
                                     cth_amount,
				     cth_counter,
				     cth_create_user,
				     cth_create_timestamp,
		      		     cth_update_user,
				     cth_update_timestamp)
           VALUES (in_date,
                   in_merchant_id,
                   in_cust_id,
                   in_code,
                   in_amount,
		   1,
                   in_create_user,
                   SYSDATE,
		   in_create_user,
                   SYSDATE);

      IF SQL%ROWCOUNT = 0
	THEN
            RETURN 1;
      END IF;
   END IF;

return 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_customer_txn_hist_insert;
/

