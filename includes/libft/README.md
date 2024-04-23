<h1 align="center"><strong>LIBFT - @42SP</strong></h1>

<p align="center">This was the first project of the 42 curriculum. The project aims to recreate several functions from the standard libc.</p>

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>
<p align="center"><img src="https://user-images.githubusercontent.com/81205527/149165832-9344c9e5-6075-4268-b276-26b60efc5733.png"> </p>
 <p align="center">Nota: <strong>122/100</strong> ✔️ </p>

<h2 align="center"><strong>What is the LIBFT?</strong></h2>

This is the first project of the 42 curriculum. It consists of recreating various standard functions of the language to be used during the course development, 
since we cannot use the originals. This is a living library and new functions can be added to it, increasing its functionalities.

<h1 align="center"><strong>Functions</strong></h1>

## Functions to handle char type

- **[`ft_isalpha`](src/char/ft_isalpha.c)** - Verifies if the param is an alphabet letter.

- **[`ft_isdigit`](src/char/ft_isdigit.c)** - Verifies if the param is a digit(0 a 9).

- **[`ft_isalnum`](src/char/ft_isalnum.c)** - Verifies if the param is a alphanumeric.

- **[`ft_isascii`](src/char/ft_isascii.c)** - Verifies if the param is a ASCII digit.

- **[`ft_isprint`](src/char/ft_isprint.c)** - Verifies if the param is printable.

- **[`ft_tolower`](src/char/ft_tolower.c)** - Lowercase the param.

- **[`ft_toupper`](src/char/ft_toupper.c)** - Uppercase the param.

- **[`ft_isspace`](src/char/ft_isspace.c)** - Verifies if the param is a space.

## Functions to handle strings

- **[`ft_strlen`](src/strings/ft_strlen.c)** - Calculates the length of a string.

- **[`ft_strlcpy`](src/strings/ft_strlcpy.c)** - Copies a string from a buffer to another.

- **[`ft_strlcat`](src/strings/ft_strlcat.c)** - Concatenates two strings in a buffer.

- **[`ft_strchr`](src/strings/ft_strchr.c)** - Locates the first occurrence of a character in a string.

- **[`ft_strrchr`](src/strings/ft_strrchr.c)** - Locates the last occurrence of a character in a string.

- **[`ft_strnrcmp`](src/strings/ft_strncmp.c)**- Compares two strings.

- **[`ft_strnstr`](src/strings/ft_strnstr.c)** - Locates a substring in a string.

- **[`ft_strdup`](src/strings/ft_strdup.c)** - Allocates memory and copies a string.

- **[`ft_strmapi`](src/strings/ft_strmapi.c)** - Applies a function to each character of a string and returns a new string.

- **[`ft_striteri`](src/strings/ft_striteri.c)** - Applies a function to each character of a string.

- **[`ft_substr`](src/strings/ft_substr.c)** - Allocates memory and returns a substring from a string.

- **[`ft_strjoin`](src/strings/ft_strjoin.c)** - Allocates memory and concatenates two strings.

- **[`ft_strtrim`](src/strings/ft_strtrim.c)** - Allocates memory and returns a copy of a string trimmed.

- **[`ft_split`](src/strings/ft_split.c)** - Allocates memory and returns an array of strings obtained by splitting a string using a delimiter.

## Function to handle memory

- **[`ft_memset`](src/memory/ft_memset.c)** - Fills a memory block with a same byte.

- **[`ft_bzero`](src/memory/ft_bzero.c)** - Fill a memory block with '\0'.

- **[`ft_memcpy`](src/memory/ft_memcpy.c)** - Copies a memory area.

- **[`ft_memmove`](src/memory/ft_memmove.c)** - Copies a memory area, even if the memory areas overlap.

- **[`ft_memchr`](src/memory/ft_memchr.c)** - Locates a byte in a memory block.

- **[`ft_memcmp`](src/memory/ft_memcmp.c)** - Compares two memory blocks.

- **[`ft_calloc`](src/memory/ft_calloc.c)** - Allocates memory and fills it with '\0'.

- **[`ft_swap.c`](src/memory/ft_swap.c)** - Swaps two variables.

## Functions to handle math operations

- **[`ft_atoi`](src/math/ft_atoi.c)** - Converts a string to an integer.

- **[`ft_atoi_base`](src/math/ft_atoi_base.c)** - Converts a string to an integer in a given base.

- **[`ft_itoa`](src/math/ft_itoa.c)** - Returns a string representing an integer.

- **[`ft_itoa_base`](src/math/ft_itoa_base.c)** - Returns a string representing an integer in a given base.

- **[`ft_itoa_base_u`](src/math/ft_itoa_base_u.c)** - Returns a string representing an unsigned integer in a given base.

- **[`ft_convert_base`](src/math/ft_convert_base.c)** - Converts a number from a base to another.

- **[`ft_calc_nbr_digits`](src/math/ft_calc_nbr_digits.c)** - Calculates the number of digits of a number.

- **[`ft_abs`](src/math/ft_abs.c)** - Returns the absolute value of a number.

## Functions to handle I/O

- **[`ft_putchar_fd`](src/stdio/ft_putchar_fd.c)** - Writes a character to a file descriptor.

- **[`ft_putstr_fd`](src/stdio/ft_putstr_fd.c)** - Writes a string to a file descriptor.

- **[`ft_putendl_fd`](src/stdio/ft_putendl_fd.c)** - Writes a string to a file descriptor, followed by a newline.

- **[`ft_putnbr_fd`](src/stdio/ft_putnbr_fd.c)** - Writes a int to a file descriptor.

- **[`ft_putmem_fd`](src/stdio/ft_putmem_fd.c)** - Writes a memory block to a file descriptor.

- **[`ft_putnbr_base_fd`](src/stdio/ft_putnbr_base_fd.c)** - Writes a number in a given base to a file descriptor.

- **[`ft_putnbr_unsigned_fd`](src/stdio/ft_putnbr_unsigned_fd.c)** - Writes an unsigned int to a file descriptor.


## Notes

This is an extensible library, so I may add more functions in the future.