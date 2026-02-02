CREATE OR REPLACE FUNCTION sp_mms_instant_txn_inq_dt_next (
  in_inq_id                 mms_instant_txn_inq_dt.mid_inq_id%type,
  in_start_txn_id           mms_instant_txn_inq_dt.mid_txn_id%type,
  in_start_dtl_txn_id       mms_instant_txn_inq_dt.mid_dtl_txn_id%type,
  out_txn_id          out   mms_instant_txn_inq_dt.mid_txn_id%type,
  out_dtl_txn_id      out   mms_instant_txn_inq_dt.mid_dtl_txn_id%type
)

RETURN NUMBER Is
  v_txn_id      mms_instant_txn_inq_dt.mid_txn_id%type;
  v_dtl_txn_id  mms_instant_txn_inq_dt.mid_dtl_txn_id%type;

Begin


	if (in_start_txn_id is NULL and in_start_dtl_txn_id is NULL) then
		select mid_txn_id, mid_dtl_txn_id
		into   v_txn_id, v_dtl_txn_id
		from   (select mid_txn_id, mid_dtl_txn_id
                	from   mms_instant_txn_inq_dt
			where  mid_inq_id = in_inq_id 
			order by mid_txn_id, mid_dtl_txn_id
		       )
	   	where rownum = 1;

	else 
		select mid_txn_id, mid_dtl_txn_id
		into   v_txn_id, v_dtl_txn_id
		from   (select mid_txn_id, mid_dtl_txn_id
                	from   mms_instant_txn_inq_dt
			where  mid_inq_id = in_inq_id 
                 	and    ( (mid_txn_id > NVL(in_start_txn_id, mid_txn_id)) or
                          	 ((mid_txn_id >= NVL(in_start_txn_id, mid_txn_id)) and (mid_dtl_txn_id > NVL(in_start_dtl_txn_id, mid_dtl_txn_id)))
                       	       )
	                order by mid_txn_id, mid_dtl_txn_id
			) 
		where rownum = 1;
	end if;

	out_txn_id := v_txn_id;
	out_dtl_txn_id := v_dtl_txn_id;

	RETURN 0;

exception
   WHEN NO_DATA_FOUND THEN
     RETURN 1;

   WHEN OTHERS THEN
     RETURN 9;
END sp_mms_instant_txn_inq_dt_next;
/
