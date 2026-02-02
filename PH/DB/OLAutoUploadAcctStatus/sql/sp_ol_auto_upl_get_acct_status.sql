


CREATE OR REPLACE FUNCTION sp_ol_auto_upl_get_acct_status(
	in_acct_type			OL_BANK_ACCTS.OB_ACCT_TYPE%type,
	out_cursor                      OUT SYS_REFCURSOR)
RETURN NUMBER IS
	iCnt	INTEGER := 0;
BEGIN

	select 	count(*)
	into 	iCnt
	from    ol_auto_upload_acct_status
     	where   oauas_acct_type = in_acct_type
	and	oauas_chk_status = 1
	and	oauas_disabled = 0;

	IF iCnt > 0 THEN
		OPEN out_cursor FOR
		select  oauas_status_type
		from 	ol_auto_upload_acct_status
		where   oauas_acct_type = in_acct_type
        	and     oauas_chk_status = 1
		and	oauas_disabled = 0;

              	return 0;
	ELSE
		return 2;
  	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_ol_auto_upl_get_acct_status;
/

