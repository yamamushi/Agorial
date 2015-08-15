# Agorial

Agorial aims to be a Multiplayer Roguelike World Simulator. 

Planned features of Agorial include:

 * A fully persistent procedurally generated world.
 * Perma-death for NPC's and Players alike.
 * Water Simulation.
 * Sound propagation and detection.
 * A full featured sandbox world.
 * An Open World Economy supported by [Open Transactions](https://github.com/open-transactions/opentxs).
 * Vehicles for Land, Water and Air travel.
 * Generated Religions and Philosophies.
 * And much more!

### Dependencies:

 * [Boost >= 1.51](https://github.com/boostorg/boost)
 * [SDL 1.2](https://www.libsdl.org/download-1.2.php)
 * [libtcod 1.5](https://bitbucket.org/libtcod/libtcod) or [libtcod-osx 1.5](https://github.com/podiki/libtcod-mac)
 * [CMake 3](http://www.cmake.org/)
 * [ZMQ 4](https://github.com/zeromq/zeromq4-x)
 * [CZMQ](https://github.com/zeromq/czmq)
 * [libsodium](https://github.com/jedisct1/libsodium)
 * [MessagePack](https://github.com/msgpack/msgpack-c)
 * [A C++11 Compatible Compiler](http://en.cppreference.com/w/cpp/compiler_support)

### Building Agorial:

Agorial uses the CMake build system.

```
$ git clone git@github.com:yamamushi/Agorial
$ cd Agorial
$ mkdir build && cd build
$ cmake .. && make -j4 
```
The built binary will be placed into the **build/bin/** directory, an install path is not provided at this time.


### Launching Agorial:

The Agorial Client comes with a default configuration file which can be modified to suit your individual needs.

Configuration files are placed into the ~/.agorial/ directory by default. (This will be updated soon)

After you have verified your config is properly setup, you may launch Agorial as follows:
```
Agorial -c /path/to/agorial.conf (defaults to ~/.agorial/agorial.conf)
```

The Agorial server can be launched with similar attributes, however it is not compatible with the client config file.
