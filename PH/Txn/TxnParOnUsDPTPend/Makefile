OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnParOnUsDPTPend
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnParOnUsDPTPend.so
SOOBJS = TxnParOnUsDPTPend.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
