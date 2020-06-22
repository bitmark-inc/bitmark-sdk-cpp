#ifndef BITMARK_SDK_UTILS_RESPONSE_SERIALIZATION_H
#define BITMARK_SDK_UTILS_RESPONSE_SERIALIZATION_H

#include <bitmark-sdk/response.h>

#include <nlohmann/json.h>

namespace Bitmark {

  using json = nlohmann::json;

  NLOHMANN_JSON_SERIALIZE_ENUM(AssetRecord::Status,
                               {
                                 {AssetRecord::Status::PENDING, "pending"},
                                 {AssetRecord::Status::CONFIRMED, "confirmed"},
                               })

  inline void to_json(json &j, const AssetRecord &r) {
    j = json{
      {"id", r.id},
      {"name", r.name},
      {"metadata", r.metadata},
      {"fingerprint", r.fingerprint},
      {"registrant", r.registrant},
      {"status", r.status},
      {"block_number", r.block_number},
      {"offset", r.offset},
      {"created_at", r.created_at},
    };
  }

  inline void from_json(const json &j, AssetRecord &r) {
    j.at("id").get_to(r.id);
    j.at("name").get_to(r.name);
    j.at("metadata").get_to(r.metadata);
    j.at("fingerprint").get_to(r.fingerprint);
    j.at("registrant").get_to(r.registrant);
    j.at("status").get_to(r.status);
    j.at("block_number").get_to(r.block_number);
    j.at("offset").get_to(r.offset);
    if (j.contains("created_at") && !j.at("created_at").is_null())
      j.at("created_at").get_to(r.created_at);
  }

  NLOHMANN_JSON_SERIALIZE_ENUM(
    TransactionRecord::Status,
    {
      {TransactionRecord::Status::PENDING, "pending"},
      {TransactionRecord::Status::CONFIRMED, "confirmed"},
    })

  inline void to_json(json &j, const TransactionRecord &r) {
    j = json{
      {"id", r.id},
      {"owner", r.owner},
      {"previous_id", r.previous_id},
      {"previous_owner", r.previous_owner},
      {"bitmark_id", r.bitmark_id},
      {"asset_id", r.asset_id},
      {"status", r.status},
      {"block_number", r.block_number},
      {"offset", r.offset},
      {"confirmation", r.confirmation},
      {"countersign", r.countersign},
    };
  }

  inline void from_json(const json &j, TransactionRecord &r) {
    j.at("id").get_to(r.id);
    j.at("owner").get_to(r.owner);
    if (j.contains("previous_id") && !j.at("previous_id").is_null()) {
      j.at("previous_id").get_to(r.previous_id);
      j.at("previous_owner").get_to(r.previous_owner);
    }
    j.at("bitmark_id").get_to(r.bitmark_id);
    j.at("asset_id").get_to(r.asset_id);
    j.at("status").get_to(r.status);
    j.at("block_number").get_to(r.block_number);
    j.at("offset").get_to(r.offset);
    j.at("confirmation").get_to(r.confirmation);
    j.at("countersign").get_to(r.countersign);
  }

  inline void to_json(json &j, const HalfSignedOffer &r) {
    j = json{
      {"link", r.link},
      {"owner", r.owner},
      {"signature", r.signature},
    };
  }

  inline void from_json(const json &j, HalfSignedOffer &r) {
    j.at("link").get_to(r.link);
    j.at("owner").get_to(r.owner);
    j.at("signature").get_to(r.signature);
  }

  inline void to_json(json &j, const OfferRecord &r) {
    j = json{
      {"id", r.id},
      {"from", r.from},
      {"to", r.to},
      {"record", r.record},
      {"extra_info", r.extra_info},
      {"created_at", r.created_at},
    };
  }

