OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnCctByUsRCK
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnCctByUsRCK.so
SOOBJS = TxnCctByUsRCK.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
