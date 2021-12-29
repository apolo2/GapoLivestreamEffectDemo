//
//  DemoViewController.swift
//  GapoEffectTest
//
//  Created by apolo2 on 29/12/2021.
//

import UIKit
import HaishinKit
import AVFoundation
import PureLayout

let sampleRate: Double = 44100.0

class DemoViewController: UIViewController {

    @IBOutlet weak var liveView: GLHKView!
    var rtmpConnection = RTMPConnection()
    var rtmpStream: RTMPStream!
    private var currentEffect: VideoEffect?
    private var currentPosition: AVCaptureDevice.Position = .front
    static var glContext: EAGLContext?
    
    override func viewDidLoad() {
        super.viewDidLoad()

        DemoViewController.glContext = liveView.context
        liveView.videoGravity = AVLayerVideoGravity.resizeAspectFill
        requestCameraAccess()
        requestMicrophoneAccess()
        setupRtmp()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        rtmpStream.attachAudio(AVCaptureDevice.default(for: .audio)) { error in
            
        }
        rtmpStream.attachCamera(DeviceUtil.device(withPosition: currentPosition)) { error in
            
        }
        liveView.attachStream(rtmpStream)
    }
    
    func requestCameraAccess() {
        AVCaptureDevice.requestAccess(for: AVMediaType.video) { accepted in }
    }
    
    func requestMicrophoneAccess() {
        AVAudioSession.sharedInstance().requestRecordPermission { (accepted) in }
    }
    
    func setupRtmp() {
        rtmpStream = RTMPStream(connection: rtmpConnection)
        if let orientation = DeviceUtil.videoOrientation(by: UIApplication.shared.statusBarOrientation) {
            rtmpStream.orientation = orientation
        }
        rtmpStream.videoSettings = [
            .width: 720,
            .height: 1280
        ]
        rtmpStream?.captureSettings = [
            .sessionPreset: AVCaptureSession.Preset.hd1280x720,
            .continuousAutofocus: true,
            .continuousExposure: true,
            .isVideoMirrored: true
        ]
        rtmpStream?.audioSettings = [
            .sampleRate: sampleRate,
            .bitrate: 32 * 1024,
        ]
    }
    
    @IBAction func beautyAction() {
        if let effect = currentEffect {
            _ = rtmpStream?.unregisterVideoEffect(effect)
        }
        let beauty = BeautyEffect()
        _ = rtmpStream?.registerVideoEffect(beauty)
        currentEffect = beauty
    }
    
    @IBAction func monochromeAction() {
        if let effect = currentEffect {
            _ = rtmpStream?.unregisterVideoEffect(effect)
        }
        let monochrome = MonochromeEffect()
        _ = rtmpStream?.registerVideoEffect(monochrome)
        currentEffect = monochrome
    }
    
    @IBAction func noneEffectAction() {
        if let effect = currentEffect {
            _ = rtmpStream?.unregisterVideoEffect(effect)
        }
        currentEffect = nil
    }
}
