/**
 * @param {string[]} emails
 * @return {number}
 */
var number = 0;
var em = []

var numUniqueEmails = function(emails) {
   
    
    for(j = 0;j<emails.length;j++){
        email = emails[j]
        
        var count = email.indexOf("@");
      var e = email[0] ;
      var f = false;
       var  i =1;
         
      while(f===false ){
          var t =email[i]
          
          switch(t){
              case '@': f = true;  break;
              case '+' : f = true;  break;
              case '.':  f = false; break;
              default : e = e+t; 
            }
          i++;
         
        }
      for(i = count;i<email.length;i++){
         
         e = e + email[i]
      }
        em.push(e)
        
    }
      
  
    var k = 0
    i = 0;
   while(em.length!==0){
     var j =   em.pop();
       k++;
     em = em.filter(f =>f!==j)
       
}
     return k
    
}
    
    
