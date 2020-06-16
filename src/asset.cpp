#include <bitmark-sdk/asset.h>

#include <string>
#include <vector>

#include <api_client.h>
#include <bitmark-sdk/error.h>
#include <bitmark-sdk/query_builder.h>
#include <bitmark-sdk/response.h>
#include <bitmark-sdk/sdk.h>
#include <utils/error_message.h>
#include <utils/response_serialization.h>

#include <nlohmann/json.h>

namespace Bitmark {
  namespace Asset {

    using json = nlohmann::json;
    using json_err = nlohmann::detail::exception;

    AssetRecord get(const std::string& asset_id) {
      std::string path = std::string("assets/") + asset_id + "?pending=true";
      auto res = BitmarkSDK::get_client()->send_request(
          detail::HTTPMethod::GET, path);

      try {
        json j = json::parse(res->body);
        return j.at("asset").get<AssetRecord>();
      }
      catch(json_err e) {
        throw detail::from_json_error(e, res->body);
      }
    }

    std::vector<AssetRecord> list(const AssetQueryBuilder& builder) {
      std::string path = std::string("assets?") + builder.build();
      auto res = BitmarkSDK::get_client()->send_request(
          detail::HTTPMethod::GET, path);

      try {
        json j = json::parse(res->body);
        return j.at("assets").get<std::vector<AssetRecord>>();
      }
      catch(json_err e) {
        throw detail::from_json_error(e, res->body);
      }
    }

  } // namespace Asset
} // namespace Bitmark
