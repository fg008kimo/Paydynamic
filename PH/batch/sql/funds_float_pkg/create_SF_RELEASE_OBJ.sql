DROP TYPE SF_RELEASE_OBJ;

CREATE OR REPLACE TYPE SF_RELEASE_OBJ is object (
                                                 aprv_date varchar(8),
                                                 rls_FT_date varchar(8),
                                                 rls_AF_date varchar(8),
						 merchant varchar(15),
						 service char(3),
						 country char(2),
						 currency char(3),
						 release_amt number(14,2)
                                                 )
/

