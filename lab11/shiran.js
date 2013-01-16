window.onload = function(){

  document.getElementById("shiran").onkeydown = function(t){
    var KEY_CODE_0 = 48;
    var KEY_CODE_9 = 57;
    if(t.keyCode<=57 && t.keyCode>=48)
      return false;
    else
      return true;

  
    
  }
}