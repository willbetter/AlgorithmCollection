//
//  ACArray.swift
//  AlgorithmCollection
//
//  Created by TalMe on 2021/9/24.
//

import Foundation

class ACArray {
    
    //两数之和
    //给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
    func twoSum(_ nums:[Int], _ target:Int) -> [Int] {
        var result = [Int]()
        var container = Set<Int>()
        for (index, value) in nums.enumerated() {
            let match = target - value
            if container.contains(match) {
                let first = nums.firstIndex(of: match)!
                result.append(first)
                result.append(index)
                break
            }
            
            container.insert(value)
        }
        
        return result
    }
}
