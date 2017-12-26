The [libopencm3][1] library is included as a submodule. It is compiled
automatically when running `make`. However, it needs to be initialized first:

	git submodule update --init
	make

To build just the library, run `make deps` or `make libopencm3`. To clean both
the example program and files built in the the library folder, run
`make distclean`.

It is also possible to build the library manually (however, it will use its
default configuration instead of passing parameters defined in the local
Makefile):

	git submodule update --init
	cd libopencm3
	make

[1]: https://github.com/libopencm3/libopencm3
