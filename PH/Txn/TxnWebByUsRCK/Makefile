OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebByUsRCK
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebByUsRCK.so
SOOBJS = TxnWebByUsRCK.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
