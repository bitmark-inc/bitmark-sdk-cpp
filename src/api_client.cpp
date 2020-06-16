#include <api_client.h>

#include <string>

#include <bitmark-sdk/error.h>
#include <bitmark-sdk/version.h>
#include <utils/common.h>
#include <utils/error_message.h>

#include <cpp-httplib/httplib.h>
#include <nlohmann/json.h>

namespace Bitmark {
  namespace detail {

    using json = nlohmann::json;

    APIClient::APIClient(const char* url, const std::string& api_token) {
      api_token_ = api_token;
      client_ = new httplib::SSLClient(url);
    }

    APIClient::~APIClient() {
      if (client_)
        delete client_;
    }

    response_t APIClient::send_request(HTTPMethod method,
                                       const std::string& path) {
      return send_request(method, path, std::string());
    }

    response_t APIClient::send_request(HTTPMethod method,
                            const std::string& path,
                            const std::string& body) {
      return send_request(method, path, body, httplib::Headers());
    }

    response_t APIClient::send_request(HTTPMethod method,
                                       const std::string& path,
                                       const std::string& body,
                                       const httplib::Headers& headers) {
      std::string n_path = std::string("/v3/") + path;

      httplib::Headers n_headers;
      n_headers.emplace("api-token", api_token_);
      n_headers.emplace("User-Agent",
                        std::string("bitmark-sdk-cpp/") + BITMARK_VERSION);
      n_headers.insert(headers.begin(), headers.end());

      response_t res;
      if (method == HTTPMethod::GET)
        res = client_->Get(n_path.c_str(), n_headers);
      else if (method == HTTPMethod::POST)
        res = client_->Post(n_path.c_str(), n_headers, body, "application/json");
      else
        res = client_->Post(n_path.c_str(), n_headers, body, "application/json");

      if (!res)
        throw NetworkError("Unable to connect to remote server", -1);
      if (res->status >= 400) {
        try {
          json j = json::parse(res->body);
          int code = j.at("code").get<int>();
          std::string message = j.at("message").get<std::string>();
          std::string reason = (j.contains("reason") && !j.at("reason").is_null())
            ? j.at("reason").get<std::string>()
            : std::string();
          throw from_remote_error(code, message, reason);
        }
        catch (nlohmann::detail::exception e) {
          throw from_http_error(res);
        }
      }
      return res;
    }
  } // namespace detail
} // namespace Bitmark
