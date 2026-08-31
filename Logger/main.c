#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Severity {
  LOG_SEVERITY_INFO,
  LOG_SEVERITY_WARN,
  LOG_SEVERITY_ERROR,
  LOG_SEVERITY_FATAL
};

void logger_log(enum Severity severity, const char *msg, ...) {
  char mssage[8000];
  char buffer[8000];
  va_list list;

  va_start(list, msg);
  vsnprintf(buffer, sizeof(buffer), msg, list);
  va_end(list);

  if (severity == LOG_SEVERITY_INFO) {
    strcpy(mssage, "[INFO] ");
  } else if (severity == LOG_SEVERITY_WARN) {
    strcpy(mssage, "[WARN] ");
  } else if (severity == LOG_SEVERITY_ERROR) {
    strcpy(mssage, "[ERROR] ");
  } else if (severity == LOG_SEVERITY_FATAL) {
    strcpy(mssage, "[FATAL] ");
  }

  strcat(mssage, buffer);
  printf("%s\n", mssage);

  if (severity == LOG_SEVERITY_FATAL) {
    exit(1);
  }

  if (severity == LOG_SEVERITY_ERROR) {
    getchar();
  }
}

void report_assertion_failure(const char *expression, const char *message,
                              const char *file, int line) {
  logger_log(LOG_SEVERITY_FATAL,
             "Assertion Failure: %s, message: %s, in file: %s, line: %d",
             expression, message, file, line);
}

#define ASSERT(expr, message)                                                  \
  do {                                                                         \
    if (!(expr)) {                                                             \
      report_assertion_failure(#expr, message, __FILE__, __LINE__);            \
    }                                                                          \
  } while (0)

int main(void) {
  int x = 5;

  ASSERT(x == 10, "x should be 10");

  return 0;
}
