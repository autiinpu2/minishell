*This library has been created as part of the 42 curriculum by apuyane, mcomin*

# Description
This Library contain remakes of servals functions from the stdlib.h and others

# Instructions
### Compilation
To compile the library you should run this command
<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style= "color: #00D7FF;">make all</span></code> </pre>
To clean the objects files, you should run this command
<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #00D7FF;">make clean</span></code>
</pre>
To clean the objects as well as the executable, you should run this command
<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #00D7FF;">make fclean</span></code>
</pre>

To recompile the library, you should run this command
<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #00D7FF;">make re</span></code>
</pre>
### Usage
To compile using this program, you have tu run this command
<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #ff7b00ff;">cc program_name libft/libft.a</span></code>
</pre>
# Functions
## is_functions

ft_isalnum

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #0099ffff;">bool           </span><span style="color: #ffffffff;">ft_isalnum(<span style="color: #66D9EF;">int</span> c);</span></code>
</pre>

ft_isalnum_string

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #0099ffff;">bool           </span><span style="color: #ffffffff;">ft_isalnum_string(<span style="color: #66D9EF;">char *</span>s);</span></code>
</pre>

ft_isalpha

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #0099ffff;">bool           </span><span style="color: #ffffffff;">ft_isalpha(<span style="color: #66D9EF;">int</span> c);</span></code>
</pre>

ft_isascii

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #0099ffff;">bool           </span><span style="color: #ffffffff;">ft_isascii(<span style="color: #66D9EF;">int</span> c);</span></code>
</pre>

ft_isdigit

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #0099ffff;">bool           </span><span style="color: #ffffffff;">ft_isdigit(<span style="color: #66D9EF;">int</span> c);</span></code>
</pre>

ft_contain_digit_only

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #0099ffff;">bool           </span><span style="color: #ffffffff;">ft_contain_digit_only(<span style="color: #66D9EF;">char *</span>s);</span></code>
</pre>

ft_isprint

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #0099ffff;">bool           </span><span style="color: #ffffffff;">ft_isprint(<span style="color: #66D9EF;">int</span> c);</span></code>
</pre>

ft_isspace

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #0099ffff;">bool           </span><span style="color: #ffffffff;">ft_isspace(<span style="color: #66D9EF;">char </span>c);</span></code>
</pre>
## to_functions

ft_tolower

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_tolower(<span style="color: #66D9EF;">int</span> c);</span></code>
</pre>

ft_toupper

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_toupper(<span style="color: #66D9EF;">int</span> c);</span></code>
</pre>
ascii/int conversions

ft_atoi

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_atoi(<span style="color: #66D9EF;">const char *</span>nptr);</span></code>
</pre>

ft_strtol

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">long         </span><span style="color: #ffffffff;">ft_strtol(<span style="color: #66D9EF;">const char *</span>nptr, <span style="color: #66D9EF;">char **</span>endptr);</span></code>
</pre>

ft_strtoll

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">long long        </span><span style="color: #ffffffff;">ft_strtoll(<span style="color: #66D9EF;">const char *</span>nptr, <span style="color: #66D9EF;">char **</span>endptr);</span></code>
</pre>

ft_itoa

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_itoa(<span style="color: #66D9EF;">int</span> n);</span></code>
</pre>
## memory functions

ft_memchr

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">void         *</span><span style="color: #ffffffff;">ft_memchr(<span style="color: #66D9EF;">const void *</span>s, <span style="color: #66D9EF;">int </span>c, <span style="color: #ffc400ff;">size_t </span>n);</span></code>
</pre>

ft_memcmp

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_memcmp(<span style="color: #66D9EF;">const void *</span>s1, <span style="color: #66D9EF;">const void *</span>s2, <span style="color: #ffc400ff;">size_t </span>n);</span></code>
</pre>

ft_memcpy

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">void         *</span><span style="color: #ffffffff;">ft_memcpy(<span style="color: #66D9EF;">void *</span>dest, <span style="color: #66D9EF;">const void *</span>src, <span style="color: #ffc400ff;">size_t </span>n);</span></code>
</pre>

ft_memmove

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">void         *</span><span style="color: #ffffffff;">ft_memmove(<span style="color: #66D9EF;">void *</span>dest, <span style="color: #66D9EF;">const void *</span>src, <span style="color: #ffc400ff;">size_t </span>n);</span></code>
</pre>

ft_memset

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">void         *</span><span style="color: #ffffffff;">ft_memset(<span style="color: #66D9EF;">void *</span>s, <span style="color: #66D9EF;">int </span>c, <span style="color: #ffc400ff;">size_t </span>n);</span></code>
</pre>

ft_bzero

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">void         </span><span style="color: #ffffffff;">ft_bzero(<span style="color: #66D9EF;">void *</span>s, <span style="color: #ffc400ff;">size_t </span>n);</span></code>
</pre>

