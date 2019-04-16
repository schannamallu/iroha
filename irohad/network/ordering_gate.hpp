/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_ORDERING_GATE_HPP
#define IROHA_ORDERING_GATE_HPP

#include <memory>

#include <rxcpp/rx.hpp>
#include "network/ordering_gate_common.hpp"
#include "network/peer_communication_service.hpp"

namespace shared_model {
  namespace interface {
    class Proposal;
    class TransactionBatch;
  }  // namespace interface
}  // namespace shared_model

namespace iroha {
  namespace network {

    /**
     * Ordering gate provide interface with network transaction order
     */
    class OrderingGate {
     public:
      /**
       * Propagate a transaction batch for further processing
       * @param batch
       */
      virtual void propagateBatch(
          std::shared_ptr<shared_model::interface::TransactionBatch> batch) = 0;

      /**
       * Return observable of all proposals in the consensus
       * @return observable with notifications
       */
      virtual rxcpp::observable<OrderingEvent> onProposal() = 0;

      virtual ~OrderingGate() = default;
    };
  }  // namespace network
}  // namespace iroha

#endif  // IROHA_ORDERING_GATE_HPP