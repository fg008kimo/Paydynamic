set serveroutput on;

declare
    cursor c1 is
	select a.psp_id, a.psp_type, B.CP_PRESET_PRODUCT
	from par_client_psp_map b, psp_detail a
	where A.PSP_ID = B.CP_PRESET_PH_PID
	and not exists (select 1
       	         	from crr_psp_product_code_map
			where pm_psp_id = a.psp_id
			and pm_business_type = a.psp_type
                	);

begin

    for i in c1 loop
dbms_output.put_line('----');
dbms_output.put_line('psp id[' || i.psp_id|| ']');
	insert into crr_psp_product_code_map (pm_psp_id, pm_business_type, pm_product_code,
                                          pm_disabled, pm_create_user, pm_create_timestamp, pm_update_user, pm_update_timestamp)
	values (i.psp_id, i.psp_type, i.cp_preset_product,
                0, 'SYSTEM', sysdate, 'SYSTEM', sysdate);
    end loop;

    commit;

exception
    when others then
	dbms_output.put_line('error.... sqlerrm ' || sqlerrm);
        rollback;
end;
/
