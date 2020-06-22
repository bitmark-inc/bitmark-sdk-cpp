#ifndef BITMARK_SDK_API_CLIENT_H
#define BITMARK_SDK_API_CLIENT_H

#include <memory>
#include <string>

#include <cpp-httplib/httplib.h>

namespace Bitmark {
  namespace detail {

    using response_t = std::shared_ptr<httplib::Response>;

    enum class HTTPMethod {
      GET,
      POST,
      PATCH,
    };

    class APIClient {
    public:
      APIClient(const char *url, const std::string &api_token);
      ~APIClient();

      response_t send_request(HTTPMethod method, const std::string &path);

      response_t send_request(HTTPMethod method,
                              const std::string &path,
                              const std::string &body);

      response_t send_request(HTTPMethod method,
                              const std::string &path,
                              const std::string &body,
                              const httplib::Headers &headers);

    private:
      std::string api_token_;
      httplib::SSLClient *client_ = nullptr;
    };

  } // namespace detail
} // namespace Bitmark

#endif // BITMARK_SDK_API_CLIENT_H
