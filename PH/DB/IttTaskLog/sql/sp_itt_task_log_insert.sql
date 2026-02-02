CREATE OR REPLACE FUNCTION sp_itt_task_log_insert (
   in_batch_id			itt_task_log.ttl_batch_id%TYPE,
   in_batch_seq			itt_task_log.ttl_batch_seq%TYPE,
   in_api_code			itt_task_log.ttl_api_code%TYPE,
   in_task_action		itt_task_log.ttl_task_action%TYPE,
   in_action_type		itt_task_log.ttl_action_type%TYPE,
   in_object			itt_task_log.ttl_object%TYPE,
   in_key			itt_task_log.ttl_key%TYPE,
   in_field			itt_task_log.ttl_field%TYPE,
   in_value			itt_task_log.ttl_value%TYPE,
   in_old_value			itt_task_log.ttl_old_value%TYPE,
   in_ret_code			itt_task_log.ttl_ret_code%TYPE,
   in_create_user		itt_task_log.ttl_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO itt_task_log  (ttl_batch_id,
                              ttl_batch_seq,
                              ttl_api_code,
                              ttl_task_action,
                              ttl_action_type,
                              ttl_object,
                              ttl_key,
                              ttl_field,
                              ttl_value,
                              ttl_old_value,
                              ttl_ret_code,
                              ttl_create_timestamp,
                              ttl_create_user,
                              ttl_update_timestamp,
                              ttl_update_user)
        VALUES (in_batch_id,
                in_batch_seq,
                in_api_code,
                in_task_action,
                in_action_type,
                in_object,
                in_key,
                in_field,
                in_value,
                in_old_value,
                in_ret_code,
                SYSDATE,
                in_create_user,
                SYSDATE,
                in_create_user);

   IF SQL%ROWCOUNT = 0
   THEN
      RETURN 1;
   ELSE
      RETURN 0;
   END IF;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_itt_task_log_insert;
/

