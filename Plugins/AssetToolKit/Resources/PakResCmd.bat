echo Pak project Resources

echo %cd%

set Localpath=%cd%

UnrealPak.exe "%Localpath%\test.pak" -create="%Localpath%\paklist.txt" -order="%Localpath%\cookopen.log" -UTF8Output -encrypt -compress

pause