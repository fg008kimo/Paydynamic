CREATE OR REPLACE PACKAGE merchant_auto_settlement_pkg
IS
    FUNCTION is_holiday_by_country(
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE
    ) RETURN CHAR;

    FUNCTION get_last_business_date(
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE
    ) RETURN VARCHAR2;

    FUNCTION get_business_date_of_month (
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE,
        in_rule_value      IN RULE_AUTO_SETTLEMENT.RS_VALUE%TYPE
    ) RETURN VARCHAR2;

    FUNCTION get_every_x_days (
        in_last_stl_date   IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE,
        in_rule_value      IN RULE_AUTO_SETTLEMENT.RS_VALUE%TYPE,
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE
    ) RETURN VARCHAR2;

    FUNCTION get_every_weekday (
        in_last_stl_date   IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE,
        in_rule_value      IN RULE_AUTO_SETTLEMENT.RS_VALUE%TYPE,
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE
    ) RETURN VARCHAR2;


END merchant_auto_settlement_pkg;
/

CREATE OR REPLACE PACKAGE BODY merchant_auto_settlement_pkg
IS

    ------------------------------------
    FUNCTION is_holiday_by_country (
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE
    ) RETURN CHAR
    IS

        iDOW         INTEGER := 0;
        iHolidayCnt  INTEGER := 0;

        vRtn         CHAR(1) := 'N';

    BEGIN

        SELECT count(1)
        INTO iHolidayCnt
        FROM holiday
        WHERE h_country = in_country
        AND h_date = in_posting_date
        AND h_is_non_holiday = 0; -- 0 means holiday

        if iHolidayCnt > 0 then
            vRtn := 'Y';
        else
            -- for Database NSL_DATE_LANGUAGE set AMERICAN, 1: Sun; ... 7: Sat
            -- reset 0 - 6, 0:Sun,... 6: Sat
            SELECT TO_NUMBER (TO_CHAR (TO_DATE (in_posting_date, 'YYYYMMDD'), 'D')) - 1
            INTO iDOW
            FROM dual;

            if iDOW in (0, 6) then
                SELECT count(1)
                INTO iHolidayCnt
                FROM holiday
                WHERE h_country = in_country
                AND h_date = in_posting_date
                AND h_is_non_holiday = 1; -- 1 means workding_day

                if (iHolidayCnt > 0) then
                    vRtn := 'N';
                else
                    vRtn := 'Y';
                end if;

            end if;
        end if;

        return vRtn;
    END is_holiday_by_country;

    ------------------------------------
    FUNCTION get_last_business_date(
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE
    ) RETURN VARCHAR2
    IS

        vBusinessLastDate  TXN_HEADER.TH_HOST_POSTING_DATE%TYPE;
        vLastDate          TXN_HEADER.TH_HOST_POSTING_DATE%TYPE;

        vHolidayFlag       CHAR(1) := 'Y';

    BEGIN
        vLastDate := to_char(last_day(to_date(in_posting_date, 'YYYYMMDD')), 'YYYYMMDD');
        vHolidayFlag := is_holiday_by_country(vLastDate, in_country);


        if vHolidayFlag = 'N' then
            vBusinessLastDate := vLastDate;
        else

            WHILE (1 > 0) LOOP
                vLastDate := to_char(to_date(vLastDate, 'YYYYMMDD') - 1, 'YYYYMMDD');
                vHolidayFlag := is_holiday_by_country(vLastDate, in_country);

                if vHolidayFlag = 'N' then
                    vBusinessLastDate := vLastDate;
                    EXIT;
                end if;
            END LOOP;
        end if;


        return vBusinessLastDate;

    END get_last_business_date;


    ------------------------------------
    FUNCTION get_business_date_of_month (
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE,
        in_rule_value      IN RULE_AUTO_SETTLEMENT.RS_VALUE%TYPE
    ) RETURN VARCHAR2
    IS
        vLastDayOfMonth   TXN_HEADER.TH_HOST_POSTING_DATE%TYPE;

        vTargetDate       TXN_HEADER.TH_HOST_POSTING_DATE%TYPE;
        vCnt              NUMBER;
        vHolidayFlag      CHAR(1) := 'Y';

        vTmpPostingDate   TXN_HEADER.TH_HOST_POSTING_DATE%TYPE;
        vTmpTargetDate    TXN_HEADER.TH_HOST_POSTING_DATE%TYPE;

    BEGIN

        vLastDayOfMonth := to_char(last_day(add_months(to_date(in_posting_date, 'YYYYMMDD'), -1)), 'YYYYMMDD');

        vTargetDate := vLastDayOfMonth;
        vCnt        := 1;

        WHILE ( 1 > 0 ) LOOP
            vTargetDate := to_char(to_date(vTargetDate, 'YYYYMMDD') + 1, 'YYYYMMDD');

            vHolidayFlag := is_holiday_by_country(vTargetDate, in_country);

            if vHolidayFlag = 'N' then
                if vCnt = to_number(in_rule_value) then
                    EXIT;
                end if;

                vCnt := vCnt + 1;

            end if;
        END LOOP;

        vTmpPostingDate := to_char(trunc(to_date(in_posting_date, 'YYYYMMDD'), 'MM'), 'YYYYMMDD');

        vTmpTargetDate := to_char(trunc(to_date(vTargetDate, 'YYYYMMDD'), 'MM'), 'YYYYMMDD');

        if (vTmpPostingDate != vTmpTargetDate) then
            vTargetDate := get_last_business_date(in_posting_date, in_country);
        end if;

        return vTargetDate;

    END get_business_date_of_month;

    
    ------------------------------------
    FUNCTION get_every_x_days (
        in_last_stl_date   IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE,
        in_rule_value      IN RULE_AUTO_SETTLEMENT.RS_VALUE%TYPE,
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE
    ) RETURN VARCHAR2
    IS

        vTargetDate       TXN_HEADER.TH_HOST_POSTING_DATE%TYPE;
        vCnt              NUMBER;
        vHolidayFlag      CHAR(1) := 'Y';

    BEGIN
        -- for 1st time running
        if in_last_stl_date is null then
            return in_posting_date;
        end if; 

        vTargetDate := in_last_stl_date;
        vCnt        := 1;

        WHILE ( 1 > 0 ) LOOP
            vTargetDate := to_char(to_date(vTargetDate, 'YYYYMMDD') + 1, 'YYYYMMDD');

            vHolidayFlag := is_holiday_by_country(vTargetDate, in_country);

            if vHolidayFlag = 'N' then
                if vCnt = to_number(in_rule_value) then
                    EXIT;
                end if;

                vCnt := vCnt + 1;

            end if;
            
        END LOOP;        
         
        return vTargetDate;

    END get_every_x_days;


    ------------------------------------
    FUNCTION get_every_weekday (
        in_last_stl_date   IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE,
        in_country         IN HOLIDAY.H_COUNTRY%TYPE,
        in_rule_value      IN RULE_AUTO_SETTLEMENT.RS_VALUE%TYPE,
        in_posting_date    IN TXN_HEADER.TH_HOST_POSTING_DATE%TYPE
    ) RETURN VARCHAR2
    IS
        vTargetDate       TXN_HEADER.TH_HOST_POSTING_DATE%TYPE;
        vHolidayFlag      CHAR(1) := 'Y';

        v_day_of_week     VARCHAR2(1);
        l_temp            NUMBER;

    BEGIN
        if in_last_stl_date is null then
            vTargetDate := to_char(to_date(in_posting_date, 'YYYYMMDD') - 1, 'YYYYMMDD');
        else 
            vTargetDate := in_last_stl_date;
        end if;

        WHILE ( 1 > 0) LOOP
            vTargetDate := to_char(to_date(vTargetDate, 'YYYYMMDD') + 1, 'YYYYMMDD');
            v_day_of_week := to_char(to_number(to_char(to_date(vTargetDate, 'YYYYMMDD'), 'D')) -1);

            l_temp := instr(in_rule_value, v_day_of_week);

            if (l_temp != 0) then
                vHolidayFlag :=  is_holiday_by_country(vTargetDate, in_country);
                if (vHolidayFlag = 'Y') then
                    WHILE ( 1 > 0) LOOP
                        vTargetDate := to_char(to_date(vTargetDate, 'YYYYMMDD') + 1, 'YYYYMMDD');
                        vHolidayFlag := is_holiday_by_country(vTargetDate, in_country);
                        if vHolidayFlag = 'N' then
                            EXIT;
                        end if;
                    
                    END LOOP;
                end if;
                
                EXIT;
            end if;
        END LOOP;

        return vTargetDate;

    END get_every_weekday;

END merchant_auto_settlement_pkg;
/
