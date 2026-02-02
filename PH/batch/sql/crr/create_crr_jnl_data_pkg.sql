CREATE OR REPLACE PACKAGE CRR_JNL_DATA_PKG
AS
   /*TYPE CRR_JNL_DATA_REC IS RECORD
   (
      TXN_DATE               VARCHAR2 (8 BYTE),
      CR_COUNTRY_ID          CHAR (2 BYTE),
      CR_PRODUCT_CODE        CHAR (3 BYTE),
      CR_JNL_TYPE_ID         INTEGER,
      CR_JNL_ENTRY_TYPE_ID   VARCHAR2 (20 BYTE),
      CR_PARTY_TYPE          CHAR (1 BYTE),
      CR_PARTY_ID            VARCHAR (15 BYTE),
      CR_CURRENCY_ID         CHAR (3 BYTE),
      GL_ID                  INTEGER,
      CR_IND                 CHAR (1 BYTE),
      TXN_AMT                NUMBER (14, 2),
      TXN_COUNT              INTEGER,
      TXN_ID                 VARCHAR (16 BYTE)
   );

   TYPE CRR_JNL_DATA_TAB IS TABLE OF CRR_JNL_DATA_REC;
   */

   FUNCTION GET_JNL (in_jnl_type_id    crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
                     in_group_id       crr_jnl_entry_type_mapping.group_id%TYPE,
                     in_fr_txn_date    txn_header.th_approval_date%TYPE,
                     in_to_txn_date    txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_OFL_JNL (in_jnl_type_id    crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
                         in_group_id       crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
                         in_fr_txn_date    txn_header.th_approval_date%TYPE,
                         in_to_txn_date    txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_JNL (in_jnl_type_id    crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
                        in_group_id       crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
                        in_fr_txn_date    txn_header.th_approval_date%TYPE,
                        in_to_txn_date    txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_TABLE (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_OFL_TABLE (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_TABLE (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MERCH_TXN_AMT_MULTI (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MERCH_TXN_ELEMENTS_MULTI (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_PSP_TXN_ELEMENTS_MULTI (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MERCH_TXN_ELEMENTS_SINGLE (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_PSP_TXN_ELEMENTS_SINGLE (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_OFL_PSP_SINGLE (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_OFL_PSP_MULTI (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_OFL_MERCH_SINGLE (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%type,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%type,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%type,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_amt_type         varchar)
      return crr_jnl_data_tab
      pipelined;

   FUNCTION GET_OFL_MERCH_MULTI (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%type,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%type,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%type,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_amt_type         varchar)
      return crr_jnl_data_tab
      pipelined;

   FUNCTION GET_OFL_PSP_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%type,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%type,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%type,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%type)
      return crr_jnl_data_tab
      pipelined;

   FUNCTION GET_OFL_PSP_BAID_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%type,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%type,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%type,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%type)
      return crr_jnl_data_tab
      pipelined;

   FUNCTION GET_OFL_MERCH_TXN_AMT_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%type,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%type,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%type,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%type)
      return crr_jnl_data_tab
      pipelined;

  FUNCTION GET_OFL_MERCH_FEE_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%type,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%type,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%type,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%type)
      return crr_jnl_data_tab
      pipelined;

  FUNCTION GET_OFL_MERCH_MARKUP_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%type,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%type,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%type,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%type)
      return crr_jnl_data_tab
      pipelined;

   FUNCTION GET_OFL_PSP_MARKUP_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%type,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%type,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%type,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%type)
      return crr_jnl_data_tab
      pipelined;

   FUNCTION GET_OFL_PSP_DELI_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%type,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%type,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%type,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%type,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%type)
      return crr_jnl_data_tab
      pipelined;

   FUNCTION GET_MI_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_MULTI_CCY (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_GLOBAL (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_GLOBAL_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_PSP_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_PSP_GLOBAL (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_OFL_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_OFL_GLOBAL (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;

   FUNCTION GET_MI_OFL_PSP_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED;


END CRR_JNL_DATA_PKG;
/

CREATE OR REPLACE PACKAGE BODY CRR_JNL_DATA_PKG
AS
   FUNCTION GET_JNL (in_jnl_type_id    crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
                     in_group_id       crr_jnl_entry_type_mapping.group_id%TYPE,
                     in_fr_txn_date    txn_header.th_approval_date%TYPE,
                     in_to_txn_date    txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN

      FOR ENTRY IN (SELECT ENTRY_TYPE_ID
                      FROM CRR_JNL_ENTRY_TYPE_MAPPING
                     WHERE JNL_TYPE_ID = in_jnl_type_id
                       AND GROUP_ID = in_group_id
                  GROUP BY ENTRY_TYPE_ID)
      LOOP
         FOR RESULT IN (SELECT *
                          FROM TABLE (GET_TABLE (in_jnl_type_id,
                                                 ENTRY.ENTRY_TYPE_ID,
                                                 in_group_id,
                                                 in_fr_txn_date,
                                                 in_to_txn_date)))
         LOOP
            PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                        RESULT.CR_COUNTRY_ID,
                                        RESULT.CR_PRODUCT_CODE,
                                        RESULT.CR_JNL_TYPE_ID,
                                        RESULT.CR_JNL_ENTRY_TYPE_ID,
                                        RESULT.CR_PARTY_TYPE,
                                        RESULT.CR_PARTY_ID,
                                        RESULT.CR_CURRENCY_ID,
                                        RESULT.GL_ID,
                                        RESULT.CR_IND,
                                        RESULT.TXN_AMT,
                                        RESULT.TXN_COUNT,
                                        RESULT.TXN_ID));
         END LOOP;
      END LOOP;

      RETURN;
   END GET_JNL;


   FUNCTION GET_OFL_JNL (in_jnl_type_id    crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
                         in_group_id       crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
                         in_fr_txn_date    txn_header.th_approval_date%TYPE,
                         in_to_txn_date    txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN

      FOR ENTRY IN (SELECT COM_ENTRY_TYPE_ID
                      FROM CRR_OFL_JNL_ENTRY_TYPE_MAPPING
                     WHERE COM_JNL_TYPE_ID = in_jnl_type_id
                       AND COM_GROUP_ID = in_group_id
                  GROUP BY COM_ENTRY_TYPE_ID)
      LOOP
         FOR RESULT IN (SELECT *
                          FROM TABLE (GET_OFL_TABLE (in_jnl_type_id,
                                                     ENTRY.COM_ENTRY_TYPE_ID,
                                                     in_group_id,
                                                     in_fr_txn_date,
                                                     in_to_txn_date)))
         LOOP
            PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                        RESULT.CR_COUNTRY_ID,
                                        RESULT.CR_PRODUCT_CODE,
                                        RESULT.CR_JNL_TYPE_ID,
                                        RESULT.CR_JNL_ENTRY_TYPE_ID,
                                        RESULT.CR_PARTY_TYPE,
                                        RESULT.CR_PARTY_ID,
                                        RESULT.CR_CURRENCY_ID,
                                        RESULT.GL_ID,
                                        RESULT.CR_IND,
                                        RESULT.TXN_AMT,
                                        RESULT.TXN_COUNT,
                                        RESULT.TXN_ID));
         END LOOP;
dbms_output.put_line(in_jnl_type_id || ' ' || to_char(sysdate,'dd-mon-yyyy hh24:mi:ss'));
      END LOOP;

      RETURN;
   END GET_OFL_JNL;


   FUNCTION GET_MI_JNL (in_jnl_type_id    crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
                        in_group_id       crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
                        in_fr_txn_date    txn_header.th_approval_date%TYPE,
                        in_to_txn_date    txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN

      FOR ENTRY IN (SELECT CMM_ENTRY_TYPE_ID
                      FROM CRR_MI_JNL_ENTRY_TYPE_MAPPING
                     WHERE CMM_JNL_TYPE_ID = in_jnl_type_id
                       AND CMM_GROUP_ID = in_group_id
                  GROUP BY CMM_ENTRY_TYPE_ID)
      LOOP
         FOR RESULT IN (SELECT *
                          FROM TABLE (GET_MI_TABLE (in_jnl_type_id,
                                                    ENTRY.CMM_ENTRY_TYPE_ID,
                                                    in_group_id,
                                                    in_fr_txn_date,
                                                    in_to_txn_date)))
         LOOP
            PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                        RESULT.CR_COUNTRY_ID,
                                        RESULT.CR_PRODUCT_CODE,
                                        RESULT.CR_JNL_TYPE_ID,
                                        RESULT.CR_JNL_ENTRY_TYPE_ID,
                                        RESULT.CR_PARTY_TYPE,
                                        RESULT.CR_PARTY_ID,
                                        RESULT.CR_CURRENCY_ID,
                                        RESULT.GL_ID,
                                        RESULT.CR_IND,
                                        RESULT.TXN_AMT,
                                        RESULT.TXN_COUNT,
                                        RESULT.TXN_ID));
         END LOOP;
dbms_output.put_line(in_jnl_type_id || ' ' || to_char(sysdate,'dd-mon-yyyy hh24:mi:ss'));
      END LOOP;

      RETURN;
   END GET_MI_JNL;


   FUNCTION GET_TABLE (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
      txn_table   crr_jnl_entry_type_mapping.TXN_TABLE%TYPE;
      txn_side    crr_jnl_entry_type_mapping.TXN_SIDE%TYPE;
      txn_type    crr_jnl_entry_type_mapping.TXN_ELEMENT_TYPE%TYPE;
      single      crr_jnl_entry_type_mapping.SINGLE%TYPE;
   BEGIN
      SELECT TXN_TABLE, TXN_SIDE, TXN_ELEMENT_TYPE, SINGLE
        INTO txn_table, txn_side, txn_type, single
        FROM (SELECT TXN_TABLE, TXN_SIDE, TXN_ELEMENT_TYPE, SINGLE
                FROM CRR_JNL_ENTRY_TYPE_MAPPING
               WHERE     JNL_TYPE_id = in_jnl_type_id
                     AND ENTRY_TYPE_ID = in_entry_type_id
                     AND GROUP_ID = in_group_id)
       WHERE ROWNUM = 1;

      IF txn_table = 'TXN_HEADER'
      THEN
         IF single <> 1
         THEN
            IF txn_side = 'M'
            THEN
               IF txn_type = 'TAMT'
               THEN
                  FOR RESULT
                     IN (SELECT *
                           FROM TABLE (
                                   GET_MERCH_TXN_AMT_MULTI (
                                      in_jnl_type_id,
                                      in_entry_type_id,
                                      in_group_id,
                                      in_fr_txn_date,
                                      in_to_txn_date)))
                  LOOP
                     PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                                 RESULT.CR_COUNTRY_ID,
                                                 RESULT.CR_PRODUCT_CODE,
                                                 RESULT.CR_JNL_TYPE_ID,
                                                 RESULT.CR_JNL_ENTRY_TYPE_ID,
                                                 RESULT.CR_PARTY_TYPE,
                                                 RESULT.CR_PARTY_ID,
                                                 RESULT.CR_CURRENCY_ID,
                                                 RESULT.GL_ID,
                                                 RESULT.CR_IND,
                                                 RESULT.TXN_AMT,
                                                 RESULT.TXN_COUNT,
                                                 RESULT.TXN_ID));
                  END LOOP;
               END IF;
            END IF;
         END IF;
      ELSIF txn_table = 'TXN_ELEMENTS'
      THEN
         IF single = 1
         THEN
            IF txn_side = 'M'
            THEN
               FOR RESULT
                  IN (SELECT *
                        FROM TABLE (
                                GET_MERCH_TXN_ELEMENTS_SINGLE (
                                   in_jnl_type_id,
                                   in_entry_type_id,
                                   in_group_id,
                                   in_fr_txn_date,
                                   in_to_txn_date)))
               LOOP
                  PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                              RESULT.CR_COUNTRY_ID,
                                              RESULT.CR_PRODUCT_CODE,
                                              RESULT.CR_JNL_TYPE_ID,
                                              RESULT.CR_JNL_ENTRY_TYPE_ID,
                                              RESULT.CR_PARTY_TYPE,
                                              RESULT.CR_PARTY_ID,
                                              RESULT.CR_CURRENCY_ID,
                                              RESULT.GL_ID,
                                              RESULT.CR_IND,
                                              RESULT.TXN_AMT,
                                              RESULT.TXN_COUNT,
                                              RESULT.TXN_ID));
               END LOOP;
            ELSIF txn_side = 'P'
            THEN
               FOR RESULT
                  IN (SELECT *
                        FROM TABLE (
                                GET_PSP_TXN_ELEMENTS_SINGLE (
                                   in_jnl_type_id,
                                   in_entry_type_id,
                                   in_group_id,
                                   in_fr_txn_date,
                                   in_to_txn_date)))
               LOOP
                  PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                              RESULT.CR_COUNTRY_ID,
                                              RESULT.CR_PRODUCT_CODE,
                                              RESULT.CR_JNL_TYPE_ID,
                                              RESULT.CR_JNL_ENTRY_TYPE_ID,
                                              RESULT.CR_PARTY_TYPE,
                                              RESULT.CR_PARTY_ID,
                                              RESULT.CR_CURRENCY_ID,
                                              RESULT.GL_ID,
                                              RESULT.CR_IND,
                                              RESULT.TXN_AMT,
                                              RESULT.TXN_COUNT,
                                              RESULT.TXN_ID));
               END LOOP;
            END IF;
         ELSE
            IF txn_side = 'M'
            THEN
               FOR RESULT
                  IN (SELECT *
                        FROM TABLE (
                                GET_MERCH_TXN_ELEMENTS_MULTI (
                                   in_jnl_type_id,
                                   in_entry_type_id,
                                   in_group_id,
                                   in_fr_txn_date,
                                   in_to_txn_date)))
               LOOP
                  PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                              RESULT.CR_COUNTRY_ID,
                                              RESULT.CR_PRODUCT_CODE,
                                              RESULT.CR_JNL_TYPE_ID,
                                              RESULT.CR_JNL_ENTRY_TYPE_ID,
                                              RESULT.CR_PARTY_TYPE,
                                              RESULT.CR_PARTY_ID,
                                              RESULT.CR_CURRENCY_ID,
                                              RESULT.GL_ID,
                                              RESULT.CR_IND,
                                              RESULT.TXN_AMT,
                                              RESULT.TXN_COUNT,
                                              RESULT.TXN_ID));
               END LOOP;
            ELSIF txn_side = 'P'
            THEN
               FOR RESULT
                  IN (SELECT *
                        FROM TABLE (
                                GET_PSP_TXN_ELEMENTS_MULTI (in_jnl_type_id,
                                                            in_entry_type_id,
                                                            in_group_id,
                                                            in_fr_txn_date,
                                                            in_to_txn_date)))
               LOOP
                  PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                              RESULT.CR_COUNTRY_ID,
                                              RESULT.CR_PRODUCT_CODE,
                                              RESULT.CR_JNL_TYPE_ID,
                                              RESULT.CR_JNL_ENTRY_TYPE_ID,
                                              RESULT.CR_PARTY_TYPE,
                                              RESULT.CR_PARTY_ID,
                                              RESULT.CR_CURRENCY_ID,
                                              RESULT.GL_ID,
                                              RESULT.CR_IND,
                                              RESULT.TXN_AMT,
                                              RESULT.TXN_COUNT,
                                              RESULT.TXN_ID));
               END LOOP;
            END IF;
         END IF;
      END IF;

      RETURN;
   END GET_TABLE;


   FUNCTION GET_OFL_TABLE (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
      txn_side    crr_ofl_jnl_entry_type_mapping.COM_TXN_SIDE%TYPE;
      txn_type    crr_ofl_jnl_entry_type_mapping.COM_AMT_FIELD%TYPE;
      single      crr_ofl_jnl_entry_type_mapping.COM_IS_SINGLE%TYPE;
      txn_code    crr_ofl_jnl_entry_type_mapping.COM_TXN_CODE%TYPE;
   BEGIN
      SELECT COM_AMT_FIELD
        INTO txn_type
        FROM (SELECT COM_TXN_SIDE, COM_AMT_FIELD, COM_IS_SINGLE, COM_TXN_CODE
                FROM CRR_OFL_JNL_ENTRY_TYPE_MAPPING
               WHERE     COM_JNL_TYPE_id = in_jnl_type_id
                     AND COM_ENTRY_TYPE_ID = in_entry_type_id
                     AND COM_GROUP_ID = in_group_id)
       WHERE ROWNUM = 1;

      IF txn_type in ('TXN_AMT')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_PSP_SINGLE (in_jnl_type_id,
                                               in_entry_type_id,
                                               in_group_id,
                                               in_fr_txn_date,
                                               in_to_txn_date,
                                               'TXN_AMT')
		           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                  	                   RESULT.CR_COUNTRY_ID,
	                                   RESULT.CR_PRODUCT_CODE,
	                                   RESULT.CR_JNL_TYPE_ID,
	                                   RESULT.CR_JNL_ENTRY_TYPE_ID,
	                                   RESULT.CR_PARTY_TYPE,
        	                           RESULT.CR_PARTY_ID,
        	                           RESULT.CR_CURRENCY_ID,
        	                           RESULT.GL_ID,
        	                           RESULT.CR_IND,
        	                           RESULT.TXN_AMT,
        	                           RESULT.TXN_COUNT,
        	                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type = 'TXN_P_AMT'
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_PSP_SINGLE (in_jnl_type_id,
                                               in_entry_type_id,
                                               in_group_id,
                                               in_fr_txn_date,
                                               in_to_txn_date,
                                               'PSP_AMT')
		           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                  	                   RESULT.CR_COUNTRY_ID,
	                                   RESULT.CR_PRODUCT_CODE,
	                                   RESULT.CR_JNL_TYPE_ID,
	                                   RESULT.CR_JNL_ENTRY_TYPE_ID,
	                                   RESULT.CR_PARTY_TYPE,
        	                           RESULT.CR_PARTY_ID,
        	                           RESULT.CR_CURRENCY_ID,
        	                           RESULT.GL_ID,
        	                           RESULT.CR_IND,
        	                           RESULT.TXN_AMT,
        	                           RESULT.TXN_COUNT,
        	                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'FEE'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_MERCH_MULTI (in_jnl_type_id,
                                                 in_entry_type_id,
                                                 in_group_id,
                                                 in_fr_txn_date,
                                                 in_to_txn_date,
						 'FEE')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'G_TXN_AMT'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_PSP_GLOBAL (in_jnl_type_id,
                                                in_entry_type_id,
                                                in_group_id,
                                                in_fr_txn_date,
                                                in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'G_TXN_AMT_BAID'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_PSP_BAID_GLOBAL (in_jnl_type_id,
                                                     in_entry_type_id,
                                                     in_group_id,
                                                     in_fr_txn_date,
                                                     in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'M_TXN_AMT'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_MERCH_MULTI (in_jnl_type_id,
                                                 in_entry_type_id,
                                                 in_group_id,
                                                 in_fr_txn_date,
                                                 in_to_txn_date,
						 'TXN')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'M_NET_AMT'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_MERCH_MULTI (in_jnl_type_id,
                                                 in_entry_type_id,
                                                 in_group_id,
                                                 in_fr_txn_date,
                                                 in_to_txn_date,
						 'NET')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'M_TXN_AMT_SINGLE'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_MERCH_SINGLE (in_jnl_type_id,
                                                 in_entry_type_id,
                                                 in_group_id,
                                                 in_fr_txn_date,
                                                 in_to_txn_date,
						 'TXN')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'FEE_SINGLE'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_MERCH_SINGLE (in_jnl_type_id,
                                                 in_entry_type_id,
                                                 in_group_id,
                                                 in_fr_txn_date,
                                                 in_to_txn_date,
						 'FEE')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
      ELSIF txn_type = 'G_M_TXN_AMT'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_MERCH_TXN_AMT_GLOBAL (in_jnl_type_id,
                                                          in_entry_type_id,
                                                          in_group_id,
                                                          in_fr_txn_date,
                                                          in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'G_FEE'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_MERCH_FEE_GLOBAL (in_jnl_type_id,
                                                      in_entry_type_id,
                                                      in_group_id,
                                                      in_fr_txn_date,
                                                      in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'G_M_MARKUP'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_MERCH_MARKUP_GLOBAL (in_jnl_type_id,
                                                         in_entry_type_id,
                                                         in_group_id,
                                                         in_fr_txn_date,
                                                         in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'MARKUP_AMT'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_PSP_MARKUP_GLOBAL (in_jnl_type_id,
                                                       in_entry_type_id,
                                                       in_group_id,
                                                       in_fr_txn_date,
                                                       in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     ELSIF txn_type = 'DELI_AMT'
     THEN
       FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_OFL_PSP_DELI_GLOBAL (in_jnl_type_id,
                                                       in_entry_type_id,
                                                       in_group_id,
                                                       in_fr_txn_date,
                                                       in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     END IF;
   END GET_OFL_TABLE;


   FUNCTION GET_MI_TABLE (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
      txn_side    crr_mi_jnl_entry_type_mapping.CMM_TXN_SIDE%TYPE;
      txn_type    crr_mi_jnl_entry_type_mapping.CMM_AMT_FIELD%TYPE;
      single      crr_mi_jnl_entry_type_mapping.CMM_IS_SINGLE%TYPE;
      txn_code    crr_mi_jnl_entry_type_mapping.CMM_TXN_CODE%TYPE;
   BEGIN
      SELECT CMM_AMT_FIELD
        INTO txn_type
        FROM (SELECT CMM_TXN_SIDE, CMM_AMT_FIELD, CMM_IS_SINGLE, CMM_TXN_CODE
                FROM CRR_MI_JNL_ENTRY_TYPE_MAPPING
               WHERE     CMM_JNL_TYPE_id = in_jnl_type_id
                     AND CMM_ENTRY_TYPE_ID = in_entry_type_id
                     AND CMM_GROUP_ID = in_group_id)
       WHERE ROWNUM = 1;

      IF txn_type in ('TXN_AMT','TXN_INTR','TXN_INCT','OVPA_AMT','UDPA_AMT')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_MULTI (in_jnl_type_id,
                                          in_entry_type_id,
                                          in_group_id,
                                          in_fr_txn_date,
                                          in_to_txn_date,
					  'TXN_AMT')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('NET_AMT')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_MULTI (in_jnl_type_id,
                                          in_entry_type_id,
                                          in_group_id,
                                          in_fr_txn_date,
                                          in_to_txn_date,
					  'NET_AMT')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('TXN_MULTI_CCY')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_MULTI_CCY (in_jnl_type_id,
                                              in_entry_type_id,
                                              in_group_id,
                                              in_fr_txn_date,
                                              in_to_txn_date,
				              'TXN_AMT')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('NET_MULTI_CCY')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_MULTI_CCY (in_jnl_type_id,
                                              in_entry_type_id,
                                              in_group_id,
                                              in_fr_txn_date,
                                              in_to_txn_date,
				              'NET_AMT')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('FEE')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_MULTI (in_jnl_type_id,
                                          in_entry_type_id,
                                          in_group_id,
                                          in_fr_txn_date,
                                          in_to_txn_date,
					  'FEE')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('IBBT_AMT')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_MULTI (in_jnl_type_id,
                                          in_entry_type_id,
                                          in_group_id,
                                          in_fr_txn_date,
                                          in_to_txn_date,
					  'IBBT_AMT')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('IBBT_FEE')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_MULTI (in_jnl_type_id,
                                          in_entry_type_id,
                                          in_group_id,
                                          in_fr_txn_date,
                                          in_to_txn_date,
					  'IBBT_AMT')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('G_TXN_AMT','G_TXN_INTR','G_TXN_INCT','G_FEE','G_OVPA','G_UDPA')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_GLOBAL (in_jnl_type_id,
                                          in_entry_type_id,
                                          in_group_id,
                                          in_fr_txn_date,
                                          in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('G_TXN_AMT_M','G_TXN_INTR_M','G_TXN_INCT_M','G_FEE_M')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_GLOBAL_MULTI (in_jnl_type_id,
                                                 in_entry_type_id,
                                                 in_group_id,
                                                 in_fr_txn_date,
                                                 in_to_txn_date,
                                                 'FEE')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('G_NET_AMT_M')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_GLOBAL_MULTI (in_jnl_type_id,
                                                 in_entry_type_id,
                                                 in_group_id,
                                                 in_fr_txn_date,
                                                 in_to_txn_date,
                                                 'NET_AMT')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('G_IBBT_FEE')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_GLOBAL_MULTI (in_jnl_type_id,
                                                 in_entry_type_id,
                                                 in_group_id,
                                                 in_fr_txn_date,
                                                 in_to_txn_date,
                                                 'G_IBBT_FEE')
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
        RETURN;
      ELSIF txn_type in ('TXN_P_AMT','P_FEE')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_PSP_MULTI (in_jnl_type_id,
                                              in_entry_type_id,
                                              in_group_id,
                                              in_fr_txn_date,
                                              in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
      ELSIF txn_type = 'G_TXN_P_AMT' OR txn_type = 'G_P_FEE'
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_PSP_GLOBAL (in_jnl_type_id,
                                              in_entry_type_id,
                                              in_group_id,
                                              in_fr_txn_date,
                                              in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
      ELSIF txn_type in ('OL_TXN_AMT','OL_NET_AMT','OL_FEE','OL_INTR_AMT','OL_OVPA_AMT','OL_UDPA_AMT')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_OFL_MULTI (in_jnl_type_id,
                                              in_entry_type_id,
                                              in_group_id,
                                              in_fr_txn_date,
                                              in_to_txn_date,
                                              txn_type)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
      ELSIF txn_type in ('OL_G_TXN_AMT')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_OFL_GLOBAL (in_jnl_type_id,
                                               in_entry_type_id,
                                               in_group_id,
                                               in_fr_txn_date,
                                               in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
      ELSIF txn_type in ('OL_TXN_P_AMT')
      THEN
        FOR RESULT
          IN (SELECT *
              FROM   TABLE (GET_MI_OFL_PSP_MULTI (in_jnl_type_id,
                                                  in_entry_type_id,
                                                  in_group_id,
                                                  in_fr_txn_date,
                                                  in_to_txn_date)
                           )
             )
             LOOP
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END LOOP;
       RETURN;
     END IF;
   END GET_MI_TABLE;


   FUNCTION GET_MERCH_TXN_AMT_MULTI (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (  SELECT TH_APPROVAL_DATE TXN_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CASE
                         WHEN CR_PARTY_TYPE <> 'G' THEN CR_PARTY_ID
                         ELSE ''
                      END
                         CR_PARTY_ID,
                      TD_TXN_CCY CR_CURRENCY_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN CR_DEBIT_GL_ID
                         ELSE 0
                      END
                         GL_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
                         ELSE ''
                      END
                         CR_IND,
                      SUM (TH_TRANSACTION_AMOUNT) TXN_AMT,
                      1 TXN_COUNT,
                      TH_TXN_ID TXN_ID
                 FROM (SELECT TH_TXN_ID,
                              TH_TXN_CODE,
                              TH_APPROVAL_DATE,
                              TH_TRANSACTION_AMOUNT,
                              TH_NET_CCY,
                              TH_NET_AMOUNT,
                              TH_MERCHANT_ID,
                              TH_SERVICE_CODE
                         FROM TXN_HEADER
                        WHERE     TH_APPROVAL_DATE >= in_fr_txn_date
                              AND TH_APPROVAL_DATE <= in_to_txn_date
                              AND TH_STATUS IN ('C', 'R')
                              AND TH_AR_IND = 'A'),
                      (SELECT TD_TXN_ID, TD_TXN_COUNTRY, TD_TXN_CCY
                         FROM TXN_DETAIL),
                      (SELECT CR_COUNTRY_ID,
                              CR_PARTY_TYPE,
                              CR_PARTY_ID,
                              CR_JNL_TYPE_ID,
                              CR_JNL_ENTRY_TYPE_ID,
                              CR_TXN_CODE,
                              CR_PRODUCT_CODE,
                              CR_CURRENCY_ID,
                              CR_CREDIT_GL_ID,
                              CR_DEBIT_GL_ID
                         FROM CRR_RULE_POSTING
                        WHERE     CR_JNL_TYPE_ID = in_jnl_type_id
                              AND CR_JNL_ENTRY_TYPE_ID = in_entry_type_id
                              AND CR_DISABLED = 0),
                      (SELECT TXN_CODE,
                              PARTY_TYPE,
                              TXN_ELEMENT_TYPE,
                              SIGN
                         FROM CRR_JNL_ENTRY_TYPE_MAPPING
                        WHERE     JNL_TYPE_ID = in_jnl_type_id
                              AND ENTRY_TYPE_ID = in_entry_type_id
                              AND GROUP_ID = in_group_id
                              AND DISABLED = 0)
                WHERE     TH_TXN_ID = TD_TXN_ID
                      AND TH_TXN_CODE = TXN_CODE
                      AND (CR_COUNTRY_ID = TD_TXN_COUNTRY)
                      AND EXISTS
                             (SELECT *
                                FROM CRR_PRODUCT_CODE_MAP
                               WHERE     TH_MERCHANT_ID = PM_MERCHANT_ID
                                     AND TH_SERVICE_CODE = PM_SERVICE_CODE
                                     AND TD_TXN_COUNTRY = PM_COUNTRY
                                     AND CR_PRODUCT_CODE = PM_PRODUCT_CODE
                                     AND PM_DISABLED = 0)
                      AND (CR_PARTY_ID = TH_MERCHANT_ID OR CR_PARTY_TYPE = 'G')
                      AND (   CR_CURRENCY_ID = TD_TXN_CCY
                           OR CR_CURRENCY_ID = 'ALL')
             GROUP BY TH_APPROVAL_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CR_PARTY_ID,
                      TD_TXN_CCY,
                      CR_CREDIT_GL_ID,
                      CR_DEBIT_GL_ID,
                      TH_TXN_ID)
      LOOP
         PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                     RESULT.CR_COUNTRY_ID,
                                     RESULT.CR_PRODUCT_CODE,
                                     RESULT.CR_JNL_TYPE_ID,
                                     RESULT.CR_JNL_ENTRY_TYPE_ID,
                                     RESULT.CR_PARTY_TYPE,
                                     RESULT.CR_PARTY_ID,
                                     RESULT.CR_CURRENCY_ID,
                                     RESULT.GL_ID,
                                     RESULT.CR_IND,
                                     RESULT.TXN_AMT,
                                     RESULT.TXN_COUNT,
                                     RESULT.TXN_ID));
      END LOOP;

      RETURN;
   END GET_MERCH_TXN_AMT_MULTI;



   FUNCTION GET_MERCH_TXN_ELEMENTS_MULTI (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (  SELECT TH_APPROVAL_DATE TXN_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CASE
                         WHEN CR_PARTY_TYPE <> 'G' THEN CR_PARTY_ID
                         ELSE ''
                      END
                         CR_PARTY_ID,
                      TE_CCY CR_CURRENCY_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN CR_DEBIT_GL_ID
                         ELSE 0
                      END
                         GL_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
                         ELSE ''
                      END
                         CR_IND,
                      SUM (TE_AMOUNT * SIGN) TXN_AMT,
                      1 TXN_COUNT,
                      TH_TXN_ID TXN_ID
                 FROM (SELECT TH_TXN_ID,
                              TH_TXN_CODE,
                              TH_APPROVAL_DATE,
                              TH_TRANSACTION_AMOUNT,
                              TH_NET_CCY,
                              TH_NET_AMOUNT,
                              TH_MERCHANT_ID,
                              TH_SERVICE_CODE
                         FROM TXN_HEADER
                        WHERE     TH_APPROVAL_DATE >= in_fr_txn_date
                              AND TH_APPROVAL_DATE <= in_to_txn_date
                              AND TH_STATUS IN ('C', 'R')
                              AND TH_AR_IND = 'A'),
                      (SELECT TD_TXN_ID, TD_TXN_COUNTRY, TD_TXN_CCY
                         FROM TXN_DETAIL),
                      (SELECT TE_TXN_ID,
                              TE_PARTY_TYPE,
                              TE_TXN_ELEMENT_TYPE,
                              TE_CCY,
                              TE_AMOUNT
                         FROM TXN_ELEMENTS),
                      (SELECT CR_COUNTRY_ID,
                              CR_PARTY_TYPE,
                              CR_PARTY_ID,
                              CR_JNL_TYPE_ID,
                              CR_JNL_ENTRY_TYPE_ID,
                              CR_TXN_CODE,
                              CR_PRODUCT_CODE,
                              CR_CURRENCY_ID,
                              CR_CREDIT_GL_ID,
                              CR_DEBIT_GL_ID
                         FROM CRR_RULE_POSTING
                        WHERE     CR_JNL_TYPE_ID = in_jnl_type_id
                              AND CR_JNL_ENTRY_TYPE_ID = in_entry_type_id
                              AND CR_DISABLED = 0),
                      (SELECT TXN_CODE,
                              PARTY_TYPE,
                              TXN_ELEMENT_TYPE,
                              SIGN
                         FROM CRR_JNL_ENTRY_TYPE_MAPPING
                        WHERE     JNL_TYPE_ID = in_jnl_type_id
                              AND ENTRY_TYPE_ID = in_entry_type_id
                              AND GROUP_ID = in_group_id
                              AND DISABLED = 0)
                WHERE     TH_TXN_ID = TD_TXN_ID
                      AND TH_TXN_ID = TE_TXN_ID
                      AND TH_TXN_CODE = TXN_CODE
                      AND TE_PARTY_TYPE = PARTY_TYPE
                      AND TE_TXN_ELEMENT_TYPE = TXN_ELEMENT_TYPE
                      AND (CR_COUNTRY_ID = TD_TXN_COUNTRY)
                      AND EXISTS
                             (SELECT *
                                FROM CRR_PRODUCT_CODE_MAP
                               WHERE     TH_MERCHANT_ID = PM_MERCHANT_ID
                                     AND TH_SERVICE_CODE = PM_SERVICE_CODE
                                     AND TD_TXN_COUNTRY = PM_COUNTRY
                                     AND CR_PRODUCT_CODE = PM_PRODUCT_CODE
                                     AND PM_DISABLED = 0)
                      AND (CR_PARTY_ID = TH_MERCHANT_ID OR CR_PARTY_TYPE = 'G')
                      AND (CR_CURRENCY_ID = TE_CCY OR CR_CURRENCY_ID = 'ALL')
             GROUP BY TH_APPROVAL_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CR_PARTY_ID,
                      TE_CCY,
                      CR_CREDIT_GL_ID,
                      CR_DEBIT_GL_ID,
                      TH_TXN_ID)
      LOOP
         PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                     RESULT.CR_COUNTRY_ID,
                                     RESULT.CR_PRODUCT_CODE,
                                     RESULT.CR_JNL_TYPE_ID,
                                     RESULT.CR_JNL_ENTRY_TYPE_ID,
                                     RESULT.CR_PARTY_TYPE,
                                     RESULT.CR_PARTY_ID,
                                     RESULT.CR_CURRENCY_ID,
                                     RESULT.GL_ID,
                                     RESULT.CR_IND,
                                     RESULT.TXN_AMT,
                                     RESULT.TXN_COUNT,
                                     RESULT.TXN_ID));
      END LOOP;

      RETURN;
   END GET_MERCH_TXN_ELEMENTS_MULTI;


   FUNCTION GET_PSP_TXN_ELEMENTS_MULTI (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (  SELECT TH_APPROVAL_DATE TXN_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CASE
                         WHEN CR_PARTY_TYPE <> 'G' THEN CR_PARTY_ID
                         ELSE ''
                      END
                         CR_PARTY_ID,
                      TE_CCY CR_CURRENCY_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN CR_DEBIT_GL_ID
                         ELSE 0
                      END
                         GL_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
                         ELSE ''
                      END
                         CR_IND,
                      SUM (TE_AMOUNT * SIGN) TXN_AMT,
                      1 TXN_COUNT,
                      TH_TXN_ID TXN_ID
                 FROM (SELECT TH_TXN_ID,
                              TH_TXN_CODE,
                              TH_APPROVAL_DATE,
                              TH_TRANSACTION_AMOUNT,
                              TH_NET_CCY,
                              TH_NET_AMOUNT,
                              TH_MERCHANT_ID,
                              TH_SERVICE_CODE
                         FROM TXN_HEADER
                        WHERE     TH_APPROVAL_DATE >= in_fr_txn_date
                              AND TH_APPROVAL_DATE <= in_to_txn_date
                              AND TH_STATUS IN ('C', 'R')
                              AND TH_AR_IND = 'A'),
                      (SELECT TD_TXN_ID, TD_TXN_COUNTRY, TD_TXN_CCY
                         FROM TXN_DETAIL),
                      (SELECT TP_TXN_ID, TP_PSP_ID FROM TXN_PSP_DETAIL),
                      (SELECT TE_TXN_ID,
                              TE_PARTY_TYPE,
                              TE_TXN_ELEMENT_TYPE,
                              TE_CCY,
                              TE_AMOUNT
                         FROM TXN_ELEMENTS),
                      (SELECT CR_COUNTRY_ID,
                              CR_PARTY_TYPE,
                              CR_PARTY_ID,
                              CR_JNL_TYPE_ID,
                              CR_JNL_ENTRY_TYPE_ID,
                              CR_TXN_CODE,
                              CR_PRODUCT_CODE,
                              CR_CURRENCY_ID,
                              CR_CREDIT_GL_ID,
                              CR_DEBIT_GL_ID
                         FROM CRR_RULE_POSTING
                        WHERE     CR_JNL_TYPE_ID = in_jnl_type_id
                              AND CR_JNL_ENTRY_TYPE_ID = in_entry_type_id
                              AND CR_DISABLED = 0),
                      (SELECT TXN_CODE,
                              PARTY_TYPE,
                              TXN_ELEMENT_TYPE,
                              SIGN
                         FROM CRR_JNL_ENTRY_TYPE_MAPPING
                        WHERE     JNL_TYPE_ID = in_jnl_type_id
                              AND ENTRY_TYPE_ID = in_entry_type_id
                              AND GROUP_ID = in_group_id
                              AND DISABLED = 0)
                WHERE     TH_TXN_ID = TD_TXN_ID
                      AND TH_TXN_ID = TP_TXN_ID
                      AND TH_TXN_ID = TE_TXN_ID
                      AND TH_TXN_CODE = TXN_CODE
                      AND TE_PARTY_TYPE = PARTY_TYPE
                      AND TE_TXN_ELEMENT_TYPE = TXN_ELEMENT_TYPE
                      AND (CR_COUNTRY_ID = TD_TXN_COUNTRY)
                      AND EXISTS
                             (SELECT *
                                FROM PSP_DETAIL, CRR_PSP_PRODUCT_CODE_MAP
                               WHERE     PSP_ID = TP_PSP_ID
                                     AND PSP_ID = PM_PSP_ID
                                     AND PSP_TYPE = PM_BUSINESS_TYPE
                                     AND CR_PRODUCT_CODE = PM_PRODUCT_CODE
                                     AND PM_DISABLED = 0)
                      AND (CR_PARTY_ID = TP_PSP_ID OR CR_PARTY_TYPE = 'G')
                      AND (CR_CURRENCY_ID = TE_CCY OR CR_CURRENCY_ID = 'ALL')
             GROUP BY TH_APPROVAL_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CR_PARTY_ID,
                      TE_CCY,
                      CR_CREDIT_GL_ID,
                      CR_DEBIT_GL_ID,
                      TH_TXN_ID)
      LOOP
         PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                     RESULT.CR_COUNTRY_ID,
                                     RESULT.CR_PRODUCT_CODE,
                                     RESULT.CR_JNL_TYPE_ID,
                                     RESULT.CR_JNL_ENTRY_TYPE_ID,
                                     RESULT.CR_PARTY_TYPE,
                                     RESULT.CR_PARTY_ID,
                                     RESULT.CR_CURRENCY_ID,
                                     RESULT.GL_ID,
                                     RESULT.CR_IND,
                                     RESULT.TXN_AMT,
                                     RESULT.TXN_COUNT,
                                     RESULT.TXN_ID));
      END LOOP;

      RETURN;
   END GET_PSP_TXN_ELEMENTS_MULTI;



   FUNCTION GET_MERCH_TXN_ELEMENTS_SINGLE (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (  SELECT TH_APPROVAL_DATE TXN_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CASE
                         WHEN CR_PARTY_TYPE <> 'G' THEN CR_PARTY_ID
                         ELSE ''
                      END
                         CR_PARTY_ID,
                      TE_CCY CR_CURRENCY_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN CR_DEBIT_GL_ID
                         ELSE 0
                      END
                         GL_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
                         ELSE ''
                      END
                         CR_IND,
                      SUM (TE_AMOUNT * SIGN) TXN_AMT,
                      COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
                      '' TXN_ID
                 FROM (SELECT TH_TXN_ID,
                              TH_TXN_CODE,
                              TH_APPROVAL_DATE,
                              TH_TRANSACTION_AMOUNT,
                              TH_NET_CCY,
                              TH_NET_AMOUNT,
                              TH_MERCHANT_ID,
                              TH_SERVICE_CODE
                         FROM TXN_HEADER
                        WHERE     TH_APPROVAL_DATE >= in_fr_txn_date
                              AND TH_APPROVAL_DATE <= in_to_txn_date
                              AND TH_STATUS IN ('C', 'R')
                              AND TH_AR_IND = 'A'),
                      (SELECT TD_TXN_ID, TD_TXN_COUNTRY, TD_TXN_CCY
                         FROM TXN_DETAIL),
                      (SELECT TE_TXN_ID,
                              TE_PARTY_TYPE,
                              TE_TXN_ELEMENT_TYPE,
                              TE_CCY,
                              TE_AMOUNT
                         FROM TXN_ELEMENTS),
                      (SELECT CR_COUNTRY_ID,
                              CR_PARTY_TYPE,
                              CR_PARTY_ID,
                              CR_JNL_TYPE_ID,
                              CR_JNL_ENTRY_TYPE_ID,
                              CR_TXN_CODE,
                              CR_PRODUCT_CODE,
                              CR_CURRENCY_ID,
                              CR_CREDIT_GL_ID,
                              CR_DEBIT_GL_ID
                         FROM CRR_RULE_POSTING
                        WHERE     CR_JNL_TYPE_ID = in_jnl_type_id
                              AND CR_JNL_ENTRY_TYPE_ID = in_entry_type_id
                              AND CR_DISABLED = 0),
                      (SELECT TXN_CODE,
                              PARTY_TYPE,
                              TXN_ELEMENT_TYPE,
                              SIGN
                         FROM CRR_JNL_ENTRY_TYPE_MAPPING
                        WHERE     JNL_TYPE_ID = in_jnl_type_id
                              AND ENTRY_TYPE_ID = in_entry_type_id
                              AND GROUP_ID = in_group_id
                              AND DISABLED = 0)
                WHERE     TH_TXN_ID = TD_TXN_ID
                      AND TH_TXN_ID = TE_TXN_ID
                      AND TH_TXN_CODE = TXN_CODE
                      AND TE_PARTY_TYPE = PARTY_TYPE
                      AND TE_TXN_ELEMENT_TYPE = TXN_ELEMENT_TYPE
                      AND (CR_COUNTRY_ID = TD_TXN_COUNTRY)
                      AND EXISTS
                             (SELECT *
                                FROM CRR_PRODUCT_CODE_MAP
                               WHERE     TH_MERCHANT_ID = PM_MERCHANT_ID
                                     AND TH_SERVICE_CODE = PM_SERVICE_CODE
                                     AND TD_TXN_COUNTRY = PM_COUNTRY
                                     AND CR_PRODUCT_CODE = PM_PRODUCT_CODE
                                     AND PM_DISABLED = 0)
                      AND (CR_PARTY_ID = TH_MERCHANT_ID OR CR_PARTY_TYPE = 'G')
                      AND (CR_CURRENCY_ID = TE_CCY OR CR_CURRENCY_ID = 'ALL')
             GROUP BY TH_APPROVAL_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CR_PARTY_ID,
                      TE_CCY,
                      CR_CREDIT_GL_ID,
                      CR_DEBIT_GL_ID)
      LOOP
         PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                     RESULT.CR_COUNTRY_ID,
                                     RESULT.CR_PRODUCT_CODE,
                                     RESULT.CR_JNL_TYPE_ID,
                                     RESULT.CR_JNL_ENTRY_TYPE_ID,
                                     RESULT.CR_PARTY_TYPE,
                                     RESULT.CR_PARTY_ID,
                                     RESULT.CR_CURRENCY_ID,
                                     RESULT.GL_ID,
                                     RESULT.CR_IND,
                                     RESULT.TXN_AMT,
                                     RESULT.TXN_COUNT,
                                     RESULT.TXN_ID));
      END LOOP;

      RETURN;
   END GET_MERCH_TXN_ELEMENTS_SINGLE;


   FUNCTION GET_PSP_TXN_ELEMENTS_SINGLE (
      in_jnl_type_id      crr_jnl_entry_type_mapping.jnl_type_id%TYPE,
      in_entry_type_id    crr_jnl_entry_type_mapping.entry_type_id%TYPE,
      in_group_id         crr_jnl_entry_type_mapping.group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (  SELECT TH_APPROVAL_DATE TXN_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CASE
                         WHEN CR_PARTY_TYPE <> 'G' THEN CR_PARTY_ID
                         ELSE ''
                      END
                         CR_PARTY_ID,
                      TE_CCY CR_CURRENCY_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN CR_DEBIT_GL_ID
                         ELSE 0
                      END
                         GL_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
                         ELSE ''
                      END
                         CR_IND,
                      SUM (TE_AMOUNT * SIGN) TXN_AMT,
                      COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
                      '' TXN_ID
                 FROM (SELECT TH_TXN_ID,
                              TH_TXN_CODE,
                              TH_APPROVAL_DATE,
                              TH_TRANSACTION_AMOUNT,
                              TH_NET_CCY,
                              TH_NET_AMOUNT,
                              TH_MERCHANT_ID,
                              TH_SERVICE_CODE
                         FROM TXN_HEADER
                        WHERE     TH_APPROVAL_DATE >= in_fr_txn_date
                              AND TH_APPROVAL_DATE <= in_to_txn_date
                              AND TH_STATUS IN ('C', 'R')
                              AND TH_AR_IND = 'A'),
                      (SELECT TD_TXN_ID, TD_TXN_COUNTRY, TD_TXN_CCY
                         FROM TXN_DETAIL),
                      (SELECT TP_TXN_ID, TP_PSP_ID FROM TXN_PSP_DETAIL),
                      (SELECT TE_TXN_ID,
                              TE_PARTY_TYPE,
                              TE_TXN_ELEMENT_TYPE,
                              TE_CCY,
                              TE_AMOUNT
                         FROM TXN_ELEMENTS),
                      (SELECT CR_COUNTRY_ID,
                              CR_PARTY_TYPE,
                              CR_PARTY_ID,
                              CR_JNL_TYPE_ID,
                              CR_JNL_ENTRY_TYPE_ID,
                              CR_TXN_CODE,
                              CR_PRODUCT_CODE,
                              CR_CURRENCY_ID,
                              CR_CREDIT_GL_ID,
                              CR_DEBIT_GL_ID
                         FROM CRR_RULE_POSTING
                        WHERE     CR_JNL_TYPE_ID = in_jnl_type_id
                              AND CR_JNL_ENTRY_TYPE_ID = in_entry_type_id
                              AND CR_DISABLED = 0),
                      (SELECT TXN_CODE,
                              PARTY_TYPE,
                              TXN_ELEMENT_TYPE,
                              SIGN
                         FROM CRR_JNL_ENTRY_TYPE_MAPPING
                        WHERE     JNL_TYPE_ID = in_jnl_type_id
                              AND ENTRY_TYPE_ID = in_entry_type_id
                              AND GROUP_ID = in_group_id
                              AND DISABLED = 0)
                WHERE     TH_TXN_ID = TD_TXN_ID
                      AND TH_TXN_ID = TP_TXN_ID
                      AND TH_TXN_ID = TE_TXN_ID
                      AND TH_TXN_CODE = TXN_CODE
                      AND TE_PARTY_TYPE = PARTY_TYPE
                      AND TE_TXN_ELEMENT_TYPE = TXN_ELEMENT_TYPE
                      AND (CR_COUNTRY_ID = TD_TXN_COUNTRY)
                      AND EXISTS
                             (SELECT *
                                FROM PSP_DETAIL, CRR_PSP_PRODUCT_CODE_MAP
                               WHERE     PSP_ID = TP_PSP_ID
                                     AND PSP_ID = PM_PSP_ID
                                     AND PSP_TYPE = PM_BUSINESS_TYPE
                                     AND CR_PRODUCT_CODE = PM_PRODUCT_CODE
                                     AND PM_DISABLED = 0)
                      AND (CR_PARTY_ID = TP_PSP_ID OR CR_PARTY_TYPE = 'G')
                      AND (CR_CURRENCY_ID = TE_CCY OR CR_CURRENCY_ID = 'ALL')
             GROUP BY TH_APPROVAL_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CR_PARTY_ID,
                      TE_CCY,
                      CR_CREDIT_GL_ID,
                      CR_DEBIT_GL_ID)
      LOOP
         PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                     RESULT.CR_COUNTRY_ID,
                                     RESULT.CR_PRODUCT_CODE,
                                     RESULT.CR_JNL_TYPE_ID,
                                     RESULT.CR_JNL_ENTRY_TYPE_ID,
                                     RESULT.CR_PARTY_TYPE,
                                     RESULT.CR_PARTY_ID,
                                     RESULT.CR_CURRENCY_ID,
                                     RESULT.GL_ID,
                                     RESULT.CR_IND,
                                     RESULT.TXN_AMT,
                                     RESULT.TXN_COUNT,
                                     RESULT.TXN_ID));
      END LOOP;

      RETURN;
   END GET_PSP_TXN_ELEMENTS_SINGLE;

   FUNCTION GET_OFL_PSP_SINGLE (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OPPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    COTH_CCY CR_CURRENCY_ID,
                    SUM(NVL (COTH_TXN_AMT, 0)) TXN_AMT,
                    COTP_PSP_CCY PSP_CCY,
                    SUM(NVL (COTP_PSP_AMT, 0)) PSP_AMT,
                    COUNT(COTH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            A.com_baid_category,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = b.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            cotp_client_id,
                            cotp_psp_id,
                            cotp_baid,
                            cotp_baid_category,
                            coth_ccy,
                            coth_txn_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotp_psp_ccy,
                            cotp_psp_amt,
                            oppm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_psp_detail,
                            (SELECT oppm_psp_id,
                                    oppm_product_code,
                                    MAX (oppm_effective_date)
                             FROM   crr_ofl_psp_product_code_map
                             GROUP BY oppm_psp_id,
                                      oppm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotp_txn_id
                       AND  cotp_psp_id = oppm_psp_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_party_id = cotp_psp_id
               AND  L.cr_product_code = R.oppm_product_code
               AND  DECODE(L.CR_PARTY_TYPE,  'X', L.com_baid_category,
					     'I', L.com_baid_category,
					     'T', L.com_baid_category,
                                             'P', DECODE(L.com_baid_category, 'ALL', NVL(R.cotp_baid_category,'~'),
                                                                                     L.com_baid_category),
                                             NVL(R.cotp_baid_category,'~')) = NVL(R.cotp_baid_category,'~')
	     GROUP BY
		    COTH_APPROVAL_DATE,
		    CR_COUNTRY_ID,
		    OPPM_PRODUCT_CODE,
		    CR_JNL_TYPE_ID,
		    CR_JNL_ENTRY_TYPE_ID,
		    CR_PARTY_TYPE,
		    CR_PARTY_ID,
		    COTH_CCY,
		    COTP_PSP_CCY,
		    CR_CREDIT_GL_ID,
		    CR_DEBIT_GL_ID
         )
         LOOP
           IF (in_amt_type = 'TXN_AMT')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.TXN_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'PSP_AMT')
           THEN
              PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.PSP_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
          END IF;
         END LOOP;
      RETURN;
   END GET_OFL_PSP_SINGLE;

   FUNCTION GET_OFL_PSP_MULTI (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OPPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    COTH_CCY CR_CURRENCY_ID,
                    NVL (COTH_TXN_AMT, 0) TXN_AMT,
                    COTH_FEE_CCY FEE_CCY,
                    NVL (COTH_FEE, 0) FEE_AMT,
                    COTH_NET_CCY NET_CCY,
                    COTH_NET_AMT NET_AMT,
                    COTH_MARKUP_CCY,
                    NVL (COTH_MARKUP_AMT, 0) MARKUP_AMT,
                    COTP_PSP_CCY PSP_CCY,
                    NVL (COTP_PSP_AMT, 0) PSP_AMT,
                    1 TXN_COUNT,
                    COTH_TXN_ID TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            A.com_baid_category,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = b.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            cotp_client_id,
                            cotp_psp_id,
                            cotp_baid,
                            cotp_baid_category,
                            coth_ccy,
                            coth_txn_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotp_psp_ccy,
                            cotp_psp_amt,
                            oppm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_psp_detail,
                            (SELECT oppm_psp_id,
                                    oppm_product_code,
                                    MAX (oppm_effective_date)
                             FROM   crr_ofl_psp_product_code_map
                             GROUP BY oppm_psp_id,
                                      oppm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotp_txn_id
                       AND  cotp_psp_id = oppm_psp_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_party_id = cotp_psp_id
               AND  L.cr_product_code = R.oppm_product_code
               AND  DECODE(L.CR_PARTY_TYPE,  'X', L.com_baid_category,
					     'I', L.com_baid_category,
					     'T', L.com_baid_category,
                                             'P', DECODE(L.com_baid_category, 'ALL', NVL(R.cotp_baid_category,'~'),
                                                                                     L.com_baid_category),
                                             NVL(R.cotp_baid_category,'~')) = NVL(R.cotp_baid_category,'~')
         )
         LOOP
           IF (in_amt_type = 'TXN_AMT')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.TXN_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'PSP_AMT')
           THEN
              PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.PSP_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
          END IF;
         END LOOP;
      RETURN;
   END GET_OFL_PSP_MULTI;

   FUNCTION GET_OFL_MERCH_SINGLE (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                           END CR_IND,
                    COTH_CCY CR_CURRENCY_ID,
                    SUM(NVL (COTh_TXN_AMT, 0)) TXN_AMT,
                    COTH_FEE_CCY FEE_CCY,
                    SUM(NVL (COTH_FEE, 0)) FEE_AMT,
                    COUNT(COTH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.CR_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = B.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = B.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            coth_ccy,
                            coth_txn_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotd_merchant_id,
                            ompm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_detail,
                            (SELECT ompm_merch_id,
                                    ompm_product_code,
                                    MAX (ompm_effective_date)
                             FROM   crr_ofl_merch_product_code_map
                             GROUP BY ompm_merch_id,
                                      ompm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotd_txn_id
                       AND  cotd_merchant_id = ompm_merch_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_product_code = R.ompm_product_code
               AND  L.cr_party_id = R.cotd_merchant_id
             GROUP BY
		COTH_APPROVAL_DATE,
                CR_COUNTRY_ID,
                OMPM_PRODUCT_CODE,
                CR_JNL_TYPE_ID,
                CR_JNL_ENTRY_TYPE_ID,
                CR_PARTY_TYPE,
                CR_PARTY_ID,
                COTH_CCY,
                COTH_FEE_CCY,
                CR_CREDIT_GL_ID,
		CR_DEBIT_GL_ID
         )
         LOOP
           IF (in_amt_type = 'TXN')
           THEN
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
           ELSIF (in_amt_type = 'FEE')
           THEN
             IF RESULT.FEE_AMT > 0 THEN
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.FEE_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END IF;
           END IF;
         END LOOP;
      RETURN;
   END GET_OFL_MERCH_SINGLE;

   FUNCTION GET_OFL_MERCH_MULTI (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                           END CR_IND,
                    COTH_CCY CR_CURRENCY_ID,
                    NVL (COTh_TXN_AMT, 0) TXN_AMT,
                    COTH_FEE_CCY FEE_CCY,
                    NVL (COTH_FEE, 0) FEE_AMT,
                    COTH_NET_CCY NET_CCY,
                    COTH_NET_AMT NET_AMT,
                    COTH_MARKUP_CCY,
                    NVL (COTH_MARKUP_AMT, 0) MARKUP_AMT,
                    1 TXN_COUNT,
                    COTH_TXN_ID TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.CR_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = B.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = B.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            coth_ccy,
                            coth_txn_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotd_merchant_id,
                            ompm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_detail,
                            (SELECT ompm_merch_id,
                                    ompm_product_code,
                                    MAX (ompm_effective_date)
                             FROM   crr_ofl_merch_product_code_map
                             GROUP BY ompm_merch_id,
                                      ompm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotd_txn_id
                       AND  cotd_merchant_id = ompm_merch_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_product_code = R.ompm_product_code
               AND  L.cr_party_id = R.cotd_merchant_id
             order by coth_txn_id
         )
         LOOP
           IF (in_amt_type = 'TXN')
           THEN
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.TXN_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
           ELSIF (in_amt_type = 'FEE')
           THEN
             IF RESULT.FEE_AMT > 0 THEN
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.CR_CURRENCY_ID,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.FEE_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END IF;
           ELSIF (in_amt_type = 'NET')
           THEN
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.NET_CCY,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.NET_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
           END IF;
         END LOOP;
      RETURN;
   END GET_OFL_MERCH_MULTI;

   FUNCTION GET_OFL_PSP_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OPPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    COTH_CCY CR_CURRENCY_ID,
                    SUM(NVL (COTH_TXN_AMT, 0)) TXN_AMT,
                    COUNT(COTH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            A.com_baid_category,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = b.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            cotp_client_id,
                            cotp_psp_id,
                            cotp_baid,
                            cotp_baid_category,
                            coth_ccy,
                            coth_txn_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotp_psp_ccy,
                            cotp_psp_amt,
                            oppm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_psp_detail,
                            (SELECT oppm_psp_id,
                                    oppm_product_code,
                                    MAX (oppm_effective_date)
                             FROM   crr_ofl_psp_product_code_map
                             GROUP BY oppm_psp_id,
                                      oppm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotp_txn_id
                       AND  cotp_psp_id = oppm_psp_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_product_code = R.oppm_product_code
             GROUP BY
                    COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OPPM_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    COTH_CCY,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
         )
         LOOP
           PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                       RESULT.CR_COUNTRY_ID,
                                       RESULT.CR_PRODUCT_CODE,
                                       RESULT.CR_JNL_TYPE_ID,
                                       RESULT.CR_JNL_ENTRY_TYPE_ID,
                                       RESULT.CR_PARTY_TYPE,
                                       RESULT.CR_PARTY_ID,
                                       RESULT.CR_CURRENCY_ID,
                                       RESULT.GL_ID,
                                       RESULT.CR_IND,
                                       RESULT.TXN_AMT,
                                       RESULT.TXN_COUNT,
                                       RESULT.TXN_ID));
         END LOOP;
      RETURN;
   END GET_OFL_PSP_GLOBAL;

   FUNCTION GET_OFL_PSP_BAID_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OPPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    COTH_CCY CR_CURRENCY_ID,
                    SUM(NVL (COTH_TXN_AMT, 0)) TXN_AMT,
                    COUNT(COTH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            A.com_baid_category,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = b.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            cotp_client_id,
                            cotp_psp_id,
                            cotp_baid,
                            cotp_baid_category,
                            coth_ccy,
                            coth_txn_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotp_psp_ccy,
                            cotp_psp_amt,
                            oppm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_psp_detail,
                            (SELECT oppm_psp_id,
                                    oppm_product_code,
                                    MAX (oppm_effective_date)
                             FROM   crr_ofl_psp_product_code_map
                             GROUP BY oppm_psp_id,
                                      oppm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotp_txn_id
                       AND  cotp_psp_id = oppm_psp_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_product_code = R.oppm_product_code
               AND  L.com_baid_category = R.cotp_baid_category
             GROUP BY
                    COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OPPM_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    COTH_CCY,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
         )
         LOOP
           PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                       RESULT.CR_COUNTRY_ID,
                                       RESULT.CR_PRODUCT_CODE,
                                       RESULT.CR_JNL_TYPE_ID,
                                       RESULT.CR_JNL_ENTRY_TYPE_ID,
                                       RESULT.CR_PARTY_TYPE,
                                       RESULT.CR_PARTY_ID,
                                       RESULT.CR_CURRENCY_ID,
                                       RESULT.GL_ID,
                                       RESULT.CR_IND,
                                       RESULT.TXN_AMT,
                                       RESULT.TXN_COUNT,
                                       RESULT.TXN_ID));
         END LOOP;
      RETURN;
   END GET_OFL_PSP_BAID_GLOBAL;

   FUNCTION GET_OFL_MERCH_TXN_AMT_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                           END CR_IND,
                    COTH_CCY CR_CURRENCY_ID,
                    SUM(NVL (COTH_TXN_AMT, 0)) TXN_AMT,
                    COUNT(COTH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.CR_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = B.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = B.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            coth_ccy,
                            coth_txn_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotd_merchant_id,
                            ompm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_detail,
                            (SELECT ompm_merch_id,
                                    ompm_product_code,
                                    MAX (ompm_effective_date)
                             FROM   crr_ofl_merch_product_code_map
                             GROUP BY ompm_merch_id,
                                      ompm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotd_txn_id
                       AND  cotd_merchant_id = ompm_merch_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_product_code = R.ompm_product_code
             GROUP BY
                    COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    COTH_CCY,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
         )
         LOOP
           PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                       RESULT.CR_COUNTRY_ID,
                                       RESULT.CR_PRODUCT_CODE,
                                       RESULT.CR_JNL_TYPE_ID,
                                       RESULT.CR_JNL_ENTRY_TYPE_ID,
                                       RESULT.CR_PARTY_TYPE,
                                       RESULT.CR_PARTY_ID,
                                       RESULT.CR_CURRENCY_ID,
                                       RESULT.GL_ID,
                                       RESULT.CR_IND,
                                       RESULT.TXN_AMT,
                                       RESULT.TXN_COUNT,
                                       RESULT.TXN_ID));
         END LOOP;
      RETURN;
   END GET_OFL_MERCH_TXN_AMT_GLOBAL;

   FUNCTION GET_OFL_MERCH_FEE_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                           END CR_IND,
                    COTH_FEE_CCY FEE_CCY,
                    SUM(NVL (COTH_FEE, 0)) FEE_AMT,
                    COUNT(COTH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.CR_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = B.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = B.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            coth_ccy,
                            coth_txn_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotd_merchant_id,
                            ompm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_detail,
                            (SELECT ompm_merch_id,
                                    ompm_product_code,
                                    MAX (ompm_effective_date)
                             FROM   crr_ofl_merch_product_code_map
                             GROUP BY ompm_merch_id,
                                      ompm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotd_txn_id
                       AND  cotd_merchant_id = ompm_merch_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_product_code = R.ompm_product_code
             GROUP BY
                    COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    COTH_FEE_CCY,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
         )
         LOOP
           IF RESULT.FEE_AMT > 0
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.FEE_CCY,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.FEE_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           END IF;
         END LOOP;
      RETURN;
   END GET_OFL_MERCH_FEE_GLOBAL;

   FUNCTION GET_OFL_MERCH_MARKUP_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                           END CR_IND,
                    COTH_MARKUP_CCY MARKUP_CCY,
                    SUM(NVL (COTH_MARKUP_AMT, 0)) MARKUP_AMT,
                    COUNT(COTH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.CR_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = B.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = B.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            coth_ccy,
                            coth_txn_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotd_merchant_id,
                            ompm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_detail,
                            (SELECT ompm_merch_id,
                                    ompm_product_code,
                                    MAX (ompm_effective_date)
                             FROM   crr_ofl_merch_product_code_map
                             GROUP BY ompm_merch_id,
                                      ompm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotd_txn_id
                       AND  cotd_merchant_id = ompm_merch_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_product_code = R.ompm_product_code
             GROUP BY
                    COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    COTH_MARKUP_CCY,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
         )
         LOOP
           IF RESULT.MARKUP_AMT > 0 THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.MARKUP_CCY,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.MARKUP_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           END IF;
         END LOOP;
      RETURN;
   END GET_OFL_MERCH_MARKUP_GLOBAL;

   FUNCTION GET_OFL_PSP_MARKUP_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    COTH_MARKUP_CCY CR_CURRENCY_ID,
                    SUM(NVL (COTH_MARKUP_AMT, 0)) MARKUP_AMT,
                    COUNT(COTH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            A.com_baid_category,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = b.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            coth_deli_ccy,
                            coth_deli_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotd_merchant_id,
                            ompm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_detail,
                            (SELECT ompm_merch_id,
                                    ompm_product_code,
                                    MAX (ompm_effective_date)
                             FROM   crr_ofl_merch_product_code_map
                             GROUP BY ompm_merch_id,
                                      ompm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotd_txn_id
                       AND  cotd_merchant_id = ompm_merch_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_product_code = R.ompm_product_code
             GROUP BY
                    COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    COTH_MARKUP_CCY,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
         )
         LOOP
           IF RESULT.MARKUP_AMT > 0
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.MARKUP_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           END IF;
         END LOOP;
      RETURN;
   END GET_OFL_PSP_MARKUP_GLOBAL;

   FUNCTION GET_OFL_PSP_DELI_GLOBAL (
      in_jnl_type_id      crr_ofl_jnl_entry_type_mapping.com_jnl_type_id%TYPE,
      in_entry_type_id    crr_ofl_jnl_entry_type_mapping.com_entry_type_id%TYPE,
      in_group_id         crr_ofl_jnl_entry_type_mapping.com_group_id%TYPE,
      in_fr_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE,
      in_to_txn_date      crr_ofl_txn_data_header.coth_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    COTH_DELI_CCY CR_CURRENCY_ID,
                    SUM(NVL (COTH_DELI_AMT, 0)) DELI_AMT,
                    COUNT(COTH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.com_group_id,
                            A.com_txn_side,
                            A.com_is_single,
                            A.com_txn_code,
                            A.com_baid_category,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_ofl_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.com_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.com_jnl_type_id = b.cr_jnl_type_id
                       AND  A.com_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.com_group_id = in_group_id
                       and  A.com_jnl_type_id = in_jnl_type_id
                       and  A.com_entry_type_id = in_entry_type_id) L,
                    (SELECT coth_txn_id,
                            coth_txn_code,
                            coth_deli_ccy,
                            coth_deli_amt,
                            coth_fee,
                            nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                            coth_net_amt,
                            coth_net_ccy,
                            coth_markup_amt,
                            coth_markup_ccy,
                            coth_approval_date,
                            cotd_merchant_id,
                            ompm_product_code
                     FROM   crr_ofl_txn_data_header,
                            crr_ofl_txn_data_detail,
                            (SELECT ompm_merch_id,
                                    ompm_product_code,
                                    MAX (ompm_effective_date)
                             FROM   crr_ofl_merch_product_code_map
                             GROUP BY ompm_merch_id,
                                      ompm_product_code) C
                     WHERE  coth_approval_date = in_fr_txn_date
                       AND  coth_txn_id||'' = cotd_txn_id
                       AND  cotd_merchant_id = ompm_merch_id) R
             WHERE  L.com_txn_code = coth_txn_code
               AND  L.cr_product_code = R.ompm_product_code
             GROUP BY
                    COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OMPM_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    COTH_DELI_CCY,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
         )
         LOOP
           PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                       RESULT.CR_COUNTRY_ID,
                                       RESULT.CR_PRODUCT_CODE,
                                       RESULT.CR_JNL_TYPE_ID,
                                       RESULT.CR_JNL_ENTRY_TYPE_ID,
                                       RESULT.CR_PARTY_TYPE,
                                       RESULT.CR_PARTY_ID,
                                       RESULT.CR_CURRENCY_ID,
                                       RESULT.GL_ID,
                                       RESULT.CR_IND,
                                       RESULT.DELI_AMT,
                                       RESULT.TXN_COUNT,
                                       RESULT.TXN_ID));
         END LOOP;
      RETURN;
   END GET_OFL_PSP_DELI_GLOBAL;


   FUNCTION GET_MI_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT TH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    TM_TXN_PRODUCT CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    TM_TXN_CCY CR_CURRENCY_ID,
                    NVL (TE_AMOUNT, 0) TXN_AMT,
                    TH_FEE_CCY COST_CCY,
                    NVL (TM_ACTUAL_COST, 0) FEE_AMT,
                    TH_NET_CCY NET_CCY,
                    TH_NET_AMOUNT NET_AMT,
                    1 TXN_COUNT,
                    TH_TXN_ID TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.cmm_group_id,
                            A.cmm_txn_side,
                            A.cmm_is_single,
                            A.cmm_txn_code,
                            A.cmm_amt_field,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_mi_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.cmm_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.cmm_jnl_type_id = b.cr_jnl_type_id
                       AND  A.cmm_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.cmm_group_id = in_group_id
                       and  A.cmm_jnl_type_id = in_jnl_type_id
                       and  A.cmm_entry_type_id = in_entry_type_id) L,
                    (SELECT th_txn_id,
                            th_txn_code,
                            tm_entity_id,
                            tm_party_type,
                            tm_party_id,
                            tm_txn_ccy,
                            th_transaction_amount,
                            tm_actual_cost,
                            tm_txn_ccy th_fee_ccy,
                            th_net_amount,
                            th_net_ccy,
                            th_approval_date,
			    tm_txn_product,
                            te_txn_element_type,
                            te_amount
                     FROM   txn_header,
                            txn_mi_detail,
                            txn_elements
                     WHERE  th_approval_date = in_fr_txn_date
                       AND  th_txn_id||'' = te_txn_id
                       AND  th_txn_id||'' = tm_txn_id) R
             WHERE  L.cmm_txn_code = th_txn_code
               AND  L.cr_party_id = tm_party_id
               AND  L.cr_product_code = tm_txn_product
               AND  te_txn_element_type = DECODE(CMM_AMT_FIELD,'TXN_AMT','TAMT',
                                                               'TXN_INTR','INTR',
                                                               'TXN_INCT','INCT',
                                                               'OVPA_AMT','OVPA',
                                                               'UDPA_AMT','UDPA',
                                                               'FEE','TFEE',
                                                               'IBBT_FEE','TFEE',
                                                               'TAMT')
         )
         LOOP
           IF (in_amt_type = 'TXN_AMT')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.TXN_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'NET_AMT')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.NET_CCY,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.NET_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'FEE')
           THEN
             IF RESULT.FEE_AMT > 0 THEN
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.COST_CCY,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.FEE_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END IF;
           ELSIF (in_amt_type = 'IBBT_AMT')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.NET_CCY,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.TXN_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'IBBT_FEE')
           THEN
             IF RESULT.FEE_AMT > 0 THEN
               PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                           RESULT.CR_COUNTRY_ID,
                                           RESULT.CR_PRODUCT_CODE,
                                           RESULT.CR_JNL_TYPE_ID,
                                           RESULT.CR_JNL_ENTRY_TYPE_ID,
                                           RESULT.CR_PARTY_TYPE,
                                           RESULT.CR_PARTY_ID,
                                           RESULT.NET_CCY,
                                           RESULT.GL_ID,
                                           RESULT.CR_IND,
                                           RESULT.FEE_AMT,
                                           RESULT.TXN_COUNT,
                                           RESULT.TXN_ID));
             END IF;
           END IF;
         END LOOP;
      RETURN;
   END GET_MI_MULTI;


   FUNCTION GET_MI_MULTI_CCY (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT TH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    TM_TXN_PRODUCT CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    TM_TXN_CCY CR_CURRENCY_ID,
                    NVL (TH_TRANSACTION_AMOUNT, 0) TXN_AMT,
                    TH_FEE_CCY COST_CCY,
                    NVL (TM_ACTUAL_COST, 0) FEE_AMT,
                    TH_NET_CCY NET_CCY,
                    TH_NET_AMOUNT NET_AMT,
                    1 TXN_COUNT,
                    TH_TXN_ID TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.cmm_group_id,
                            A.cmm_txn_side,
                            A.cmm_is_single,
                            A.cmm_txn_code,
                            A.cmm_amt_field,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_mi_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.cmm_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.cmm_jnl_type_id = b.cr_jnl_type_id
                       AND  A.cmm_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.cmm_group_id = in_group_id
                       and  A.cmm_jnl_type_id = in_jnl_type_id
                       and  A.cmm_entry_type_id = in_entry_type_id) L,
                    (SELECT th_txn_id,
                            th_txn_code,
                            tm_entity_id,
                            tm_party_type,
                            tm_party_id,
                            tm_txn_ccy,
                            th_transaction_amount,
                            tm_actual_cost,
                            tm_txn_ccy th_fee_ccy,
                            th_net_amount,
                            th_net_ccy,
                            th_approval_date,
			    tm_txn_product,
                            te_txn_element_type,
                            te_amount
                     FROM   txn_header,
                            txn_mi_detail,
                            txn_elements
                     WHERE  th_approval_date = in_fr_txn_date
                       AND  th_txn_id||'' = te_txn_id
                       AND  th_txn_id||'' = tm_txn_id) R
             WHERE  L.cmm_txn_code = th_txn_code
               AND  (L.cr_party_id = tm_party_id OR L.cr_party_type = 'G')
               AND  L.cr_product_code = tm_txn_product
               AND  te_txn_element_type = DECODE(CMM_AMT_FIELD,'TXN_AMT','TAMT',
                                                               'TXN_INTR','INTR',
                                                               'TXN_INCT','INCT',
                                                               'OVPA_AMT','OVPA',
                                                               'UDPA_AMT','UDPA',
                                                               'FEE','TFEE',
                                                               'IBBT_FEE','TFEE',
                                                               'TAMT')
         )
         LOOP
           IF (in_amt_type = 'TXN_AMT')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.TXN_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'NET_AMT')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.NET_CCY,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.NET_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           END IF;
         END LOOP;
      RETURN;
   END GET_MI_MULTI_CCY;


   FUNCTION GET_MI_GLOBAL (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT TH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    TM_TXN_PRODUCT CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    TM_TXN_CCY CR_CURRENCY_ID,
                    SUM(NVL (TE_AMOUNT, 0)) TXN_AMT,
                    TH_FEE_CCY COST_CCY,
                    SUM(NVL (TM_ACTUAL_COST, 0)) FEE_AMT,
                    TH_NET_CCY NET_CCY,
                    SUM(TH_NET_AMOUNT) NET_AMT,
                    COUNT(TH_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.cmm_group_id,
                            A.cmm_txn_side,
                            A.cmm_is_single,
                            A.cmm_txn_code,
                            A.cmm_amt_field,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_mi_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.cmm_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.cmm_jnl_type_id = b.cr_jnl_type_id
                       AND  A.cmm_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.cmm_group_id = in_group_id
                       and  A.cmm_jnl_type_id = in_jnl_type_id
                       and  A.cmm_entry_type_id = in_entry_type_id) L,
                    (SELECT th_txn_id,
                            th_txn_code,
                            tm_entity_id,
                            tm_party_type,
                            tm_party_id,
                            tm_txn_ccy,
                            th_transaction_amount,
                            tm_actual_cost,
                            tm_txn_ccy th_fee_ccy,
                            th_net_amount,
                            th_net_ccy,
                            th_approval_date,
			    tm_txn_product,
                            te_txn_element_type,
                            te_amount
                     FROM   txn_header,
                            txn_mi_detail,
                            txn_elements
                     WHERE  th_approval_date = in_fr_txn_date
                       AND  th_txn_id||'' = te_txn_id
                       AND  th_txn_id||'' = tm_txn_id) R
             WHERE  L.cmm_txn_code = th_txn_code
               AND  L.cr_product_code = tm_txn_product
               AND  te_txn_element_type = DECODE(CMM_AMT_FIELD,'G_TXN_AMT','TAMT',
                                                               'G_TXN_INTR','INTR',
                                                               'G_TXN_INCT','INCT',
                                                               'G_FEE','TFEE',
                                                               'G_OVPA','OVPA',
                                                               'G_UDPA','UDPA',
                                                               'TAMT')
             GROUP BY
                     TH_APPROVAL_DATE,
                     CR_COUNTRY_ID,
                     TM_TXN_PRODUCT,
                     CR_JNL_TYPE_ID,
                     CR_JNL_ENTRY_TYPE_ID,
                     CR_PARTY_TYPE,
                     CR_PARTY_ID,
                     TM_TXN_CCY,
                     TH_NET_CCY,
                     CR_CREDIT_GL_ID,
                     CR_DEBIT_GL_ID
         )
         LOOP
           PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                       RESULT.CR_COUNTRY_ID,
                                       RESULT.CR_PRODUCT_CODE,
                                       RESULT.CR_JNL_TYPE_ID,
                                       RESULT.CR_JNL_ENTRY_TYPE_ID,
                                       RESULT.CR_PARTY_TYPE,
                                       RESULT.CR_PARTY_ID,
                                       RESULT.CR_CURRENCY_ID,
                                       RESULT.GL_ID,
                                       RESULT.CR_IND,
                                       RESULT.TXN_AMT,
                                       RESULT.TXN_COUNT,
                                       RESULT.TXN_ID));
         END LOOP;
      RETURN;
   END GET_MI_GLOBAL;


   FUNCTION GET_MI_GLOBAL_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT TH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    TM_TXN_PRODUCT CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    TM_TXN_CCY CR_CURRENCY_ID,
                    NVL(TE_AMOUNT, 0) TXN_AMT,
                    TH_FEE_CCY COST_CCY,
                    NVL(TM_ACTUAL_COST, 0) FEE_AMT,
                    TH_NET_CCY NET_CCY,
                    TH_NET_AMOUNT NET_AMT,
                    1 TXN_COUNT,
                    TH_TXN_ID TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.cmm_group_id,
                            A.cmm_txn_side,
                            A.cmm_is_single,
                            A.cmm_txn_code,
                            A.cmm_amt_field,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_mi_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.cmm_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.cmm_jnl_type_id = b.cr_jnl_type_id
                       AND  A.cmm_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.cmm_group_id = in_group_id
                       and  A.cmm_jnl_type_id = in_jnl_type_id
                       and  A.cmm_entry_type_id = in_entry_type_id) L,
                    (SELECT th_txn_id,
                            th_txn_code,
                            tm_entity_id,
                            tm_party_type,
                            tm_party_id,
                            tm_txn_ccy,
                            th_transaction_amount,
                            tm_actual_cost,
                            tm_txn_ccy th_fee_ccy,
                            th_net_amount,
                            th_net_ccy,
                            th_approval_date,
			    tm_txn_product,
                            te_txn_element_type,
                            te_amount
                     FROM   txn_header,
                            txn_mi_detail,
                            txn_elements
                     WHERE  th_approval_date = in_fr_txn_date
                       AND  th_txn_id||'' = te_txn_id
                       AND  th_txn_id||'' = tm_txn_id) R
             WHERE  L.cmm_txn_code = th_txn_code
               AND  L.cr_product_code = tm_txn_product
               AND  te_txn_element_type = DECODE(CMM_AMT_FIELD,'G_TXN_AMT_M','TAMT',
                                                               'G_NET_AMT_M','TAMT',
                                                               'G_TXN_INTR_M','INTR',
                                                               'G_TXN_INCT_M','INCT',
                                                               'G_FEE_M','TFEE',
                                                               'G_IBBT_FEE','TFEE',
                                                               'TAMT')
         )
         LOOP
           IF (in_amt_type = 'FEE')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.TXN_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'NET_AMT')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.NET_CCY,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.NET_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'G_IBBT_FEE')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.TH_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.NET_CCY,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.TXN_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           END IF;
         END LOOP;
      RETURN;
   END GET_MI_GLOBAL_MULTI;


   FUNCTION GET_MI_PSP_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (  SELECT TH_APPROVAL_DATE TXN_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CASE
                         WHEN CR_PARTY_TYPE <> 'G' THEN CR_PARTY_ID
                         ELSE ''
                      END
                         CR_PARTY_ID,
                      TE_CCY CR_CURRENCY_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN CR_DEBIT_GL_ID
                         ELSE 0
                      END
                         GL_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
                         ELSE ''
                      END
                         CR_IND,
                      TE_AMOUNT TXN_AMT,
                      1 TXN_COUNT,
                      TH_TXN_ID TXN_ID
                 FROM (SELECT TH_TXN_ID,
                              TH_TXN_CODE,
                              TH_APPROVAL_DATE,
                              TH_TRANSACTION_AMOUNT,
                              TH_NET_CCY,
                              TH_NET_AMOUNT,
                              TH_MERCHANT_ID,
                              TH_SERVICE_CODE
                         FROM TXN_HEADER
                        WHERE     TH_APPROVAL_DATE >= in_fr_txn_date
                              AND TH_APPROVAL_DATE <= in_to_txn_date
                              AND TH_STATUS IN ('C', 'R')
                              AND TH_AR_IND = 'A'),
                      (SELECT TD_TXN_ID, TD_TXN_COUNTRY, TD_TXN_CCY
                         FROM TXN_DETAIL),
                      (SELECT TP_TXN_ID, TP_PSP_ID FROM TXN_PSP_DETAIL),
                      (SELECT TE_TXN_ID,
                              TE_PARTY_TYPE,
                              TE_TXN_ELEMENT_TYPE,
                              TE_CCY,
                              TE_AMOUNT
                         FROM TXN_ELEMENTS),
                      (SELECT CR_COUNTRY_ID,
                              CR_PARTY_TYPE,
                              CR_PARTY_ID,
                              CR_JNL_TYPE_ID,
                              CR_JNL_ENTRY_TYPE_ID,
                              CR_TXN_CODE,
                              CR_PRODUCT_CODE,
                              CR_CURRENCY_ID,
                              CR_CREDIT_GL_ID,
                              CR_DEBIT_GL_ID
                         FROM CRR_RULE_POSTING
                        WHERE     CR_JNL_TYPE_ID = in_jnl_type_id
                              AND CR_JNL_ENTRY_TYPE_ID = in_entry_type_id
                              AND CR_DISABLED = 0),
                      (SELECT CMM_TXN_CODE,
                              CMM_PARTY_TYPE,
                              CMM_AMT_FIELD,
                              CMM_SIGN
                         FROM CRR_MI_JNL_ENTRY_TYPE_MAPPING
                        WHERE CMM_JNL_TYPE_ID = in_jnl_type_id
                              AND CMM_ENTRY_TYPE_ID = in_entry_type_id
                              AND CMM_GROUP_ID = in_group_id
                              AND CMM_DISABLED = 0)
                WHERE     TH_TXN_ID = TD_TXN_ID
                      AND TH_TXN_ID = TP_TXN_ID
                      AND TH_TXN_ID = TE_TXN_ID
                      AND TH_TXN_CODE = CMM_TXN_CODE
                      AND TE_PARTY_TYPE = CMM_PARTY_TYPE
                      AND TE_TXN_ELEMENT_TYPE = DECODE(CMM_AMT_FIELD,'TXN_P_AMT','TAMT',
                                                                     'P_FEE','TFEE',
                                                                     'TAMT')
                      AND (CR_COUNTRY_ID = TD_TXN_COUNTRY)
                      AND EXISTS
                             (SELECT *
                                FROM PSP_DETAIL, CRR_PSP_PRODUCT_CODE_MAP
                               WHERE     PSP_ID = TP_PSP_ID
                                     AND PSP_ID = PM_PSP_ID
                                     AND PSP_TYPE = PM_BUSINESS_TYPE
                                     AND CR_PRODUCT_CODE = PM_PRODUCT_CODE
                                     AND PM_DISABLED = 0)
                      AND (CR_PARTY_ID = TP_PSP_ID OR CR_PARTY_TYPE = 'G')
                      AND (CR_CURRENCY_ID = TE_CCY OR CR_CURRENCY_ID = 'ALL'))
      LOOP
         PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                     RESULT.CR_COUNTRY_ID,
                                     RESULT.CR_PRODUCT_CODE,
                                     RESULT.CR_JNL_TYPE_ID,
                                     RESULT.CR_JNL_ENTRY_TYPE_ID,
                                     RESULT.CR_PARTY_TYPE,
                                     RESULT.CR_PARTY_ID,
                                     RESULT.CR_CURRENCY_ID,
                                     RESULT.GL_ID,
                                     RESULT.CR_IND,
                                     RESULT.TXN_AMT,
                                     RESULT.TXN_COUNT,
                                     RESULT.TXN_ID));
      END LOOP;

      RETURN;
   END GET_MI_PSP_MULTI;


   FUNCTION GET_MI_PSP_GLOBAL (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      txn_header.th_approval_date%TYPE,
      in_to_txn_date      txn_header.th_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (  SELECT TH_APPROVAL_DATE TXN_DATE,
                      CR_COUNTRY_ID,
                      CR_PRODUCT_CODE,
                      CR_JNL_TYPE_ID,
                      CR_JNL_ENTRY_TYPE_ID,
                      CR_PARTY_TYPE,
                      CASE
                         WHEN CR_PARTY_TYPE <> 'G' THEN CR_PARTY_ID
                         ELSE ''
                      END
                         CR_PARTY_ID,
                      TE_CCY CR_CURRENCY_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN CR_DEBIT_GL_ID
                         ELSE 0
                      END
                         GL_ID,
                      CASE
                         WHEN CR_CREDIT_GL_ID <> 0 THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
                         ELSE ''
                      END
                         CR_IND,
                      SUM (TE_AMOUNT) TXN_AMT,
                      COUNT(TH_TXN_ID) TXN_COUNT,
                      '' TXN_ID
                 FROM (SELECT TH_TXN_ID,
                              TH_TXN_CODE,
                              TH_APPROVAL_DATE,
                              TH_TRANSACTION_AMOUNT,
                              TH_NET_CCY,
                              TH_NET_AMOUNT,
                              TH_MERCHANT_ID,
                              TH_SERVICE_CODE
                         FROM TXN_HEADER
                        WHERE     TH_APPROVAL_DATE >= in_fr_txn_date
                              AND TH_APPROVAL_DATE <= in_to_txn_date
                              AND TH_STATUS IN ('C', 'R')
                              AND TH_AR_IND = 'A'),
                      (SELECT TD_TXN_ID, TD_TXN_COUNTRY, TD_TXN_CCY
                         FROM TXN_DETAIL),
                      (SELECT TP_TXN_ID, TP_PSP_ID FROM TXN_PSP_DETAIL),
                      (SELECT TE_TXN_ID,
                              TE_PARTY_TYPE,
                              TE_TXN_ELEMENT_TYPE,
                              TE_CCY,
                              TE_AMOUNT
                         FROM TXN_ELEMENTS),
                      (SELECT CR_COUNTRY_ID,
                              CR_PARTY_TYPE,
                              CR_PARTY_ID,
                              CR_JNL_TYPE_ID,
                              CR_JNL_ENTRY_TYPE_ID,
                              CR_TXN_CODE,
                              CR_PRODUCT_CODE,
                              CR_CURRENCY_ID,
                              CR_CREDIT_GL_ID,
                              CR_DEBIT_GL_ID
                         FROM CRR_RULE_POSTING
                        WHERE     CR_JNL_TYPE_ID = in_jnl_type_id
                              AND CR_JNL_ENTRY_TYPE_ID = in_entry_type_id
                              AND CR_DISABLED = 0),
                      (SELECT CMM_TXN_CODE,
                              CMM_PARTY_TYPE,
                              CMM_AMT_FIELD,
                              CMM_SIGN
                         FROM CRR_MI_JNL_ENTRY_TYPE_MAPPING
                        WHERE CMM_JNL_TYPE_ID = in_jnl_type_id
                              AND CMM_ENTRY_TYPE_ID = in_entry_type_id
                              AND CMM_GROUP_ID = in_group_id
                              AND CMM_DISABLED = 0)
                WHERE     TH_TXN_ID = TD_TXN_ID
                      AND TH_TXN_ID = TP_TXN_ID
                      AND TH_TXN_ID = TE_TXN_ID
                      AND TH_TXN_CODE = CMM_TXN_CODE
                      AND TE_TXN_ELEMENT_TYPE = DECODE(CMM_AMT_FIELD,'G_TXN_P_AMT','TAMT',
                                                                     'G_P_FEE','TFEE',
                                                                     'TAMT')
                      AND (CR_COUNTRY_ID = TD_TXN_COUNTRY)
                      AND EXISTS
                             (SELECT *
                                FROM PSP_DETAIL, CRR_PSP_PRODUCT_CODE_MAP
                               WHERE     PSP_ID = TP_PSP_ID
                                     AND PSP_ID = PM_PSP_ID
                                     AND PSP_TYPE = PM_BUSINESS_TYPE
                                     AND CR_PRODUCT_CODE = PM_PRODUCT_CODE
                                     AND PM_DISABLED = 0)
                      AND (CR_PARTY_ID = TP_PSP_ID OR CR_PARTY_TYPE = 'G')
                      AND (CR_CURRENCY_ID = TE_CCY OR CR_CURRENCY_ID = 'ALL')
		GROUP BY
			  TH_APPROVAL_DATE,
			  CR_COUNTRY_ID,
			  CR_PRODUCT_CODE,
			  CR_JNL_TYPE_ID,
			  CR_JNL_ENTRY_TYPE_ID,
			  CR_PARTY_TYPE,
			  CR_PARTY_ID,
			  TE_CCY,
			  CR_CREDIT_GL_ID,
			  CR_DEBIT_GL_ID
		)
      LOOP
         PIPE ROW (CRR_JNL_DATA_REC (RESULT.TXN_DATE,
                                     RESULT.CR_COUNTRY_ID,
                                     RESULT.CR_PRODUCT_CODE,
                                     RESULT.CR_JNL_TYPE_ID,
                                     RESULT.CR_JNL_ENTRY_TYPE_ID,
                                     RESULT.CR_PARTY_TYPE,
                                     RESULT.CR_PARTY_ID,
                                     RESULT.CR_CURRENCY_ID,
                                     RESULT.GL_ID,
                                     RESULT.CR_IND,
                                     RESULT.TXN_AMT,
                                     RESULT.TXN_COUNT,
                                     RESULT.TXN_ID));
      END LOOP;

      RETURN;
   END GET_MI_PSP_GLOBAL;


   FUNCTION GET_MI_OFL_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_amt_type         varchar)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT CMTD_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    CMTD_TXN_PRODUCT CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    CMTD_CCY CR_CURRENCY_ID,
                    CMTD_TXN_AMT TXN_AMT,
                    CMTD_FEE_CCY FEE_CCY,
                    CMTD_FEE_AMT FEE_AMT,
                    CMTD_NET_CCY NET_CCY,
                    CMTD_NET_AMT NET_AMT,
                    CMTD_INTR_AMT INTR_AMT,
                    CMTD_OVPA_AMT OVPA_AMT,
                    CMTD_UDPA_AMT UDPA_AMT,
                    1 TXN_COUNT,
                    CMTD_TXN_ID TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.cmm_group_id,
                            A.cmm_txn_side,
                            A.cmm_is_single,
                            A.cmm_txn_code,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_mi_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.cmm_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.cmm_jnl_type_id = b.cr_jnl_type_id
                       AND  A.cmm_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.cmm_group_id = in_group_id
                       and  A.cmm_jnl_type_id = in_jnl_type_id
                       and  A.cmm_entry_type_id = in_entry_type_id) L,
                    (SELECT cmtd_txn_id,
                            cmtd_txn_code,
                            cmtd_entity_id,
                            cmtd_party_id,
                            cmtd_party_type,
                            cmtd_ccy,
                            cmtd_txn_amt,
                            cmtd_net_ccy,
                            cmtd_net_amt,
                            cmtd_intr_amt,
                            cmtd_ovpa_amt,
                            cmtd_udpa_amt,
                            cmtd_fee_ccy,
                            cmtd_fee_amt,
                            cmtd_approval_date,
                            cmtd_txn_product
                     FROM   crr_mi_txn_data
                     WHERE  cmtd_approval_date = in_fr_txn_date) R
             WHERE  L.cmm_txn_code = cmtd_txn_code
               AND  L.cr_party_id = cmtd_party_id
         )
         LOOP
           IF (in_amt_type = 'OL_TXN_AMT')
           THEN
             PIPE ROW (CRR_JNL_DATA_REC (RESULT.CMTD_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.TXN_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'OL_NET_AMT')
           THEN
              PIPE ROW (CRR_JNL_DATA_REC (RESULT.CMTD_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.NET_CCY,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.NET_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'OL_FEE')
           THEN
              IF RESULT.FEE_AMT > 0 THEN
                PIPE ROW (CRR_JNL_DATA_REC (RESULT.CMTD_APPROVAL_DATE,
                                            RESULT.CR_COUNTRY_ID,
                                            RESULT.CR_PRODUCT_CODE,
                                            RESULT.CR_JNL_TYPE_ID,
                                            RESULT.CR_JNL_ENTRY_TYPE_ID,
                                            RESULT.CR_PARTY_TYPE,
                                            RESULT.CR_PARTY_ID,
                                            RESULT.FEE_CCY,
                                            RESULT.GL_ID,
                                            RESULT.CR_IND,
                                            RESULT.FEE_AMT,
                                            RESULT.TXN_COUNT,
                                            RESULT.TXN_ID));
              END IF;
           ELSIF (in_amt_type = 'OL_INTR_AMT')
           THEN
              PIPE ROW (CRR_JNL_DATA_REC (RESULT.CMTD_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.INTR_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'OL_OVPA_AMT')
           THEN
              PIPE ROW (CRR_JNL_DATA_REC (RESULT.CMTD_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.OVPA_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
           ELSIF (in_amt_type = 'OL_UDPA_AMT')
           THEN
              PIPE ROW (CRR_JNL_DATA_REC (RESULT.CMTD_APPROVAL_DATE,
                                         RESULT.CR_COUNTRY_ID,
                                         RESULT.CR_PRODUCT_CODE,
                                         RESULT.CR_JNL_TYPE_ID,
                                         RESULT.CR_JNL_ENTRY_TYPE_ID,
                                         RESULT.CR_PARTY_TYPE,
                                         RESULT.CR_PARTY_ID,
                                         RESULT.CR_CURRENCY_ID,
                                         RESULT.GL_ID,
                                         RESULT.CR_IND,
                                         RESULT.UDPA_AMT,
                                         RESULT.TXN_COUNT,
                                         RESULT.TXN_ID));
          END IF;
         END LOOP;
      RETURN;
   END GET_MI_OFL_MULTI;


   FUNCTION GET_MI_OFL_GLOBAL (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT CMTD_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    CMTD_TXN_PRODUCT CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN   CR_PARTY_TYPE <> 'G'
                           THEN CR_PARTY_ID
                           ELSE ''
                         END CR_PARTY_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN CR_CREDIT_GL_ID
                         WHEN   CR_DEBIT_GL_ID IS NOT NULL
                           THEN CR_DEBIT_GL_ID
                           ELSE 0
                         END GL_ID,
                    CASE WHEN   CR_CREDIT_GL_ID <> 0
                           THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                           THEN 'D'
                           ELSE ''
                         END CR_IND,
                    CMTD_CCY CR_CURRENCY_ID,
                    SUM(CMTD_TXN_AMT) TXN_AMT,
                    COUNT(CMTD_TXN_ID) TXN_COUNT,
                    '' TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.cmm_group_id,
                            A.cmm_txn_side,
                            A.cmm_is_single,
                            A.cmm_txn_code,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_mi_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.cmm_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.cmm_jnl_type_id = b.cr_jnl_type_id
                       AND  A.cmm_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.cmm_group_id = in_group_id
                       and  A.cmm_jnl_type_id = in_jnl_type_id
                       and  A.cmm_entry_type_id = in_entry_type_id) L,
                    (SELECT cmtd_txn_id,
                            cmtd_txn_code,
                            cmtd_entity_id,
                            cmtd_party_id,
                            cmtd_party_type,
                            cmtd_ccy,
                            cmtd_txn_amt,
                            cmtd_net_ccy,
                            cmtd_net_amt,
                            cmtd_intr_amt,
                            cmtd_ovpa_amt,
                            cmtd_udpa_amt,
                            cmtd_fee_ccy,
                            cmtd_fee_amt,
                            cmtd_approval_date,
                            cmtd_txn_product
                     FROM   crr_mi_txn_data
                     WHERE  cmtd_approval_date = in_fr_txn_date) R
             WHERE  L.cmm_txn_code = cmtd_txn_code
               AND  (L.cr_party_id = cmtd_party_id OR L.cr_party_type = 'G')
             GROUP BY
                    CMTD_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    CMTD_TXN_PRODUCT,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    CMTD_CCY,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
         )
         LOOP
           PIPE ROW (CRR_JNL_DATA_REC (RESULT.CMTD_APPROVAL_DATE,
                                       RESULT.CR_COUNTRY_ID,
                                       RESULT.CR_PRODUCT_CODE,
                                       RESULT.CR_JNL_TYPE_ID,
                                       RESULT.CR_JNL_ENTRY_TYPE_ID,
                                       RESULT.CR_PARTY_TYPE,
                                       RESULT.CR_PARTY_ID,
                                       RESULT.CR_CURRENCY_ID,
                                       RESULT.GL_ID,
                                       RESULT.CR_IND,
                                       RESULT.TXN_AMT,
                                       RESULT.TXN_COUNT,
                                       RESULT.TXN_ID));
         END LOOP;
      RETURN;
   END GET_MI_OFL_GLOBAL;


   FUNCTION GET_MI_OFL_PSP_MULTI (
      in_jnl_type_id      crr_mi_jnl_entry_type_mapping.cmm_jnl_type_id%TYPE,
      in_entry_type_id    crr_mi_jnl_entry_type_mapping.cmm_entry_type_id%TYPE,
      in_group_id         crr_mi_jnl_entry_type_mapping.cmm_group_id%TYPE,
      in_fr_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE,
      in_to_txn_date      crr_mi_txn_data.cmtd_approval_date%TYPE)
      RETURN CRR_JNL_DATA_TAB
      PIPELINED
   AS
   BEGIN
      FOR RESULT
         IN (SELECT COTH_APPROVAL_DATE,
                    CR_COUNTRY_ID,
                    OPPM_PRODUCT_CODE CR_PRODUCT_CODE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_PARTY_TYPE,
                    CASE WHEN CR_PARTY_TYPE <> 'G'
                      THEN CR_PARTY_ID
                      ELSE ''
                      END CR_PARTY_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                      THEN CR_CREDIT_GL_ID
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                      THEN CR_DEBIT_GL_ID
                      ELSE 0
                      END GL_ID,
                    CASE WHEN CR_CREDIT_GL_ID <> 0
                      THEN 'C'
                         WHEN CR_DEBIT_GL_ID IS NOT NULL
                      THEN 'D'
                      ELSE ''
                      END CR_IND,
                    COTH_CCY CR_CURRENCY_ID,
                    NVL (COTH_TXN_AMT, 0) TXN_AMT,
                    COTH_FEE_CCY FEE_CCY,
                    NVL (COTH_FEE, 0) FEE_AMT,
                    COTH_NET_CCY NET_CCY,
                    COTH_NET_AMT NET_AMT,
                    COTH_MARKUP_CCY,
                    NVL (COTH_MARKUP_AMT, 0) MARKUP_AMT,
                    COTP_PSP_CCY PSP_CCY,
                    NVL (COTP_PSP_AMT, 0) PSP_AMT,
                    1 TXN_COUNT,
                    COTH_TXN_ID TXN_ID
             FROM   (SELECT B.cr_jnl_type_id,
                            B.cr_jnl_entry_type_id,
                            A.cmm_group_id,
                            A.cmm_txn_side,
                            A.cmm_is_single,
                            A.cmm_txn_code,
                            B.cr_party_type,
                            B.cr_product_code,
                            B.cr_credit_gl_id,
                            B.cr_debit_gl_id,
                            B.cr_country_id,
                            B.cr_party_id,
                            B.cr_currency_id
                     FROM   crr_mi_jnl_entry_type_mapping A,
                            crr_rule_posting B
                     WHERE  A.cmm_entry_type_id = b.cr_jnl_entry_type_id
                       AND  A.cmm_jnl_type_id = b.cr_jnl_type_id
                       AND  A.cmm_disabled = 0
                       AND  B.cr_disabled = 0
                       AND  A.cmm_group_id = in_group_id
                       AND  A.cmm_jnl_type_id = in_jnl_type_id
                       AND  A.cmm_entry_type_id = in_entry_type_id) L,
                   (SELECT coth_txn_id,
                           coth_txn_code,
                           cotp_client_id,
                           cotp_psp_id,
                           cotp_baid,
                           cotp_baid_category,
                           coth_ccy,
                           coth_txn_amt,
                           coth_fee,
                           nvl(coth_fee_ccy,coth_net_ccy) coth_fee_ccy,
                           coth_net_amt,
                           coth_net_ccy,
                           coth_markup_amt,
                           coth_markup_ccy,
                           coth_approval_date,
                           cotp_psp_ccy,
                           cotp_psp_amt,
                           oppm_product_code
                    FROM   crr_ofl_txn_data_header,
                           crr_ofl_txn_data_psp_detail,
                           (SELECT oppm_psp_id,
                                   oppm_product_code,
                                   MAX (oppm_effective_date)
                            FROM   crr_ofl_psp_product_code_map
                            GROUP BY oppm_psp_id,
                                     oppm_product_code) C
                    WHERE  coth_approval_date = in_fr_txn_date
                      AND  coth_txn_id||'' = cotp_txn_id
                      AND  cotp_psp_id = oppm_psp_id) R
             WHERE  L.cmm_txn_code = coth_txn_code
               AND  L.cr_party_id = cotp_psp_id
               AND  L.cr_product_code = R.oppm_product_code
               AND  DECODE(L.CR_PARTY_TYPE,  'X', 'ITL_GEN',
                                             'I', 'IQ',
                                             'T', 'TEMP',
                                             'P', NVL(R.cotp_baid_category,'~'),
                                             NVL(R.cotp_baid_category,'~')) = NVL(R.cotp_baid_category,'~')
         )
         LOOP
           PIPE ROW (CRR_JNL_DATA_REC (RESULT.COTH_APPROVAL_DATE,
                                       RESULT.CR_COUNTRY_ID,
                                       RESULT.CR_PRODUCT_CODE,
                                       RESULT.CR_JNL_TYPE_ID,
                                       RESULT.CR_JNL_ENTRY_TYPE_ID,
                                       RESULT.CR_PARTY_TYPE,
                                       RESULT.CR_PARTY_ID,
                                       RESULT.CR_CURRENCY_ID,
                                       RESULT.GL_ID,
                                       RESULT.CR_IND,
                                       RESULT.TXN_AMT,
                                       RESULT.TXN_COUNT,
                                       RESULT.TXN_ID));
         END LOOP;
      RETURN;
   END GET_MI_OFL_PSP_MULTI;

END CRR_JNL_DATA_PKG;
/
