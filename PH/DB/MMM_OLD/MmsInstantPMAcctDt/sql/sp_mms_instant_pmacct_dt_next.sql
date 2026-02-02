CREATE OR REPLACE FUNCTION sp_mms_instant_pmacct_dt_next (
  in_party_type             mms_instant_pm_acct_dt.mid_party_type%type,
  in_business_type          mms_instant_pm_acct_dt.mid_business_type%type,
  in_last_party_id          mms_instant_pm_acct_dt.mid_party_id%type,
  in_mms_node_id                 mms_instant_pm_acct_dt.mid_mms_node_id%type,
  out_party_id          out mms_instant_pm_acct_dt.mid_party_id%type)

RETURN NUMBER Is
  v_party_id	mms_instant_pm_acct_dt.mid_party_id%type;
Begin

	if in_last_party_id is null then
            select mid_party_id 
            into   v_party_id
            from   (select mid_party_id
                    from   mms_instant_pm_acct_dt
                    where  mid_party_type = in_party_type
                    and    mid_business_type = in_business_type
                    and    mid_mms_node_id = NVL(in_mms_node_id, mid_mms_node_id)
                    order by mid_party_id
                    )
            where rownum = 1;

        else 
	    select mid_party_id 
 	    into   v_party_id
            from   (select mid_party_id
		    from   mms_instant_pm_acct_dt 
		    where  mid_party_type = in_party_type
		    and    mid_business_type = in_business_type
		    and    mid_mms_node_id = NVL(in_mms_node_id, mid_mms_node_id) 
		    and    mid_party_id > in_last_party_id
		    order by mid_party_id
		    )  
	    where rownum = 1;
	end if;

	out_party_id := v_party_id;

	RETURN 0;


exception
   WHEN NO_DATA_FOUND THEN
     RETURN 1;

   WHEN OTHERS THEN
     RETURN 9;
END sp_mms_instant_pmacct_dt_next;
/
