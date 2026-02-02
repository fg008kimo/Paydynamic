


CREATE OR REPLACE FUNCTION sp_ol_sar_trigger_chk_conflict (
    in_s_provider_id    ol_semi_auto_recon_trigger_log.otl_s_provider_id%TYPE,
    in_s_pid            ol_semi_auto_recon_trigger_log.otl_s_pid%TYPE,
    in_r_provider_id    ol_semi_auto_recon_trigger_log.otl_r_provider_id%TYPE,
    in_r_pid            ol_semi_auto_recon_trigger_log.otl_r_pid%TYPE)
    RETURN sar_trigger_chk_conflict_tab
    PIPELINED
IS
    out_rec                        sar_trigger_chk_conflict_obj;

    TRIGGER_SEQ                    INTEGER;
    CREATE_USER                    VARCHAR2 (20);
    CREATE_TIMESTAMP               DATE;
    S_PROVIDER_ID                  VARCHAR2 (20);
    S_PID                          VARCHAR2 (10);
    R_PROVIDER_ID                  VARCHAR2 (20);
    R_PID                          VARCHAR2 (10);

    sql_base                       VARCHAR2 (300);
    sql_stmt                       VARCHAR2 (4000);
    sar_trigger_chk_conflict_cur   SYS_REFCURSOR;
BEGIN
    sql_base := '
	SELECT	OTL_TRIGGER_SEQ,
			OTL_CREATE_USER,
			OTL_CREATE_TIMESTAMP,
			OTL_S_PROVIDER_ID,
			OTL_S_PID,
			OTL_R_PROVIDER_ID,
			OTL_R_PID
	FROM	OL_SEMI_AUTO_RECON_TRIGGER_LOG
	WHERE	OTL_TRIGGER_STATUS IN (''I'',''P'')
';

    IF in_s_pid = '000'
    THEN
        sql_stmt :=
               sql_base
            || '
		AND		OTL_S_PROVIDER_ID = '''
            || in_s_provider_id
            || '''
		UNION '
            || sql_base
            || '
		AND		OTL_R_PROVIDER_ID = '''
            || in_s_provider_id
            || '''
	';
    ELSE
        sql_stmt :=
               sql_base
            || '
		AND		OTL_S_PROVIDER_ID = '''
            || in_s_provider_id
            || '''
		AND		OTL_S_PID IN (''000'', '''
            || in_s_pid
            || ''')
		UNION '
            || sql_base
            || '
		AND		OTL_R_PROVIDER_ID = '''
            || in_s_provider_id
            || '''
		AND		OTL_R_PID IN (''000'', '''
            || in_s_pid
            || ''')
	';
    END IF;

    IF in_r_pid = '000'
    THEN
        sql_stmt :=
               sql_stmt
            || '
		UNION '
            || sql_base
            || '
		AND		OTL_S_PROVIDER_ID = '''
            || in_r_provider_id
            || '''
		UNION '
            || sql_base
            || '
		AND		OTL_R_PROVIDER_ID = '''
            || in_r_provider_id
            || '''
	';
    ELSE
        sql_stmt :=
               sql_stmt
            || '
		UNION '
            || sql_base
            || '
		AND		OTL_S_PROVIDER_ID = '''
            || in_r_provider_id
            || '''
		AND		OTL_S_PID IN (''000'', '''
            || in_r_pid
            || ''')
		UNION '
            || sql_base
            || '
		AND		OTL_R_PROVIDER_ID = '''
            || in_r_provider_id
            || '''
		AND		OTL_R_PID IN (''000'', '''
            || in_r_pid
            || ''')
	';
    END IF;

    OPEN sar_trigger_chk_conflict_cur FOR sql_stmt;

    LOOP
        FETCH sar_trigger_chk_conflict_cur
            INTO TRIGGER_SEQ,
                 CREATE_USER,
                 CREATE_TIMESTAMP,
                 S_PROVIDER_ID,
                 S_PID,
                 R_PROVIDER_ID,
                 R_PID;

        EXIT WHEN sar_trigger_chk_conflict_cur%NOTFOUND;

        PIPE ROW (sar_trigger_chk_conflict_obj (TRIGGER_SEQ,
                                                CREATE_USER,
                                                CREATE_TIMESTAMP,
                                                S_PROVIDER_ID,
                                                S_PID,
                                                R_PROVIDER_ID,
                                                R_PID));
    END LOOP;

    CLOSE sar_trigger_chk_conflict_cur;

    RETURN;
END sp_ol_sar_trigger_chk_conflict;
/

