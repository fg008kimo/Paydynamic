OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/batch/migration/test_tpl
COMPLIBHOME = $(HOME)/lib
COMPOBJHOME = $(COMPHOME)/obj
BIN_PATH=$(HOME)/bin
LIB_PATH=/usr/lib

include $(HOME)/config/Make.rules

CPPFLAGS += -D_LINUX_DEBUG_ -I$(COMPHOME)/include -I$(HOME)/include -I/usr/include -I/usr/local/include -I$(ORACLE_HOME)/otrace/public -I$(ORACLE_HOME)/precomp/public 
LDLIBS = -lcurl -lutilitys -lc -lm -lmyhash  -lObjPtr -lmyrecordset -lhtmlstreamparser
BIN	= vg_test_tpl 

.c.o:
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) -c $<
	mv $*.o $(OBJHOME)

all     : $(BIN) 
vg_test_tpl	: vg_test_tpl.o 
	$(CPP) $(OBJHOME)/vg_test_tpl.o $(SHARED_LIB_OBJS) $(LDFLAGS) $(LDLIBS) -o $@

clean:
	rm -f $(BIN_PATH)/vg_test_tpl
