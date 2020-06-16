#ifndef BITMARK_SDK_RESPONSE_H
#define BITMARK_SDK_RESPONSE_H

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace Bitmark {

  struct AssetRecord {
    enum class Status {
      PENDING,
      CONFIRMED,
    };

    std::string id;
    std::string name;
    std::map<std::string, std::string> metadata;
    std::string fingerprint;
    std::string registrant;
    Status status;
    uint64_t block_number;
    uint64_t offset;
    std::string created_at;
  };

  struct TransactionRecord {
    enum class Status {
      PENDING,
      CONFIRMED,
    };

    std::string id;
    std::string owner;
    std::string previous_id;
    std::string previous_owner;
    std::string bitmark_id;
    std::string asset_id;
    Status status;
    uint64_t block_number;
    uint64_t offset;
    uint64_t confirmation;
    bool countersign;
  };

  struct HalfSignedOffer {
    std::string link;
    std::string owner;
    std::string signature;
  };

  struct OfferRecord {
    std::string id;
    std::string from;
    std::string to;
    HalfSignedOffer record;
    std::map<std::string, std::string> extra_info;
    std::string created_at;
  };

  struct BitmarkRecord {
    enum class Status {
      ISSUING,
      TRANSFERRING,
      OFFERING,
      SETTLED,
    };

    std::string id;
    std::string asset_id;
    std::string head_id;
    std::string issuer;
    std::string owner;
    OfferRecord offer;
    Status status;
    uint64_t block_number;
    uint64_t offset;
    int edition;
    std::string created_at;
    std::string confirmed_at;
  };

  struct GetTransactionResponse {
    TransactionRecord tx;
    AssetRecord asset;
  };

  struct GetTransactionsResponse {
    std::vector<TransactionRecord> txs;
    std::vector<AssetRecord> assets;
  };

  struct GetBitmarkResponse {
    BitmarkRecord bitmark;
    AssetRecord asset;
  };

  struct GetBitmarksResponse {
    std::vector<BitmarkRecord> bitmarks;
    std::vector<AssetRecord> assets;
  };

} // namespace Bitmark

#endif // BITMARK_SDK_RESPONSE_H
