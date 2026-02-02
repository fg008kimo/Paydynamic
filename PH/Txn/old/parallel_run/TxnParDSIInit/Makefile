OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnParDSIInit
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnParDSIInit.so
SOOBJS = TxnParDSIInit.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
