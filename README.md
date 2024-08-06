# Dynamic C String using Stretchy Buffers

This repository provides a dynamic string implementation in C using stretchy buffers. Stretchy buffers automatically resize as elements are added, providing a convenient way to handle dynamic arrays in C. Every time the buffer is full, it doubles the capacity.

## License

This project is released under the [Unlicense](http://unlicense.org/), which means it is free and unencumbered software released into the public domain.

## Author

GiovanyH

GitHub: [GiovanyH](https://github.com/GiovanyH)

## Usage

### Example Code

Below is an example of how to use the dynamic string implementation:

```c
int main(void) {
	char* string = string_new("Hello, World!");

	append_string(&string, "Teste");

	printf("string: %s\n", string);

	free(vec_get_hdr(string));
}
```
```
"Hello, World!Teste"
```

### Functions and Macros

- **new_vector(type, v)**: Declares a new vector of the specified type.
- **vec_get_capacity(v)**: Returns the current capacity of the vector.
- **vec_get_len(v)**: Returns the current length of the vector.
- **append_string(&v, string)**: Appends the specified string to the vector.
- **vec_free(v)**: Frees the memory allocated for the vector.

## How It Works

The dynamic string implementation uses stretchy buffers that automatically resize when more space is needed. The capacity of the buffer doubles each time it becomes full, ensuring efficient memory allocation and append operations.

## Contributing

Feel free to fork this repository and contribute by submitting pull requests. Any enhancements, bug fixes, or suggestions are welcome.

## Acknowledgements

This implementation is inspired by the need for efficient dynamic string handling in C, utilizing stretchy buffers for automatic resizing.
