OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/NtpMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libNtpMsg.so
SOOBJS = NtpMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
