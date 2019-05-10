/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
    
    
    var em = []
    
    var morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    
    
    for(j = 0;j<words.length;j++){
        var e = ''
      var word = words[j];
        
      for(i = 0;i<word.length;i++){
          var lower = word[i].toLowerCase();
          var value = lower.charCodeAt(0) - 'a'.charCodeAt(0);
          e = e+ morse[value];
          
      }
        
        em.push(e)
    }
    console.log(em)
    
    var k = 0
    
    var values = [];
   while(em.length!==0){
     var j = em.pop();
     em = em.filter(f =>f!==j)
     k++;
     }
    return k;
    
};