#include <bitmark-sdk/transaction.h>

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
  namespace Transaction {

    using json = nlohmann::json;
    using json_err = nlohmann::detail::exception;

    GetTransactionResponse get(const std::string& transaction_id) {
      std::string path = std::string("txs/") + transaction_id + "?pending=true";
      auto res = BitmarkSDK::get_client()->send_request(
          detail::HTTPMethod::GET, path);

      try {
        json j = json::parse(res->body);
        return j.get<GetTransactionResponse>();
      }
      catch(json_err e) {
        throw detail::from_json_error(e, res->body);
      }
    }

    GetTransactionResponse getWithAsset(const std::string& transaction_id) {
      std::string path = std::string("txs/") + transaction_id
        + "?pending=true&asset=true";
      auto res = BitmarkSDK::get_client()->send_request(
          detail::HTTPMethod::GET, path);

      try {
        json j = json::parse(res->body);
        return j.get<GetTransactionResponse>();
      }
      catch(json_err e) {
        throw detail::from_json_error(e, res->body);
      }
    }


    GetTransactionsResponse list(const TransactionQueryBuilder& builder) {
      std::string path = std::string("txs?") + builder.build();
      auto res = BitmarkSDK::get_client()->send_request(
          detail::HTTPMethod::GET, path);

      try {
        json j = json::parse(res->body);
        return j.get<GetTransactionsResponse>();
      }
      catch(json_err e) {
        throw detail::from_json_error(e, res->body);
      }
    }

  } // namespace Transaction
} // namespace Bitmark
