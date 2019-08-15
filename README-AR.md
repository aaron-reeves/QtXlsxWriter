qmake apparently must be run in three directories:
  - This one, the root directory
  - src
  - src/xlsx
  
Once qmake has been run in all three places, run mingw32-make.exe from the root directory.

Finally, run mingw32-make.exe install.