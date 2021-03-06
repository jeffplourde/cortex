[![Build Status](https://travis-ci.org/cortexlang/cortex.svg?branch=master)](https://travis-ci.org/Seldomberry/cortex) [![Coverity](https://scan.coverity.com/projects/3807/badge.svg)](https://scan.coverity.com/projects/3807) [![Join the chat at https://gitter.im/cortexlang/cortex](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/cortexlang/cortex?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

An open source, easy to use, multi-language CRUD API and scripting language for connecting to your technology stack.

Cortex is in alpha. It is expected to reach v1.0 status by the end of 2015. The project has been validated on the following platforms:
 * Ubuntu 14.04 (32/64 bit)
 * OS X 10.10.2 (64 bit)

## Building Cortex
Download and unpack Cortex on your machine. Run the following command to build it:
```
source configure; rake
```
#### Dependencies
Cortex depends on the following packages - make sure to have them installed:
 * flex
 * bison
 * libxml2-dev (only required for building)
 * rake
