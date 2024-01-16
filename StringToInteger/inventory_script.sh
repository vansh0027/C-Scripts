#!/bin/bash

for file in *.c;do
echo "$file: "
grep -E --color=auto  "^[a-zA-Z_][a-zA-Z0-9_]*\s*\([^;]+\)\s*\{" "$file" | sed 's/[{]//'| sed -E 's/^([a-zA-Z_][a-zA-Z0-9_]*)/\x1B[31m&\x1B[0m/g' | sed -E 's/(\([^;]+\))/\x1b[34m&\x1b[0m/g'
#Color figures in sed command are taken from online resources. I absolutely have no idea about the composition about this color number above  but I have used sed to replace parts of the output with colored versions. 
done

