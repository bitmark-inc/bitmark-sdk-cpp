#ifndef BITMARK_SDK_UTILS_ERROR_MESSAGE_H
#define BITMARK_SDK_UTILS_ERROR_MESSAGE_H

#include <memory>
#include <string>

#include <bitmark-sdk/error.h>
#include <utils/common.h>

#include <cpp-httplib/httplib.h>
#include <nlohmann/json.h>

namespace Bitmark {
  namespace detail {

    using response_t = std::shared_ptr<httplib::Response>;
    using json_err = nlohmann::detail::exception;

    inline RemoteAPIError from_remote_error(int code,
                                            const std::string &message,
                                            const std::string &reason) {
      std::string err_message =
        std::string("Remote server throwing errors: [") + to_string(code) +
        "] message: " + message + " reason: " + reason;
      return RemoteAPIError(err_message, code);
    }

    inline NetworkError from_http_error(response_t res) {
      std::string err_message = std::string("Got unexpected response: [") +
                                to_string(res->status) + " " +
                                httplib::detail::status_message(res->status) +
                                "] content: " + res->body;
      return NetworkError(err_message, res->status);
    }

    inline JSONError from_json_error(json_err e, const std::string &raw_json) {
      std::string err_message =
        std::string("Unable to parse JSON object! reason: ") + e.what();
      return JSONError(err_message, raw_json);
    }

  } // namespace detail
} // namespace Bitmark

#endif // BITMARK_SDK_UTILS_ERROR_MESSAGE_H
