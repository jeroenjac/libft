echo 'all test results (output diff files)' > results_all_tests

# 1- 10
echo 'TESTING FT_MEMSET'
gcc -Wall -Werror -Wextra ../libft.a test_ft_memset.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_BZERO'
# echo 'libc abort vs libft segfault expected here?'
# (currently excluded in testset)
gcc -Wall -Werror -Wextra ../libft.a test_ft_bzero.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_MEMCPY'
gcc -Wall -Werror -Wextra ../libft.a test_ft_memcpy.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_MEMCCPY'
gcc -Wall -Werror -Wextra ../libft.a test_ft_memccpy.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_MEMCHR'
gcc -Wall -Werror -Wextra ../libft.a test_ft_memchr.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_MEMMOVE'
gcc -Wall -Werror -Wextra ../libft.a test_ft_memmove.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_MEMCMP'
gcc -Wall -Werror -Wextra ../libft.a test_ft_memcmp.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_STRLEN'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strlen.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
echo 'error is generated for these tests...'
./a.out 1 1 1 1
./a.out 1 1 1 1 1

echo 'TESTING FT_STRLCPY'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strlcpy.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_STRLCAT'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strlcat.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

# 11- 20
echo 'TESTING FT_STRCHR'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strchr.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

echo 'TESTING FT_STRRCHR'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strrchr.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

echo 'TESTING FT_STRNSTR'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strnstr.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_STRNCMP'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strncmp.c
./a.out 1 1 1

echo 'TESTING FT_ATOI'
gcc -Wall -Werror -Wextra ../libft.a test_ft_atoi.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_ISALPHA'
gcc -Wall -Werror -Wextra ../libft.a test_ft_isalpha.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_ISDIGIT'
gcc -Wall -Werror -Wextra ../libft.a test_ft_isdigit.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_ISALNUM'
gcc -Wall -Werror -Wextra ../libft.a test_ft_isalnum.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_ISASCII'
gcc -Wall -Werror -Wextra ../libft.a test_ft_isascii.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

echo 'TESTING FT_ISPRINT'
gcc -Wall -Werror -Wextra ../libft.a test_ft_isprint.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests

#21- 24
echo 'TESTING FT_TOUPPER'
gcc -Wall -Werror -Wextra ../libft.a test_ft_toupper.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

echo 'TESTING FT_TOLOWER'
gcc -Wall -Werror -Wextra ../libft.a test_ft_tolower.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

echo 'TESTING FT_CALLOC'
gcc -Wall -Werror -Wextra ../libft.a test_ft_calloc.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
echo '##### calloc test failing #####'
./a.out 1 1 1 1
echo '##### ft_calloc test failing #####'
./a.out 1 1 1 1 1

echo 'TESTING FT_STRDUP'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strdup.c
./a.out 1 > libft
./a.out > libc
diff libc libft >> results_all_tests
./a.out 1 1

#part 2
echo 'TESTING FT_SUBSTR'
gcc -Wall -Werror -Wextra ../libft.a test_ft_substr.c
./a.out 1 1 1

echo 'TESTING FT_STRJOIN'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strjoin.c
./a.out 1 1 1

echo 'TESTING FT_STRTRIM'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strtrim.c
./a.out 1 1 1

echo 'TESTING FT_SPLIT'
gcc -Wall -Werror -Wextra ../libft.a test_ft_split.c
./a.out 1 1 1
echo '##### THIS TEST (s = NULL) DOES COMPILE & RUNS w/o ASAN -> seg fault'
./a.out 1 2 3 4 5

echo 'TESTING FT_ITOA'
gcc -Wall -Werror -Wextra ../libft.a test_ft_itoa.c
./a.out 1 1 1

echo 'TESTING FT_STRMAPI'
gcc -Wall -Werror -Wextra ../libft.a test_ft_strmapi.c
./a.out 1 1 1
echo 'strmapi with either str or fun = NULL results in segfault (2x)'
./a.out 1 1 1 1
./a.out 1 1 1 1 1

echo 'TESTING FT_PUTCHAR*_FD (*AND ALSO STR, ENDL and NBR'
gcc -Wall -Werror -Wextra ../libft.a test_ft_putchar_fd.c
echo 'a -C- will be printed...?'
rm output_ft_putendl_fd
./a.out 1
echo
echo 'And this should show -Y-, which is written into a file:'
cat output_ft_putchar_fd
echo
echo 'And this should show -line with \n-, which is written into a file:'
cat output_ft_putendl_fd
echo
echo 'And this should show INT_MIN in digits, which is written into a file:'
cat output_ft_putnbr_fd

echo '.'
echo '.'
echo '.'
echo '.'
echo 'DONE!!!'
echo 'all tests executed >> inspect output file "results_all_tests" for diff results!'
