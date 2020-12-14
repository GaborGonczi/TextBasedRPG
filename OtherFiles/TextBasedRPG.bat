@echo off
set /P filelocation=Adja meg a jatekhoz szukseges adatfajl helyet:
set /P unitslocation=Adja meg a tortenetreszek helyet:
START "Game" "Game.exe"  %filelocation% %unitslocation%