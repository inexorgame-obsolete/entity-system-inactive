# Inexor entity-system prototype
[![Build Status](https://travis-ci.org/inexorgame/entity-system.svg?branch=master)](https://travis-ci.org/inexorgame/entity-system)

Inexor used to be a fork of the open-source First-Person-Shooter Cube 2: Sauerbraten, a fast-paced shooting game featuring an in-game map editor.
In contrast to Sauerbraten, Inexor adds a lot of functionality and strives to stay open to improvements and suggestions.
The goal of this project is to be more flexible and create an environment where development is easy, fast and where creativity can prosper.


## How is Inexor organized?

We are a non-hierarchical organization. This means we are simply a group of people with different ideas working together without a leader making all the decisions. Anyone of us is free to work on the particular things they want to.
For this organization to work properly we rely on good communication. We are on Telegram and Mumble pretty much everyday. Every so often we organize official Mumble meetings to discuss our roadmap and strategies.

We are open for new people!

## Where are we headed?

Our goal is to make the game as moddable and developer-friendly as possible.
Even though we might have refactored most of the code at some point, Inexor should always feel like Sauerbraten gameplay wise.

A popular stance among the Sauerbraten community is "that's impossible", and this is what we want to prove wrong. Our answer to remarks like "things are best like they are" is: standing still means falling behind.

## The entity-system

The entity-system will lay the basis on the other systems of the game will be built on.
For more information take a look at the [wiki](https://inexor.org/wiki/features/Entity-System.html).

## Build process

Building the `entity-system` is quite straightforward:

### Prerequirements

To build the entity-system one needs:

- a compiler of choice (`gcc`, `clang`, `MSVC`)
- `cmake`
- [`conan`](https://conan.io)

### Building

- `mkdir build && cd build`
- `cmake ..` (creates project files, can also be done via gui)
- `cmake --build .` (compiles the project)

### Documentation

You need to run `doxygen` (retrievable from http://doxygen.nl/) inside this folder to create the docs at the moment, like so:

`doxygen . `

## Join us

You have already accomplished the first step by reading this readme. Congratz!

The second one is only slightly harder by joining us in [Telegram](https://t.me/inexor), consider the [contact](https://inexor.org/wiki/Contact.html) page in our wiki for more ways to chat.

To contribute to the project and merge your changes into the master branch you need to convince enough members that the changes are an improvement.
It probably won't be an issue. However you should still communicate what you're doing and why you are doing it and of course take feedback and tips from others into account.

More information about the contributing process can be found [here](https://github.com/inexorgame/inexor-core/wiki/How-To-Contribute-Code).
