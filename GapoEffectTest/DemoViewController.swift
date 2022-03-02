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
import RxKeyboard
import RxSwift
import RxCocoa
import RxGesture

let sampleRate: Double = 44100.0

class DemoViewController: UIViewController {

    @IBOutlet weak var liveView: GLHKView!
    @IBOutlet weak var buttonsStack: UIStackView!
    @IBOutlet weak var textView: UITextView!
    @IBOutlet weak var textViewBottomConstraint: NSLayoutConstraint!
    
    var rtmpConnection = RTMPConnection()
    var rtmpStream: RTMPStream!
    private var currentEffect: VideoEffect?
    private var currentPosition: AVCaptureDevice.Position = .front
    static var glContext: EAGLContext?
    
    var disposeBag: DisposeBag? = DisposeBag()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        DemoViewController.glContext = liveView.context
        liveView.videoGravity = AVLayerVideoGravity.resizeAspectFill
        requestCameraAccess()
        requestMicrophoneAccess()
        setupRtmp()
        bindKeyboardDidChange()
        bindViewTapGesture()
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
        GPEffectManager.shared().update()
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
    
    @IBAction func resetScreen() {
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else { return }
        appDelegate.resetScreen()
    }
    
    func hideKeyboard() {
        textView.resignFirstResponder()
    }
    
    // MARK: Bindings
    func bindKeyboardDidChange() {
        RxKeyboard.instance.visibleHeight
        .drive(onNext: { [weak self] height in
            guard let self = self else { return }
            if height > 0 && !self.textView.isFirstResponder { return }
            
            let textViewBottom = height - (self.view.height - self.buttonsStack.top) + 8
            self.textViewBottomConstraint.constant = max(textViewBottom, 32)
            self.view.setNeedsLayout()
            UIView.animate(withDuration: 0) {
                self.view.layoutIfNeeded()
            }
        }) => disposeBag
    }
    
    func bindViewTapGesture() {
        liveView.rx.tapGesture()
            .subscribe(onNext: { [weak self] gesture in
                self?.hideKeyboard()
            }) => disposeBag
    }
}
