# Directory Listing Utility

A minimal C program demonstrating POSIX directory traversal and file statistics retrieval.

## Overview

This educational project implements a basic directory listing tool in C, similar to `ls -l` but simplified. It demonstrates fundamental systems programming concepts including directory operations, file stat retrieval, and error handling.

## What It Does

The program:
- Opens the current working directory
- Iterates through all entries (files, directories, links)
- Retrieves and displays each entry's name and size in bytes
- Handles errors appropriately

## Compilation

```bash
gcc -o dirlist main.c
```

Or with warnings enabled (recommended):
```bash
gcc -Wall -Wextra -o dirlist main.c
```

## Usage

```bash
./dirlist
```

**Output example:**
```
.               4096 bytes
..              4096 bytes
main.c          523 bytes
dirlist         16384 bytes
README.md       1247 bytes
```

## Learning Objectives

This code teaches:
- **POSIX directory APIs**: `opendir()`, `readdir()`, `closedir()`
- **File system queries**: `stat()` system call
- **Error handling**: `perror()` for diagnostic output
- **Resource management**: Proper cleanup of directory handles

## Key Concepts

### `dirent` Structure
Contains directory entry information, primarily the filename (`d_name`).

### `stat` Structure
Holds file metadata including:
- `st_size` - file size in bytes
- `st_mode` - permissions and file type
- `st_mtime` - last modification time

### Error Handling Pattern
```c
if (operation() != 0) {
    perror("operation");
    // handle error
}
```

## Limitations

- Only displays current directory (no recursive traversal)
- Shows size in bytes only (no human-readable formatting)
- Reports 4096 bytes for directories (implementation-specific)
- No sorting or filtering capabilities

## Possible Enhancements

1. Accept directory path as command-line argument
2. Add human-readable size formatting (KB, MB, GB)
3. Display file permissions and timestamps
4. Implement recursive directory traversal
5. Add filtering options (exclude hidden files, etc.)

## Requirements

- POSIX-compliant system (Linux, macOS, BSD, Unix)
- C compiler (GCC, Clang)
- Standard C library with POSIX extensions

## License

Educational/Public Domain - use freely for learning purposes.

---

**Note**: This is a teaching example. Production code would require additional validation, security considerations, and feature completeness.
