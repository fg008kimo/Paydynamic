CREATE OR REPLACE FUNCTION sp_def_bank_support(
  in_country			psp_pay_method.pp_country%type,
  in_service_code		service_pay_method.sp_service_code%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt    integer := 0;
Begin

	select count(distinct bm_int_bank_code)
	into iCnt
	from psp_detail,
	     psp_pay_method,
	     bank_mapping,
	     bank_service_mapping,
	     service_pay_method,
	     psp_master
        where psp_detail.psp_id =psp_pay_method.pp_psp_id
        and PSP_PAY_METHOD.PP_PAY_METHOD = SERVICE_PAY_METHOD.SP_PAY_METHOD
        --and PSP_DETAIL.PSP_CHANNEL_CODE = BANK_MAPPING.BM_PSP_CHANNEL_ID
	and ((psp_detail.overrided_bank_code_channel is not NULL and BANK_MAPPING.bm_psp_channel_id = psp_detail.overrided_bank_code_channel)
                 or (psp_detail.overrided_bank_code_channel is NULL and BANK_MAPPING.bm_psp_channel_id = psp_detail.psp_channel_code))
        and PSP_DETAIL.client_id = psp_master.pm_client_id 
	and BANK_MAPPING.bm_disabled = 0
        and BANK_MAPPING.bm_country = in_country
        and psp_pay_method.pp_country = in_country
        and psp_pay_method.pp_disabled = 0
        and     psp_detail.status = 'O'
        and     psp_detail.txn_type in ('A','D')
        and     psp_detail.disabled = 0
        and     psp_detail.online_mode = 'Y'
        and     psp_master.pm_status = 'O'
	and	sp_service_code = in_service_code
	and	sp_disabled = 0
	and     bs_service_code =in_service_code
	and     bs_disabled = 0
	and     bm_int_bank_code = bs_int_bank_code;

	if iCnt > 0 THEN
	OPEN out_cursor for
		select bm_int_bank_code
                from psp_detail,
		     psp_pay_method,
		     bank_mapping,
		     bank_service_mapping,
		     service_pay_method,
		     psp_master,
		     bank_desc
                where psp_detail.psp_id =psp_pay_method.pp_psp_id
                and PSP_PAY_METHOD.PP_PAY_METHOD = SERVICE_PAY_METHOD.SP_PAY_METHOD
                --and PSP_DETAIL.PSP_CHANNEL_CODE = BANK_MAPPING.BM_PSP_CHANNEL_ID
		and ((psp_detail.overrided_bank_code_channel is not NULL and BANK_MAPPING.bm_psp_channel_id=psp_detail.overrided_bank_code_channel)
             		or (psp_detail.overrided_bank_code_channel is NULL and BANK_MAPPING.bm_psp_channel_id = psp_detail.psp_channel_code))
		and PSP_DETAIL.client_id = psp_master.pm_client_id
                and BANK_MAPPING.bm_disabled = 0
                and BANK_MAPPING.bm_country = in_country
                and psp_pay_method.pp_country = in_country
                and psp_pay_method.pp_disabled = 0
                and     psp_detail.status = 'O'
                and     psp_detail.txn_type in ('A','D')
                and     psp_detail.disabled = 0
                and     psp_detail.online_mode = 'Y'
		and     psp_master.pm_status = 'O'
                and     sp_service_code =in_service_code
                and     sp_disabled = 0
		and     bs_service_code =in_service_code
		and     bs_disabled = 0
		and     bm_int_bank_code = bs_int_bank_code
		and     bank_desc.internal_bank_code = bm_int_bank_code
                group by bm_int_bank_code, fe_display_order
                order by fe_display_order, bm_int_bank_code;

		RETURN 1;
        end if;
	return 0;

 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_def_bank_support;
/

