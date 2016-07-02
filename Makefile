P=ttt

MKDIR=mkdir -p
RM=rm

CC=clang
CFLAGS=-Wall -Wextra -g

SRCDIR=src
OBJDIR=obj
BINDIR=bin

TARGET=$(BINDIR)/$(P)
SOURCES:=$(wildcard $(SRCDIR)/*.c)
OBJECTS:=$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

.PHONY : clean

$(TARGET): $(OBJECTS)
	$(MKDIR) $(BINDIR)
	$(CC) $(OBJECTS) $(CFLAGS) -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
