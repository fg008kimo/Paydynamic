OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMgtByUsPSF
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMgtByUsPSF.so
SOOBJS = TxnMgtByUsPSF.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
