#include <bitmark-sdk/bitmark.h>

#include <string>

#include <api_client.h>
#include <bitmark-sdk/error.h>
#include <bitmark-sdk/query_builder.h>
#include <bitmark-sdk/response.h>
#include <bitmark-sdk/sdk.h>
#include <utils/error_message.h>
#include <utils/response_serialization.h>

#include <nlohmann/json.h>

namespace Bitmark {
  namespace Bitmark {

    using json = nlohmann::json;
    using json_err = nlohmann::detail::exception;

    GetBitmarkResponse get(const std::string& bitmark_id) {
      std::string path = std::string("bitmarks/") + bitmark_id + "?pending=true";
      auto res = BitmarkSDK::get_client()->send_request(
          detail::HTTPMethod::GET, path);

      try {
        json j = json::parse(res->body);
        return j.get<GetBitmarkResponse>();
      }
      catch(json_err e) {
        throw detail::from_json_error(e, res->body);
      }
    }

    GetBitmarkResponse getWithAsset(const std::string& bitmark_id) {
      std::string path = std::string("bitmarks/") + bitmark_id
        + "?pending=true&asset=true";
      auto res = BitmarkSDK::get_client()->send_request(
          detail::HTTPMethod::GET, path);

      try {
        json j = json::parse(res->body);
        return j.get<GetBitmarkResponse>();
      }
      catch(json_err e) {
        throw detail::from_json_error(e, res->body);
      }
    }


    GetBitmarksResponse list(const BitmarkQueryBuilder& builder) {
      std::string path = std::string("bitmarks?") + builder.build();
      auto res = BitmarkSDK::get_client()->send_request(
          detail::HTTPMethod::GET, path);

      try {
        json j = json::parse(res->body);
        return j.get<GetBitmarksResponse>();
      }
      catch(json_err e) {
        throw detail::from_json_error(e, res->body);
      }
    }

  } // namespace Bitmark
} // namespace Bitmark
