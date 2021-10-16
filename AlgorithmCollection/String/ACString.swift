//
//  ACString.swift
//  AlgorithmCollection
//
//  Created by TalMe on 2021/10/14.
//

import Foundation

class ACString {
    
    //最长子串，子串中没有重复字符
    func lengthOfLongestSubstring(_ s: String) -> Int {
         if(s == ""){
            return 0
        }
        var maxStr = String()
        var curStr = String()
        for char in s{
            while curStr.contains(char) {
                curStr.remove(at: curStr.startIndex)
            }
            curStr.append(char)
            if(curStr.count > maxStr.count){
                maxStr = curStr
            }
        }
        return maxStr.count
    }
    
    //编写一个函数来查找字符串数组中的最长公共前缀。
    func longestCommonPrefix(_ strs: [String]) -> String {
        guard strs.count > 0 else { return "" }
        if (strs.count == 1) {
            return strs[0]
        }
        var prefix = strs[0]
        
        for i in 1..<strs.count {
            while !strs[i].hasPrefix(prefix) {
               
                prefix.removeLast()
                if prefix == "" { return "" }
            }
        }
        return prefix
    }
    
    
    func longestCommonPrefix1(_ strs: [String]) -> String {
        guard strs.count > 0 else {
            return ""
        }
        
        var prefix = strs[0]
        
        for i in 1..<strs.count {
            while !strs[i].hasPrefix(prefix) {
                prefix.removeLast()
                if prefix == "" {
                    return ""
                }
            }
        }
        
        return prefix
    }
    
   
}
