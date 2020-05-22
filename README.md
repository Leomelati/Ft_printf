# Printf - 42 São Paulo
***Because putnbr and putstr aren’t enough***

One of the first projects is the recoding of the Printf function because 42 Students can't use a huge part of the built-in functions that C provides. The reimplementation will cover the following points:

- It must not do the buffer management like the real printf
- It will manage the following conversions:

| Conversion  | Description                                |
|-------------|------------------------------------------  |
| c           | Character                                  |
| s           | String of characters                       |
| p(WIP)           | Pointer Address                            |
| d           | Signed decimal integer                     |
| i           | Signed decimal integer                     |
| u           | Unsigned decimal integer                   |
| x           | Unsigned hexadecimal integer               |
| X           | Unsigned hexadecimal integer (uppercase)   |
| %           | Two followed "%" will write a "%"          |

- It will manage any combination of the following flags:

| Flags  | Description                                                   |
|--------|-------------------------------------------------------------  |
| -(WIP)      | Left-justify within the given field width                |
| 0(WIP)      | Left-pads the number with zeroes (0) instead of spaces   |
| +(WIP)      | Preceed the result with a "+" for positive numbers       |
| #(WIP)      | Alternate input method for placeholder                   |

- It will manage minimum field width with all conversions

## Getting Started

The library that contains the ft_printf function will be ready to use after the compilation process. To do so, just use `make` command at the root of the repository and it will create a `libftprintf.a`file.

## Libft Disclaimer

Don't jump into the Libft folder! It is the first project that we made at 42 School and it contains a lot of functions that we need to recode to use it during other projects. To avoid confusion I will advise you to just see the functions that are used in this project that are listed below.

- [Ft_putnbr_fd](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_putnbr_fd.c)
- [Ft_putnbr_uns_fd](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_putnbr_uns_fd.c)
- [Ft_putstr_fd](https://github.com/Leomelati/Ft_printf/blob/master/Libft/ft_putstr_fd.c)
