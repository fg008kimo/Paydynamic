create or replace function sp_eml_messages_insert(
  in_txn_id             eml_messages.eml_txn_id%type,
  in_sender             eml_messages.eml_sender%type, 
  in_ref_num            eml_messages.eml_ref_num%type,  
  in_seq_num            eml_messages.eml_seq_num%type,  
  in_total              eml_messages.eml_total%type,  
  in_send_datetime      eml_messages.eml_send_datetime%type,  
  in_local_tm_date      eml_messages.eml_local_tm_date%type,
  in_local_tm_time      eml_messages.eml_local_tm_time%type,
  in_tag                eml_messages.eml_tag%type,
  in_has_missing_parts  eml_messages.eml_has_missing_parts%type,
  in_sms_center         eml_messages.eml_sms_center%type,
  in_sender_num_type    eml_messages.eml_sender_num_type%type,
  in_status             eml_messages.eml_status%type,
  in_body               eml_messages.eml_body%type,
  in_create_user        eml_messages.eml_create_user%type,
  in_update_user        eml_messages.eml_update_user%type)

  RETURN NUMBER IS
begin

  insert into eml_messages
              (eml_txn_id,
              eml_sender,
              eml_ref_num,
              eml_seq_num,
              eml_total,
              eml_send_datetime,
              eml_local_tm_date,
              eml_local_tm_time,
              eml_tag,
              eml_has_missing_parts,
              eml_sms_center,
              eml_sender_num_type,
              eml_status,
              eml_body,
              eml_create_user,
              eml_create_timestamp,
              eml_update_user,
              eml_update_timestamp)
         values(in_txn_id,
                in_sender,
                in_ref_num,
                in_seq_num,
                in_total,
                in_send_datetime,
                in_local_tm_date,
                in_local_tm_time,
                in_tag,
                in_has_missing_parts,
                in_sms_center,
                in_sender_num_type,
                in_status,
                in_body,
                in_create_user,
                sysdate,
                in_update_user,
                sysdate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_eml_messages_insert;
/
