# MasterEverdrive
This is a Sega Master System emulator

* Add _CRT_SECURE_NO_WARNINGS to Library Preprocessor definitions
* Remove static library references from  Library
* Attempt to remove gtest warnings Linker | Enable Incremental Linking
* Deleted previous DLLs from bin\Debug folder as causing issues on Windows 10


Ever
Ignore LNK4099 errors - can't be done!  Rebuild and find the PDB files and rename
https://stackoverflow.com/questions/661606/visual-c-how-to-disable-specific-linker-warnings

LNK4204 solved
https://stackoverflow.com/questions/30517604/how-do-i-fix-lnk4204-or-get-rid-of-it

Download and rebuild gtestd.library
However, embed the debugging information in the static lib itself

I ended up recompiling all libraries metioned by the warnings with Z7 (
Properties -> C/C++ -> Debug Information Format), as to embed the debug info in the libs themselves. 
This removed all warnings.


Copy gtestd.lib to deps/lib/gtest
Rebuild and now no more linker errors!