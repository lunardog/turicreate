/* Copyright © 2019 Apple Inc. All rights reserved.
 *
 * Use of this source code is governed by a BSD-3-clause license that can
 * be found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause
 */

#import <Accelerate/Accelerate.h>
#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import <MetalPerformanceShaders/MetalPerformanceShaders.h> 

#import <ml/neural_net/mps_descriptor_utils.h>
#import <ml/neural_net/style_transfer/mps_style_transfer_weights.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(10.14))
@interface TCMPSStyleTransferTransformerNetwork : NSObject 

@property (nonatomic) MPSNNImageNode *forwardPass;

- (instancetype) initWithParameters:(NSString *)name
                          inputNode:(MPSNNImageNode *)inputNode
                             device:(id<MTLDevice>)dev
                           cmdQueue:(id<MTLCommandQueue>)cmdQ
                         descriptor:(TCMPSTransformerDescriptor *)descriptor
                        initWeights:(NSDictionary<NSString *, NSData *> *) weights;

- (void) setStyleIndex:(NSUInteger)styleIndex;
- (MPSNNImageNode * _Nullable) backwardPass:(MPSNNImageNode *) inputNode;
- (void) setLearningRate:(float)lr;
- (NSDictionary<NSString *, TCMPSStyleTransferWeights *> *) exportWeights:(NSString *) prefix;
@end

NS_ASSUME_NONNULL_END