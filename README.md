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
4. If initialization succeeds, you can begin logging.
```cpp
logger.log("variable_name", variable);
```
5. Flush when finished
```cpp
logger.flush();
```
**Example**
```cpp
#include "matlogger/logger.hpp"
int main()
{
    Logger logger("my_log", "/path/to/output");
    for (int i = 0; i < 100; ++i)
    {
        logger.log("index", i);
    }
    logger.flush();
    return 0;
}
```
### Console Styling (`std::cout` / `std::cerr`)
1. Include the header file. 
```cpp
#include "console/customised_console.hpp"
```
2. Use the functions:

**Examples**
```cpp
ilog::info("information msg");
ilog::error("error msg");
```
