CREATE OR REPLACE FUNCTION sp_ol_stmt_keywords_update (
   in_int_bank_code      ol_stmt_format_keywords.olfk_int_bank_code%TYPE,
   in_format_type        ol_stmt_format_keywords.olfk_format_type%TYPE,
   in_format_value       ol_stmt_format_keywords.olfk_format_value%TYPE,
   in_format_txn_code    ol_stmt_format_keywords.olfk_format_txn_code%TYPE,
   in_format_template    ol_stmt_format_keywords.olfk_format_template%TYPE,
   in_format_col_name    ol_stmt_format_keywords.olfk_format_col_name%TYPE,
   in_display_order      ol_stmt_format_keywords.olfk_display_order%TYPE,
   in_disabled           ol_stmt_format_keywords.olfk_disabled%TYPE,
   in_user               ol_stmt_format_keywords.olfk_update_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   UPDATE ol_stmt_format_keywords
      SET olfk_update_user = in_user,
          olfk_update_timestamp = SYSDATE,
          olfk_disabled = 1
    WHERE     olfk_int_bank_code = in_int_bank_code
          AND olfk_format_type = in_format_type
          AND olfk_format_value = in_format_value;

   IF in_disabled = 0
   THEN
      INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code,
                                           olfk_format_type,
                                           olfk_format_value,
                                           olfk_format_txn_code,
                                           olfk_format_template,
                                           olfk_format_col_name,
                                           olfk_display_order,
                                           olfk_disabled,
                                           olfk_create_timestamp,
                                           olfk_create_user,
                                           olfk_update_timestamp,
                                           olfk_update_user)
              VALUES (
                        in_int_bank_code,
                        in_format_type,
                        (SELECT NVL (MAX (OLFK_FORMAT_VALUE), 0) + 1
                           FROM OL_STMT_FORMAT_KEYWORDS
                          WHERE     OLFK_INT_BANK_CODE = in_int_bank_code
                                AND OLFK_FORMAT_TYPE = in_format_type),
                        in_format_txn_code,
                        in_format_template,
                        in_format_col_name,
                        in_display_order,
                        in_disabled,
                        SYSDATE,
                        in_user,
                        SYSDATE,
                        in_user);

      IF SQL%ROWCOUNT = 0
      THEN
         RETURN 1;
      END IF;

      UPDATE ol_stmt_format_keywords
         SET olfk_update_user = in_user, olfk_update_timestamp = SYSDATE
       WHERE     olfk_int_bank_code = in_int_bank_code
             AND olfk_format_type = in_format_type
             AND olfk_format_txn_code = in_format_txn_code
             AND olfk_display_order = in_display_order
             AND olfk_disabled = 0;

      IF SQL%ROWCOUNT = 0
      THEN
         RETURN 1;
      END IF;
   END IF;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_ol_stmt_keywords_update;
/

