# Code Design

## C++ Version

* Currently, code should target [C++17 standard](https://en.cppreference.com/w/cpp/compiler_support), i.e., should not
use C++2x features yet. The C++ version targeted by this guide will advance (aggressively) over time
* Do not use non-standard extensions
* Consider portability to other environments before using features from C++14 and C++17 in your project

## Header Files

* In general, every .cpp file should have an associated .hpp file
* Correct use of header files can make a huge difference to the readability, size and performance of your code
* We use #pragma include guards
```
#pragma once
```
* Include headers in the following order: Related header, C system headers, C++ standard library headers, other libraries' headers, your project's headers
* All of a project's header files should be listed as descendants of the project's source directory without use of UNIX directory aliases . (the current directory) or .. (the parent directory)

## Namespaces
* Like every other module of Inexor the entity system uses namespaces:

```
namespace inexor {
namespace entity_system {
   // Code here..
};
};
```
* Namespaces wrap the entire source file after includes and forward declarations of classes from other namespaces.

## Class design
TODO

## Standard Libraries
The following standard libraries will be used in the code:

* [std::string](https://en.cppreference.com/w/cpp/string/basic_string)
* [std::vector](https://en.cppreference.com/w/cpp/container/vector)
* [std::unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)
* [std::shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr)
* [std::chrono](https://en.cppreference.com/w/cpp/chrono)
* [std::optional](https://en.cppreference.com/w/cpp/utility/optional)

## Code Formating
We use [clang format](https://clang.llvm.org/docs/ClangFormat.html) for source code formatting.

A .clang-format file is placed in the project tree. The is some support for automatically use the code formatter:
* [CLion](https://www.jetbrains.com/help/clion/clangformat-as-alternative-formatter.html), [code assistance](https://blog.jetbrains.com/clion/2019/05/clion-starts-2019-2-eap-parameter-hints-go-to-address-code-assistance-for-clangformat/)

## Multithreading
TODO

