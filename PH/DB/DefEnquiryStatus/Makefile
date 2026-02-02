OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/DefEnquiryStatus
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBDefEnquiryStatus.so
SOOBJS =  DefEnquiryStatus.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
