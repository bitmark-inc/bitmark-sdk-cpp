#ifndef BITMARK_SDK_BITMARK_H
#define BITMARK_SDK_BITMARK_H

#include <string>

#include <bitmark-sdk/query_builder.h>
#include <bitmark-sdk/response.h>

namespace Bitmark {
  namespace Bitmark {

    GetBitmarkResponse get(const std::string &bitmark_id);

    GetBitmarkResponse getWithAsset(const std::string &bitmark_id);

    GetBitmarksResponse list(const BitmarkQueryBuilder &builder);

  } // namespace Bitmark
} // namespace Bitmark

#endif // BITMARK_SDK_BITMARK_H
