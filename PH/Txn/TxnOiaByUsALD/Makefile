OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOiaByUsALD
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOiaByUsALD.so
SOOBJS = TxnOiaByUsALD.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
