CREATE OR REPLACE FUNCTION BAID_TXN_OPEN_BAL  (
    in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
    in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
    in_psp_id                ol_txn_psp_detail.otp_psp_id%TYPE,
    in_baid                  OL_BANK_ACCT_ID.OBAI_BAID%type,
    in_ccy                   ol_txn_elements.ote_ccy%TYPE,
    in_ele                   varchar2) return  baid_txn_tab pipelined is
 in_cur sys_refcursor;
 in_cur1 sys_refcursor;
 out_rec baid_txn_type_obj;
 OBAI_BAID             VARCHAR2(20);
 OBAI_BAID_NAME        VARCHAR2(50);
 psp_id                varchar(10);
 TXN_ID                VARCHAR2(16);
 TID                   VARCHAR2(50);
 TXN_CODE              CHAR(3);
 TXN_CODE_DESC         VARCHAR2(50);
 OPEN_BAL              NUMBER;
 AMT_TYPE              CHAR(2);
 AMOUNT                NUMBER;
 BAL                   NUMBER;
 TXN_ELEMENT_TYPE      CHAR(4);
 TXN_ELEMENT_TYPE_DESC VARCHAR2(50);
 EXEC_SEQ              NUMBER(38);
 TXN_CCY               CHAR(3);
 APPROVAL_TIMESTAMP    TIMESTAMP(6);
 APPROVAL_DATE         VARCHAR2(20);
 REPORT_DATE           VARCHAR2(20);
 VOID_TXN_ID           VARCHAR2(16);
 PARTY_TYPE            CHAR(1);
 cur_kount             number;
 begin
 in_cur :=baid_txn_null(in_approval_date_from ,in_approval_date_to,in_psp_id,in_baid,in_ccy,in_ele);
 loop
    fetch in_cur into
             OBAI_BAID,
             OBAI_BAID_NAME,
             psp_id,
             TXN_ID,
             TID,
             TXN_CODE,
             TXN_CODE_DESC,
             OPEN_BAL,
             AMT_TYPE,
             AMOUNT,
             BAL,
             TXN_ELEMENT_TYPE,
             TXN_ELEMENT_TYPE_DESC,
             EXEC_SEQ,
             TXN_CCY,
             APPROVAL_TIMESTAMP,
             APPROVAL_DATE,
             REPORT_DATE,
             VOID_TXN_ID,
             PARTY_TYPE;

    

    EXIT WHEN in_cur%NOTFOUND;

   pipe row (baid_txn_type_obj(OBAI_BAID,
                   OBAI_BAID_NAME,
                   psp_id,
                   TXN_ID,
                   TID,
                   TXN_CODE,
                   TXN_CODE_DESC,
                   OPEN_BAL,
                   AMT_TYPE,
                   AMOUNT,
                   BAL,
                   TXN_ELEMENT_TYPE,
                   TXN_ELEMENT_TYPE_DESC,
                   EXEC_SEQ,
                   TXN_CCY,
                   APPROVAL_TIMESTAMP,
                   APPROVAL_DATE,
                   REPORT_DATE,
                   VOID_TXN_ID,
                   PARTY_TYPE));

 end loop;
-- dbms_output.put_line('xxxxxxx' || in_cur%rowcount);
 cur_kount := in_cur%rowcount;
 close in_cur;

 
 if cur_kount=0 then

   pipe row (baid_txn_type_obj(in_baid,
                   NULL,
                   in_psp_id,
                   NULL,
                   NULL,
                   NULL,
                   NULL,
                   0,
                   NULL,
                   0,
                   0,
                   NULL,
                   NULL,
                   NULL,
                   in_ccy,
                   NULL,
                   NULL,
                   NULL,
                   NULL,
                   NULL));

 
 
end if;

 return;
 end BAID_TXN_OPEN_BAL;
/

