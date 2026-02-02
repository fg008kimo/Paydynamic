CREATE OR REPLACE FUNCTION sp_txn_psp_dt_getbydlvid(
  in_dlv_id	            	txn_psp_detail.tp_delivery_id%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin

	select count(*)
	  into	iCnt
	  from	
	  	txn_psp_detail
	  where	tp_delivery_id=in_dlv_id;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	
			tp_txn_id
		from	
			txn_psp_detail
		where	tp_delivery_id=in_dlv_id
		order by tp_txn_id;

		return 1;
	
	else
		return 0;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_txn_psp_dt_getbydlvid;
/
