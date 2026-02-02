CREATE OR REPLACE FUNCTION sp_mms_entity_nmap_insert (
	in_nature_id			mms_entity_nature_map.m_nature_id%TYPE,
	in_nature_grp			mms_entity_nature_map.m_nature_grp%TYPE,
	in_nature_grp_val		mms_entity_nature_map.m_nature_grp_val%TYPE,
	in_user				mms_entity_nature_map.m_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ENTITY_NATURE_MAP (
	m_nature_id,
	m_nature_grp,
	m_nature_grp_val,
     	m_create_timestamp,
     	m_create_user,
     	m_update_timestamp,
     	m_update_user
	)

  VALUES (
	in_nature_id,
	in_nature_grp,
	in_nature_grp_val,
       	SYSDATE,
       	in_user,
       	SYSDATE,
       	in_user
	);

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

END sp_mms_entity_nmap_insert;
/

