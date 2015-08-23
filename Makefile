APPNAME=tearing

# Compiler flags
ifeq ($(RELEASE), 1)
CFLAGS = -Wall -ansi -pedantic -ffast-math -s -O5 -DNDEBUG
else
CFLAGS = -Wall -ansi -pedantic -g
endif

# OpenGL Libraries 
GL_LIBS = -lglut -lGL
GL_LIBDIR = -L/usr/X11/lib
LINK_GL = $(GL_LIBDIR)

# all needed libraries
LINK = $(LINK_GL)

# Files
OBJECTS = tearing.o
	   
# build rules
.PHONY: all
all:	$(APPNAME)

# build and start with "make run"
.PHONY: run
run:	all
	__GL_SYNC_TO_VBLANK=1 ./$(APPNAME)

# rule to build application
$(APPNAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(LINK) $(LDFLAGS) $(OBJECTS) $(GL_LIBS) -o$(APPNAME)

# remove all unneeded files
.PHONY: clean
clean:
	@echo removing binary: $(APPNAME)
	@rm -f $(APPNAME)
	@echo removing object files: $(OBJECTS)
	@rm -f $(OBJECTS)

