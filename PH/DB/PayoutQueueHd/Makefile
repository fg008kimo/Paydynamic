OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/PayoutQueueHd
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBPayoutQueueHd.so
SOOBJS =  PayoutQueueHd.o

include $(HOME)/config/Make.rules

LDLIBS +=

all     : $(COMPSO)
