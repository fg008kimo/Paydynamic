OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebByUsNWM
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebByUsNWM.so
SOOBJS = TxnWebByUsNWM.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
