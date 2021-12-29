//
//  LivestreamEffect.swift
//  GapoEffectTest
//
//  Created by apolo2 on 29/12/2021.
//

import Foundation
import HaishinKit
import CoreMedia
import CoreImage

extension VideoEffect {
    func getPixelBuffer(from image: CIImage) -> CVPixelBuffer? {
        var pixelBuffer: CVPixelBuffer?
        let attrs = [kCVPixelBufferCGImageCompatibilityKey: kCFBooleanTrue,
                     kCVPixelBufferCGBitmapContextCompatibilityKey: kCFBooleanTrue] as CFDictionary
        let width:Int = Int(image.extent.size.width)
        let height:Int = Int(image.extent.size.height)
        CVPixelBufferCreate(kCFAllocatorDefault,
                            width,
                            height,
                            kCVPixelFormatType_32BGRA,
                            attrs,
                            &pixelBuffer)
        guard let pixelBuffer = pixelBuffer else { return nil }
        ciContext?.render(image, to: pixelBuffer)
        return pixelBuffer
    }
}

class BeautyEffect: VideoEffect {
    
    override func execute(_ image: CIImage, info: CMSampleBuffer?) -> CIImage {
        guard let pixelBuffer = getPixelBuffer(from: image) else { return image }
        guard let info = info else { return image }
    
        if EAGLContext.current() != DemoViewController.glContext {
            EAGLContext.setCurrent(DemoViewController.glContext)
        }
        
        let sampleTime: CMTime = CMSampleBufferGetPresentationTimeStamp(info)
        let timeStamp: Double = Double(sampleTime.value) / Double(sampleTime.timescale)
        
        let outImage = GPEffectManager.shared().process(with: pixelBuffer, rotation: 0, timeStamp: timeStamp)
        if outImage != nil {
            return outImage
        }
        return image
    }
}

final class MonochromeEffect: VideoEffect {
    let filter: CIFilter? = CIFilter(name: "CIColorMonochrome")

    override func execute(_ image: CIImage, info: CMSampleBuffer?) -> CIImage {
        guard let filter: CIFilter = filter else {
            return image
        }
        
        filter.setValue(image, forKey: "inputImage")
        filter.setValue(CIColor(red: 0.75, green: 0.75, blue: 0.75), forKey: "inputColor")
        filter.setValue(1.0, forKey: "inputIntensity")
        return filter.outputImage!
    }
}
