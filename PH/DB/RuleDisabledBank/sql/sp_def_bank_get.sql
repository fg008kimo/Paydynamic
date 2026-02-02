CREATE OR REPLACE FUNCTION sp_def_bank_get (
  in_country			def_bank.db_country%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
          into iCnt    
  	  from def_bank
	 where db_country = in_country;

        if iCnt > 0 THEN
              OPEN out_cursor for
	       select db_int_bank_code
  	  	 from def_bank
	 	where db_country = in_country
		order by db_int_bank_code;
                RETURN 1;
	end if;

	RETURN 0;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_def_bank_get;
/

