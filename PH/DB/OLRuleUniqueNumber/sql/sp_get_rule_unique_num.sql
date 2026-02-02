DROP FUNCTION sp_get_rule_unique_num;

CREATE OR REPLACE FUNCTION sp_get_rule_unique_num (
   in_txn_code		ol_rule_unique_number.ru_txn_code%TYPE,
   in_party_id		ol_rule_unique_number.ru_party_id%TYPE,
   in_party_type	ol_rule_unique_number.ru_party_type%TYPE,
   in_disabled		ol_rule_unique_number.ru_disabled%TYPE,
   out_cursor          OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
   iCnt		INTEGER := 0;
   csGroup	CHAR := 'X';
BEGIN

   select opt_group
   into	  csGroup
   from	  ol_def_party_type
   where  opt_type = in_party_type;
	
   if csGroup = 'M'
   then
	select	count(1)
	into	iCnt
	from	ol_def_party_type,
     		OL_RULE_UNIQUE_NUMBER,
     		(select md_merchant_id,
            		md_client_id
        	 from	ol_merch_detail, clients
        	 where	client_id = md_client_id
        	 and	md_merchant_id = in_party_id)
	where   opt_type = ru_party_type
	and     (opt_group = csGroup or opt_group is NULL)
	and     ru_txn_code = in_txn_code
	and	ru_disabled = in_disabled
	and     ((ru_party_id = md_client_id and ru_party_type = 'CLIENT') 
	      or (ru_party_id = md_merchant_id and ru_party_type = 'MERCH')
	      or (ru_party_type = 'GLOBAL'));

	if iCnt > 0
	then
	    OPEN out_cursor FOR
		select	ru_party_type,
			md_client_id,
			md_client_id,
			ru_auto_extend,
			ru_extend_amount,
			ru_max_range_amount,
			ru_check_interval,
			ru_range_end,
			ru_step_size,
			ru_operate_direction,
			order_in_group
		from
		(select	OL_RULE_UNIQUE_NUMBER.*,
			md_client_id,
			nvl(opt_order_in_group,99) order_in_group
		 from ol_def_party_type,
		      OL_RULE_UNIQUE_NUMBER,
		      (select md_merchant_id,md_client_id
		       from ol_merch_detail, clients
		       where client_id = md_client_id
		       and md_merchant_id = in_party_id)
		 where   opt_type = ru_party_type
		 and     (opt_group = csGroup or opt_group is NULL)
		 and     ru_txn_code = in_txn_code
		 and	ru_disabled = in_disabled
		 and     ((ru_party_id = md_client_id and ru_party_type = 'CLIENT') 
		       or (ru_party_id = md_merchant_id and ru_party_type = 'MERCH')
		       or (ru_party_type = 'GLOBAL'))
		 order by order_in_group 
		)
		where rownum <= 1;
		return 1;
	else
		return 0;
	end if;	

   elsif csGroup = 'P'
   then
	select	count(1)
	into	iCnt
	from	ol_def_party_type,
     		OL_RULE_UNIQUE_NUMBER,
     		(select obai_baid,opd_psp_id,pm_client_id
		 from ol_bank_acct_id,
		      ol_psp_detail,
		      psp_master
		 where obai_status = 'O'
		 and opd_status = 'O'
		 and pm_status = 'O'
		 and opd_disabled = 0
		 and pm_mode_type = 'OFL'
		 and opd_psp_id = obai_psp_id
		 and opd_client_id = pm_client_id
		 and obai_baid = in_party_id)
	where   opt_type = ru_party_type
	and     (opt_group = csGroup or opt_group is NULL)
	and     ru_txn_code = in_txn_code
	and	ru_disabled = in_disabled
	and     ((ru_party_id = pm_client_id and ru_party_type = 'PROV') 
	      or (ru_party_id = opd_psp_id and ru_party_type = 'PID')
	      or (ru_party_id = obai_baid and ru_party_type = 'BAID')
	      or (ru_party_type = 'GLOBAL'));
		
	if iCnt > 0
	then
	    OPEN out_cursor FOR
		select	ru_party_type,
			opd_psp_id,
			pm_client_id,
			ru_auto_extend,
			ru_extend_amount,
			ru_max_range_amount,
			ru_check_interval,
			ru_range_end,
			ru_step_size,
			ru_operate_direction,
			order_in_group
		from
		(select	OL_RULE_UNIQUE_NUMBER.*,
			opd_psp_id,
			pm_client_id,
			nvl(opt_order_in_group,99) order_in_group
		 from ol_def_party_type,
		      OL_RULE_UNIQUE_NUMBER,
     		      (select obai_baid,opd_psp_id,pm_client_id
		       from ol_bank_acct_id,
		       	    ol_psp_detail,
			    psp_master
		       where obai_status = 'O'
		       and opd_status = 'O'
		       and pm_status = 'O'
		       and opd_disabled = 0
		       and pm_mode_type = 'OFL'
		       and opd_psp_id = obai_psp_id
		       and opd_client_id = pm_client_id
		       and obai_baid = in_party_id)
		 where   opt_type = ru_party_type
		 and     (opt_group = csGroup or opt_group is NULL)
		 and     ru_txn_code = in_txn_code
		 and	ru_disabled = in_disabled
		 and     ((ru_party_id = pm_client_id and ru_party_type = 'PROV') 
		       or (ru_party_id = opd_psp_id and ru_party_type = 'PID')
		       or (ru_party_id = obai_baid and ru_party_type = 'BAID')
		       or (ru_party_type = 'GLOBAL'))
		 order by order_in_group 
		)
		where rownum <= 1;
		return 1;
	else
		return 0;
	end if;	

   else
	return 0;
   end if;



EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 0;
END sp_get_rule_unique_num;
/

