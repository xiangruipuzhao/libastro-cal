# libastro-cal

A simple astronomical algorithm library based on astro-rust project in C.

# Online documentation

https://faraco.github.io/libastro-cal/html/index.html

## Getting Started

### Prerequisites

* gcc
* make
* autotools
    - automake
    - autoreconf
    - libtool
    - autoconf

## Building the static library (libastro-cal.a)

> Run `autoreconf --install` in the main directory to initialize autotools build files.


After you follow the instruction above, execute the command below in order

1. ./configure

2. make

At this point, you can use the local generated static library in *src* to build your programs/softwares. For example:
    
```sh
    cd src

    # note, you'll need libmath (-lm) to compile the library properly!
    gcc my_program.c -o my_program libastro-cal.a -lm
```

or if you prefer to access the library globally, then run

```sh

    cd src
    sudo cp libastro-cal.a /usr/lib
```


and then you can test it by compiling an asteroid_diameter program in *examples/* which uses the globally located static library. Please follow the README.md in *examples/* directory for instructions on how to build.

## Running the tests

Go to *tests/* directory, and follow the instructions in README.md to build and run the tests.

## Authors
* faraco <skelic3@gmail.com>
        
## License
This project is licensed under the GPL3 License - see the LICENSE file for details.

    
