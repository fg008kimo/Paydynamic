CREATE OR REPLACE FUNCTION sp_ol_payout_rtn_rc_multi_chk (
    in_txn_id       ol_txn_header.oth_txn_id%type
) RETURN NUMBER IS
    g_rtn           NUMBER := 1; --0: succ; 1: error

    l_tmp_cnt       NUMBER;
    l_tmp_txn_id    ol_txn_header.oth_txn_id%type;
    l_tmp_batch_id  ol_batch_txn_relation.obtr_batch_id%type;
    l_tmp_category  OL_DEF_BAID_CATEGORY.BC_TYPE%type;

begin
    -- --check if multiple and with other merchant payout recon relation
    select count(1)
    into l_tmp_cnt
    from ol_txn_psp_detail, ol_txn_header
    where otp_tracking_txn_id = in_txn_id
    and otp_txn_id = oth_txn_id
    and oth_status = 'C'
    and oth_ar_ind = 'A'
    and not exists (select 1
                    from txn_code
                    where tc_code = oth_txn_code
                    and (tc_ofl_is_offset = 1 or tc_ofl_is_void = 1)
                    );

    -- dbms_output.put_line('approved record count = [' || l_tmp_cnt || ']');

    if l_tmp_cnt = 0 then
        NULL;  --unexpected, return error

    elsif l_tmp_cnt = 1 then
        select otp_txn_id
        into l_tmp_txn_id
        from ol_txn_psp_detail, ol_txn_header
        where otp_tracking_txn_id = in_txn_id
        and otp_txn_id = oth_txn_id
        and oth_status = 'C'
        and oth_ar_ind = 'A'
        and not exists (select 1
                        from txn_code
                        where tc_code = oth_txn_code
                        and (tc_ofl_is_offset = 1 or tc_ofl_is_void = 1)
                        );

        -- dbms_output.put_line('1 approved txn_id = [' || l_tmp_txn_id || ']');

        begin
            select obtr_batch_id
            into l_tmp_batch_id
            from ol_batch_txn_relation
            where obtr_txn_id = l_tmp_txn_id
            and obtr_batch_type = 'G'
            and obtr_txn_level = 'T'
            and obtr_batch_sub_type != 'V'
            and obtr_is_input_txn = 0;

            -- dbms_output.put_line('1 recon batch_id = [' || l_tmp_batch_id || ']');
        exception
            when no_data_found then
                l_tmp_batch_id := NULL;

                select obai_category
                into l_tmp_category
                from ol_txn_psp_detail, ol_bank_acct_id
                where otp_txn_id =  l_tmp_txn_id
                and otp_baid = obai_baid;

                if l_tmp_category = 'TEMP' then
                   -- dbms_output.put_line('1 pass => TEMP unrecon case!');
                    g_rtn := 0;
                else
                    NULL; --unexpected case
                end if;
        end;

        if l_tmp_batch_id is not null then
            select count (distinct otp_grp_tracking_txn_id)
            into l_tmp_cnt
            from ol_txn_psp_detail
            where otp_txn_id in (
                select obtr_txn_id
                from ol_batch_txn_relation
                where obtr_txn_level = 'T'
                and obtr_batch_id = l_tmp_batch_id
                and obtr_batch_type = 'G'
                and obtr_is_input_txn = 1
                );
            if l_tmp_cnt = 1 then
                -- dbms_output.put_line('1 pass => no other merchant payout in the same batch');
                g_rtn := 0;
            else
                -- dbms_output.put_line('1 fail => other merchant payout found');
                NULL;
            end if;
        end if;


    else

        select count(distinct otp_grp_tracking_txn_id)
        into l_tmp_cnt
        from ol_txn_psp_detail
        where otp_txn_id in (
                select OBTR2.OBTR_TXN_ID
                from ol_batch_txn_relation obtr1, ol_batch_txn_relation obtr2
                where obtr1.obtr_batch_type = 'G'
                and obtr1.obtr_txn_level = 'T'
                and obtr1.obtr_txn_id in (
                    select otp_txn_id
                    from ol_txn_psp_detail, ol_txn_header
                    where otp_tracking_txn_id = in_txn_id
                    and otp_txn_id = oth_txn_id
                    and oth_status = 'C'
                    and oth_ar_ind = 'A'
                    and not exists (select 1
                                    from txn_code
                                    where tc_code = oth_txn_code
                                    and (tc_ofl_is_offset = 1 or tc_ofl_is_void = 1)
                                    )
                    )
                and obtr1.obtr_batch_id = obtr2.obtr_batch_id
                and obtr2.obtr_batch_type = 'G'
                and obtr2.obtr_txn_level = 'T'
                and obtr2.obtr_is_input_txn = 1
                group by OBTR2.OBTR_TXN_ID
        );

        if l_tmp_cnt = 1 then
            -- dbms_output.put_line('multi pass => no other merchant payout found');
            g_rtn := 0;
        end if;

    end if;

    -- dbms_output.put_line('final return = [' || g_rtn || ']');

    return g_rtn;
end;
/
