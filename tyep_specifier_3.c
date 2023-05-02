/**
* String_setter - print value of not printable char
* @valist: string
* Return: length of the string
*/
int String_setter(va_list valist)
{
	int i = 0;
	int size = 0;
	unsigned char *str;

	str = va_arg(valist, unsigned char *);
	if (str == NULL)
	{
		_putstr("\\x00");
		return (4);
	}
	while (str[i])
	{
		if ((str[i] < 32 || str[i] >= 127) && str[i])
		{
			_putstr("\\x");
			hex_upp_setter(str[i], &size);
			size += 2;
			i++;
		}
		else
		{
			_putchar(str[i]);
			i++;
			size++;
		}
	}
	return (size);
}
/**
 * pointer_setter - Print a number in hexadecimal format
 * @valist: Number to print
 *
 * Return: Length of the number;
 **/
int pointer_setter(va_list valist)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(valist, unsigned long int), 16);

	if (!_strcmp(p_buff, "0"))
		return (print("(nil)"));

	size = print("0x");

	if (!_strcmp(p_buff, "-1"))
		size += print("ffffffffffffffff");
	else
		size += print(p_buff);

	return (size);
}
/**
* rev_string_setter - prints astring in reverse
* @valist: string to print
* Return: number of chars printed;
*/
int rev_string_setter(va_list valist)
{
	char *st;
	int i, j = 0;

	st = va_arg(valist, char *);
	if (st == NULL)
		st = ")llun(";
	for (i = 0; st[i] != '\0'; i++)
		;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(st[i]);
		j++;
	}
	return (j);
}
/**
 * rot13 - Encodes a string using rot13.
 * @s: String to enconde
 * Return: String encode
 */
int rot13(char *s)
{
	int i, j;
	char *input, *output;

	input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; input[j] != '\0'; j++)
		{
			if (s[i] == input[j])
			{
				_putchar(output[j]);
				break;
			}
		}

		if (!input[j])
			_putchar(s[i]);
	}
	return (i);
}
/**
  * rot_setter - encodes a string into rot13.
  * @valist: string to convert
  * Return: size the output text;
  */
int rot_setter(va_list valist)
{
	char *p;
	int p_len;

	p = va_arg(valist, char *);
	p_len = rot13((p != NULL) ? p : "(ahyy)");

	return (p_len);
}
