create or replace function sp_mms_txn_detail_insert(
        in_txn_id                               mms_txn_detail.td_txn_id%type,
        in_txn_ccy                              mms_txn_detail.td_txn_ccy%type,
        in_txn_country                          mms_txn_detail.td_txn_country%type,
        in_encrypt_type                         mms_txn_detail.td_encrypt_type%type,
        in_version_no                           mms_txn_detail.td_version_no%type,
        in_remark                               mms_txn_detail.td_remark%type,
        in_create_user                          mms_txn_detail.td_create_user%type,
        in_update_user                          mms_txn_detail.td_update_user%type
        )
  RETURN NUMBER IS
Begin
        update mms_txn_detail
           set td_txn_ccy = in_txn_ccy,
               td_txn_country = in_txn_country,
               td_encrypt_type=in_encrypt_type,
               td_version_no = in_version_no,
               td_remark = in_remark,
               td_update_timestamp = sysdate,
	       td_update_user = in_update_user
         where td_txn_id = in_txn_id;

        IF SQL%ROWCOUNT = 0 THEN
                insert into mms_txn_detail
                        (td_txn_id,
                         td_txn_ccy,
                         td_txn_country,
                         td_encrypt_type,
                         td_version_no,
                         td_remark,
                         td_create_timestamp,
                         td_update_timestamp,
                         td_create_user,
                         td_update_user)
                 values (in_txn_id,
                         in_txn_ccy,
                         in_txn_country,
                         in_encrypt_type,
                         in_version_no,
                         in_remark,
                         sysdate, 
                         sysdate,
                         in_create_user,
                         in_update_user);

                IF SQL%ROWCOUNT = 0 THEN
                        RETURN 1;
                ELSE
                        RETURN 0;
                END IF;

        ELSE
                RETURN 0;
        END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mms_txn_detail_insert;
/
