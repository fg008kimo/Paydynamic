CREATE OR REPLACE PACKAGE OL_PO_RES_SUMM_PKG is

	--TYPE   PO_RES_SUMM_type is REF cursor return PO_RES_SUMM_VIEW%rowtype;

	function F_po_res_summ (in_amt_type	ol_merchant_reserved_amt.omr_type%type)
	return po_res_summ_tab;

end OL_PO_RES_SUMM_PKG;
/


CREATE OR REPLACE PACKAGE BODY OL_PO_RES_SUMM_PKG
IS
   FUNCTION F_po_res_summ (in_amt_type    ol_merchant_reserved_amt.omr_type%type)
	RETURN po_res_summ_tab
   IS
      Result     po_res_summ_tab := po_res_summ_tab();
      n	         INTEGER := 0;

      v_client_id         clients.client_id%type;
      v_client_name       clients.client_name%type;
      v_merchant_id       ol_merchant_reserved_amt.omr_merchant_id%type;
      v_merchant_name     ol_merch_detail.md_name%type;
      v_merchant_short_name     ol_merch_detail.md_short_name%type;
      v_country_id        ol_merchant_reserved_amt.omr_country_id%type;
      v_country_name      country.country_name%type;
      v_service_code      ol_merchant_reserved_amt.omr_service_code%type;
      v_service_name      def_service_code.sc_desc%type;
      v_currency_id       ol_merchant_reserved_amt.omr_currency_id%type;
      v_status            ol_merchant_reserved_amt.omr_status%type;

      v_tmp_res_amt       ol_merchant_reserved_amt.omr_reserved_amount%type;
      v_tmp_effect_date   ol_merchant_reserved_amt.omr_effect_date%type;

      v_sun_res_amt       ol_merchant_reserved_amt.omr_reserved_amount%type;
      v_sun_effect_date   ol_merchant_reserved_amt.omr_effect_date%type;
      v_mon_res_amt       ol_merchant_reserved_amt.omr_reserved_amount%type;
      v_mon_effect_date   ol_merchant_reserved_amt.omr_effect_date%type;
      v_tue_res_amt       ol_merchant_reserved_amt.omr_reserved_amount%type;
      v_tue_effect_date   ol_merchant_reserved_amt.omr_effect_date%type;
      v_wed_res_amt       ol_merchant_reserved_amt.omr_reserved_amount%type;
      v_wed_effect_date   ol_merchant_reserved_amt.omr_effect_date%type;
      v_thu_res_amt       ol_merchant_reserved_amt.omr_reserved_amount%type;
      v_thu_effect_date   ol_merchant_reserved_amt.omr_effect_date%type;
      v_fri_res_amt       ol_merchant_reserved_amt.omr_reserved_amount%type;
      v_fri_effect_date   ol_merchant_reserved_amt.omr_effect_date%type;
      v_sat_res_amt       ol_merchant_reserved_amt.omr_reserved_amount%type;
      v_sat_effect_date   ol_merchant_reserved_amt.omr_effect_date%type;
      
      v_tmp_remain_res_amt  ol_merchant_reserved_amt.omr_remain_reserved_amount%type;
      v_sun_remain_res_amt  ol_merchant_reserved_amt.omr_remain_reserved_amount%type;
      v_mon_remain_res_amt  ol_merchant_reserved_amt.omr_remain_reserved_amount%type;
      v_tue_remain_res_amt  ol_merchant_reserved_amt.omr_remain_reserved_amount%type;
      v_wed_remain_res_amt  ol_merchant_reserved_amt.omr_remain_reserved_amount%type;
      v_thu_remain_res_amt  ol_merchant_reserved_amt.omr_remain_reserved_amount%type;
      v_fri_remain_res_amt  ol_merchant_reserved_amt.omr_remain_reserved_amount%type;
      v_sat_remain_res_amt  ol_merchant_reserved_amt.omr_remain_reserved_amount%type;

      cursor     cur_merchant_account is
          select clients.client_id as client_id, client_name,
                 omr_merchant_id, md_name ,
                 md_short_name,
                 omr_country_id, country_name,
                 omr_service_code, sc_desc,
                 omr_currency_id,
                 omr_status
            from clients, def_service_code, country, ol_merch_detail, ol_merchant_reserved_amt
           where omr_type = in_amt_type
             and omr_merchant_id = md_merchant_id
             and omr_country_id = country_code
             and omr_service_code = sc_code
             and ol_merch_detail.md_client_id = clients.client_id
        group by clients.client_id, client_name,
                 omr_merchant_id, md_name,
                 md_short_name,
                 omr_country_id, country_name,
                 omr_service_code, sc_desc,
                 omr_currency_id,
                 omr_status
        order by clients.client_id, client_name,
                 omr_merchant_id, md_name,
                 md_short_name,
                 omr_country_id, country_name,
                 omr_service_code, sc_desc,
                 omr_currency_id,
                 omr_status;
   BEGIN
      OPEN cur_merchant_account;

      LOOP
         FETCH cur_merchant_account
         INTO  v_client_id,
               v_client_name,
               v_merchant_id,
               v_merchant_name,
               v_merchant_short_name,
               v_country_id,
               v_country_name,
               v_service_code,
               v_service_name,
               v_currency_id,
               v_status;

         EXIT WHEN cur_merchant_account%NOTFOUND;

         for v_day_of_week in 0..6 loop
             v_tmp_res_amt     := NULL;
             v_tmp_effect_date := NULL;
             v_tmp_remain_res_amt     := NULL;

             begin
                 select omr_reserved_amount, omr_effect_date, omr_remain_reserved_amount
                   into v_tmp_res_amt, v_tmp_effect_date, v_tmp_remain_res_amt
                   from ol_merchant_reserved_amt
                  where omr_merchant_id = v_merchant_id
                    and omr_currency_id = v_currency_id
                    and omr_country_id  = v_country_id
                    and omr_service_code = v_service_code
                    and omr_type = in_amt_type
                    and omr_status = v_status
                    and omr_day_of_week = v_day_of_week
                    and omr_effect_date = (select max(omr_effect_date)
                                            from ol_merchant_reserved_amt
                                           where omr_merchant_id = v_merchant_id
                                             and omr_currency_id = v_currency_id
                                             and omr_country_id  = v_country_id
                                             and omr_service_code = v_service_code
	                                     and omr_type = in_amt_type
                                             and omr_status = v_status
                                             and omr_day_of_week = v_day_of_week
                                         );
             exception
                 when no_data_found then
	             v_tmp_res_amt := NULL;
                     v_tmp_effect_date := NULL;
                     v_tmp_remain_res_amt := NULL;
	     end;

             if (v_day_of_week = 0) then
                 v_sun_res_amt       := v_tmp_res_amt;
                 v_sun_effect_date   := v_tmp_effect_date;
                 v_sun_remain_res_amt := v_tmp_remain_res_amt;
             elsif (v_day_of_week = 1) then
                 v_mon_res_amt       := v_tmp_res_amt;
                 v_mon_effect_date   := v_tmp_effect_date;
                 v_mon_remain_res_amt := v_tmp_remain_res_amt;
             elsif (v_day_of_week = 2) then
                 v_tue_res_amt       := v_tmp_res_amt;
                 v_tue_effect_date   := v_tmp_effect_date;
                 v_tue_remain_res_amt := v_tmp_remain_res_amt;                 
             elsif (v_day_of_week = 3) then
                 v_wed_res_amt       := v_tmp_res_amt;
                 v_wed_effect_date   := v_tmp_effect_date;
                 v_wed_remain_res_amt := v_tmp_remain_res_amt;
             elsif (v_day_of_week = 4) then
                 v_thu_res_amt       := v_tmp_res_amt;
                 v_thu_effect_date   := v_tmp_effect_date;
                 v_thu_remain_res_amt := v_tmp_remain_res_amt;
             elsif (v_day_of_week = 5) then
                 v_fri_res_amt       := v_tmp_res_amt;
                 v_fri_effect_date   := v_tmp_effect_date;
                 v_fri_remain_res_amt := v_tmp_remain_res_amt;
             elsif (v_day_of_week = 6) then
                 v_sat_res_amt       := v_tmp_res_amt;
                 v_sat_effect_date   := v_tmp_effect_date;
                 v_sat_remain_res_amt := v_tmp_remain_res_amt;
             end if;
         end loop;

         Result.EXTEND;
         n := n+1;

         result (n) :=
            PO_RES_SUMM_OBJ(v_client_id,
                            v_client_name,
                            v_merchant_id,
                            v_merchant_name,
                            v_merchant_short_name,
                            v_country_id,
                            v_country_name,
                            v_service_code,
                            v_service_name,
                            v_currency_id,
                            v_status,
                            v_sun_res_amt,
                            v_sun_remain_res_amt,
                            to_char(v_sun_effect_date, 'YYYYMMDDHH24MISS'),
                            v_mon_res_amt,
                            v_mon_remain_res_amt,
                            to_char(v_mon_effect_date, 'YYYYMMDDHH24MISS'),
                            v_tue_res_amt,
                            v_tue_remain_res_amt,
                            to_char(v_tue_effect_date, 'YYYYMMDDHH24MISS'),
                            v_wed_res_amt,
                            v_wed_remain_res_amt,
                            to_char(v_wed_effect_date, 'YYYYMMDDHH24MISS'),
                            v_thu_res_amt,
                            v_thu_remain_res_amt,
                            to_char(v_thu_effect_date, 'YYYYMMDDHH24MISS'),
                            v_fri_res_amt,
                            v_fri_remain_res_amt,
                            to_char(v_fri_effect_date, 'YYYYMMDDHH24MISS'),
                            v_sat_res_amt,
                            v_sat_remain_res_amt,
                            to_char(v_sat_effect_date, 'YYYYMMDDHH24MISS')
			   );
      END LOOP;

      CLOSE cur_merchant_account;

      RETURN (Result);
   END;

END OL_PO_RES_SUMM_PKG;
/

