CREATE OR REPLACE FUNCTION sp_ol_auto_upl_job_status_get (
   in_nature_path       	ol_auto_upload_job_status.oaujs_nature_path%TYPE,
   in_provider_path          	ol_auto_upload_job_status.oaujs_provider_path%TYPE,
   in_process_bank    		ol_auto_upload_job_status.oaujs_process_bank%TYPE,
   in_exclude_mode           	ol_auto_upload_job_status.oaujs_exclude_mode%TYPE,
   out_cursor                   OUT SYS_REFCURSOR)	
RETURN NUMBER IS
	iCnt    integer := 0;
BEGIN

	select  count(*)
        into    iCnt
        from    ol_auto_upload_job_status
        where   oaujs_nature_path = in_nature_path
        and     oaujs_provider_path = in_provider_path
        and     oaujs_process_bank = in_process_bank
        and     oaujs_exclude_mode = in_exclude_mode;

	IF iCnt > 0 THEN
		
		OPEN out_cursor FOR
		select 	oaujs_job_seq,
		       	oaujs_status
		from    ol_auto_upload_job_status
        	where   oaujs_nature_path = in_nature_path
        	and     oaujs_provider_path = in_provider_path
        	and     oaujs_process_bank = in_process_bank
        	and     oaujs_exclude_mode = in_exclude_mode;

		return 0;

	ELSE
                return 2;
        END IF;

EXCEPTION
   WHEN OTHERS THEN
      	RETURN 9;
END sp_ol_auto_upl_job_status_get;
/

