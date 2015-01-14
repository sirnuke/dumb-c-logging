// Dumb C/C++ Logging
// Original Author: Bryan DeGrendel
//
// This is free and unencumbered software released into the public domain.
// 
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
// 
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
// 
// For more information, please refer to <http://unlicense.org>

#ifndef ___DUMB_LOGGING_H___
#define ___DUMB_LOGGING_H___

/// Uncomment to disable all macros.
// #define DUMB_LOGGING_NO_MACROS
/// Uncomment to enable short macros.  V(...), T(...), etc.
// #define DUMB_LOGGING_SHORT_MACROS
/// Uncomment to enable medium  macros.  VERBOSE(....), TODO(...), etc.
#define DUMB_LOGGING_MEDIUM_MACROS
/// Uncomment to enable global functions.  verbose(...), todo(...), etc.
/// Less convenient than a macro, but if preprocessor macros make your
/// skin crawl...
// #define DUMB_LOGGING_FUNCTIONS

/// Set to the output stream.  Presumably stderr or stdout, maybe a
/// global FILE * variable.
#define DUMB_LOGGING_STREAM stderr
/// Set the minimum length of the tag.  Default covers "[VERBOSE] ".
#define DUMB_LOGGING_TAG_PADDING 10
/// Set the minimum length of the output heading padding.  Longer wastes
/// space but helps everything line up properly.
#define DUMB_LOGGING_FULL_PADDING 44

#if (defined DUMB_LOGGING_SHORT_MACROS) && !(defined DUMB_LOGGING_NO_MACROS)
#define T DUMB_LOGGING_TODO
#define V DUMB_LOGGING_VERBOSE
#define I DUMB_LOGGING_INFO
#define W DUMB_LOGGING_WARN
#define E DUMB_LOGGING_ERROR
#undef DUMB_LOGGING_SHORT_MACROS
#endif // DUMB_LOGGING_SHORT_MACROS && !DUMB_LOGGING_NO_MACROS

#if (defined DUMB_LOGGING_MEDIUM_MACROS) && !(defined DUMB_LOGGING_NO_MACROS)
#define TODO DUMB_LOGGING_TODO
#define VERBOSE DUMB_LOGGING_VERBOSE
#define INFO DUMB_LOGGING_INFO
#define WARN DUMB_LOGGING_WARN
#define ERROR DUMB_LOGGING_ERROR
#undef DUMB_LOGGING_MEDIUM_MACROS
#endif // DUMB_LOGGING_MEDIUM_MACROS && !DUMB_LOGGING_NO_MACROS

#ifndef DUMB_LOGGING_NO_MACROS
#define DUMB_LOGGING_TODO(MESSAGE, ...) \
  dumb_logging("TODO", __LINE__, __FUNCTION__, TAG, MESSAGE, ##__VA_ARGS__)
#define DUMB_LOGGING_VERBOSE(MESSAGE, ...) \
  dumb_logging("Verbose", __LINE__, __FUNCTION__, TAG, MESSAGE, ##__VA_ARGS__)
#define DUMB_LOGGING_INFO(MESSAGE, ...) \
  dumb_logging("Info" , __LINE__, __FUNCTION__, TAG, MESSAGE, ##__VA_ARGS__)
#define DUMB_LOGGING_WARN(MESSAGE, ...) \
  dumb_logging("Warn", __LINE__, __FUNCTION__, TAG, MESSAGE, ##__VA_ARGS__)
#define DUMB_LOGGING_ERROR(MESSAGE, ...) \
  dumb_logging("Error", __LINE__, __FUNCTION__, TAG, MESSAGE, ##__VA_ARGS__)
#else // !DUMB_LOGGING_NO_MACROS

#ifdef DUMB_LOGGING_MEDIUM_MACROS
#undef DUMB_LOGGING_MEDIUM_MACROS
#endif
#ifdef DUMB_LOGGING_SHORT_MACROS
#undef DUMB_LOGGING_SHORT_MACROS
#endif
#undef DUMB_LOGGING_NO_MACROS

#endif // !DUMB_LOGGING_NO_MACROS

#ifdef __cplusplus
#include <cstdio>
#include <cstdarg>
#else // __cplusplus
#include <stdio.h>
#include <stdarg.h>
#endif // __cplusplus

#ifdef DUMB_LOGGING_FUNCTIONS
#define DUMB_LOGGING_FUNCTION_IMPL(NAME, LEVEL) \
static void NAME(const int line, const char *function, const char *tag, \
    const char *format, ...) \
{ \
  va_list args; \
  va_start(args, format); \
  dumb_logging_perform(LEVEL, line, function, tag, format, args); \
  va_end(args); \
}

static void dumb_logging_perform(const char *level, const int line,
    const char *function, const char *tag, const char *format, va_list args)
{

#else // DUMB_LOGGING_FUNCTIONS
static void dumb_logging(const char *level, const int line, const char *function,
    const char *tag, const char *format, ...)
{
  va_list args;
  va_start(args, format);
#endif // DUMB_LOGGING_FUNCTIONS
  int len = fprintf(DUMB_LOGGING_STREAM, "[%s] ", level);
  int pad = DUMB_LOGGING_TAG_PADDING - len;
  if (pad > 0) len += fprintf(DUMB_LOGGING_STREAM, "%*s", pad, " ");
  len += fprintf(DUMB_LOGGING_STREAM, "%s:%s@%i  ", tag, function, line);
  pad = DUMB_LOGGING_FULL_PADDING - len;
  if (pad > 0) fprintf(DUMB_LOGGING_STREAM, "%*s", pad, " ");
  vfprintf(DUMB_LOGGING_STREAM, format, args);
  fprintf(DUMB_LOGGING_STREAM, "\n");
#ifdef DUMB_LOGGING_FUNCTIONS
  va_end(args);
#endif // DUMB_LOGGING_FUNCTIONS
}

#ifdef DUMB_LOGGING_FUNCTIONS

static void dumb_logging(const char *level, const int line, const char *function,
    const char *tag, const char *format, ...)
{
  va_list args;
  va_start(args, format);
  dumb_logging_perform(level, line, function, tag, format, args);
  va_end(args);
}

DUMB_LOGGING_FUNCTION_IMPL(todo, "TODO");
DUMB_LOGGING_FUNCTION_IMPL(verbose, "Verbose");
DUMB_LOGGING_FUNCTION_IMPL(info, "Info");
DUMB_LOGGING_FUNCTION_IMPL(warn, "Warn");
DUMB_LOGGING_FUNCTION_IMPL(error, "Error");
#undef DUMB_LOGGING_FUNCTION_IMP
#undef DUMB_LOGGING_FUNCTIONS
#endif // DUMB_LOGGING_FUNCTIONS

#undef DUMB_LOGGING_STREAM
#undef DUMB_LOGGING_TAG_PADDING
#undef DUMB_LOGGING_FULL_PADDING

#endif // ___DUMB_LOGGING_H___
