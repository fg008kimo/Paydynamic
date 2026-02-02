OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOmtByUsTAR
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOmtByUsTAR.so
SOOBJS = TxnOmtByUsTAR.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
