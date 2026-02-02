DROP FUNCTION SP_MERCHANT_BUCKET_PRE_DEL;

CREATE OR REPLACE FUNCTION sp_merchant_bucket_pre_del
return number is
begin
	delete from  merchant_bucket_preview
             WHERE     mbp_bucket_type = 'AF'
         AND mbp_posting_date < (SELECT sys_val
                                    FROM system_control
                                   WHERE sys_code = 'CTPHDATE');
	return 0;

exception
  when others then
  return 9;
end sp_merchant_bucket_pre_del;
/
