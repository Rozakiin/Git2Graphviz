Git2Graphviz
========

Git2Graphviz creates a graphviz file representing the history of a Git repository.

Look how easy it is to use:

```shell
$ ./git2graphviz 'https://github.com/fador/mineserver' mineserver.gv
```

Features
--------
- Create graphviz file of repository history
- Option to specify start and end commits

Installation
------------

## Dependencies
- [git](https://git-scm.com/) (tested with version 2.17.1)
- [libgit2](https://github.com/libgit2/libgit2) (tested with version 1.0.0)
- (libgit2 needs ssl, crypto and pthreads linked)
- [boost/graph](https://github.com/boostorg/graph) (tested with version 1.73.0)

## Installation

### Windows 10
1. install libgit2 ([good tutorial](https://bvisness.me/libgit2/))
2. install boost/graph
3. clone this repository
4. link libgit2 and boost/graph to project
5. Compile Git2Graphviz using c++11 or greater
6. Verify Git2Graphviz was correctly installed by checking version
```shell
$ ./Code/Git2Graphviz/Debug/git2graphviz.exe --version
```

Tested using MINGW64 (git Bash)

1. Clone this repository
2. libgit2 install (possibly not needed?)
3. ./scripts/install.bat
4. build using CMake
41. 
5. Verify Git2Graphviz was correctly installed by checking version
```shell
$ ./Code/Git2Graphviz/Debug/git2graphviz.exe --version
```

### Linux/Ubuntu
1. install libgit2 ([good tutorial](https://bvisness.me/libgit2/))
2. install boost/graph
3. clone this repository
4. link libgit2 and boost/graph to project
5. Compile Git2Graphviz using c++11 or greater
6. Verify Git2Graphviz was correctly installed by checking version
```shell
$ ./Code/Git2Graphviz/Debug/git2graphviz.exe --version
```

### Linux Install Notes
- boost/program_options needs to be built
- build and install to dependents/install removing .so extension libs helped 
- linking needed ssl, pthreads and crypto from path /usr/lib/x86_64-linux-gnu
- adding Xlinker --verbose is useful for debuging where the library is found/not


Contribute
----------

- Issue Tracker: github.com/rozakiin/Git2Graphviz/issues
- Source Code: github.com/rozakiin/Git2Graphviz

Usage
-----

### Arguments
- -r --repo repository local path
- -s --start start commit hash
- -e --end end commit hash
- -f --file path to file conatining list of commits to compare (WIP)
- -o --output output file name
- --help prints usage information
- --version prints version of program
- The output file name can be without argument



Examples
--------
Create a dot file for the ground truth of [mineserver](https://github.com/fador/mineserver) repository save as mineserver.gv

```shell
$ ./git2graphviz --repo './mineserver' mineserver.gv
```

Create a dot file for the ground truth of [mineserver](https://github.com/fador/mineserver) repository from commit 20c7 to 3671, save as mineserver20c73671.gv

```shell
$ ./git2graphviz --repo './mineserver' --start 20c7 --end 3671 mineserver20c73671.gv
```

Generate pdf file of the ground truth using Graphviz
```shell
$ dot -Tpdf mineserver.gv -o mineserver.pdf
```



Support
-------

If you are having issues, please let us know.
Please email: ruari.armstrong@uea.ac.uk

License
-------

The project is licensed under the GNU General Public License v3.0.
