echo 'all test results (output diff files)' > results_all_tests

# 1- 10
gcc -Wall -Werror -Wextra ../libft.a test_ft_memset.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

# echo 'libc abort vs libft segfault expected here?'
# (currently excluded in testset)
gcc -Wall -Werror -Wextra ../libft.a test_ft_bzero.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_memcpy.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_memccpy.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_memchr.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_memmove.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_memcmp.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'error is generated for these tests...'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strlen.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_strlcpy.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_strlcat.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

# 11- 20
gcc -Wall -Werror -Wextra ../libft.a test_ft_strchr.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

gcc -Wall -Werror -Wextra ../libft.a test_ft_strrchr.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

gcc -Wall -Werror -Wextra ../libft.a test_ft_strnstr.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_strncmp.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_atoi.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_isalpha.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_isdigit.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_isalnum.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_isascii.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_isprint.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

#21- 24
gcc -Wall -Werror -Wextra ../libft.a test_ft_toupper.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

gcc -Wall -Werror -Wextra ../libft.a test_ft_tolower.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

gcc -Wall -Werror -Wextra ../libft.a test_ft_calloc.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

gcc -Wall -Werror -Wextra ../libft.a test_ft_strdup.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

#part 2
gcc -Wall -Werror -Wextra ../libft.a test_ft_substr.c
./a.out 1 1 1

gcc -Wall -Werror -Wextra ../libft.a test_ft_strjoin.c
./a.out 1 1 1

#gcc -Wall -Werror -Wextra ../libft.a test_ft_strtrim.c
#./a.out 1 1 1

echo 'all tests executed >> inspect output file "results_all_tests" for diff results!'
