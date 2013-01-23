window.onload = function(){
	document.getElementById("username").onkeydown = function(t)
	{
		if(t.keyCode<=57 && t.keyCode>=48)
			return false;
		else
			return true;    
  	}

	document.getElementById("password").onkeydown = function(t)
	{
		if (document.getElementById("password").value.length == 0)
		{
			if(t.keyCode<=57 && t.keyCode>=48)
				return false;
			else
				return true;
		}
	}

}

function validateForm()
{
	if ((document.getElementById("password").value.length < 5) || (document.getElementById("username").value.length == 0))
	{
		alert("password must be at least 5 chars and username must not be empty");
		return false;
	}
	else
	{
		return true;
	}
}

function showHint(str){
	varxmlhttp;
	if (str.length==0){
		document.getElementById("txtHint").innerHTML="";
		return;
	}
	if (window.XMLHttpRequest){// IE7+,Firefox,Chrome,Opera, Safari
		xmlhttp=new XMLHttpRequest();
	}
	else{// code for IE6, IE5
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	}
	xmlhttp.onreadystatechange=function(){
		if (xmlhttp.readyState==4 &&xmlhttp.status==200){
			document.getElementById("txtHint").innerHTML=xmlhttp.responseText;
		}
	}
	xmlhttp.open("GET","http://www.cs.bgu.ac.il/~abedas/suggest.php?q="+str,true);
	xmlhttp.send();
}




