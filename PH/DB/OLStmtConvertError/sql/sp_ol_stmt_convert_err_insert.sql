


CREATE OR REPLACE FUNCTION sp_ol_stmt_convert_err_insert (
    in_file_id          ol_stmt_convert_error.ce_file_id%TYPE,
    in_message_code     ol_stmt_convert_error.ce_message_code%TYPE,
    in_result           ol_stmt_convert_error.ce_result%TYPE,
    in_format_id        ol_stmt_convert_error.ce_format_id%TYPE,
    in_create_user      ol_stmt_convert_error.ce_create_user%TYPE)
    RETURN NUMBER
IS
BEGIN
    INSERT INTO ol_stmt_convert_error (ce_file_id,
                    ce_message_code,
                    ce_result,
                    ce_format_id,
                    ce_create_user,
                    ce_create_timestamp)
    VALUES (in_file_id,
            in_message_code,
            in_result,
            in_format_id,
            in_create_user,
            SYSDATE);

    IF SQL%ROWCOUNT = 0
    THEN
        RETURN 1;
    ELSE
        RETURN 0;
    END IF;
EXCEPTION
    WHEN OTHERS
    THEN
        RETURN 9;
END sp_ol_stmt_convert_err_insert;
/

