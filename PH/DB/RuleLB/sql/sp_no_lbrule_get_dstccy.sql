CREATE OR REPLACE FUNCTION sp_no_lbrule_get_dstccy(
   in_merchant_id       MERCH_DETAIL.MERCHANT_ID%TYPE,
   in_service_code	rule_psp_lb_criteria.rc_service_code%TYPE,
   out_cursor       OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR

   SELECT currency_id
    FROM psp_country,
         (SELECT pp_country, pp_psp_id
            FROM psp_pay_method
           WHERE     pp_disabled = 0
                 AND pp_pay_method IN
                        (SELECT pm_pay_method
                           FROM (SELECT pm_merchant_id, pm_pay_method
                                   FROM merchant_pay_method
                                  WHERE     pm_disabled = 0
                                        AND pm_merchant_id = in_merchant_id),
                                (SELECT sp_service_code, sp_pay_method
                                   FROM service_pay_method
                                  WHERE     sp_disabled = 0
                                        AND sp_service_code = in_service_code)
                          WHERE pm_pay_method = sp_pay_method)),
         (SELECT psp_id 
            FROM psp_detail, psp_master
           WHERE     disabled = 0
                 AND client_id = pm_client_id
                 AND online_mode = 'Y'
                 AND status = 'O'
                 AND pm_status = 'O') pdt
   WHERE     country = pp_country
         AND psp_country.psp_id = pp_psp_id
         AND pdt.psp_id = pp_psp_id
   GROUP BY currency_id;


   RETURN 0;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_no_lbrule_get_dstccy;
/

