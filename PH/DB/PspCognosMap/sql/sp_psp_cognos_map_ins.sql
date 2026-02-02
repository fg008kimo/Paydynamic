CREATE OR REPLACE FUNCTION sp_psp_cognos_map_ins(
	in_psp_id                       psp_cognos_map.pcm_psp_id%type,
	in_group                        psp_cognos_map.pcm_group%type,	
	in_create_user                  psp_cognos_map.pcm_create_user%type,
	in_group_1                      psp_cognos_map.pcm_group_1%type
)
  RETURN NUMBER IS
Begin
        insert into psp_cognos_map (
				pcm_group,
				pcm_psp_id,
				pcm_create_user,
				pcm_create_timestamp,
				pcm_update_user,
				pcm_update_timestamp,
				pcm_group_1
		)
		values
		(
			 in_group,
		     in_psp_id,
			 in_create_user,
			 sysdate,
			 in_create_user,
			 sysdate,
			 in_group_1
		);

		IF SQL%ROWCOUNT = 0 THEN
			RETURN 1;
		ELSE
			RETURN 0;
		END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_psp_cognos_map_ins;
/

