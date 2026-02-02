CREATE OR REPLACE FUNCTION sp_email_notify_list_find (
        in_party_type                 EMAIL_SETTING.ES_PARTY_TYPE%TYPE,
        in_party_id                   EMAIL_SETTING.ES_PARTY_ID%TYPE,
        in_funct                      EMAIL_SETTING.ES_FUNCT%TYPE,
        out_cursor            OUT     SYS_REFCURSOR)
RETURN NUMBER Is
        iCnt        INTEGER := 0;
BEGIN

        /* ***** in_party_type */

	
        SELECT COUNT(*)
          INTO iCnt
          FROM EMAIL_NOTIFY_LIST, EMAIL_SETTING
         WHERE ES_PARTY_TYPE = 'M' 
           AND ES_PARTY_ID = in_party_id
           AND ES_FUNCT = in_funct
           AND ES_DISABLED = 0
           AND ES_EMAIL_ID = EL_ID;
	
	
        IF iCnt > 0 THEN
                OPEN OUT_CURSOR FOR
                    SELECT EL_EMAIL
                      FROM EMAIL_NOTIFY_LIST, EMAIL_SETTING
                     WHERE ES_PARTY_TYPE = 'M' 
                       AND ES_PARTY_ID = in_party_id
                       AND ES_FUNCT = in_funct
                       AND ES_DISABLED = 0
                       AND ES_EMAIL_ID = EL_ID;
                RETURN 1;
        END IF;

        SELECT COUNT(*)
          INTO iCnt
          FROM EMAIL_NOTIFY_LIST, MERCH_DETAIL, EMAIL_SETTING
         WHERE ES_PARTY_TYPE = 'C' 
           AND MERCHANT_ID = in_party_id
           AND ES_PARTY_ID = CLIENT_ID
           AND ES_FUNCT = in_funct
           AND ES_DISABLED = 0
           AND ES_EMAIL_ID = EL_ID;

        IF iCnt > 0 THEN
                OPEN OUT_CURSOR FOR
                    SELECT EL_EMAIL
                      FROM EMAIL_NOTIFY_LIST, MERCH_DETAIL, EMAIL_SETTING
                     WHERE ES_PARTY_TYPE = 'C' 
                       AND MERCHANT_ID = in_party_id
                       AND ES_PARTY_ID = CLIENT_ID
                       AND ES_FUNCT = in_funct
                       AND ES_DISABLED = 0
                       AND ES_EMAIL_ID = EL_ID;
                RETURN 1;
        END IF;

        SELECT COUNT(*)
          INTO iCnt 
          FROM EMAIL_NOTIFY_LIST, EMAIL_SETTING
         WHERE ES_PARTY_TYPE = 'G' 
           AND ES_FUNCT = in_funct
           AND ES_DISABLED = 0
           AND ES_EMAIL_ID = EL_ID;
 
        IF iCnt > 0 THEN
                OPEN OUT_CURSOR FOR
                    SELECT EL_EMAIL
                      FROM EMAIL_NOTIFY_LIST, EMAIL_SETTING
                     WHERE ES_PARTY_TYPE = 'G' 
                       AND ES_FUNCT = in_funct
                       AND ES_DISABLED = 0
                       AND ES_EMAIL_ID = EL_ID;

                RETURN 1;
        END IF;

	RETURN 0;

EXCEPTION
    WHEN OTHERS THEN
        RETURN 9;
END sp_email_notify_list_find;
/

