CREATE OR REPLACE FUNCTION sp_getall_promote_segment (
   in_merchant_id        MERCH_DETAIL.MERCHANT_ID%TYPE,
   in_group              customer_group_detail.cgd_code%TYPE,
   out_cursor        OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR

   select CGR_GROUP_CODE
   from CUSTOMER_GROUP_RULES
   where cgr_merchant_id = in_merchant_id
   and cgr_from_group_code = in_group;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_getall_promote_segment;
/
