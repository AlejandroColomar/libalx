devel:

 - It should be used to work on libalx.
 - Contains the libraries needed by libalx
 - Prepared to be used in a host that has a local repository with libalx.  The
   host will be used for the graphical text editor, and the container for
   compiling and everything else.

dev:

 - It should be used to work on programs that depend on libalx
 - Contains the libraries needed by libalx
 - libalx is installed in the system (/usr/lib/ & /usr/include/)
 - Contains a local repository with libalx, which can be used to upgrade the
   installed version.
