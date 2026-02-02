


select osmt_format_id, osmt_format_type, osmt_format_value, osmt_format_desc, osmt_delimiter, osmt_delimiter_desc, osmt_is_generic
from ol_sms_format_template
where osmt_format_id like '086309%'
order by osmt_format_id, osmt_format_type, osmt_format_value;

