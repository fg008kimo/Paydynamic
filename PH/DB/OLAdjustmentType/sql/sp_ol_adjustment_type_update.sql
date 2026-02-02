CREATE OR REPLACE FUNCTION sp_ol_adjustment_type_update (
   in_party_type      ol_adjustment_type.oat_party_type%TYPE,
   in_code            ol_adjustment_type.oat_code%TYPE,
   in_dc_ind          ol_adjustment_type.oat_dc_ind%TYPE,
   in_desc            ol_adjustment_type.oat_desc%TYPE,
   in_disabled        ol_adjustment_type.oat_disabled%TYPE,
   in_update_user     ol_adjustment_type.oat_update_user%TYPE,
   in_bal_type	      ol_adjustment_type.oat_bal_type%TYPE)
   RETURN NUMBER
IS
BEGIN
   UPDATE ol_adjustment_type
      SET oat_dc_ind = in_dc_ind,
          oat_desc = in_desc,
          oat_disabled = in_disabled,
	  oat_bal_type = in_bal_type,
          oat_update_user = in_update_user,
          oat_update_timestamp = SYSDATE
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
END sp_ol_adjustment_type_update;
/

