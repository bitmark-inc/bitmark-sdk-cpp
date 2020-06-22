#ifndef BITMARK_SDK_SDK_H
#define BITMARK_SDK_SDK_H

#include <string>

namespace Bitmark {

  enum class NetworkType {
    LIVENET,
    TESTNET,
  };

  // forward declaration
  namespace detail {
    class APIClient;
  }

  class BitmarkSDK {
  public:
    static BitmarkSDK &get_instance() {
      static BitmarkSDK instance;
      return instance;
    }

    static void init(const std::string &api_token) {
      init(NetworkType::LIVENET, api_token);
    }

    static void init(NetworkType network_type, const std::string &api_token) {
      get_instance().init_(network_type, api_token);
    }

    static NetworkType get_network() { return get_instance().get_network_(); }

    static std::string get_api_token() {
      return get_instance().get_api_token_();
    }

    static detail::APIClient *get_client() {
      return get_instance().get_client_();
    }

  private:
    BitmarkSDK() {}
    void init_(NetworkType, const std::string &);
    NetworkType get_network_();
    std::string get_api_token_();
    detail::APIClient *get_client_();
    void check_initialized_();

    NetworkType network_type_;
    std::string api_token_;
    detail::APIClient *client_ = nullptr;

  public:
    BitmarkSDK(const BitmarkSDK &) = delete;
    void operator=(const BitmarkSDK &) = delete;
    ~BitmarkSDK();
  };

} // namespace Bitmark

#endif // BITMARK_SDK_SDK_H
