CREATE OR REPLACE FUNCTION sp_update_batch(
       in_batch_no                         batch.b_batch_no%Type,
       in_status                              batch.b_batch_status%Type,
       in_update_user                     batch.b_update_user%Type
)
  RETURN NUMBER IS

BEGIN

  UPDATE  batch t
         Set  b_batch_status = in_status,
                b_update_user  = in_update_user,
                b_update_timestamp = Sysdate
  Where b_batch_no = in_batch_no;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_update_batch;
/
