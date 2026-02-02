-- Update Data in the ol_baid_txn_code_mapping table
update ol_baid_txn_code_mapping 
set obtm_keywords = 1, obtm_full_match = 0
where obtm_code in ('FDI', 'FDO');
