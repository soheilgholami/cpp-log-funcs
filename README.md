# Customised Loggers 

This repository provides two lightweight wrappers:
1. **Matrix/variable logging**: it logs [Eigen](https://libeigen.gitlab.io/)-based matrices and vectors, as well as scalar variables of type `double` (e.g. time).
2. **Console styling**: it customises `std::cout` and `std::cerr` output (e.g. adding colors).

## Dependencies

- [matlogger2](https://github.com/ADVRHumanoids/MatLogger2)
- [Eigen](https://libeigen.gitlab.io/)

## Usage
### Matrix/variable logging
1. Install matlogger2: Follow the build instructions in the [MatLogger2 repository](https://github.com/ADVRHumanoids/MatLogger2)
2. Include the header file. This gives you access to the `Logger` class.
```cpp
#include "matlogger/logger.hpp"
```
3. Create a logger object (by providing a name and a directory for the output file)
```cpp
Logger logger(name, directory);
```
