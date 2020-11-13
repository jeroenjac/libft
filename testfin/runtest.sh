# compile the function
# this can be done with $1 etc?

# this compares output of libc function with libf function
./a.out > libc
./a.out 1 > libft
diff libc libft

#./a.out 1 1
#./a.out 1 | HEXDUMP > libft.hex
#./a.out | HEXDUMP > libc.hex
#diff libft.hex libc.hex -y
