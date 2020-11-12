echo 'all test results (output diff files)' > allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_memcpy.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_memccpy.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_memchr.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_memmove.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_memcmp.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_strlen.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_strlcpy.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_strlcat.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_strchr.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_strnstr.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_strncmp.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_atoi.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_isalpha.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_isdigit.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_isalnum.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_isascii.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_isprint.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_toupper.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

gcc -Wall -Werror -Wextra ../libft.a test_ft_tolower.c
./a.out 1 > libft
./a.out > libc
diff libft libc >> allresults

echo 'all tests executed'
