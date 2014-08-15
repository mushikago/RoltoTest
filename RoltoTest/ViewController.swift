//
//  ViewController.swift
//  RoltoTest
//
//  Created by Tetsuya Shiraishi on 2014/08/15.
//  Copyright (c) 2014年 mushikago. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var targetImage: UIImageView!
                            
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


    @IBAction func printTarget(sender: AnyObject) {
        let dicover = RoltoPrintDiscover()
        dicover.searchPrintersWithCallback(
            { (var print) in
                self.performPrint(print)
            }
            , comletion: {}, duration: 3)
    }
    
    
    func performPrint(_print:RoltoPrint) -> Void{
        var _params = [
            RoltoPrintParameterBlockSize:0.7,
            RoltoPrintParameterBinarizationOffset:0.05,
            RoltoPrintParameterErrorDiffusion:false
        ]
        _print.performPrintImage(
            targetImage.image,
            params: _params,
            completion: {(var result:RoltoPrintResult) in })
    }
    
}

