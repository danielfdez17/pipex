# pipex 42 Madrid
This objective of the project is to simulate pipes with a C program.

## Installation
- Clone the repo
```bash
git clone https://github.com/danielfdez17/pipex.git
cd pipex
```
## Build
If you have make installed in your system, justbBuild the project with make. Otherwise, you will need to install it.
```bash
make
```

## Usage
It is necessary to indicate the first four params. On the other hand, the last one is optional.
```bash
./pipex infile cmd ... cmd outfile
```

## Example usage
```bash
./pipex Makefile "cat" "grep NAME" "wc -l" outfile
```
