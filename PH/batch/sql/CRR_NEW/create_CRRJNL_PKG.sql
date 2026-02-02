CREATE OR REPLACE PACKAGE CRRJNL_PKG is

	TYPE   CRRJNL_type is REF cursor return CRRJNL_VIEW%rowtype;

	function F_TEST001(in_view_name	IN	varchar2
		)return CRRJNL_TAB;

	procedure open_cur_CRRJNL(
	    in_function_name	 IN	varchar2,
            cursor_CRRJNL        IN OUT CRRJNL_type);

end CRRJNL_PKG;
/

CREATE OR REPLACE PACKAGE BODY CRRJNL_PKG
IS
   FUNCTION F_TEST001(in_view_name IN	varchar2)
	RETURN CRRJNL_TAB
   IS
      Result                    CRRJNL_TAB := CRRJNL_TAB ();

      n                         INTEGER := 0;
      v_txn_id                  txn_header.th_txn_id%TYPE;

      CURSOR CRRJNL_cur
      IS
           SELECT th_txn_id
	     FROM txn_header
            WHERE  ROWNUM = 1;
   BEGIN
      OPEN CRRJNL_cur;

      LOOP
         FETCH CRRJNL_cur
         INTO v_txn_id;

         EXIT WHEN CRRJNL_cur%NOTFOUND;


         Result.EXTEND;
         n := n + 1;

         result (n) :=
            CRRJNL_OBj (v_txn_id);

      END LOOP;

      CLOSE CRRJNL_cur;

      RETURN (Result);
   END;


   PROCEDURE open_cur_CRRJNL(
       in_function_name	 IN	varchar2,
       cursor_CRRJNL        IN OUT CRRJNL_type)
   IS
	str_function_name	varchar2(100);
	str_view_name		varchar2(100);
   BEGIN

	str_function_name := 'CRRJNL_PKG.' || in_function_name;
	str_view_name := in_function_name || '_view';

   	EXECUTE IMMEDIATE 'SELECT str_function_name(str_view_name) into cursor_crrjnl';

   END open_cur_CRRJNL;


END CRRJNL_PKG;
/
