insert into ol_def_email_notify_template (
    oet_funct, oet_template,
    oet_create_user, oet_update_user, oet_create_timestamp, oet_update_timestamp
)
values (
    'OFL_SETT_A',
'Subject: [ARGV1]: Settlement Initiated' || chr(10) ||
'<html>' || chr(10) ||
'<body>' || chr(10) ||
'Dear Merchant, <br>' || chr(10) ||
'<br>' || chr(10) ||
'Please be advised that [ARGV1] has initiated a settlement request for your merchant account [ARGV2].  Please refer to the following for details.  Thank you. <br>' || chr(10) ||
'<br>' || chr(10) ||
'Transaction ID: [ARGV3] <br>' || chr(10) ||
'Request Date/Time (GMT+8): [ARGV4] <br>' || chr(10) ||
'Merchant ID: [ARGV2] <br>' || chr(10) ||
'Country: [ARGV5] <br>' || chr(10) ||
'Service: [ARGV6] <br>' || chr(10) ||
'Settlement Amount: [ARGV7] $[ARGV8] <br>' || chr(10) ||
'Delivery Amount: [ARGV9] $[ARGV10] <br>' || chr(10) ||
'<br>' || chr(10) ||
'Please do not reply directly to this system-generated e-mail. This address cannot accept incoming messages. If you have any questions about this payment, please contact us at: <br>' || chr(10) ||
'Email: AsiaPayments@OptimalPayments.com <br>' || chr(10) ||
'<br>' || chr(10) ||
'Best regards, <br>' || chr(10) ||
'Asia Payments Merchant Services <br>' || chr(10) ||
'Optimal Payments <br>' || chr(10) ||
'</body>' || chr(10) ||
'</html>'
, 'SYSTEM', 'SYSTEM', sysdate, sysdate);
