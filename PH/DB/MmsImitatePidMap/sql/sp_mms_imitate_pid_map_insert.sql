CREATE OR REPLACE FUNCTION sp_mms_imitate_pid_map_insert (
   in_imitate_pid	mms_imitate_pid_map.mpm_imitate_pid%TYPE,
   in_org_pid		mms_imitate_pid_map.mpm_org_pid%TYPE,
   in_country		mms_imitate_pid_map.mpm_country%TYPE,
   in_service		mms_imitate_pid_map.mpm_service_code%TYPE,
   in_product		mms_imitate_pid_map.mpm_product%TYPE,
   in_nature_type	mms_imitate_pid_map.mpm_nature_type%TYPE,
   in_business_type	mms_imitate_pid_map.mpm_business_type%TYPE,
   in_create_user	mms_imitate_pid_map.mpm_create_user%TYPE)
   RETURN NUMBER
IS
	iCnt integer := 0;
BEGIN

   SELECT nvl(max(mpm_version),0)
	INTO iCnt
   FROM mms_imitate_pid_map
   WHERE mpm_org_pid = in_imitate_pid
   AND	mpm_country = in_country
   AND	mpm_service_code = in_service
   AND	mpm_product = in_product
   AND	mpm_nature_type = in_nature_type
   AND	mpm_business_type = in_business_type;

   iCnt := iCnt + 1;

   INSERT INTO mms_imitate_pid_map 
		(mpm_imitate_pid,
		 mpm_org_pid,
		 mpm_version,
		 mpm_country,
		 mpm_service_code,
		 mpm_product,
		 mpm_nature_type,
		 mpm_business_type,
		 mpm_fe_display,
		 mpm_create_timestamp,
		 mpm_create_user,
		 mpm_update_timestamp,
		 mpm_update_user)
        VALUES (in_imitate_pid,
                in_org_pid,
		iCnt,
                in_country,
                in_service,
                in_product,
                in_nature_type,
                in_business_type,
		0,
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
END sp_mms_imitate_pid_map_insert;
/
