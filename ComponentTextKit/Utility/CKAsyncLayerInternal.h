/*
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#import <ComponentKit/CKDefines.h>

#if CK_NOT_SWIFT

#import <ComponentKit/CKAsyncLayer.h>
#import <ComponentKit/CKAsyncTransaction.h>
#include <atomic>
@class CKAsyncTransaction;

@protocol CKAsyncLayerDrawingDelegate
- (void)drawAsyncLayerInContext:(CGContextRef)context parameters:(NSObject *)parameters;
@end

@interface CKAsyncLayer ()
{
  std::atomic<int32_t> _displaySentinel;
}

/**
 @summary The dispatch queue used for async display.

 @desc This is exposed here for tests only.
 */
+ (dispatch_queue_t)displayQueue;

+ (ck_async_transaction_operation_block_t)asyncDisplayBlockWithBounds:(CGRect)bounds
                                                        contentsScale:(CGFloat)contentsScale
                                                               opaque:(BOOL)opaque
                                                      backgroundColor:(CGColorRef)backgroundColor
                                                      displaySentinel:(std::atomic<int32_t>&)displaySentinel
                                         expectedDisplaySentinelValue:(int32_t)expectedDisplaySentinelValue
                                                      drawingDelegate:(id<CKAsyncLayerDrawingDelegate>)drawingDelegate
                                                       drawParameters:(NSObject *)drawParameters;

@end

#endif
