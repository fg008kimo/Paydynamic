OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebOnUsMSI
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebOnUsMSI.so
SOOBJS = TxnWebOnUsMSI.o

include $(HOME)/config/Make.rules

LDLIBS +=
CPPFLAGS += -D_SUMULATOR_ 

all     : $(COMPSO)
