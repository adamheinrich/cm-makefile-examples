The [STM32Cube][1] library is included as a submodule. It is compiled
automatically when running `make`. However, it needs to be initialized first:

	git submodule update --init
	make

[1]: https://github.com/STMicroelectronics/STM32CubeF0
