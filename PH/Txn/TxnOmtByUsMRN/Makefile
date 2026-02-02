OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOmtByUsMRN
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOmtByUsMRN.so
SOOBJS = TxnOmtByUsMRN.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
