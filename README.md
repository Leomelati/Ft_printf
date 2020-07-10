# Printf - 42 São Paulo
***Because putnbr and putstr aren’t enough***

One of the first projects is the recoding of the Printf function because 42 Students can't use a huge part of the built-in functions that C provides. The reimplementation will cover the following points:

- It must not do the buffer management like the real printf
- A format specifier follows this prototype: %\[flags\]\[width\]\[.precision\]specifier
- It will manage the following conversions:

| Specifier  | Description                                |
|-------------|------------------------------------------  |
| c           | Character                                  |
| s           | String of characters                       |
| p           | Pointer Address                            |
| d           | Signed decimal integer                     |
| i           | Signed decimal integer                     |
| u           | Unsigned decimal integer                   |
| x           | Unsigned hexadecimal integer               |
| X           | Unsigned hexadecimal integer (uppercase)   |
| %           | Two followed "%" will write a "%"          |

- It will manage any combination of the following flags:

| Flags  | Description                                                   |
|--------|-------------------------------------------------------------  |
| -      | Left-justify within the given field width                |
| 0      | Left-pads the number with zeroes (0) instead of spaces   |
| +      | Preceed the result with a "+" for positive numbers       |
| #      | Alternate input method for placeholder                   |

- It will manage minimum field width with all conversions

## Getting Started

The library that contains the ft_printf function will be ready to use after the compilation process. To do so, just use `make` command at the root of the repository and it will create a `libftprintf.a`file.

## Libft Disclaimer

Don't jump into the Libft folder! It is the first project that we made at 42 School and it contains a lot of functions that we need to recode to use it during other projects. To avoid confusion I will advise you to just see the functions that are used in this project that are listed below.

- [Ft_atoi](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_atoi.c)
- [Ft_itoa](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_itoa.c)
- [Ft_itoa_uns](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_itoa_uns.c)
- [Ft_strchr](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_strchr.c)
- [Ft_isdigit](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_isdigit.c)
- [Ft_hexlen](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_hexlen.c)
- [Ft_strlen](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_strlen.c)
