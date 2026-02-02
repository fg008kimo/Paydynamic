


-----------------------------------------------
-- Add Data into the table "DEF_MERCH_PSP_TYPE"
-----------------------------------------------
insert into DEF_MERCH_PSP_TYPE (
        DMPT_TYPE, DMPT_DESC,
        DMPT_CREATE_USER, DMPT_CREATE_TIMESTAMP, DMPT_UPDATE_USER, DMPT_UPDATE_TIMESTAMP)
values (
        'E', 'Error Adjustment', 
        'SYSTEM', sysdate, 'SYSTEM', sysdate);
