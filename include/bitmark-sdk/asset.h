#ifndef BITMARK_SDK_ASSET_H
#define BITMARK_SDK_ASSET_H

#include <string>
#include <vector>

#include <bitmark-sdk/query_builder.h>
#include <bitmark-sdk/response.h>

namespace Bitmark {
  namespace Asset {

    AssetRecord get(const std::string &asset_id);

    std::vector<AssetRecord> list(const AssetQueryBuilder &builder);

  } // namespace Asset
} // namespace Bitmark

#endif // BITMARK_SDK_ASSET_H
