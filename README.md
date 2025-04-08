# InlineWhispers3
InlineWhispers3 is an updated version of [InlineWhispers2](https://github.com/Sh0ckFR/InlineWhispers2), designed to work with Indirect System Calls in Cobalt Strike's Beacon Object Files (BOFs) using [SysWhispers3](https://github.com/klezVirus/SysWhispers3). This tool helps changing SysWhispers3 generated files to be BOF compatible.

## How to set this up?

```sh
# Clone the main repository and initialize submodules (SysWhispers3)
git clone --recurse-submodules https://github.com/tdeerenberg/InlineWhispers3
cd InlineWhispers3

# Navigate to submodule directory and run the syswhispers.py script
cd SysWhispers3/
python3 syswhispers.py -p all -a x64 -m jumper -o syscalls_all

# Navigate back to the main repository and run the InlineWhispers3.py script
cd ..
python3 InlineWhispers3.py --aio
```

This generates the required syscalls.c/h files and then runs InlineWhispers3 to make the files compatible with BOFs.

> The `--aio` flag is optional and merges all output files into one `.h` file, which can also be used instead of using `syscalls.c`, `syscalls.h`, and `syscalls-asm.h`

## How to use indirect syscalls in your BOF

Import `syscalls.h`, `syscalls.c`, and `syscalls-asm.h` (or only `syscalls-aio.h`) in your project and include `syscalls.c` (or `syscalls-aio.h`) in your C code to start using syscalls.

An example BOF for reference (creates a new process using ` `):

```c
#include <windows.h>
#include "beacon.h"
#include "syscalls.c"

void go(char* args, int length) {
    ... CODE TO BE ADDED ...
}
```

## Credits
- [@klezVirus](https://github.com/klezVirus) for SysWhispers3
- [@Sh0ckFR](https://github.com/Sh0ckFR) for InlineWhispers2
- [@outflanknl](https://github.com/outflanknl) for the first version of InlineWhispers and their informative blog post about it
- The Cyber Security Community for all the articles and resources