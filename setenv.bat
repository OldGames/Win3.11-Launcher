@ECHO OFF

IF NOT DEFINED TOOLROOTDIR CALL E:\MSVC\BIN\MSVCVARS.BAT

SET WINCC=cl -c -G2sw -Ow -W3 -Zp -Tp
SET WINLINK=link /nod
SET WINLIB=slibcew oldnames libw commdlg ddeml
SET WINRC=rc -r
SET DLLCC=cl -c -ASw -G2sw -Ow -W3 -Zp -Tp
SET DLLLINK=link /nod libentry
SET DLLLIB=sdllcew oldnames libw
SET DLLRC=rc -r