# Usage: bash ./clang_cs1010.sh hello.c
echo "Executing:"
set -x # Prints commands executed in this script. Namely the clang command.
clang -g -Wall $1 -lm
