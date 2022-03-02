//
//  GPEffectManager.m
//  GAPO
//
//  Created by apolo2 on 28/12/2021.
//  Copyright © 2021 GAPO. All rights reserved.
//

#import "GPEffectManager.h"

@implementation GPEffectManager

static GPEffectManager *_shared;

+ (instancetype)shared {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _shared = [[GPEffectManager alloc] init];
    });
    return _shared;
}

- (instancetype)init {
    if (self = [super init]) {
        self.manager = [[BEEffectManager alloc]
                        initWithResourceProvider:[BEEffectResourceHelper new]
                        licenseProvider:[BELicenseHelper shareInstance]];
        int ret = [self.manager initTask];
        if (ret == BEF_RESULT_SUC) {
            
        }
        self.imageUtils = [[BEImageUtils alloc] init];
    }
    return self;
}

- (void)updateEffectManager {
    self.manager.frontCamera = YES;
    [self.manager updateComposerNodes:@[@"beauty_IOS_lite", @"reshape_lite", @"/lip/lite/shaonvfen", @"/eyeshadow/shaonvfen"]];
    
    [self.manager updateComposerNodeIntensity:@"beauty_IOS_lite" key:@"smooth" intensity:0.5];
    [self.manager updateComposerNodeIntensity:@"beauty_IOS_lite" key:@"sharp" intensity:0.7];
    
    [self.manager updateComposerNodeIntensity:@"reshape_lite" key:@"Internal_Deform_Overall" intensity:0.35];
    [self.manager updateComposerNodeIntensity:@"reshape_lite" key:@"Internal_Deform_Eye" intensity:0.35];
    [self.manager updateComposerNodeIntensity:@"reshape_lite" key:@"Internal_Deform_MovNose" intensity:0];
    
    [self.manager updateComposerNodeIntensity:@"/lip/lite/shaonvfen" key:@"Internal_Makeup_Lips" intensity:0.5];
    
    [self.manager updateComposerNodeIntensity:@"/eyeshadow/shaonvfen" key:@"Internal_Makeup_Eye" intensity:0.35];
}

- (CIImage *)processWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer rotation:(int)rotation timeStamp:(double)timeStamp {
    BEPixelBufferInfo *pixelBufferInfo = [self.imageUtils getCVPixelBufferInfo:pixelBuffer];
    if (pixelBufferInfo.format != BE_BGRA) {
        pixelBuffer = [self.imageUtils transforCVPixelBufferToCVPixelBuffer:pixelBuffer outputFormat:BE_BGRA];
    }
    if (rotation != 0) {
        pixelBuffer = [self.imageUtils rotateCVPixelBuffer:pixelBuffer rotation:rotation];
    }
    
    id<BEGLTexture> texture = [self.imageUtils transforCVPixelBufferToTexture:pixelBuffer];
    BEPixelBufferGLTexture *outTexture = [self.imageUtils getOutputPixelBufferGLTextureWithWidth:texture.width height:texture.height format:BE_BGRA];
    
    int ret = [self.manager processTexture:texture.texture outputTexture:outTexture.texture width:texture.width height:texture.height rotate:0 timeStamp:timeStamp];
    if (ret != BEF_RESULT_SUC) {
        outTexture = texture;
    }
    return [CIImage imageWithCVPixelBuffer:[outTexture pixelBuffer]];
}

@end
