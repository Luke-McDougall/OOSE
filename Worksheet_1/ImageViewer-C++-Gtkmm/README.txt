ImageViewer -- C++, GTK
=======================

This is an (unfinished) C++-based image viewer, using the GTK GUI. It 
requires that your system has 'gtkmm' 3.0 installed, both the binaries and 
header files, and all their dependencies, and the 'pkg-config' tool.

For RedHat/Fedora systems, you generally need to install 'gtkmm30' and
'gtkmm30-devel'` (and everything on which they depend).

Gtkmm is a C++ API for using GTK. You can also use GTK directly from C++, but
for the purposes of OOSE it's nicer to work with a proper OO library. For 
general information on gtkmm, see www.gtkmm.org. 
