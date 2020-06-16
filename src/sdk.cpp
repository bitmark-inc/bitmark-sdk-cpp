#include <bitmark-sdk/sdk.h>

#include <string>

#include <api_client.h>
#include <bitmark-sdk/error.h>
#include <utils/common.h>

namespace Bitmark {

  void BitmarkSDK::init_(NetworkType network_type,
                         const std::string& api_token) {
    detail::check_non_empty_str(api_token, "api_token");
    network_type_ = network_type;
    api_token_ = api_token;

    if (network_type_ == NetworkType::LIVENET)
      client_ = new detail::APIClient("api.bitmark.com", api_token_);
    else
      client_ = new detail::APIClient("api.test.bitmark.com", api_token_);
  }

  NetworkType BitmarkSDK::get_network_() {
    check_initialized_();
    return network_type_;
  }

  std::string BitmarkSDK::get_api_token_() {
    check_initialized_();
    return api_token_;
  }

  detail::APIClient* BitmarkSDK::get_client_() {
    check_initialized_();
    return client_;
  }

  void BitmarkSDK::check_initialized_() {
    if (!client_)
      throw UnsupportedOperationError(
          "Calling SDK function before initialization");
  }

  BitmarkSDK::~BitmarkSDK() {
    if (client_)
      delete client_;
  }

} // namespace Bitmark
