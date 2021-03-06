import AVFoundation
import CoreImage
import Foundation
import CoreVideo

open class VideoEffect: NSObject {
    open var ciContext: CIContext?

    open func execute(_ image: CIImage, info: CMSampleBuffer?) -> CIImage {
        image
    }
}