  inline void from_json(const json &j, OfferRecord &r) {
    j.at("id").get_to(r.id);
    j.at("from").get_to(r.from);
    j.at("to").get_to(r.to);
    j.at("record").get_to(r.record);
    if (j.contains("extra_info") && !j.at("extra_info").is_null())
      j.at("extra_info").get_to(r.extra_info);
    j.at("created_at").get_to(r.created_at);
  }

  NLOHMANN_JSON_SERIALIZE_ENUM(BitmarkRecord::Status,
                               {
                                 {BitmarkRecord::Status::ISSUING, "issuing"},
                                 {BitmarkRecord::Status::TRANSFERRING,
                                  "transferring"},
                                 {BitmarkRecord::Status::OFFERING, "offering"},
                                 {BitmarkRecord::Status::SETTLED, "settled"},
                               })

  inline void to_json(json &j, const BitmarkRecord &r) {
    j = json{
      {"id", r.id},
      {"asset_id", r.asset_id},
      {"head_id", r.head_id},
      {"issuer", r.issuer},
      {"owner", r.owner},
      {"offer", r.offer},
      {"status", r.status},
      {"block_number", r.block_number},
      {"offset", r.offset},
      {"edition", r.edition},
      {"created_at", r.created_at},
      {"confirmed_at", r.confirmed_at},
    };
  }

  inline void from_json(const json &j, BitmarkRecord &r) {
    j.at("id").get_to(r.id);
    j.at("asset_id").get_to(r.asset_id);
    if (j.contains("head_id") && !j.at("head_id").is_null())
      j.at("head_id").get_to(r.head_id);
    j.at("issuer").get_to(r.issuer);
    j.at("owner").get_to(r.owner);
    if (j.contains("offer") && !j.at("offer").is_null())
      j.at("offer").get_to(r.offer);
    j.at("status").get_to(r.status);
    j.at("block_number").get_to(r.block_number);
    j.at("offset").get_to(r.offset);
    if (j.contains("edition") && !j.at("edition").is_null())
      j.at("edition").get_to(r.edition);
    if (j.contains("created_at") && !j.at("created_at").is_null())
      j.at("created_at").get_to(r.created_at);
    if (j.contains("confirmed_at") && !j.at("confirmed_at").is_null())
      j.at("confirmed_at").get_to(r.confirmed_at);
  }

  inline void to_json(json &j, const GetTransactionResponse &r) {
    j = json{{"tx", r.tx}, {"asset", r.asset}};
  }

  inline void from_json(const json &j, GetTransactionResponse &r) {
    j.at("tx").get_to(r.tx);
    if (j.contains("asset") && !j.at("asset").is_null())
      j.at("asset").get_to(r.asset);
  }

  inline void to_json(json &j, const GetTransactionsResponse &r) {
    j = json{{"txs", r.txs}, {"assets", r.assets}};
  }

  inline void from_json(const json &j, GetTransactionsResponse &r) {
    j.at("txs").get_to(r.txs);
    if (j.contains("assets") && !j.at("assets").is_null())
      j.at("assets").get_to(r.assets);
  }

  inline void to_json(json &j, const GetBitmarkResponse &r) {
    j = json{{"bitmark", r.bitmark}, {"asset", r.asset}};
  }

  inline void from_json(const json &j, GetBitmarkResponse &r) {
    j.at("bitmark").get_to(r.bitmark);
    if (j.contains("asset") && !j.at("asset").is_null())
      j.at("asset").get_to(r.asset);
  }

  inline void to_json(json &j, const GetBitmarksResponse &r) {
    j = json{{"bitmarks", r.bitmarks}, {"assets", r.assets}};
  }

  inline void from_json(const json &j, GetBitmarksResponse &r) {
    j.at("bitmarks").get_to(r.bitmarks);
    if (j.contains("assets") && !j.at("assets").is_null())
      j.at("assets").get_to(r.assets);
  }

} // namespace Bitmark

#endif // BITMARK_SDK_UTILS_RESPONSE_SERIALIZATION_H
