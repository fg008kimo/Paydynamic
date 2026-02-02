CREATE OR REPLACE FUNCTION sp_txn_fe_url_getblurl_new_ui(
  in_txn_code                   txn_fe_url.txn_code%type,
  in_service_code               service.code%type,
  in_merchant_id                service_blacklist_url.bu_merchant_id%type,
  in_country                    service_blacklist_url.bu_country%type,
  in_language                   txn_fe_url.language%type,
  in_route_type                 service.route_type%type,
  in_direction                  txn_fe_url.direction%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
        iCnt         integer := 0;
        v_ui_url    service_blacklist_url.bu_url%type := NULL;
        v_ui_path   service_blacklist_path.bp_path%type := NULL;
        v_ui_method service_blacklist_path.bp_method%type := NULL;
Begin

    -- URL
    --check new ui indicator
    begin
        select bu_url
        into v_ui_url
        from(select bu_url
            from   service_blacklist_url
            where bu_service_code = in_service_code
            and bu_merchant_id = in_merchant_id
            and bu_country = in_country
            and bu_new_ui = 1
            and bu_disabled = 0
            and bu_for_backup = 0
	    and bu_effect_date <= sysdate
            ORDER BY DBMS_RANDOM.VALUE)
        WHERE ROWNUM = 1;

    exception when no_data_found then
        v_ui_url := NULL;
    end;

    if v_ui_url is null then
    --when all normal new url disabled, use the backup new url (dr site)
        begin
            select bu_url
            into v_ui_url
            from(select bu_url
                from service_blacklist_url
                where bu_service_code = in_service_code
                and bu_merchant_id = in_merchant_id
                and bu_country = in_country
                and bu_new_ui = 1
                and bu_disabled = 0
                and bu_for_backup = 1
		and bu_effect_date <= sysdate
                ORDER BY DBMS_RANDOM.VALUE)
            WHERE ROWNUM = 1;

        exception when no_data_found then
            v_ui_url := NULL;
        end;
    end if;

    if v_ui_url is null then
    --when new ui indicator, select the normal url in service level
        begin
            select bu_url
            into v_ui_url
            from(select bu_url
                from service_blacklist_url
                where bu_service_code = in_service_code
                and bu_merchant_id = '000'
                and bu_country = in_country
                and bu_new_ui = 1
                and bu_disabled = 0
                and bu_for_backup = 0
		and bu_effect_date <= sysdate
                ORDER BY DBMS_RANDOM.VALUE)
            WHERE ROWNUM = 1;

        exception when no_data_found then
            v_ui_url := NULL;
        end;
    end if;

    if v_ui_url is null then
    --when no normal url , use backup url (dr site)
        begin
            select bu_url
            into v_ui_url
            from(select bu_url
                from service_blacklist_url
                where bu_service_code = in_service_code
                and bu_merchant_id = '000'
                and bu_country = in_country
                and bu_new_ui = 1
                and bu_disabled = 0
                and bu_for_backup = 1
		and bu_effect_date <= sysdate
                ORDER BY DBMS_RANDOM.VALUE)
            WHERE ROWNUM = 1;

        exception when no_data_found then
            v_ui_url := NULL;
        end;
    end if;

    if v_ui_url is null then
    --when no new ui indicator, select the normal url
        begin
            select bu_url
            into v_ui_url
            from(select bu_url
                from service_blacklist_url
                where bu_service_code = in_service_code
                and bu_merchant_id = in_merchant_id
                and bu_country = in_country
                and bu_new_ui = 0
                and bu_disabled = 0
                and bu_for_backup = 0
		and bu_effect_date <= sysdate
                ORDER BY DBMS_RANDOM.VALUE)
            WHERE ROWNUM = 1;

        exception when no_data_found then
            v_ui_url := NULL;
        end;
    end if;

    if v_ui_url is null then
    --when no normal url , use backup url (dr site)
        begin
            select bu_url
            into v_ui_url
            from(select bu_url
                from service_blacklist_url
                where bu_service_code = in_service_code
                and bu_merchant_id = in_merchant_id
                and bu_country = in_country
                and bu_new_ui = 0
                and bu_disabled = 0
                and bu_for_backup = 1
		and bu_effect_date <= sysdate
                ORDER BY DBMS_RANDOM.VALUE)
            WHERE ROWNUM = 1;

        exception when no_data_found then
            v_ui_url := NULL;
        end;
    end if;

    if v_ui_url is null then
    --when no new ui indicator, select the normal url in service level
        begin
            select bu_url
            into v_ui_url
            from(select bu_url
                from service_blacklist_url
                where bu_service_code = in_service_code
                and bu_merchant_id = '000'
                and bu_country = in_country
                and bu_new_ui = 0
                and bu_disabled = 0
                and bu_for_backup = 0
		and bu_effect_date <= sysdate
                ORDER BY DBMS_RANDOM.VALUE)
            WHERE ROWNUM = 1;

        exception when no_data_found then
            v_ui_url := NULL;
        end;
    end if;

    if v_ui_url is null then
    --when no normal url , use backup url (dr site)
        begin
            select bu_url
            into v_ui_url
            from(select bu_url
                from service_blacklist_url
                where bu_service_code = in_service_code
                and bu_merchant_id = '000'
                and bu_country = in_country
                and bu_new_ui = 0
                and bu_disabled = 0
                and bu_for_backup = 1
		and bu_effect_date <= sysdate
                ORDER BY DBMS_RANDOM.VALUE)
            WHERE ROWNUM = 1;

        exception when no_data_found then
            v_ui_url := NULL;
        end;
    end if;

    if v_ui_url is null then
        return 0;
    end if;

    -- PATH, METHOD
    begin
        select bp_path, bp_method
        into v_ui_path, v_ui_method
        from service_blacklist_path
        where bp_service_code = in_service_code
        and bp_merchant_id = in_merchant_id
        and bp_country = in_country
        and bp_direction = in_direction
        and bp_language = in_language
        and bp_new_ui = 1
        and bp_disabled = 0
        and bp_effect_date = (select max(bp_effect_date)
                              from service_blacklist_path
                              where bp_service_code = in_service_code
                              and bp_merchant_id = in_merchant_id
                              and bp_country = in_country
                              and bp_direction = in_direction
                              and bp_language = in_language
                              and bp_new_ui = 1
                              and bp_disabled = 0
                              and bp_effect_date <= SYSDATE);
    exception when no_data_found then
        v_ui_path := NULL;
        v_ui_method := NULL;
    end;

    if v_ui_path is null then
        begin
            select bp_path, bp_method
            into v_ui_path, v_ui_method
            from service_blacklist_path
            where bp_service_code = in_service_code
            and bp_merchant_id = in_merchant_id
            and bp_country = in_country
            and bp_direction = in_direction
            and bp_language = 'EN'
            and bp_new_ui = 1
            and bp_disabled = 0
            and bp_effect_date = (select max(bp_effect_date)
                                  from service_blacklist_path
                                  where bp_service_code = in_service_code
                                  and bp_merchant_id = in_merchant_id
                                  and bp_country = in_country
                                  and bp_direction = in_direction
                                  and bp_language = 'EN'
                                  and bp_new_ui = 1
                                  and bp_disabled = 0
                                  and bp_effect_date <= SYSDATE);
        exception when no_data_found then
            v_ui_path := NULL;
            v_ui_method := NULL;
        end;
    end if;

    ----
    if v_ui_path is null then
        begin
            select bp_path, bp_method
            into v_ui_path, v_ui_method
            from service_blacklist_path
            where bp_service_code = in_service_code
            and bp_merchant_id = in_merchant_id
            and bp_country = in_country
            and bp_direction = in_direction
            and bp_language = in_language
            and bp_new_ui = 0
            and bp_disabled = 0
            and bp_effect_date = (select max(bp_effect_date)
                                  from service_blacklist_path
                                  where bp_service_code = in_service_code
                                  and bp_merchant_id = in_merchant_id
                                  and bp_country = in_country
                                  and bp_direction = in_direction
                                  and bp_language = in_language
                                  and bp_new_ui = 0
                                  and bp_disabled = 0
                                  and bp_effect_date <= SYSDATE);
        exception when no_data_found then
            v_ui_path := NULL;
            v_ui_method := NULL;
        end;
    end if;

    if v_ui_path is null then
        begin
            select bp_path, bp_method
            into v_ui_path, v_ui_method
            from service_blacklist_path
            where bp_service_code = in_service_code
            and bp_merchant_id = in_merchant_id
            and bp_country = in_country
            and bp_direction = in_direction
            and bp_language = 'EN'
            and bp_new_ui = 0
            and bp_disabled = 0
            and bp_effect_date = (select max(bp_effect_date)
                                  from service_blacklist_path
                                  where bp_service_code = in_service_code
                                  and bp_merchant_id = in_merchant_id
                                  and bp_country = in_country
                                  and bp_direction = in_direction
                                  and bp_language = 'EN'
                                  and bp_new_ui = 0
                                  and bp_disabled = 0
                                  and bp_effect_date <= SYSDATE);
        exception when no_data_found then
            v_ui_path := NULL;
            v_ui_method := NULL;
        end;
    end if;

    ----
    if v_ui_path is null then
        return 0;
    end if;


    OPEN out_cursor for
        select v_ui_url ret_url,
               v_ui_path ret_path,
               v_ui_method ret_method
        from dual;

    return 1;
exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_txn_fe_url_getblurl_new_ui;
/

