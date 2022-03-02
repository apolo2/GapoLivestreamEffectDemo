//
//  GPEffectManager.h
//  GAPO
//
//  Created by apolo2 on 28/12/2021.
//  Copyright © 2021 GAPO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BEEffectManager.h"
#import "BEEffectResourceHelper.h"

NS_ASSUME_NONNULL_BEGIN

@interface GPEffectManager : NSObject

@property (nonatomic, retain) BEEffectManager *manager;
@property (nonatomic, retain) BEImageUtils *imageUtils;

+ (instancetype)shared;

- (void)updateEffectManager;
- (CIImage *)processWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer rotation:(int)rotation timeStamp:(double)timeStamp;

@end

NS_ASSUME_NONNULL_END
