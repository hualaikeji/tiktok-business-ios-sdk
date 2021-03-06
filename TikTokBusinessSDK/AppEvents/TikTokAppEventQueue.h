//
// Copyright (c) 2020. Bytedance Inc.
//
// This source code is licensed under the MIT license found in
// the LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>
#import "TikTokAppEvent.h"
#import "TikTokAppEventUtility.h"
#import "TikTokConfig.h"
#import "TikTokLogger.h"

NS_ASSUME_NONNULL_BEGIN

@interface TikTokAppEventQueue : NSObject

/**
 * @brief Event queue as a mutable array
 */
@property (nonatomic, strong) NSMutableArray *eventQueue;

/**
 * @brief Timer for flush
 */
@property (nonatomic, strong) NSTimer *flushTimer;

/**
 * @brief Timer for logging
 */
@property (nonatomic, strong) NSTimer *logTimer;

/**
 * @brief Time in seconds until flush
 */
@property (nonatomic) int timeInSecondsUntilFlush;

/**
 * @brief Remaining events until flush
 */
@property (nonatomic) int remainingEventsUntilFlushThreshold;

/**
 * @brief Configuration from SDK initialization
 */
@property (nonatomic, strong, nullable) TikTokConfig *config;


- (id)init;

- (id)initWithConfig: (TikTokConfig * _Nullable)config;

/**
 * @brief Add event to queue
 */
- (void)addEvent:(TikTokAppEvent *)event;

/**
 * @brief Flush logic
 */
- (void)flush:(TikTokAppEventsFlushReason)flushReason;

@end

NS_ASSUME_NONNULL_END
