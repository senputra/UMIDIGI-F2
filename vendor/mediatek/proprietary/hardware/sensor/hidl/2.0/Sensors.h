/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HARDWARE_INTERFACES_SENSORS_V2_0_DEFAULT_SENSORS_H_
#define HARDWARE_INTERFACES_SENSORS_V2_0_DEFAULT_SENSORS_H_

#include <android-base/macros.h>
#include <android/hardware/sensors/2.0/ISensors.h>
#include <fmq/MessageQueue.h>
#include <hardware/sensors.h>
#include <hardware_legacy/power.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <mutex>
#include <atomic>
#include <memory>
#include <thread>

namespace android {
namespace hardware {
namespace sensors {
namespace V2_0 {
namespace implementation {

using ::android::sp;
using ::android::hardware::EventFlag;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::MessageQueue;
using ::android::hardware::MQDescriptor;
using ::android::hardware::Return;
using ::android::hardware::Void;

struct Sensors : public ISensors {
    using Event = ::android::hardware::sensors::V1_0::Event;
    using OperationMode = ::android::hardware::sensors::V1_0::OperationMode;
    using RateLevel = ::android::hardware::sensors::V1_0::RateLevel;
    using Result = ::android::hardware::sensors::V1_0::Result;
    using SharedMemInfo = ::android::hardware::sensors::V1_0::SharedMemInfo;

    Sensors();
    virtual ~Sensors();
    status_t initCheck() const;

    Return<void> getSensorsList(getSensorsList_cb _hidl_cb) override;

    Return<Result> setOperationMode(OperationMode mode) override;

    Return<Result> activate(
            int32_t sensor_handle, bool enabled) override;

    Return<Result> initialize(
        const ::android::hardware::MQDescriptorSync<Event>& eventQueueDescriptor,
        const ::android::hardware::MQDescriptorSync<uint32_t>& wakeLockDescriptor,
        const sp<ISensorsCallback>& sensorsCallback) override;

    Return<Result> batch(
            int32_t sensor_handle,
            int64_t sampling_period_ns,
            int64_t max_report_latency_ns) override;

    Return<Result> flush(int32_t sensor_handle) override;

    Return<Result> injectSensorData(const Event& event) override;

    Return<void> registerDirectChannel(
            const SharedMemInfo& mem, registerDirectChannel_cb _hidl_cb) override;

    Return<Result> unregisterDirectChannel(int32_t channelHandle) override;

    Return<void> configDirectReport(
            int32_t sensorHandle, int32_t channelHandle, RateLevel rate,
            configDirectReport_cb _hidl_cb) override;

private:
    static constexpr int32_t kPollMaxBufferSize = 128;
    status_t mInitCheck;
    sensors_module_t *mSensorModule;
    sensors_poll_device_1_t *mSensorDevice;

    using EventMessageQueue = MessageQueue<Event, kSynchronizedReadWrite>;
    using WakeLockMessageQueue = MessageQueue<uint32_t, kSynchronizedReadWrite>;

    /**
     * The Event FMQ where sensor events are written
     */
    std::unique_ptr<EventMessageQueue> mEventQueue;

    /**
     * The Wake Lock FMQ that is read to determine when the framework has handled WAKE_UP events
     */
    std::unique_ptr<WakeLockMessageQueue> mWakeLockQueue;

    /**
     * Event Flag to signal to the framework when sensor events are available to be read
     */
    EventFlag* mEventQueueFlag;

    /**
     * Callback for asynchronous events, such as dynamic sensor connections.
     */
    sp<ISensorsCallback> mCallback;

    /**
     * Lock to protect writes to the FMQs
     */
    std::mutex mWriteLock;

    /**
     * Lock to protect acquiring and releasing the wake lock
     */
    std::mutex mWakeLockLock;

    /**
     * Track the number of WAKE_UP events that have not been handled by the framework
     */
    uint32_t mOutstandingWakeUpEvents;

    /**
     * A thread to read the Wake Lock FMQ
     */
    std::thread mWakeLockThread;

    /**
     * Flag to indicate that the Wake Lock Thread should continue to run
     */
    std::atomic_bool mReadWakeLockQueueRun;

    /**
     * Track the time when the wake lock should automatically be released
     */
    int64_t mAutoReleaseWakeLockTime;

    /**
     * Flag to indicate if a wake lock has been acquired
     */
    bool mHasWakeLock;

    std::atomic_bool mRunThreadEnable;

    std::thread mRunThread;

    std::atomic_bool mEventQueueInitialized;

    int getHalDeviceVersion() const;

    static void convertFromSensorEvents(
            size_t count, const sensors_event_t *src, std::vector<Event> *dst);

    /**
     * Utility function to delete the Event Flag
     */
    void deleteEventFlag();

    /**
     * Function to read the Wake Lock FMQ and release the wake lock when appropriate
     */
    void readWakeLockFMQ();

    static void startReadWakeLockThread(Sensors* sensors);

    /**
     * Responsible for acquiring and releasing a wake lock when there are unhandled WAKE_UP events
     */
    void updateWakeLock(int32_t eventsWritten, int32_t eventsHandled);

    static void startThread(Sensors* sensors);

    void poll();

    void postEvents(const std::vector<Event>& events, bool wakeup);
};

}  // namespace implementation
}  // namespace V2_0
}  // namespace sensors
}  // namespace hardware
}  // namespace android

#endif  // HARDWARE_INTERFACES_SENSORS_V2_0_DEFAULT_SENSORS_H_
