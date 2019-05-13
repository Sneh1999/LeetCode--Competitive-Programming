/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 * 
 * Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

 */
var backspaceCompare = function(S, T) {
    let kt = build(S)
    let j = build(T)
    console.log(kt)
    console.log(j)
    // if(kt.length === 0 && j.length === 0){
    //     return true
    //   }
    if(kt===j){
        return true
        }
    else{
        return false
    }
    console.log(k)
};


var build = function(x){
    var k = []
    var t;
    var j = x
    for(var i = 0 ; i<j.length;i++){
        if(x[i] === '#'){
            k.pop()
        }
        else{
            k.push(x[i])
        }
    }
    for(var i = 0;i<k.length;i++){
        t += k[i]
    }
   
    return t
}