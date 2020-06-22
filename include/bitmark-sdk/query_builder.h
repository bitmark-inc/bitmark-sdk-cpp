#ifndef BITMARK_SDK_QUERY_BUILDER_H
#define BITMARK_SDK_QUERY_BUILDER_H

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace Bitmark {

  enum class QueryDirection {
    EARLIER,
    LATER,
  };

  template <class QueryBuilder>
  class BaseQueryBuilder {
  public:
    BaseQueryBuilder();

    std::string build() const;

    QueryBuilder &pending(bool is_pending);

    QueryBuilder &limit(int size);

    QueryBuilder &at(uint64_t at);

    QueryBuilder &to(QueryDirection direction);

  protected:
    std::multimap<std::string, std::string> params_;
  };

  class AssetQueryBuilder : public BaseQueryBuilder<AssetQueryBuilder> {
  public:
    AssetQueryBuilder &registeredBy(const std::string &registrant);

    AssetQueryBuilder &assetIds(const std::vector<std::string> &asset_ids);
  };

  class TransactionQueryBuilder
    : public BaseQueryBuilder<TransactionQueryBuilder> {
  public:
    TransactionQueryBuilder &ownedBy(const std::string &owner);

    TransactionQueryBuilder &ownedByWithTransient(const std::string &owner);

    TransactionQueryBuilder &referencedBitmark(const std::string &bitmark_id);

    TransactionQueryBuilder &referencedBlockNumber(uint64_t block_number);

    TransactionQueryBuilder &referencedAsset(const std::string &asset_id);

    TransactionQueryBuilder &loadAsset(bool should_load_asset);
  };

  class BitmarkQueryBuilder : public BaseQueryBuilder<BitmarkQueryBuilder> {
  public:
    BitmarkQueryBuilder &ownedBy(const std::string &owner);

    BitmarkQueryBuilder &ownedByWithTransient(const std::string &owner);

    BitmarkQueryBuilder &issuedBy(const std::string &issuer);

    BitmarkQueryBuilder &offerTo(const std::string &receiver);

    BitmarkQueryBuilder &offerFrom(const std::string &sender);

    BitmarkQueryBuilder &
    bitmarkIds(const std::vector<std::string> &bitmark_ids);

    BitmarkQueryBuilder &referencedAsset(const std::string &asset_id);

    BitmarkQueryBuilder &loadAsset(bool should_load_asset);
  };

} // namespace Bitmark

#endif // BITMARK_SDK_QUERY_BUILDER_H
