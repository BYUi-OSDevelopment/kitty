# kitty
The kitty kernel, maintained by BYUi students

### Building
please put these precompiled binaries (x86_64) into your path: https://github.com/lordmilko/i686-elf-tools/releases/tag/7.1.0 

```make run arch=x86```

## Other components included in this repository

### x86/x86_64 bootloader

Located in src/x86-boot/, a boot sector written for 32/64 bit x86.

### EXT4 filesystem image

Located in src/test/fs_ext4/, this FS image contains just enough to get the operating system running by providing service files
that the kernel loads automatically.