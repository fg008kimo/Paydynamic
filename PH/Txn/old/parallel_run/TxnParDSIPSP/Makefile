OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnParDSIPSP
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnParDSIPSP.so
SOOBJS = TxnParDSIPSP.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
