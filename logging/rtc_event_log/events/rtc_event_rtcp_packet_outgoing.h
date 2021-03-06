/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef LOGGING_RTC_EVENT_LOG_EVENTS_RTC_EVENT_RTCP_PACKET_OUTGOING_H_
#define LOGGING_RTC_EVENT_LOG_EVENTS_RTC_EVENT_RTCP_PACKET_OUTGOING_H_

#include <memory>

#include "api/array_view.h"
#include "logging/rtc_event_log/events/rtc_event.h"
#include "rtc_base/buffer.h"

namespace webrtc {

class RtcEventRtcpPacketOutgoing final : public RtcEvent {
 public:
  explicit RtcEventRtcpPacketOutgoing(rtc::ArrayView<const uint8_t> packet);
  ~RtcEventRtcpPacketOutgoing() override;

  Type GetType() const override;

  bool IsConfigEvent() const override;

  std::unique_ptr<RtcEvent> Copy() const override;

  rtc::Buffer packet_;

 private:
  RtcEventRtcpPacketOutgoing(const RtcEventRtcpPacketOutgoing& other);
};

}  // namespace webrtc

#endif  // LOGGING_RTC_EVENT_LOG_EVENTS_RTC_EVENT_RTCP_PACKET_OUTGOING_H_
