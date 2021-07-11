# tempclc
Command-line utility for temperature conversion

I was basically bored when developing this and just wanted to test out more advanced input parsing in C++. Got something suprisingly useful in result.

# Compilation and installation
Classically:

```
$ make
$ sudo make install
```

# Usage

```
Usage: tempclc [-uv] value<c|C|f|F>

-u, --units    Show units in output
-v, --verbose  Show output as XX = YY
-h, --help     Print this help message and exit
```

# Examples

Convert 32 Fahrenheit to Celcius:

```
$ tempclc 32F
0
```

Convert 100 Celcius to Fahrenheir and display the unit in output:

```
$ tempclc -u 100C
212°F
```

Convert 59 Fahrenheit to Celcius, include input in the output and present it with units:
```
$ $ tempclc -u -v 59F
59°F = 15°C
```

# Credits

- [Simon Schneegans](http://schneegans.github.io/) for his outstanding lightweight [parsing class](http://schneegans.github.io/tutorials/2019/08/06/commandline)
