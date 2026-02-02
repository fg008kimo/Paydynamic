


select oaubd_int_bank_code, oaubd_bank_acct_num, oaubd_acct_type, oaubd_disabled
from ol_auto_upload_bank_detail
where oaubd_int_bank_code = '086309'
and oaubd_bank_acct_num = '000'
and oaubd_acct_type = 'DSI';

