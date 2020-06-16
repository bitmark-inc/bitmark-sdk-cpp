#include <bitmark-sdk/query_builder.h>

#include <cstdint>
#include <string>
#include <vector>

#include <bitmark-sdk/error.h>
#include <utils/common.h>

#include <cpp-httplib/httplib.h>

namespace Bitmark {

  template <class QueryBuilder>
    BaseQueryBuilder<QueryBuilder>::BaseQueryBuilder() {
      params_.emplace("pending", "true");
    }

  template <class QueryBuilder>
    std::string BaseQueryBuilder<QueryBuilder>::build() const {
      return httplib::detail::params_to_query_str(params_);
    }

  template <class QueryBuilder>
    QueryBuilder& BaseQueryBuilder<QueryBuilder>::pending(bool is_pending) {
      params_.erase("pending");
      params_.emplace("pending", detail::to_string(is_pending));
      return static_cast<QueryBuilder&>(*this);
    }

  template <class QueryBuilder>
    QueryBuilder& BaseQueryBuilder<QueryBuilder>::limit(int size) {
      if (size > 100 || size < 0)
        throw InvalidArgumentError("\"size\" must be between 0 and 100");
      params_.erase("limit");
      params_.emplace("limit", detail::to_string(size));
      return static_cast<QueryBuilder&>(*this);
    }

  template <class QueryBuilder>
    QueryBuilder& BaseQueryBuilder<QueryBuilder>::at(uint64_t at) {
      params_.erase("at");
      params_.emplace("at", detail::to_string(at));
      return static_cast<QueryBuilder&>(*this);
    }

  template <class QueryBuilder>
    QueryBuilder& BaseQueryBuilder<QueryBuilder>::to(QueryDirection direction) {
      params_.erase("to");
      if (direction == QueryDirection::EARLIER)
        params_.emplace("to", "earlier");
      else
        params_.emplace("to", "later");
      return static_cast<QueryBuilder&>(*this);
    }


  AssetQueryBuilder&
    AssetQueryBuilder::registeredBy(const std::string& registrant) {
      params_.erase("registrant");
      params_.emplace("registrant", registrant);
      return *this;
    }

  AssetQueryBuilder&
    AssetQueryBuilder::assetIds(const std::vector<std::string>& asset_ids) {
      for (auto& asset_id : asset_ids) {
        params_.emplace("asset_ids", asset_id);
      }
      return *this;
    }

  TransactionQueryBuilder&
    TransactionQueryBuilder::ownedBy(const std::string& owner) {
      params_.erase("owner");
      params_.emplace("owner", owner);
      return *this;
    }

  TransactionQueryBuilder&
    TransactionQueryBuilder::ownedByWithTransient(const std::string& owner) {
      params_.erase("owner");
      params_.erase("sent");
      params_.emplace("owner", owner);
      params_.emplace("sent", "true");
      return *this;
    }

  TransactionQueryBuilder&
    TransactionQueryBuilder::referencedBitmark(const std::string& bitmark_id) {
      params_.erase("bitmark_id");
      params_.emplace("bitmark_id", bitmark_id);
      return *this;
    }

  TransactionQueryBuilder&
    TransactionQueryBuilder::referencedBlockNumber(uint64_t block_number) {
      params_.erase("block_number");
      params_.emplace("block_number", detail::to_string(block_number));
      return *this;
    }

  TransactionQueryBuilder&
    TransactionQueryBuilder::referencedAsset(const std::string& asset_id) {
      params_.erase("asset_id");
      params_.emplace("asset_id", asset_id);
      return *this;
    }

  TransactionQueryBuilder&
    TransactionQueryBuilder::loadAsset(bool should_load_asset) {
      params_.erase("asset");
      params_.emplace("asset", detail::to_string(should_load_asset));
      return *this;
    }

  BitmarkQueryBuilder&
    BitmarkQueryBuilder::ownedBy(const std::string& owner) {
      params_.erase("owner");
      params_.emplace("owner", owner);
      return *this;
    }

  BitmarkQueryBuilder&
    BitmarkQueryBuilder::ownedByWithTransient(const std::string& owner) {
      params_.erase("owner");
      params_.erase("sent");
      params_.emplace("owner", owner);
      params_.emplace("sent", "true");
      return *this;
    }

  BitmarkQueryBuilder&
    BitmarkQueryBuilder::issuedBy(const std::string& issuer) {
      params_.erase("issuer");
      params_.emplace("issuer", issuer);
      return *this;
    }

  BitmarkQueryBuilder&
    BitmarkQueryBuilder::offerTo(const std::string& receiver) {
      params_.erase("offer_to");
      params_.emplace("offer_to", receiver);
      return *this;
    }

  BitmarkQueryBuilder&
    BitmarkQueryBuilder::offerFrom(const std::string& sender) {
      params_.erase("offer_from");
      params_.emplace("offer_from", sender);
      return *this;
    }

  BitmarkQueryBuilder&
    BitmarkQueryBuilder::bitmarkIds(const std::vector<std::string>& bitmark_ids) {
      for (auto& bitmark_id : bitmark_ids) {
        params_.emplace("bitmark_ids", bitmark_id);
      }
      return *this;
    }

  BitmarkQueryBuilder&
    BitmarkQueryBuilder::referencedAsset(const std::string& asset_id) {
      params_.erase("asset_id");
      params_.emplace("asset_id", asset_id);
      return *this;
    }

  BitmarkQueryBuilder&
    BitmarkQueryBuilder::loadAsset(bool should_load_asset) {
      params_.erase("asset");
      params_.emplace("asset", detail::to_string(should_load_asset));
      return *this;
    }

  template class BaseQueryBuilder<AssetQueryBuilder>;
  template class BaseQueryBuilder<TransactionQueryBuilder>;
  template class BaseQueryBuilder<BitmarkQueryBuilder>;

} // namespace Bitmark
