CREATE OR REPLACE FUNCTION sp_ol_po_api_get_psp(
  in_action_id			ol_payout_api_pregen_hd.oap_action_id%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
Begin
	OPEN out_cursor for
	select  oag_psp_id,
               	oag_bank_code,
               	opd_currency_id,
               	country,
               	cnt,
             	amount
        from	(select oag_psp_id,
                        oag_bank_code,
                        opd_currency_id,
                        country,
                        cnt,
                        amount
               	from    (select oag_psp_id,
                                oag_bank_code,
                                count(oag_txn_id) cnt,
                                sum(opr_payout_amount) amount
                        from    ol_payout_api_pregen_hd,
				ol_payout_api_pregen_dt,
                                ol_payout_request
                        where   oap_action_id = in_action_id
			and     oag_batch_id = oap_batch_id
                        and     oag_txn_id = opr_txn_id
			and	(opr_psp_payout_grp = oap_payout_group or opr_psp_payout_grp is NULL)
                        group by oag_psp_id, oag_bank_code),
                        ol_rule_payout_psp,
                        (select opd_currency_id,
                                opd_psp_id
                         from   ol_psp_detail
                        group by opd_currency_id,opd_psp_id),
                        (select country,
                                internal_bank_code
                         from   bank_desc)
                where   oag_psp_id = orp_psp_id
                and     opd_psp_id = oag_psp_id
                and     internal_bank_code = oag_bank_code
                and     orp_to_bank_code = internal_bank_code
                order by orp_priority)
        group by oag_psp_id,
               	 oag_bank_code,
                 opd_currency_id,
                 country,
                 cnt,
                 amount;

        return 0;

exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_ol_po_api_get_psp;
/

