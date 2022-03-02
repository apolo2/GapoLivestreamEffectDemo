//
//  UIView+Bounds.swift
//  GapoEffectTest
//
//  Created by apolo2 on 02/03/2022.
//

import Foundation
import UIKit

public extension UIView {

    var top: CGFloat {
        get {
            return frame.origin.y
        }
        set {
            var rect = frame
            rect.origin.y = newValue
            frame = rect
        }
    }

    var bottom: CGFloat {
        get {
            return frame.origin.y + frame.size.height
        }
        set {
            var rect = frame
            rect.origin.y = newValue - rect.size.height
            frame = rect
        }
    }

    var left: CGFloat {
        get {
            return frame.origin.x
        }
        set {
            var rect = frame
            rect.origin.x = newValue
            frame = rect
        }
    }

    var right: CGFloat {
        get {
            return frame.origin.x + frame.size.width
        }
        set {
            var rect = frame
            rect.origin.x = newValue - rect.size.width
            frame = rect
        }
    }

    var width: CGFloat {
        get {
            return frame.size.width
        }
        set {
            var rect = frame
            rect.size.width = newValue
            frame = rect
        }
    }

    var height: CGFloat {
        get {
            return frame.size.height
        }
        set {
            var rect = frame
            rect.size.height = newValue
            frame = rect
        }
    }
    
}
