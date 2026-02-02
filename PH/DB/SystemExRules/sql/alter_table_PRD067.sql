


alter table system_ex_rules add
(sr_manual_input char(1 byte),
 sr_ref_ex_rate_type char(6 byte),
 sr_min_ref_tolerance number(12,5),
 sr_max_ref_tolerance number(12,5)
);

comment on column system_ex_rules.sr_manual_input is 'M - Mandatory; O - Optional; N - Not allowed';

