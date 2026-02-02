OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnTpmByUsINQ
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnTpmByUsINQ.so
SOOBJS = TxnTpmByUsINQ.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
