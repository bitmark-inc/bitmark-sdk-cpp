#ifndef BITMARK_SDK_UTILS_COMMON_H
#define BITMARK_SDK_UTILS_COMMON_H

#include <sstream>
#include <string>

#include <bitmark-sdk/error.h>

namespace Bitmark {
  namespace detail {

    template <typename T>
    inline std::string to_string(const T &val) {
      std::ostringstream ss;
      ss << std::boolalpha << val;
      return ss.str();
    }

    inline void check_non_empty_str(const std::string &str,
                                    const std::string &name) {
      if (str.empty())
        throw InvalidArgumentError("\"" + name + "\" must not be empty");
    }

  } // namespace detail
} // namespace Bitmark

#endif // BITMARK_SDK_UTILS_COMMON_H
