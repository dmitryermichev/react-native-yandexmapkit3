//
//  RNYandexPlacemarkManager.swift
//  ReactNativeYandexmapkit3
//
//  Created by Dev on 10/10/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

import Foundation

@objc(RNYandexPlacemarkManager)
class RNYandexPlacemarkManager: RCTViewManager {
//    override func view() -> UIView! {  return RNYandexPlacemark()}
    override func view() -> UIView! {
        let labelView = MyLabelView()
        labelView.textColor = UIColor.orange
        labelView.textAlignment = NSTextAlignment.center
        return labelView
    }
}

class MyLabelView: UILabel {
    private var _myText:String?
    var myText: String? {
        set {
            _myText = newValue
            self.text = newValue
        }
        get {
            return _myText
        }
    }

}
