OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebByUsACK
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebByUsACK.so
SOOBJS = TxnWebByUsACK.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
