


CREATE OR REPLACE FUNCTION sp_ol_auto_upl_disable_chk_stt(
	in_acct_type			OL_BANK_ACCTS.OB_ACCT_TYPE%type,
	in_fr_status_type		OL_BANK_ACCTS.OB_STATUS_TYPE%type,
	in_to_status_type		OL_BANK_ACCTS.OB_STATUS_TYPE%type)

RETURN NUMBER IS
	iCnt	INTEGER := 0;

BEGIN

	select  count(*)
        into    iCnt
        from    ol_auto_upload_acct_status
        where   oauas_acct_type = in_acct_type
        and     oauas_status_type = in_to_status_type
        and     oauas_disable_chk_to_status = (select oauas_disable_chk_fr_status
                                              from   ol_auto_upload_acct_status
                                              where  oauas_acct_type = in_acct_type
                                              and    oauas_status_type = in_fr_status_type
                                              and    oauas_disable_chk_fr_status > 0
                                              and    oauas_disabled = 0
                                             )
        and     oauas_disable_chk_to_status > 0
        and     oauas_disabled = 0;

        IF iCnt > 0 THEN
                return 0;
        ELSE
                return 2;
        END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_ol_auto_upl_disable_chk_stt;
/