ft_calloc

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">void         *</span><span style="color: #ffffffff;">ft_calloc(<span style="color: #ffc400ff;">size_t </span>nmemb, <span style="color: #ffc400ff;">size_t </span>size);</span></code>
</pre>
## string manipulation

ft_strlen

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_strlen(<span style="color: #66D9EF;">char *</span>str);</span></code>
</pre>

ft_strchr

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_strchr(<span style="color: #66D9EF;">const char *</span>s, <span style="color: #66D9EF;">int </span>c);</span></code>
</pre>

ft_strrchr

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_strrchr(<span style="color: #66D9EF;">const char *</span>s, <span style="color: #66D9EF;">int </span>c);</span></code>
</pre>

ft_strnstr

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_strnstr(<span style="color: #66D9EF;">const char *</span>big, <span style="color: #66D9EF;">const char *</span>little, <span style="color: #ffc400ff;">size_t </span>len);</span></code>
</pre>

ft_strcmp

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_strcmp(<span style="color: #66D9EF;">const char *</span>s1, <span style="color: #66D9EF;">const char *</span>s2);</span></code>
</pre>

ft_strncmp

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_strncmp(<span style="color: #66D9EF;">const char *</span>s1, <span style="color: #66D9EF;">const char *</span>s2, <span style="color: #ffc400ff;">size_t </span>n);</span></code>
</pre>

ft_strlcpy

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #ffc400ff;">size_t         </span><span style="color: #ffffffff;">ft_strlcpy(<span style="color: #66D9EF;">char *</span>dst, <span style="color: #66D9EF;">const char *</span>src, <span style="color: #ffc400ff;">size_t </span>size);</span></code>
</pre>

ft_strlcat

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #ffc400ff;">size_t         </span><span style="color: #ffffffff;">ft_strlcat(<span style="color: #66D9EF;">char *</span>dst, <span style="color: #66D9EF;">const char *</span>src, <span style="color: #ffc400ff;">size_t </span>size);</span></code>
</pre>

ft_strdup

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_strdup(<span style="color: #66D9EF;">const char *</span>s);</span></code>
</pre>
string transformation

ft_substr

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_substr(<span style="color: #66D9EF;">char const *</span>s, <span style="color: #66D9EF;">unsigned int </span>start, <span style="color: #ffc400ff;">size_t </span>len);</span></code>
</pre>

ft_strjoin

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_strjoin(<span style="color: #66D9EF;">char *</span>s1, <span style="color: #66D9EF;">char *</span>s2);</span></code>
</pre>

ft_strjoin_free

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_strjoin_free(<span style="color: #66D9EF;">char *</span>s1, <span style="color: #66D9EF;">char *</span>s2);</span></code>
</pre>

ft_strjoin_tab

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_strjoin_tab(<span style="color: #66D9EF;">char **</span>tab);</span></code>
</pre>

ft_strtrim

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">ft_strtrim(<span style="color: #66D9EF;">char const *</span>s1, <span style="color: #66D9EF;">char const *</span>set);</span></code>
</pre>

ft_split

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         **</span><span style="color: #ffffffff;">ft_split(<span style="color: #66D9EF;">char const *</span>s, <span style="color: #66D9EF;">char </span>c);</span></code>
</pre>
## Output functions

ft_dprintf

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_dprintf(<span style="color: #66D9EF;">int </span>fd, <span style="color: #66D9EF;">const char *</span>format, ...);</span></code>
</pre>

ft_putchar_fd

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_putchar_fd(<span style="color: #66D9EF;">char </span>c, <span style="color: #66D9EF;">int </span>fd);</span></code>
</pre>

ft_putnbr

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_putnbr(<span style="color: #66D9EF;">int </span>nb);</span></code>
</pre>

ft_putnbr_fd

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_putnbr_fd(<span style="color: #66D9EF;">int </span>nb, <span style="color: #66D9EF;">int </span>fd);</span></code>
</pre>

ft_putstr_fd

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">int              </span><span style="color: #ffffffff;">ft_putstr_fd(<span style="color: #66D9EF;">char *</span>str, <span style="color: #66D9EF;">int </span>fd);</span></code>
</pre>

ft_putendl_fd

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">void             </span><span style="color: #ffffffff;">ft_putendl_fd(<span style="color: #66D9EF;">char *</span>s, <span style="color: #66D9EF;">int </span>fd);</span></code>
</pre>
## Input functions

get_next_line

<pre style="background-color: #202020ff; padding: 10px; border-radius: 5px;">
<code style="margin-left: 35px;"><span style="color: #66D9EF;">char         *</span><span style="color: #ffffffff;">get_next_line(<span style="color: #66D9EF;">int </span>fd);</span></code>
</pre>
