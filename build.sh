# Red Hat Fedora Linux
gcc -m64 main.c knapsack.c -o x86_64-redhat-linux # 64-bit
gcc -m32 main.c knapsack.c -o i686-redhat-linux # 32-bit

# Microsoft Windows
x86_64-w64-mingw32-gcc main.c knapsack.c -o x86_64-windows # 64-bit
i686-w64-mingw32-gcc main.c knapsack.c -o i686-windows # 32-bit

# Move binaries to /bin folder
mv x86_64-redhat-linux bin
mv i686-redhat-linux bin
mv x86_64-windows.exe bin
mv i686-windows.exe bin
