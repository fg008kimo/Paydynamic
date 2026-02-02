--------------------------------------------------------
--  DDL for Function SP_CRR_JNL_DETAIL_INSERT
--------------------------------------------------------

  CREATE OR REPLACE FUNCTION "SP_CRR_JNL_DETAIL_INSERT" (
	in_jnl_id				crr_jnl_detail.jnl_id%type,
	in_line_no				crr_jnl_detail.line_no%type,
	in_gl_id				crr_jnl_detail.gl_id%type,
	in_currency_id				crr_jnl_detail.currency_id%type,
	in_txn_amt				crr_jnl_detail.txn_amt%type,
	in_cr_ind				crr_jnl_detail.cr_ind%type,
	in_remarks				crr_jnl_detail.remarks%type DEFAULT NULL,
	in_disabled				crr_jnl_detail.disabled%type,
	in_create_user				crr_jnl_detail.create_user%type,
	in_txn_count				crr_jnl_detail.txn_count%type DEFAULT NULL,
	in_report_date				crr_jnl_detail.report_date%type
)

		RETURN NUMBER IS
		begin

		insert into crr_jnl_detail (
				jnl_id,
				line_no,
				gl_id,
				currency_id,
				txn_amt,
				cr_ind,
				remarks,
				disabled,
				create_timestamp,
				update_timestamp,
				create_user,
				update_user,
				txn_count,
				report_date
 		) values (
				in_jnl_id,
				in_line_no,
				in_gl_id,
				in_currency_id,
				in_txn_amt,
				in_cr_ind,
				in_remarks,
				in_disabled,
				sysdate,
				sysdate,
				in_create_user,
				in_create_user,
				in_txn_count,
				in_report_date
		);

		IF SQL%ROWCOUNT = 0 THEN
		   RETURN 1;
		ELSE
		   RETURN 0;
		END IF;

EXCEPTION
WHEN OTHERS THEN
   RETURN 9;
end sp_crr_jnl_detail_insert;

/

