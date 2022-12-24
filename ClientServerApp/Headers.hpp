#ifndef PMVANKERSOCKET_GLOBAL_H
#define PMVANKERSOCKET_GLOBAL_H

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#  define Q_DECL_EXPORT __declspec(dllexport)
#  define Q_DECL_IMPORT __declspec(dllimport)
#else
#  define Q_DECL_EXPORT     __attribute__((visibility("default")))
#  define Q_DECL_IMPORT     __attribute__((visibility("default")))
#endif

#if defined(PMVANKERSOCKET_LIBRARY)
#  define PMVANKERSOCKET_EXPORT Q_DECL_EXPORT
#else
#  define PMVANKERSOCKET_EXPORT Q_DECL_IMPORT
#endif

#include <sys/types.h>  /* Primitive System Data Types */
#include <sys/socket.h> /* Declarations of socket constants, types, and functions */
#include <arpa/inet.h>
#include <unistd.h> /*Symbolic Constants*/

#include <iostream>  /* Standard iostream objects -*- C++ -*- */
#include <string>    /*Standard C++ Library header*/
#include <map>
#include <array>
#include <vector>
#include <thread>
#include <exception> /*Exception Handling support header for -*- C++ -*-*/
#include <stdexcept> /*Standard exception classes  -*- C++ -*-*/

#endif // PMVANKERSOCKET_GLOBAL_H
