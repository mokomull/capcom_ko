# Warning

:warning: This module is a joke.  It is completely insecure, and it is the very
definition of a bad idea.  **Do not** use this on a system you care about.  I
highly recommend testing it in a VM, then throwing the entire VM image away.

# capcom.ko

A Windows driver `capcom.sys` has been [making the news](https://www.reddit.com/r/Games/comments/545cjy/sfvs_new_pc_update_is_accessing_kernel_level_in/d7z4eev)
in the last few days, and I thought it would be a fun exercise to do the
equivalent on Linux.

## Requirements

It appears that this works with Linux 4.0 or later, but I don't make any
guarantees.  It would be simple to support other versions, but I consider it to
be a security **feature** if this **fails** to build on a given platform.

## Using

    $ make -C /lib/modules/$(uname -r)/build M=$PWD

After inserting the module, you can run `./exploit` as an unprivileged user to
see a message printed in `dmesg`, demonstrating that kernel security is
completely undermined.

## Disclaimer

I do not play Street Fighter V, nor have I even seen a copy of `capcom.sys`.
This was designed solely based on
[a tweet](https://twitter.com/TheWack0lian/status/779397840762245124) and
[a Reddit comment](https://www.reddit.com/r/Games/comments/545cjy/sfvs_new_pc_update_is_accessing_kernel_level_in/d7z4eev)
describing its behavior.
