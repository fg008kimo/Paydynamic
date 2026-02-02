DROP FUNCTION sp_mob_bank_get_all;

CREATE OR REPLACE FUNCTION sp_mob_bank_get_all (
   in_merchant_id        MERCH_DETAIL.MERCHANT_ID%TYPE,
   out_cursor        OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR

    select
        mbs_group,
	mbm_bank_code,
        mbs_overflow_grp,
        mbs_union_grp,
        mbs_def_assign_grp,
        mst_cust_cnt,
        mst_amt_limit,
        rb_scheduler_id,
        rb_note_id

    from
    (
	select	mbs_group,
		mbm_bank_code,
		mbs_overflow_grp,
		mbs_union_grp,
		mbs_def_assign_grp,
		mst_cust_cnt,
		mst_amt_limit
	FROM (  SELECT	mbs_group,
			mbs_overflow_grp,
			mbs_union_grp,
			mbs_def_assign_grp,
			mbm_bank_code
		FROM	mob_bank_selection, customer_group_rules,mob_bank_map
		WHERE	cgr_group_code = mbs_group
		AND	cgr_merchant_id = in_merchant_id
		AND	cgr_from_group_code IS NULL
		AND	mbs_disabled = 0
		AND	cgr_disabled = 0
		AND	mbs_group = mbm_group
        ORDER BY mbs_def_assign_grp)
       LEFT JOIN mob_segment_ctl on (msc_group = mbs_group or msc_group = '000')
       LEFT JOIN mob_segment_threshold ON mst_group = mbs_group
	where	(mbs_def_assign_grp = 0 and mst_is_exceed_cnt = 0 and mst_is_exceed_amt = 0 and msc_enable_new_cust = 1)
	or	mbs_def_assign_grp = 1
    )
    left join  (SELECT rb_bank_code,
                           rb_type,
                           rb_party_id,
                           rb_scheduler_id,
                           rb_note_id
                      FROM rule_disabled_bank
                     WHERE     rb_disabled = 0
                           AND rb_channel_code = 'WEB'
                           AND rb_type IN ('G'))
                      ON rb_bank_code = mbm_bank_code
    ORDER BY mbs_def_assign_grp,mbs_group,mbm_bank_code;


   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_mob_bank_get_all;
/

