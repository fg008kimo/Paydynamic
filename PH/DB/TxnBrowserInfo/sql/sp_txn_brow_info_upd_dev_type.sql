create or replace function sp_txn_brow_info_upd_dev_type(
       in_txn_id                                txn_browser_info.tb_txn_id%type,
       in_device_type                           txn_browser_info.tb_device_type%type)

RETURN NUMBER IS
BEGIN

  update txn_browser_info
  set tb_device_type = in_device_type
  where tb_txn_id = in_txn_id;

  IF SQL%ROWCOUNT = 0 THEN
     	RETURN 1;
  ELSE
     	RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_txn_brow_info_upd_dev_type;
/
