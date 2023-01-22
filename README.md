# CM-Makefile Examples

This repository contains set of "Hello World" (which is usually led blinking in
the embedded world) examples for Cortex-M microcontrollers using the
[Arm GNU Toolchain][1]. It's aim is to demonstrate how to use the
[CM-Makefile][2] template in custom projects.

Although the repository contains pre-configured examples for a few particular
MCUs and board, the [CM-Makefile][2] can be easily used with other boards or
other vendors' SDKs as well.

## Usage

To compile the project, simply run `make` in its source directory. To flash the
compiled binary to the target MCU, run `make flash`:

	cd stm32-cube
	make
	make flash

The complete usage is described in [CM-Makefile][2]'s `README` file. Moreover,
all examples have their own `README` with target-specific information (e.g. how
to obtain required libraries).

The base repository also contains [installation instructions][3] for the
cross-compilation toolchain.

## License

CM-Makefile is free software: you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

See `COPYING` and `COPYING.LESSER` for details.

[1]: https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain
[2]: https://github.com/adamheinrich/cm-makefile
[3]: https://github.com/adamheinrich/cm-makefile/blob/master/INSTALL.md
