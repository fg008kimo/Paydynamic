OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnTpmByUsPOL
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnTpmByUsPOL.so
SOOBJS = TxnTpmByUsPOL.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
