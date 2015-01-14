#!/bin/sh
sed -i 's/\/\/ #define DUMB_LOGGING_NO_MACROS/#define DUMB_LOGGING_NO_MACROS/' logging.h
sed -i 's/\/\/ #define DUMB_LOGGING_FUNCTIONS/#define DUMB_LOGGING_FUNCTIONS/' logging.h
