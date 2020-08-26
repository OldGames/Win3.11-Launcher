#------------------------
# Go.MAK make file
# Microsoft Visual C++ - Version 1.52c (Microsoft) (1995)
#------------------------

Go.exe : Go.obj Go.def
     $(WINLINK) Go, Go, NUL, $(WINLIB), Go
     rc -t Go.exe

Go.obj : Go.c
     $(WINCC) Go.c
