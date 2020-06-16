#ifndef BITMARK_SDK_TRANSACTION_H
#define BITMARK_SDK_TRANSACTION_H

#include <string>

#include <bitmark-sdk/query_builder.h>
#include <bitmark-sdk/response.h>

namespace Bitmark {
  namespace Transaction {

    GetTransactionResponse get(const std::string& transaction_id);

    GetTransactionResponse getWithAsset(const std::string& transaction_id);

    GetTransactionsResponse list(const TransactionQueryBuilder& builder);

  } // namespace Transaction
} // namespace Bitmark

#endif // BITMARK_SDK_TRANSACTION_H
