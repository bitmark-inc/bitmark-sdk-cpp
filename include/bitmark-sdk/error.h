#ifndef BITMARK_SDK_ERROR_H
#define BITMARK_SDK_ERROR_H

#include <exception>
#include <stdexcept>
#include <string>

namespace Bitmark {

  // base class for all exceptions thrown by the library
  class Exception : public std::exception {
   public:
    const char* what() const noexcept override { return m.what(); }

   protected:
    Exception(const char* what_arg) : m(what_arg) {}

    Exception(const std::string& what_arg) : m(what_arg) {}

   private:
    std::runtime_error m;
  };

  // exceptions which holds the remote API error
  class RemoteAPIError : public Exception {
   public:
    RemoteAPIError(const std::string& message, int code)
      : Exception(message), code(code) {}

    int code;
  };

  class UnsupportedOperationError : public Exception {
   public:
    UnsupportedOperationError(const std::string& message)
      : Exception(message) {}
  };

  class NetworkError : public Exception {
   public:
    NetworkError(const std::string& message, int status)
      : Exception(message), status(status) {}

    int status;
  };

  class SDKError : public Exception {
   public:
    SDKError(const std::string& message)
      : Exception(message) {}
  };

  class JSONError : public Exception {
   public:
    JSONError(const std::string& message, const std::string& raw_json)
      : Exception(message), raw_json_(raw_json) {}

    const char* get_raw_json() const noexcept { return raw_json_.what(); }

   private:
    std::runtime_error raw_json_;
  };

  class InvalidArgumentError : public Exception {
   public:
    InvalidArgumentError(const std::string& message)
      : Exception(message) {}
  };

} // namespace Bitmark

#endif // BITMARK_SDK_ERROR_H
