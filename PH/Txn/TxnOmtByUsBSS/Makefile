OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOmtByUsBSS
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOmtByUsBSS.so
SOOBJS = TxnOmtByUsBSS.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
