CREATE OR REPLACE FUNCTION sp_ol_adjustment_type_delete (
   in_party_type    ol_adjustment_type.oat_party_type%TYPE,
   in_code          ol_adjustment_type.oat_code%TYPE)
   RETURN NUMBER
IS
BEGIN
   DELETE FROM ol_adjustment_type
         WHERE oat_party_type = in_party_type AND oat_code = in_code;

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
END sp_ol_adjustment_type_delete;
/

