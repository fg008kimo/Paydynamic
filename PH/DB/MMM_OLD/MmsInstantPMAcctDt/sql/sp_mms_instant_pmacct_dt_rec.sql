CREATE OR REPLACE FUNCTION sp_mms_instant_pmacct_dt_rec (
  in_party_type         mms_instant_pm_acct_dt.mid_party_type%type,
  in_business_type      mms_instant_pm_acct_dt.mid_business_type%type,
  in_mms_node_id             mms_instant_pm_acct_dt.mid_mms_node_id%type,
  in_start_party_id     mms_instant_pm_acct_dt.mid_party_id%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
	into   iCnt
	from   mms_instant_pm_acct_dt
	where  mid_party_type = in_party_type
	and    mid_business_type = in_business_type
  	and    mid_mms_node_id = NVL(in_mms_node_id, mid_mms_node_id)
        and    mid_party_id >= NVL(in_start_party_id, mid_party_id);

        if iCnt > 0 THEN
		OPEN out_cursor for
                select mid_party_id,
                       mid_party_name,
                       mid_mms_node_id
                  from mms_instant_pm_acct_dt
                 where mid_party_type = in_party_type
                   and mid_business_type = in_business_type
                   and mid_mms_node_id = NVL(in_mms_node_id, mid_mms_node_id) 
                   and mid_party_id >= NVL(in_start_party_id, mid_party_id)
                order by mid_party_id;

		RETURN 0;
	end if;

	RETURN 1;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_mms_instant_pmacct_dt_rec;
/
